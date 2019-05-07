#include "pms7003m.h"
#include "delay.h"
#include "sys.h"
u8 pms7003_recv_buf[32];
u8 pms7003_cmd_buf[7];
u16 ERR_CODE;
u16 recv_usart1_byte_count;

//////////////////////////////////////////////////////////////////
//加入以下代码,支持printf函数,而不需要选择use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
_sys_exit(int x) 
{ 
	x = x; 
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//循环发送,直到发送完毕   
    USART1->DR = (u8) ch;      
	return ch;
}
#endif 
 
#if EN_USART1_RX   //如果使能了接收
//串口1中断服务程序
//注意,读取USARTx->SR能避免莫名其妙的错误   	
u8  USART1_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
u16 USART1_RX_STA;         		   //接收状态标记	
u16 PM1_0,PM2_5,PM10,DQPM1_0,DQPM2_5,DQPM10;
u16 P03UP,P05UP,P10UP,P25UP,P50UP,P100UP;
  
void Init_USART1(u32 bound)
{
  //GPIO端口设置
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//使能USART1，GPIOA时钟
  
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.9
   
  //USART1_RX	  GPIOA.10初始化
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.10  

  //Usart1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
  
   //USART 初始化设置

	USART_InitStructure.USART_BaudRate = bound;//串口波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

  USART_Init(USART1, &USART_InitStructure); //初始化串口1
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启串口接受中断
  USART_Cmd(USART1, ENABLE);                    //使能串口1 

}



void USART1_IRQHandler(void)                	//串口1中断服务程序
	{

	  u8 Res,i;
#if SYSTEM_SUPPORT_OS 		//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
	OSIntEnter();    
#endif
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x42 0x4d开头)
	{
			Res =USART_ReceiveData(USART1);	//读取接收到的数据
			if((USART1_RX_STA&0x8000)==0)//接收未完成
			{
				if(USART1_RX_STA&0x4000)//接收到了0x42 0x4d
				{
						USART1_RX_BUF[recv_usart1_byte_count]=Res ;
						recv_usart1_byte_count ++;
					  if (recv_usart1_byte_count==32)
						{				  
							for(i=0;i<32;i++)
							{
								pms7003_recv_buf[i]=USART1_RX_BUF[i];
							}
							PMS7003MConvert();
							USART1_RX_STA|=0x8000; //接受完；
						}
						
							
				}
				else //还没收到0X4d
				{	
					if(USART1_RX_STA&0x2000)
					{
						if (Res==0x4d)
						{
							USART1_RX_STA|=0x4000;
							USART1_RX_BUF[0]=0x42;
							USART1_RX_BUF[1]=0x4d;
							recv_usart1_byte_count=2;
						}
						else
							USART1_RX_STA=0;
					}
					else
					{
					   if (Res==0x42)	USART1_RX_STA|=0x2000;
						 else 
							 USART1_RX_STA=0;
					}		 
				}
			} 
		
   } 
	
#if SYSTEM_SUPPORT_OS 	//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
	OSIntExit();  											 
#endif
} 
#endif	

void Gett_PMS7003M_Cmd_Data(u8 scmd ,u16 sdata)
{
    u16 lrcdata,temp16data;
    u8 i;
    pms7003_cmd_buf[0]=0x42;
    pms7003_cmd_buf[1]=0x4d;
    pms7003_cmd_buf[2]=scmd;
    pms7003_cmd_buf[3]=sdata>>8;
    pms7003_cmd_buf[4]=sdata;
    lrcdata=0;
    for(i=0;i<5;i++)
     	{
          temp16data = pms7003_cmd_buf[i];
        	lrcdata= lrcdata + temp16data;
        }
    pms7003_cmd_buf[5]=lrcdata>>8;
    pms7003_cmd_buf[6]=lrcdata;
}

u8 PMS7003MConvert(void)  // 转换出各种参数
{  
	  u8 i,succ;
    u8 lrcdatah,lrcdatal;
	  u16 lrcdata,temp16data;
    u16 t16data1,t16data2,t16data3;
    
    succ=0;

	  if((pms7003_recv_buf[0]==0x42)&&(pms7003_recv_buf[1]==0x4d))//判断固定标记
    {
        if(pms7003_recv_buf[3]==0x1c)//判断帧长度
        {   
            lrcdata=0;
            for(i=0;i<30;i++)
						{
							temp16data = pms7003_recv_buf[i];
							lrcdata= lrcdata + temp16data;
						}
    		    lrcdatah=lrcdata>>8;
    		    lrcdatal=lrcdata;
    		    if((lrcdatah==pms7003_recv_buf[30])&&(lrcdatal==pms7003_recv_buf[31]))//校验和
            {
							t16data1=pms7003_recv_buf[4];
							t16data2=pms7003_recv_buf[5];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							PM1_0=t16data3;

							t16data1=pms7003_recv_buf[6];
							t16data2=pms7003_recv_buf[7];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							PM2_5=t16data3;

							t16data1=pms7003_recv_buf[8];
							t16data2=pms7003_recv_buf[9];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							PM10=t16data3;

							t16data1=pms7003_recv_buf[10];
							t16data2=pms7003_recv_buf[11];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							DQPM1_0=t16data3;

							t16data1=pms7003_recv_buf[12];
							t16data2=pms7003_recv_buf[13];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							DQPM2_5=t16data3;

							t16data1=pms7003_recv_buf[14];
							t16data2=pms7003_recv_buf[15];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							DQPM10=t16data3;

							t16data1=pms7003_recv_buf[16];
							t16data2=pms7003_recv_buf[17];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							P03UP=t16data3;

							t16data1=pms7003_recv_buf[18];
							t16data2=pms7003_recv_buf[19];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							P05UP=t16data3;

							t16data1=pms7003_recv_buf[20];
							t16data2=pms7003_recv_buf[21];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							P10UP=t16data3;

							t16data1=pms7003_recv_buf[22];
							t16data2=pms7003_recv_buf[23];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							P25UP=t16data3;

							t16data1=pms7003_recv_buf[24];
							t16data2=pms7003_recv_buf[25];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							P50UP=t16data3;

							t16data1=pms7003_recv_buf[26];
							t16data2=pms7003_recv_buf[27];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							P100UP=t16data3;

							t16data1=pms7003_recv_buf[28];
							t16data2=pms7003_recv_buf[29];
							t16data3=((t16data1<<8)&0xff00)|(t16data2&0xff);
							ERR_CODE=t16data3;   
              succ=0;
            }
						else
							succ=3;
        }
				else
					succ=2;
    }
		else
			succ=1;
    return succ;
}	

void SendCmd_PMS7003(u8 cmd)
{  
	u8 i,sendcmd;
  Gett_PMS7003M_Cmd_Data(cmd,0);
  delay_us(10);
  sendcmd=0;
	do
	{
		for(i=0;i<7;i++)
		{
			USART_SendData(USART1,pms7003_cmd_buf[i]);
		}
		delay_us(200);
		sendcmd++;
	}while(sendcmd<5);	
}
void Init_PMS7003M(void)
{ 
	Init_USART1(9600);
	SendCmd_PMS7003(0xe1);
}
void PMS7003M_Start(void)
{
	SendCmd_PMS7003(0xe2);
}

//void PMS7003M_Standby()
//{
//	SendCmd_PMS7003(0xe4);
//}



