/*
*********************************************************************************************************
*
*	模块名称 : 汉字点阵字库。有效显示区 高16x宽15, 最右一列留白
*	文件名称 : hz16.c
*	版    本 : V1.0
*	说    明 : 只包含本程序用到汉字字库
*	修改记录 :
*		版本号  日期       作者    说明
*		v1.0    2011-09-08 armfly  ST固件库V3.5.0版本。
*
*	Copyright (C), 2010-2011, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/


/*
	FLASH中内嵌小字库，只包括本程序用到的汉字点阵
	每行点阵数据，头2字节是汉子的内码，后面32字节是16点阵汉子的字模数据。
*/

unsigned char const g_Hz16[] = {
0xA1,0xA3, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 。 //
           0x00,0x00,0x00,0x00,0x3C,0x00,0x66,0x00,0x66,0x00,0x66,0x00,0x3C,0x00,0x00,0x00,

0xA3,0xAC, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// ， //
           0x0C,0x00,0x1E,0x00,0x1E,0x00,0x0C,0x00,0x04,0x00,0x08,0x00,0x10,0x00,0x00,0x00,

0xB0,0xB2, 0x02,0x00,0x01,0x00,0x7F,0xFE,0x40,0x02,0x82,0x04,0x02,0x00,0x02,0x04,0xFF,0xFE,// 安 //
           0x04,0x20,0x08,0x20,0x18,0x20,0x06,0x40,0x01,0x80,0x02,0x40,0x0C,0x30,0x30,0x10,

0xB1,0xCC, 0x04,0x40,0xFE,0x88,0x11,0xFC,0x7D,0x08,0x11,0xF8,0x1F,0x08,0xF1,0xF8,0x00,0x08,// 碧 //
           0x7F,0xFC,0x04,0x00,0x08,0x10,0x1F,0xF8,0x28,0x10,0xC8,0x10,0x0F,0xF0,0x08,0x10,

0xB2,0xD9, 0x10,0x10,0x11,0xF8,0x11,0x10,0x11,0xF0,0xFC,0x04,0x17,0xBE,0x14,0xA4,0x1F,0xBC,// 操 //
           0x30,0x40,0xD0,0x44,0x1F,0xFE,0x10,0xE0,0x11,0x50,0x12,0x4E,0x54,0x44,0x20,0x40,

0xB3,0xA4, 0x08,0x00,0x08,0x10,0x08,0x30,0x08,0x40,0x08,0x80,0x09,0x00,0x08,0x04,0xFF,0xFE,// 长 //
           0x09,0x00,0x09,0x00,0x08,0x80,0x08,0x40,0x08,0x20,0x09,0x1C,0x0E,0x08,0x08,0x00,

0xB3,0xCC, 0x08,0x04,0x1D,0xFE,0xF1,0x04,0x11,0x04,0x11,0x04,0xFF,0x04,0x11,0xFC,0x38,0x00,// 程 //
           0x37,0xFE,0x54,0x20,0x50,0x28,0x91,0xFC,0x10,0x20,0x10,0x24,0x17,0xFE,0x10,0x00,

0xB4,0xC7, 0x08,0x40,0x1C,0x20,0xF0,0x28,0x11,0xFC,0x10,0x00,0x14,0x88,0xFE,0x50,0x10,0x04,// 辞 //
           0x15,0xFE,0x7E,0x20,0x44,0x28,0x45,0xFC,0x44,0x20,0x44,0x20,0x7C,0x20,0x44,0x20,

0xB7,0xAB, 0x10,0x08,0x10,0xFC,0x14,0x88,0x7E,0x88,0x54,0x88,0x54,0xC8,0x54,0xA8,0x54,0xA8,// 帆 //
           0x54,0x88,0x54,0x88,0x5C,0x88,0x54,0x88,0x11,0x0A,0x11,0x0A,0x12,0x06,0x14,0x00,

0xB8,0xBB, 0x02,0x00,0x01,0x00,0x7F,0xFE,0x40,0x22,0x9F,0xF4,0x00,0x00,0x1F,0xF0,0x10,0x10,// 富 //
           0x1F,0xF0,0x00,0x08,0x3F,0xFC,0x21,0x08,0x3F,0xF8,0x21,0x08,0x3F,0xF8,0x20,0x08,

0xB8,0xCB, 0x10,0x00,0x10,0x08,0x11,0xFC,0x10,0x20,0xFC,0x20,0x10,0x20,0x30,0x24,0x3B,0xFE,// 杆 //
           0x54,0x20,0x50,0x20,0x90,0x20,0x10,0x20,0x10,0x20,0x10,0x20,0x10,0x20,0x10,0x20,

0xB9,0xC2, 0x00,0x08,0x7C,0x3C,0x07,0xC0,0x0A,0x10,0x12,0x90,0x12,0x90,0x16,0x90,0x1A,0x90,// 孤 //
           0x32,0x90,0xD2,0x90,0x12,0x90,0x12,0x90,0x14,0xA8,0x15,0xEE,0x58,0x24,0x20,0x00,

0xB9,0xCA, 0x10,0x40,0x10,0x40,0x10,0x40,0x14,0x44,0xFE,0xFE,0x11,0x08,0x12,0x88,0x10,0x88,// 故 //
           0x7C,0x88,0x44,0x88,0x44,0x50,0x44,0x20,0x44,0x20,0x7C,0x50,0x44,0x8E,0x03,0x04,

0xBA,0xD7, 0x08,0x20,0x08,0x48,0x7F,0xFC,0x52,0x88,0x90,0xA8,0x28,0x88,0x7E,0xA8,0xA8,0x90,// 鹤 //
           0x3E,0x84,0x28,0xFE,0x3E,0x04,0x28,0x24,0x29,0xF4,0x3E,0x04,0x20,0x14,0x20,0x08,

0xBB,0xA8, 0x08,0x20,0x08,0x24,0xFF,0xFE,0x08,0x20,0x08,0x20,0x08,0x80,0x10,0x88,0x10,0x98,// 花 //
           0x30,0xA0,0x50,0xC0,0x90,0x80,0x11,0x80,0x12,0x82,0x14,0x82,0x10,0x7E,0x10,0x00,

0xBB,0xC6, 0x04,0x40,0x04,0x50,0x3F,0xF8,0x04,0x40,0x04,0x44,0xFF,0xFE,0x01,0x10,0x1F,0xF8,// 黄 //
           0x11,0x10,0x1F,0xF0,0x11,0x10,0x1F,0xF0,0x10,0x00,0x04,0x60,0x18,0x18,0x60,0x04,

0xBC,0xCA, 0x00,0x08,0x7D,0xFC,0x44,0x00,0x48,0x00,0x48,0x00,0x50,0x04,0x4B,0xFE,0x48,0x20,// 际 //
           0x44,0x20,0x44,0xA8,0x44,0xA4,0x69,0x22,0x52,0x22,0x40,0x20,0x40,0xA0,0x40,0x40,

0xBC,0xFB, 0x00,0x10,0x1F,0xF8,0x10,0x10,0x11,0x10,0x11,0x10,0x11,0x10,0x11,0x10,0x11,0x10,// 见 //
           0x11,0x10,0x12,0x10,0x12,0x90,0x04,0x80,0x04,0x82,0x08,0x82,0x30,0x7E,0xC0,0x00,

0xBD,0xAD, 0x40,0x00,0x30,0x08,0x17,0xFC,0x00,0x40,0x80,0x40,0x60,0x40,0x20,0x40,0x08,0x40,// 江 //
           0x10,0x40,0x20,0x40,0xE0,0x40,0x20,0x40,0x20,0x44,0x2F,0xFE,0x20,0x00,0x20,0x00,

0xBE,0xA1, 0x00,0x08,0x1F,0xFC,0x10,0x08,0x10,0x08,0x1F,0xF8,0x11,0x08,0x10,0x80,0x10,0x80,// 尽 //
           0x10,0x40,0x16,0x20,0x21,0x90,0x40,0x0E,0x86,0x04,0x01,0x80,0x00,0xC0,0x00,0x40,

0xBF,0xD5, 0x02,0x00,0x01,0x00,0x7F,0xFE,0x40,0x02,0x84,0x44,0x0C,0x30,0x10,0x18,0x20,0x08,// 空 //
           0x00,0x00,0x3F,0xF8,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x04,0xFF,0xFE,0x00,0x00,

0xC0,0xB3, 0x08,0x20,0x08,0x24,0xFF,0xFE,0x09,0x20,0x01,0x08,0x7F,0xFC,0x01,0x00,0x09,0x20,// 莱 //
           0x05,0x44,0xFF,0xFE,0x03,0x80,0x05,0x40,0x09,0x30,0x31,0x0E,0xC1,0x04,0x01,0x00,

0xC0,0xFD, 0x10,0x04,0x10,0x44,0x1F,0xE4,0x22,0x04,0x22,0x14,0x67,0xD4,0xA4,0x54,0x28,0x54,// 例 //
           0x34,0x94,0x22,0x94,0x21,0x14,0x22,0x04,0x24,0x04,0x28,0x04,0x20,0x14,0x20,0x08,

0xC1,0xF7, 0x00,0x80,0x40,0x48,0x37,0xFC,0x10,0x40,0x80,0x90,0x61,0x08,0x27,0xFC,0x08,0x04,// 流 //
           0x11,0x50,0x21,0x50,0xE1,0x50,0x21,0x50,0x21,0x52,0x21,0x52,0x22,0x4E,0x24,0x40,

0xC2,0xA5, 0x10,0x40,0x12,0x48,0x11,0x50,0x10,0x44,0xFF,0xFE,0x11,0x50,0x3A,0x4C,0x34,0x44,// 楼 //
           0x50,0x80,0x5F,0xFE,0x91,0x08,0x12,0x08,0x11,0xB0,0x10,0x40,0x11,0xB0,0x16,0x08,

0xC7,0xEB, 0x00,0x48,0x47,0xFC,0x20,0x40,0x23,0xF8,0x00,0x40,0xEF,0xFE,0x20,0x08,0x23,0xFC,// 请 //
           0x22,0x08,0x23,0xF8,0x22,0x08,0x23,0xF8,0x2A,0x08,0x32,0x08,0x22,0x28,0x02,0x10,

0xC8,0xCB, 0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x02,0x80,// 人 //
           0x02,0x80,0x02,0x80,0x04,0x40,0x04,0x40,0x08,0x20,0x10,0x10,0x20,0x0E,0x40,0x04,

0xC8,0xFD, 0x00,0x00,0x00,0x08,0x7F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x3F,0xF8,// 三 //
           0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xFF,0xFE,0x00,0x00,0x00,0x00,

0xCC,0xEC, 0x00,0x08,0x7F,0xFC,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x04,0xFF,0xFE,0x01,0x00,// 天 //
           0x02,0x80,0x02,0x80,0x04,0x40,0x04,0x40,0x08,0x20,0x10,0x10,0x20,0x0E,0xC0,0x04,

0xCE,0xA8, 0x00,0x80,0x08,0xA0,0x7C,0x94,0x49,0xFE,0x49,0x10,0x4B,0x10,0x4D,0xFC,0x49,0x10,// 唯 //
           0x49,0x10,0x49,0xFC,0x49,0x10,0x79,0x10,0x49,0x14,0x01,0xFE,0x01,0x00,0x01,0x00,

0xCE,0xF7, 0x00,0x00,0x00,0x04,0xFF,0xFE,0x04,0x40,0x04,0x40,0x04,0x44,0x7F,0xFE,0x44,0x44,// 西 //
           0x44,0x44,0x44,0x44,0x44,0x44,0x48,0x34,0x50,0x04,0x40,0x04,0x7F,0xFC,0x40,0x04,

0xCF,0xC2, 0x00,0x04,0xFF,0xFE,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x80,0x02,0x40,0x02,0x30,// 下 //
           0x02,0x10,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,

0xD1,0xCC, 0x20,0x04,0x27,0xFE,0x24,0x04,0x24,0x44,0x2C,0x44,0xB4,0x44,0xA7,0xFC,0xA4,0x44,// 烟 //
           0x24,0x44,0x24,0xA4,0x24,0x94,0x25,0x0C,0x56,0x0C,0x4C,0x04,0x87,0xFC,0x04,0x04,

0xD1,0xEF, 0x10,0x00,0x13,0xF8,0x10,0x10,0x10,0x20,0xFC,0x40,0x10,0x84,0x17,0xFE,0x18,0xA4,// 扬 //
           0x30,0xA4,0xD0,0xA4,0x11,0x24,0x11,0x44,0x12,0x44,0x14,0x84,0x51,0x28,0x20,0x10,

0xD2,0xA1, 0x10,0x08,0x10,0x3C,0x17,0xC0,0x12,0x48,0xFD,0x48,0x11,0x50,0x16,0x00,0x1B,0xFC,// 摇 //
           0x34,0x40,0xD0,0x44,0x1F,0xFE,0x10,0x40,0x12,0x48,0x12,0x48,0x53,0xF8,0x22,0x08,

0xD3,0xB0, 0x00,0x84,0x3F,0xC4,0x20,0x88,0x3F,0x90,0x20,0xA0,0x3F,0x84,0x04,0x04,0xFF,0xE8,// 影 //
           0x00,0x10,0x3F,0xA2,0x20,0x82,0x3F,0x84,0x15,0x08,0x24,0x90,0x54,0xA0,0x08,0x40,

0xD4,0xB6, 0x00,0x10,0x43,0xF8,0x30,0x00,0x10,0x00,0x00,0x08,0x07,0xFC,0xF1,0x20,0x11,0x20,// 远 //
           0x11,0x20,0x11,0x24,0x12,0x24,0x12,0x1C,0x14,0x00,0x28,0x06,0x47,0xFC,0x00,0x00,

0xD4,0xC2, 0x00,0x10,0x0F,0xF8,0x08,0x10,0x08,0x10,0x08,0x10,0x0F,0xF0,0x08,0x10,0x08,0x10,// 月 //
           0x08,0x10,0x0F,0xF0,0x08,0x10,0x08,0x10,0x10,0x10,0x10,0x10,0x20,0x50,0x40,0x20,

0xD6,0xDD, 0x10,0x04,0x10,0x84,0x10,0x84,0x10,0x84,0x54,0xA4,0x52,0x94,0x52,0x94,0x90,0x84,// 州 //
           0x10,0x84,0x10,0x84,0x10,0x84,0x10,0x84,0x20,0x84,0x20,0x84,0x40,0x04,0x00,0x04,

0xD7,0xF7, 0x09,0x00,0x09,0x00,0x09,0x04,0x11,0xFE,0x12,0x80,0x32,0x80,0x54,0x90,0x98,0xF8,// 作 //
           0x10,0x80,0x10,0x80,0x10,0x88,0x10,0xFC,0x10,0x80,0x10,0x80,0x10,0x80,0x10,0x80,

0xB7,0xD6, 0x00,0x80,0x04,0x80,0x04,0x40,0x08,0x40,0x08,0x20,0x10,0x10,0x20,0x08,0x4F,0xEE,// 分 //
           0x84,0x24,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x08,0x20,0x11,0x40,0x20,0x80,

0xC3,0xEB, 0x04,0x20,0x0E,0x20,0x78,0x20,0x08,0x20,0x08,0xA8,0xFE,0xA6,0x08,0xA2,0x1D,0x20,// 秒 //
           0x1A,0x24,0x28,0x24,0x28,0x28,0x48,0x10,0x88,0x20,0x08,0x40,0x08,0x80,0x0B,0x00,

0xC4,0xEA, 0x08,0x00,0x08,0x08,0x1F,0xFC,0x11,0x00,0x21,0x00,0x41,0x10,0x1F,0xF8,0x11,0x00,// 年 //
           0x11,0x00,0x11,0x04,0xFF,0xFE,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,

0xC8,0xD5, 0x00,0x10,0x1F,0xF8,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,// 日 //
           0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1F,0xF0,0x10,0x10,0x00,0x00,

0xCA,0xB1, 0x00,0x08,0x04,0x08,0x7E,0x08,0x44,0x08,0x47,0xFE,0x44,0x08,0x44,0x08,0x7C,0x88,// 时 //
           0x44,0x48,0x44,0x48,0x44,0x08,0x44,0x08,0x7C,0x08,0x44,0x48,0x00,0x28,0x00,0x10,

0xD4,0xC2, 0x00,0x10,0x0F,0xF8,0x08,0x10,0x08,0x10,0x08,0x10,0x0F,0xF0,0x08,0x10,0x08,0x10,// 月 //
           0x08,0x10,0x0F,0xF0,0x08,0x10,0x08,0x10,0x10,0x10,0x10,0x10,0x20,0x50,0x40,0x20,
/* 最后一行必须用0xFF,0xFF结束，这是字库数组结束标志 */
0xFF,0xFF

};
