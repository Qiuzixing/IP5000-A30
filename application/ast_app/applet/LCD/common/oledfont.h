#ifndef __OLEDFONT_H
#define __OLEDFONT_H


#if 0
const unsigned char char_16_8[][16] = {
    {0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00},/*"0",0*/
    {0x00,0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00},/*"1",1*/
    {0x00,0x70,0x08,0x08,0x08,0x08,0xF0,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00},/*"2",2*/
    {0x00,0x30,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x18,0x20,0x21,0x21,0x22,0x1C,0x00},/*"3",3*/
    {0x00,0x00,0x80,0x40,0x30,0xF8,0x00,0x00,0x00,0x06,0x05,0x24,0x24,0x3F,0x24,0x24},/*"4",4*/
    {0x00,0xF8,0x88,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x20,0x20,0x20,0x11,0x0E,0x00},/*"5",5*/
    {0x00,0xE0,0x10,0x88,0x88,0x90,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x20,0x1F,0x00},/*"6",6*/
    {0x00,0x18,0x08,0x08,0x88,0x68,0x18,0x00,0x00,0x00,0x00,0x3E,0x01,0x00,0x00,0x00},/*"7",7*/
    {0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00},/*"8",8*/
    {0x00,0xF0,0x08,0x08,0x08,0x10,0xE0,0x00,0x00,0x01,0x12,0x22,0x22,0x11,0x0F,0x00},/*"9",9*/
    
    {0x00,0x00,0xE0,0x1C,0x70,0x80,0x00,0x00,0x10,0x1E,0x11,0x01,0x01,0x13,0x1C,0x10},/*"A",0*/ //10
    {0x04,0xFC,0x44,0x44,0x44,0xB8,0x00,0x00,0x10,0x1F,0x10,0x10,0x10,0x08,0x07,0x00},/*"B",1*/
    {0xE0,0x18,0x04,0x04,0x04,0x04,0x1C,0x00,0x03,0x0C,0x10,0x10,0x10,0x08,0x04,0x00},/*"C",2*/
    {0x04,0xFC,0x04,0x04,0x04,0x08,0xF0,0x00,0x10,0x1F,0x10,0x10,0x10,0x08,0x07,0x00},/*"D",3*/
    {0x04,0xFC,0x44,0x44,0xF4,0x04,0x08,0x00,0x10,0x1F,0x10,0x10,0x11,0x10,0x0C,0x00},/*"E",4*/
    {0x04,0xFC,0x44,0x44,0xF4,0x04,0x08,0x00,0x10,0x1F,0x10,0x00,0x01,0x00,0x00,0x00},/*"F",5*/
    {0xE0,0x18,0x04,0x04,0x04,0x1C,0x00,0x00,0x03,0x0C,0x10,0x10,0x11,0x0F,0x01,0x00},/*"G",6*/
    {0x04,0xFC,0x84,0x80,0x80,0x84,0xFC,0x04,0x10,0x1F,0x10,0x00,0x00,0x10,0x1F,0x10},/*"H",7*/
    {0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00,0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},/*"I",8*/
    {0x00,0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x60,0x40,0x40,0x40,0x3F,0x00,0x00,0x00},/*"J",9*/
    {0x04,0xFC,0x44,0xE0,0x14,0x0C,0x04,0x00,0x10,0x1F,0x10,0x00,0x13,0x1C,0x10,0x00},/*"K",10*/
    {0x04,0xFC,0x04,0x00,0x00,0x00,0x00,0x00,0x10,0x1F,0x10,0x10,0x10,0x10,0x18,0x00},/*"L",11*/
    {0x04,0xFC,0xFC,0x00,0xFC,0xFC,0x04,0x00,0x10,0x1F,0x00,0x1F,0x00,0x1F,0x10,0x00},/*"M",12*/
    {0x04,0xFC,0x18,0x60,0x80,0x04,0xFC,0x04,0x10,0x1F,0x10,0x00,0x03,0x0C,0x1F,0x00},/*"N",13*/
    {0xF0,0x08,0x04,0x04,0x04,0x08,0xF0,0x00,0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00},/*"O",14*/
    {0x04,0xFC,0x84,0x84,0x84,0x84,0x78,0x00,0x10,0x1F,0x10,0x00,0x00,0x00,0x00,0x00},/*"P",15*/
    {0xF0,0x08,0x04,0x04,0x04,0x08,0xF0,0x00,0x07,0x08,0x14,0x14,0x18,0x28,0x27,0x00},/*"Q",16*/
    {0x04,0xFC,0x44,0x44,0xC4,0x44,0x38,0x00,0x10,0x1F,0x10,0x00,0x01,0x06,0x18,0x10},/*"R",17*/
    {0x00,0x38,0x44,0x84,0x84,0x04,0x1C,0x00,0x00,0x1C,0x10,0x10,0x10,0x11,0x0E,0x00},/*"S",18*/
    {0x0C,0x04,0x04,0xFC,0x04,0x04,0x0C,0x00,0x00,0x00,0x10,0x1F,0x10,0x00,0x00,0x00},/*"T",19*/
    {0x04,0xFC,0x04,0x00,0x00,0x04,0xFC,0x04,0x00,0x0F,0x10,0x10,0x10,0x10,0x0F,0x00},/*"U",20*/
    {0x04,0x3C,0xC4,0x00,0x00,0xE4,0x1C,0x04,0x00,0x00,0x03,0x1C,0x07,0x00,0x00,0x00},/*"V",21*/
    {0x04,0xFC,0x00,0xFC,0x00,0xFC,0x04,0x00,0x00,0x01,0x1F,0x00,0x1F,0x01,0x00,0x00},/*"W",22*/
    {0x04,0x0C,0x34,0xC0,0xC0,0x34,0x0C,0x04,0x10,0x18,0x16,0x01,0x01,0x16,0x18,0x10},/*"X",23*/
    {0x04,0x1C,0x64,0x80,0x64,0x1C,0x04,0x00,0x00,0x00,0x10,0x1F,0x10,0x00,0x00,0x00},/*"Y",24*/
    {0x08,0x04,0x04,0x84,0x64,0x1C,0x04,0x00,0x10,0x1C,0x13,0x10,0x10,0x10,0x0C,0x00},/*"Z",25*/ //35
    
    {0x00,0x80,0x40,0x40,0x40,0x80,0x00,0x00,0x00,0x0C,0x12,0x12,0x09,0x1F,0x10,0x00},/*"a",0*/ //36
    {0x08,0xF8,0x80,0x40,0x40,0x80,0x00,0x00,0x00,0x1F,0x08,0x10,0x10,0x08,0x07,0x00},/*"b",1*/
    {0x00,0x00,0x80,0x40,0x40,0x40,0x80,0x00,0x00,0x07,0x08,0x10,0x10,0x10,0x08,0x00},/*"c",2*/
    {0x00,0x80,0x40,0x40,0x40,0x48,0xF8,0x00,0x00,0x0F,0x10,0x10,0x10,0x08,0x1F,0x10},/*"d",3*/
    {0x00,0x80,0x40,0x40,0x40,0x40,0x80,0x00,0x00,0x0F,0x12,0x12,0x12,0x12,0x0B,0x00},/*"e",4*/
    {0x00,0x40,0x40,0xF0,0x48,0x48,0x10,0x00,0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},/*"f",5*/
    {0x00,0x80,0x40,0x40,0x40,0xC0,0x40,0x00,0x00,0x35,0x4A,0x4A,0x4A,0x49,0x30,0x00},/*"g",6*/
    {0x08,0xF8,0x80,0x40,0x40,0x40,0x80,0x00,0x10,0x1F,0x10,0x00,0x00,0x10,0x1F,0x10},/*"h",7*/
    {0x00,0x40,0x4C,0xCC,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},/*"i",8*/
    {0x00,0x00,0x00,0x40,0x4C,0xCC,0x00,0x00,0x00,0x60,0x40,0x40,0x40,0x3F,0x00,0x00},/*"j",9*/
    {0x08,0xF8,0x00,0x00,0xC0,0x40,0x40,0x00,0x10,0x1F,0x12,0x03,0x14,0x18,0x10,0x00},/*"k",10*/
    {0x00,0x08,0x08,0xFC,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},/*"l",11*/
    {0x40,0xC0,0x40,0x40,0xC0,0x40,0x40,0x80,0x10,0x1F,0x10,0x00,0x1F,0x10,0x00,0x1F},/*"m",12*/
    {0x40,0xC0,0x80,0x40,0x40,0x40,0x80,0x00,0x10,0x1F,0x10,0x00,0x00,0x10,0x1F,0x10},/*"n",13*/
    {0x00,0x80,0x40,0x40,0x40,0x40,0x80,0x00,0x00,0x0F,0x10,0x10,0x10,0x10,0x0F,0x00},/*"o",14*/
    {0x40,0xC0,0x80,0x40,0x40,0x80,0x00,0x00,0x40,0x7F,0x48,0x10,0x10,0x08,0x07,0x00},/*"p",15*/
    {0x00,0x00,0x80,0x40,0x40,0x80,0xC0,0x00,0x00,0x07,0x08,0x10,0x10,0x48,0x7F,0x40},/*"q",16*/
    {0x40,0x40,0xC0,0x80,0x40,0x40,0xC0,0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00,0x00},/*"r",17*/
    {0x00,0x80,0x40,0x40,0x40,0x40,0xC0,0x00,0x00,0x19,0x12,0x12,0x12,0x12,0x0C,0x00},/*"s",18*/
    {0x00,0x40,0x40,0xF0,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x0F,0x10,0x10,0x08,0x00},/*"t",19*/
    {0x40,0xC0,0x00,0x00,0x00,0x40,0xC0,0x00,0x00,0x0F,0x10,0x10,0x10,0x08,0x1F,0x10},/*"u",20*/
    {0x40,0xC0,0x40,0x00,0x40,0xC0,0x40,0x00,0x00,0x01,0x06,0x18,0x06,0x01,0x00,0x00},/*"v",21*/
    {0xC0,0x40,0x00,0x40,0xC0,0x00,0x40,0xC0,0x00,0x07,0x18,0x06,0x03,0x1C,0x03,0x00},/*"w",22*/
    {0x00,0x40,0xC0,0x40,0x00,0xC0,0x40,0x00,0x00,0x10,0x18,0x07,0x17,0x18,0x10,0x00},/*"x",23*/
    {0x40,0xC0,0x40,0x00,0x00,0x40,0xC0,0x40,0x00,0x40,0x43,0x3C,0x0C,0x03,0x00,0x00},/*"y",24*/
    {0x00,0xC0,0x40,0x40,0x40,0xC0,0x40,0x00,0x00,0x10,0x18,0x16,0x11,0x10,0x18,0x00},/*"z",25*/ //61

    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00},/* "." ,1*/ //62
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*空格 ,5*/ //63

};


const unsigned char word_16_8[][16] = {
    {0x00,0x00,0xE0,0x1C,0x70,0x80,0x00,0x00,0x10,0x1E,0x11,0x01,0x01,0x13,0x1C,0x10},/*"A",0*/
    {0x04,0xFC,0x44,0x44,0x44,0xB8,0x00,0x00,0x10,0x1F,0x10,0x10,0x10,0x08,0x07,0x00},/*"B",1*/
    {0xE0,0x18,0x04,0x04,0x04,0x04,0x1C,0x00,0x03,0x0C,0x10,0x10,0x10,0x08,0x04,0x00},/*"C",2*/
    {0x04,0xFC,0x04,0x04,0x04,0x08,0xF0,0x00,0x10,0x1F,0x10,0x10,0x10,0x08,0x07,0x00},/*"D",3*/
    {0x04,0xFC,0x44,0x44,0xF4,0x04,0x08,0x00,0x10,0x1F,0x10,0x10,0x11,0x10,0x0C,0x00},/*"E",4*/
    {0x04,0xFC,0x44,0x44,0xF4,0x04,0x08,0x00,0x10,0x1F,0x10,0x00,0x01,0x00,0x00,0x00},/*"F",5*/
    {0xE0,0x18,0x04,0x04,0x04,0x1C,0x00,0x00,0x03,0x0C,0x10,0x10,0x11,0x0F,0x01,0x00},/*"G",6*/
    {0x04,0xFC,0x84,0x80,0x80,0x84,0xFC,0x04,0x10,0x1F,0x10,0x00,0x00,0x10,0x1F,0x10},/*"H",7*/
    {0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00,0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},/*"I",8*/
    {0x00,0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x60,0x40,0x40,0x40,0x3F,0x00,0x00,0x00},/*"J",9*/
    {0x04,0xFC,0x44,0xE0,0x14,0x0C,0x04,0x00,0x10,0x1F,0x10,0x00,0x13,0x1C,0x10,0x00},/*"K",10*/
    {0x04,0xFC,0x04,0x00,0x00,0x00,0x00,0x00,0x10,0x1F,0x10,0x10,0x10,0x10,0x18,0x00},/*"L",11*/
    {0x04,0xFC,0xFC,0x00,0xFC,0xFC,0x04,0x00,0x10,0x1F,0x00,0x1F,0x00,0x1F,0x10,0x00},/*"M",12*/
    {0x04,0xFC,0x18,0x60,0x80,0x04,0xFC,0x04,0x10,0x1F,0x10,0x00,0x03,0x0C,0x1F,0x00},/*"N",13*/
    {0xF0,0x08,0x04,0x04,0x04,0x08,0xF0,0x00,0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00},/*"O",14*/
    {0x04,0xFC,0x84,0x84,0x84,0x84,0x78,0x00,0x10,0x1F,0x10,0x00,0x00,0x00,0x00,0x00},/*"P",15*/
    {0xF0,0x08,0x04,0x04,0x04,0x08,0xF0,0x00,0x07,0x08,0x14,0x14,0x18,0x28,0x27,0x00},/*"Q",16*/
    {0x04,0xFC,0x44,0x44,0xC4,0x44,0x38,0x00,0x10,0x1F,0x10,0x00,0x01,0x06,0x18,0x10},/*"R",17*/
    {0x00,0x38,0x44,0x84,0x84,0x04,0x1C,0x00,0x00,0x1C,0x10,0x10,0x10,0x11,0x0E,0x00},/*"S",18*/
    {0x0C,0x04,0x04,0xFC,0x04,0x04,0x0C,0x00,0x00,0x00,0x10,0x1F,0x10,0x00,0x00,0x00},/*"T",19*/
    {0x04,0xFC,0x04,0x00,0x00,0x04,0xFC,0x04,0x00,0x0F,0x10,0x10,0x10,0x10,0x0F,0x00},/*"U",20*/
    {0x04,0x3C,0xC4,0x00,0x00,0xE4,0x1C,0x04,0x00,0x00,0x03,0x1C,0x07,0x00,0x00,0x00},/*"V",21*/
    {0x04,0xFC,0x00,0xFC,0x00,0xFC,0x04,0x00,0x00,0x01,0x1F,0x00,0x1F,0x01,0x00,0x00},/*"W",22*/
    {0x04,0x0C,0x34,0xC0,0xC0,0x34,0x0C,0x04,0x10,0x18,0x16,0x01,0x01,0x16,0x18,0x10},/*"X",23*/
    {0x04,0x1C,0x64,0x80,0x64,0x1C,0x04,0x00,0x00,0x00,0x10,0x1F,0x10,0x00,0x00,0x00},/*"Y",24*/
    {0x08,0x04,0x04,0x84,0x64,0x1C,0x04,0x00,0x10,0x1C,0x13,0x10,0x10,0x10,0x0C,0x00},/*"Z",25*/
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,}/* 空格 26 */
};
#endif



//阴码, 1为点亮。一个字的字模是16*8位,取模方式是列行式。 char_list_normal
const unsigned char char_list_normal[][8] = 
{
    {0x00,0xF0,0x08,0x04,0x04,0x08,0xF0,0x00},{0x00,0x07,0x08,0x10,0x10,0x08,0x07,0x00},/*"0",0*/
    {0x00,0x00,0x08,0x08,0xFC,0x00,0x00,0x00},{0x00,0x00,0x10,0x10,0x1F,0x10,0x10,0x00},/*"1",1*/
    {0x00,0x38,0x04,0x04,0x04,0x84,0x78,0x00},{0x00,0x18,0x14,0x12,0x11,0x10,0x18,0x00},/*"2",2*/
    {0x00,0x18,0x04,0x84,0x84,0x44,0x38,0x00},{0x00,0x0C,0x10,0x10,0x10,0x11,0x0E,0x00},/*"3",3*/
    {0x00,0x00,0xC0,0x20,0x18,0xFC,0x00,0x00},{0x00,0x03,0x02,0x12,0x12,0x1F,0x12,0x12},/*"4",4*/
    {0x00,0xFC,0x44,0x44,0x44,0x84,0x04,0x00},{0x00,0x0C,0x10,0x10,0x10,0x08,0x07,0x00},/*"5",5*/
    {0x00,0xF0,0x88,0x44,0x44,0x48,0x80,0x00},{0x00,0x07,0x08,0x10,0x10,0x10,0x0F,0x00},/*"6",6*/
    {0x00,0x0C,0x04,0x04,0xC4,0x34,0x0C,0x00},{0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00},/*"7",7*/
    {0x00,0x38,0x44,0x84,0x84,0x44,0x38,0x00},{0x00,0x0E,0x11,0x10,0x10,0x11,0x0E,0x00},/*"8",8*/
    {0x00,0xF8,0x04,0x04,0x04,0x88,0xF0,0x00},{0x00,0x00,0x09,0x11,0x11,0x08,0x07,0x00},/*"9",9*/
    
    {0x00,0x00,0xE0,0x1C,0x70,0x80,0x00,0x00},{0x10,0x1E,0x11,0x01,0x01,0x13,0x1C,0x10},/*"A",0*/ //10 *2
    {0x04,0xFC,0x44,0x44,0x44,0xB8,0x00,0x00},{0x10,0x1F,0x10,0x10,0x10,0x08,0x07,0x00},/*"B",1*/
    {0xE0,0x18,0x04,0x04,0x04,0x04,0x1C,0x00},{0x03,0x0C,0x10,0x10,0x10,0x08,0x04,0x00},/*"C",2*/
    {0x04,0xFC,0x04,0x04,0x04,0x08,0xF0,0x00},{0x10,0x1F,0x10,0x10,0x10,0x08,0x07,0x00},/*"D",3*/
    {0x04,0xFC,0x44,0x44,0xF4,0x04,0x08,0x00},{0x10,0x1F,0x10,0x10,0x11,0x10,0x0C,0x00},/*"E",4*/
    {0x04,0xFC,0x44,0x44,0xF4,0x04,0x08,0x00},{0x10,0x1F,0x10,0x00,0x01,0x00,0x00,0x00},/*"F",5*/
    {0xE0,0x18,0x04,0x04,0x04,0x1C,0x00,0x00},{0x03,0x0C,0x10,0x10,0x11,0x0F,0x01,0x00},/*"G",6*/
    {0x04,0xFC,0x84,0x80,0x80,0x84,0xFC,0x04},{0x10,0x1F,0x10,0x00,0x00,0x10,0x1F,0x10},/*"H",7*/
    {0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00},{0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},/*"I",8*/
    {0xFF,0xFF,0xFB,0xFB,0x03,0xFB,0xFB,0xFF},{0x9F,0xBF,0xBF,0xBF,0xC0,0xFF,0xFF,0xFF},/*"J",9*/
    {0x04,0xFC,0x44,0xE0,0x14,0x0C,0x04,0x00},{0x10,0x1F,0x10,0x00,0x13,0x1C,0x10,0x00},/*"K",10*/
    {0x04,0xFC,0x04,0x00,0x00,0x00,0x00,0x00},{0x10,0x1F,0x10,0x10,0x10,0x10,0x18,0x00},/*"L",11*/
    {0x04,0xFC,0xFC,0x00,0xFC,0xFC,0x04,0x00},{0x10,0x1F,0x00,0x1F,0x00,0x1F,0x10,0x00},/*"M",12*/
    {0x04,0xFC,0x18,0x60,0x80,0x04,0xFC,0x04},{0x10,0x1F,0x10,0x00,0x03,0x0C,0x1F,0x00},/*"N",13*/
    {0xF0,0x08,0x04,0x04,0x04,0x08,0xF0,0x00},{0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00},/*"O",14*/
    {0x04,0xFC,0x84,0x84,0x84,0x84,0x78,0x00},{0x10,0x1F,0x10,0x00,0x00,0x00,0x00,0x00},/*"P",15*/
    {0xF0,0x08,0x04,0x04,0x04,0x08,0xF0,0x00},{0x07,0x08,0x14,0x14,0x18,0x28,0x27,0x00},/*"Q",16*/
    {0x04,0xFC,0x44,0x44,0xC4,0x44,0x38,0x00},{0x10,0x1F,0x10,0x00,0x01,0x06,0x18,0x10},/*"R",17*/
    {0x00,0x38,0x44,0x84,0x84,0x04,0x1C,0x00},{0x00,0x1C,0x10,0x10,0x10,0x11,0x0E,0x00},/*"S",18*/
    {0x0C,0x04,0x04,0xFC,0x04,0x04,0x0C,0x00},{0x00,0x00,0x10,0x1F,0x10,0x00,0x00,0x00},/*"T",19*/
    {0x04,0xFC,0x04,0x00,0x00,0x04,0xFC,0x04},{0x00,0x0F,0x10,0x10,0x10,0x10,0x0F,0x00},/*"U",20*/
    {0x04,0x3C,0xC4,0x00,0x00,0xE4,0x1C,0x04},{0x00,0x00,0x03,0x1C,0x07,0x00,0x00,0x00},/*"V",21*/
    {0x04,0xFC,0x00,0xFC,0x00,0xFC,0x04,0x00},{0x00,0x01,0x1F,0x00,0x1F,0x01,0x00,0x00},/*"W",22*/
    {0x04,0x0C,0x34,0xC0,0xC0,0x34,0x0C,0x04},{0x10,0x18,0x16,0x01,0x01,0x16,0x18,0x10},/*"X",23*/
    {0x04,0x1C,0x64,0x80,0x64,0x1C,0x04,0x00},{0x00,0x00,0x10,0x1F,0x10,0x00,0x00,0x00},/*"Y",24*/
    {0x08,0x04,0x04,0x84,0x64,0x1C,0x04,0x00},{0x10,0x1C,0x13,0x10,0x10,0x10,0x0C,0x00},/*"Z",25*/ //35
    
    {0x00,0x80,0x40,0x40,0x40,0x80,0x00,0x00},{0x00,0x0C,0x12,0x12,0x09,0x1F,0x10,0x00},/*"a",0*/ //36 *2
    {0x08,0xF8,0x80,0x40,0x40,0x80,0x00,0x00},{0x00,0x1F,0x08,0x10,0x10,0x08,0x07,0x00},/*"b",1*/
    {0x00,0x00,0x80,0x40,0x40,0x40,0x80,0x00},{0x00,0x07,0x08,0x10,0x10,0x10,0x08,0x00},/*"c",2*/
    {0x00,0x80,0x40,0x40,0x40,0x48,0xF8,0x00},{0x00,0x0F,0x10,0x10,0x10,0x08,0x1F,0x10},/*"d",3*/
    {0x00,0x80,0x40,0x40,0x40,0x40,0x80,0x00},{0x00,0x0F,0x12,0x12,0x12,0x12,0x0B,0x00},/*"e",4*/
    {0x00,0x40,0x40,0xF0,0x48,0x48,0x10,0x00},{0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},/*"f",5*/
    {0x00,0x80,0x40,0x40,0x40,0xC0,0x40,0x00},{0x00,0x35,0x4A,0x4A,0x4A,0x49,0x30,0x00},/*"g",6*/
    {0x08,0xF8,0x80,0x40,0x40,0x40,0x80,0x00},{0x10,0x1F,0x10,0x00,0x00,0x10,0x1F,0x10},/*"h",7*/
    {0x00,0x40,0x4C,0xCC,0x00,0x00,0x00,0x00},{0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},/*"i",8*/
    {0x00,0x00,0x00,0x40,0x4C,0xCC,0x00,0x00},{0x00,0x60,0x40,0x40,0x40,0x3F,0x00,0x00},/*"j",9*/
    {0x08,0xF8,0x00,0x00,0xC0,0x40,0x40,0x00},{0x10,0x1F,0x12,0x03,0x14,0x18,0x10,0x00},/*"k",10*/
    {0x00,0x08,0x08,0xFC,0x00,0x00,0x00,0x00},{0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},/*"l",11*/
    {0x40,0xC0,0x40,0x40,0xC0,0x40,0x40,0x80},{0x10,0x1F,0x10,0x00,0x1F,0x10,0x00,0x1F},/*"m",12*/
    {0x40,0xC0,0x80,0x40,0x40,0x40,0x80,0x00},{0x10,0x1F,0x10,0x00,0x00,0x10,0x1F,0x10},/*"n",13*/
    {0x00,0x80,0x40,0x40,0x40,0x40,0x80,0x00},{0x00,0x0F,0x10,0x10,0x10,0x10,0x0F,0x00},/*"o",14*/
    {0x40,0xC0,0x80,0x40,0x40,0x80,0x00,0x00},{0x40,0x7F,0x48,0x10,0x10,0x08,0x07,0x00},/*"p",15*/
    {0x00,0x00,0x80,0x40,0x40,0x80,0xC0,0x00},{0x00,0x07,0x08,0x10,0x10,0x48,0x7F,0x40},/*"q",16*/
    {0x40,0x40,0xC0,0x80,0x40,0x40,0xC0,0x00},{0x10,0x10,0x1F,0x10,0x10,0x00,0x00,0x00},/*"r",17*/
    {0x00,0x80,0x40,0x40,0x40,0x40,0xC0,0x00},{0x00,0x19,0x12,0x12,0x12,0x12,0x0C,0x00},/*"s",18*/
    {0x00,0x40,0x40,0xF0,0x40,0x40,0x00,0x00},{0x00,0x00,0x00,0x0F,0x10,0x10,0x08,0x00},/*"t",19*/
    {0x40,0xC0,0x00,0x00,0x00,0x40,0xC0,0x00},{0x00,0x0F,0x10,0x10,0x10,0x08,0x1F,0x10},/*"u",20*/
    {0x40,0xC0,0x40,0x00,0x40,0xC0,0x40,0x00},{0x00,0x01,0x06,0x18,0x06,0x01,0x00,0x00},/*"v",21*/
    {0xC0,0x40,0x00,0x40,0xC0,0x00,0x40,0xC0},{0x00,0x07,0x18,0x06,0x03,0x1C,0x03,0x00},/*"w",22*/
    {0x00,0x40,0xC0,0x40,0x00,0xC0,0x40,0x00},{0x00,0x10,0x18,0x07,0x17,0x18,0x10,0x00},/*"x",23*/
    {0x40,0xC0,0x40,0x00,0x00,0x40,0xC0,0x40},{0x00,0x40,0x43,0x3C,0x0C,0x03,0x00,0x00},/*"y",24*/
    {0x00,0xC0,0x40,0x40,0x40,0xC0,0x40,0x00},{0x00,0x10,0x18,0x16,0x11,0x10,0x18,0x00},/*"z",25*/ //61
    
    {0x40,0x40,0x80,0xF0,0x80,0x40,0x40,0x00},{0x02,0x02,0x01,0x0F,0x01,0x02,0x02,0x00},/* "*" ,0*/ //62*2
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},{0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00},/* "." ,1*/ //63
    {0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0x00},{0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x00},/* "[" ,2*/ //64
    {0x00,0x02,0x02,0x02,0xFE,0x00,0x00,0x00},{0x00,0x40,0x40,0x40,0x7F,0x00,0x00,0x00},/* "]" ,3*/ //65
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},{0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80},/* "_" ,4*/ //66
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},{0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40},/*"-"  ,5*/ //67
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*空格 ,6*/ //68
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},{0x00,0x90,0x70,0x00,0x00,0x00,0x00,0x00},/*","*/     //69
    {0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00},{0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00},/*":"*/    //70
    
};

//阳码, 0为点亮。取模方式是列行式
const unsigned char char_list_inversion[][8] =
{
    {0xFF,0x0F,0xF7,0xFB,0xFB,0xF7,0x0F,0xFF},{0xFF,0xF8,0xF7,0xEF,0xEF,0xF7,0xF8,0xFF},/*"0",0*/
    {0xFF,0xFF,0xF7,0xF7,0x03,0xFF,0xFF,0xFF},{0xFF,0xFF,0xEF,0xEF,0xE0,0xEF,0xEF,0xFF},/*"1",1*/
    {0xFF,0xC7,0xFB,0xFB,0xFB,0x7B,0x87,0xFF},{0xFF,0xE7,0xEB,0xED,0xEE,0xEF,0xE7,0xFF},/*"2",2*/
    {0xFF,0xE7,0xFB,0x7B,0x7B,0xBB,0xC7,0xFF},{0xFF,0xF3,0xEF,0xEF,0xEF,0xEE,0xF1,0xFF},/*"3",3*/
    {0xFF,0xFF,0x3F,0xDF,0xE7,0x03,0xFF,0xFF},{0xFF,0xFC,0xFD,0xED,0xED,0xE0,0xED,0xED},/*"4",4*/
    {0xFF,0x03,0xBB,0xBB,0xBB,0x7B,0xFB,0xFF},{0xFF,0xF3,0xEF,0xEF,0xEF,0xF7,0xF8,0xFF},/*"5",5*/
    {0xFF,0x0F,0x77,0xBB,0xBB,0xB7,0x7F,0xFF},{0xFF,0xF8,0xF7,0xEF,0xEF,0xEF,0xF0,0xFF},/*"6",6*/
    {0xFF,0xF3,0xFB,0xFB,0x3B,0xCB,0xF3,0xFF},{0xFF,0xFF,0xFF,0xE0,0xFF,0xFF,0xFF,0xFF},/*"7",7*/
    {0xFF,0xC7,0xBB,0x7B,0x7B,0xBB,0xC7,0xFF},{0xFF,0xF1,0xEE,0xEF,0xEF,0xEE,0xF1,0xFF},/*"8",8*/
    {0xFF,0x07,0xFB,0xFB,0xFB,0x77,0x0F,0xFF},{0xFF,0xFF,0xF6,0xEE,0xEE,0xF7,0xF8,0xFF},/*"9",9*/

    {0xFF,0xFF,0x1F,0xE3,0x8F,0x7F,0xFF,0xFF},{0xEF,0xE1,0xEE,0xFE,0xFE,0xEC,0xE3,0xEF},/*"A",0*/
    {0xFB,0x03,0xBB,0xBB,0xBB,0x47,0xFF,0xFF},{0xEF,0xE0,0xEF,0xEF,0xEF,0xF7,0xF8,0xFF},/*"B",1*/
    {0x1F,0xE7,0xFB,0xFB,0xFB,0xFB,0xE3,0xFF},{0xFC,0xF3,0xEF,0xEF,0xEF,0xF7,0xFB,0xFF},/*"C",2*/
    {0xFB,0x03,0xFB,0xFB,0xFB,0xF7,0x0F,0xFF},{0xEF,0xE0,0xEF,0xEF,0xEF,0xF7,0xF8,0xFF},/*"D",3*/
    {0xFB,0x03,0xBB,0xBB,0x0B,0xFB,0xF7,0xFF},{0xEF,0xE0,0xEF,0xEF,0xEE,0xEF,0xF3,0xFF},/*"E",4*/
    {0xFB,0x03,0xBB,0xBB,0x0B,0xFB,0xF7,0xFF},{0xEF,0xE0,0xEF,0xFF,0xFE,0xFF,0xFF,0xFF},/*"F",5*/
    {0x1F,0xE7,0xFB,0xFB,0xFB,0xE3,0xFF,0xFF},{0xFC,0xF3,0xEF,0xEF,0xEE,0xF0,0xFE,0xFF},/*"G",6*/
    {0xFB,0x03,0x7B,0x7F,0x7F,0x7B,0x03,0xFB},{0xEF,0xE0,0xEF,0xFF,0xFF,0xEF,0xE0,0xEF},/*"H",7*/
    {0xFF,0xFB,0xFB,0x03,0xFB,0xFB,0xFF,0xFF},{0xFF,0xEF,0xEF,0xE0,0xEF,0xEF,0xFF,0xFF},/*"I",8*/
    {0xFF,0xFF,0xFB,0xFB,0x03,0xFB,0xFB,0xFF},{0x9F,0xBF,0xBF,0xBF,0xC0,0xFF,0xFF,0xFF},/*"J",9*/
    {0xFB,0x03,0xBB,0x1F,0xEB,0xF3,0xFB,0xFF},{0xEF,0xE0,0xEF,0xFF,0xEC,0xE3,0xEF,0xFF},/*"K",10*/
    {0xF7,0x07,0xF7,0xFF,0xFF,0xFF,0xFF,0xFF},{0xDF,0xC0,0xDF,0xDF,0xDF,0xDF,0xCF,0xFF},/*"L",11*/
    {0xF7,0x07,0x07,0xFF,0x07,0x07,0xF7,0xFF},{0xDF,0xC0,0xFE,0xC1,0xFE,0xC0,0xDF,0xFF},/*"M",12*/
    {0xF7,0x07,0xCF,0x3F,0xFF,0xF7,0x07,0xF7},{0xDF,0xC0,0xDF,0xFF,0xF8,0xE7,0xC0,0xFF},/*"N",13*/
    {0x1F,0xEF,0xF7,0xF7,0xF7,0xEF,0x1F,0xFF},{0xF0,0xEF,0xDF,0xDF,0xDF,0xEF,0xF0,0xFF},/*"O",14*/
    {0xF7,0x07,0xF7,0xF7,0xF7,0xF7,0x0F,0xFF},{0xDF,0xC0,0xDE,0xFE,0xFE,0xFE,0xFF,0xFF},/*"P",15*/
    {0x1F,0xEF,0xF7,0xF7,0xF7,0xEF,0x1F,0xFF},{0xF0,0xEF,0xD7,0xD7,0xCF,0xAF,0xB0,0xFF},/*"Q",16*/
    {0xF7,0x07,0x77,0x77,0x77,0x77,0x8F,0xFF},{0xDF,0xC0,0xDF,0xFF,0xFC,0xF3,0xCF,0xDF},/*"R",17*/
    {0xFF,0x8F,0x77,0xF7,0xF7,0xF7,0xC7,0xFF},{0xFF,0xC7,0xDF,0xDE,0xDE,0xDD,0xE3,0xFF},/*"S",18*/
    {0xE7,0xF7,0xF7,0x07,0xF7,0xF7,0xE7,0xFF},{0xFF,0xFF,0xDF,0xC0,0xDF,0xFF,0xFF,0xFF},/*"T",19*/
    {0xF7,0x07,0xF7,0xFF,0xFF,0xF7,0x07,0xF7},{0xFF,0xE0,0xDF,0xDF,0xDF,0xDF,0xE0,0xFF},/*"U",20*/
    {0xF7,0x87,0x77,0xFF,0xFF,0x37,0xC7,0xF7},{0xFF,0xFF,0xF8,0xC7,0xF1,0xFE,0xFF,0xFF},/*"V",21*/
    {0xF7,0x07,0xFF,0x07,0xFF,0x07,0xF7,0xFF},{0xFF,0xFC,0xC1,0xFE,0xC1,0xFC,0xFF,0xFF},/*"W",22*/
    {0xF7,0xE7,0x97,0x7F,0x7F,0x97,0xE7,0xF7},{0xDF,0xCF,0xD3,0xFC,0xFC,0xD3,0xCF,0xDF},/*"X",23*/
    {0xF7,0xC7,0x37,0xFF,0x37,0xC7,0xF7,0xFF},{0xFF,0xFF,0xDF,0xC0,0xDF,0xFF,0xFF,0xFF},/*"Y",24*/
    {0xEF,0xF7,0xF7,0xF7,0x37,0xC7,0xF7,0xFF},{0xDF,0xC7,0xD9,0xDE,0xDF,0xDF,0xE7,0xFF},/*"Z",25*/

    {0xFF,0xBF,0xDF,0xDF,0x5F,0x3F,0xFF,0xFF},{0xFF,0xF9,0xF6,0xF6,0xFB,0xF0,0xF7,0xFF},/*"a",0*/
    {0xFB,0x03,0xBF,0xDF,0xDF,0xBF,0x7F,0xFF},{0xFF,0xF0,0xFB,0xF7,0xF7,0xFB,0xFC,0xFF},/*"b",1*/
    {0xFF,0x7F,0xBF,0xDF,0xDF,0xDF,0xBF,0xFF},{0xFF,0xFC,0xFB,0xF7,0xF7,0xF7,0xFB,0xFF},/*"c",2*/
    {0xFF,0x3F,0xDF,0xDF,0xDF,0xDB,0x03,0xFF},{0xFF,0xF8,0xF7,0xF7,0xF7,0xFB,0xF0,0xF7},/*"d",3*/
    {0xFF,0x3F,0xDF,0xDF,0xDF,0xDF,0x3F,0xFF},{0xFF,0xF8,0xF6,0xF6,0xF6,0xF6,0xFA,0xFF},/*"e",4*/
    {0xFF,0xDF,0xDF,0x07,0xDB,0xDB,0xF7,0xFF},{0xFF,0xF7,0xF7,0xF0,0xF7,0xF7,0xFF,0xFF},/*"f",5*/
    {0xFF,0x3F,0xDF,0xDF,0xDF,0x1F,0xDF,0xFF},{0xFF,0xE5,0xDA,0xDA,0xDA,0xDB,0xE7,0xFF},/*"g",6*/
    {0xFB,0x03,0xBF,0xDF,0xDF,0xDF,0x3F,0xFF},{0xF7,0xF0,0xF7,0xFF,0xFF,0xF7,0xF0,0xF7},/*"h",7*/
    {0xFF,0xDF,0xD9,0x19,0xFF,0xFF,0xFF,0xFF},{0xFF,0xF7,0xF7,0xF0,0xF7,0xF7,0xFF,0xFF},/*"i",8*/
    {0xFF,0xFF,0xFF,0xDF,0xD9,0x19,0xFF,0xFF},{0xFF,0xCF,0xDF,0xDF,0xDF,0xE0,0xFF,0xFF},/*"j",9*/
    {0xFB,0x03,0xFF,0x7F,0x9F,0xDF,0xDF,0xFF},{0xF7,0xF0,0xF6,0xFE,0xF5,0xF3,0xF7,0xFF},/*"k",10*/
    {0xFF,0xF7,0xF7,0x03,0xFF,0xFF,0xFF,0xFF},{0xFF,0xEF,0xEF,0xE0,0xEF,0xEF,0xFF,0xFF},/*"l",11*/
    {0xBF,0x3F,0xBF,0xBF,0x3F,0xBF,0xBF,0x7F},{0xEF,0xE0,0xEF,0xFF,0xE0,0xEF,0xFF,0xE0},/*"m",12*/
    {0xBF,0x3F,0x7F,0xBF,0xBF,0xBF,0x7F,0xFF},{0xEF,0xE0,0xEF,0xFF,0xFF,0xEF,0xE0,0xEF},/*"n",13*/
    {0xFF,0x7F,0xBF,0xBF,0xBF,0xBF,0x7F,0xFF},{0xFF,0xF0,0xEF,0xEF,0xEF,0xEF,0xF0,0xFF},/*"o",14*/
    {0xBF,0x3F,0x7F,0xBF,0xBF,0x7F,0xFF,0xFF},{0xBF,0x80,0xB7,0xEF,0xEF,0xF7,0xF8,0xFF},/*"p",15*/
    {0xFF,0xFF,0x7F,0xBF,0xBF,0x7F,0x3F,0xFF},{0xFF,0xF8,0xF7,0xEF,0xEF,0xB7,0x80,0xBF},/*"q",16*/
    {0xBF,0xBF,0x3F,0x7F,0xBF,0xBF,0x3F,0xFF},{0xEF,0xEF,0xE0,0xEF,0xEF,0xFF,0xFF,0xFF},/*"r",17*/
    {0xFF,0x7F,0xBF,0xBF,0xBF,0xBF,0x3F,0xFF},{0xFF,0xE6,0xED,0xED,0xED,0xED,0xF3,0xFF},/*"s",18*/
    {0xFF,0xBF,0xBF,0x0F,0xBF,0xBF,0xFF,0xFF},{0xFF,0xFF,0xFF,0xF0,0xEF,0xEF,0xF7,0xFF},/*"t",19*/
    {0xBF,0x3F,0xFF,0xFF,0xFF,0xBF,0x3F,0xFF},{0xFF,0xF0,0xEF,0xEF,0xEF,0xF7,0xE0,0xEF},/*"u",20*/
    {0xBF,0x3F,0xBF,0xFF,0xBF,0x3F,0xBF,0xFF},{0xFF,0xFE,0xF9,0xE7,0xF9,0xFE,0xFF,0xFF},/*"v",21*/
    {0x3F,0xBF,0xFF,0xBF,0x3F,0xFF,0xBF,0x3F},{0xFF,0xF8,0xE7,0xF9,0xFC,0xE3,0xFC,0xFF},/*"w",22*/
    {0xFF,0xBF,0x3F,0xBF,0xFF,0x3F,0xBF,0xFF},{0xFF,0xEF,0xE7,0xF8,0xE8,0xE7,0xEF,0xFF},/*"x",23*/
    {0xBF,0x3F,0xBF,0xFF,0xFF,0xBF,0x3F,0xBF},{0xFF,0xBF,0xBC,0xC3,0xF3,0xFC,0xFF,0xFF},/*"y",24*/
    {0xFF,0x3F,0xBF,0xBF,0xBF,0x3F,0xBF,0xFF},{0xFF,0xEF,0xE7,0xE9,0xEE,0xEF,0xE7,0xFF},/*"z",25*/

    {0xDF,0xDF,0x3F,0x07,0x3F,0xDF,0xDF,0xFF},{0xFE,0xFE,0xFF,0xF8,0xFF,0xFE,0xFE,0xFF},/*"*",0*/
    {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},{0xFF,0xE7,0xE7,0xFF,0xFF,0xFF,0xFF,0xFF},/*".",1*/
    {0xFF,0xFF,0xFF,0x00,0xFE,0xFE,0xFE,0xFF},{0xFF,0xFF,0xFF,0xC0,0xDF,0xDF,0xDF,0xFF},/*"[",2*/
    {0xFF,0xFE,0xFE,0xFE,0x00,0xFF,0xFF,0xFF},{0xFF,0xDF,0xDF,0xDF,0xC0,0xFF,0xFF,0xFF},/*"]",3*/
    {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},{0xBF,0xBF,0xBF,0xBF,0xBF,0xBF,0xBF,0xBF},/*"_",4*/
    {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},/*"空格",5*/
    {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},{0xFF,0xB7,0xC7,0xFF,0xFF,0xFF,0xFF,0xFF},/*",",6*/
    {0xFF,0xFF,0xFF,0x9F,0x9F,0xFF,0xFF,0xFF},{0xFF,0xFF,0xFF,0xE7,0xE7,0xFF,0xFF,0xFF},/*":",7*/
    
};
    
#endif

