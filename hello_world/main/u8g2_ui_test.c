#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "u8g2_ui_test.h"

//进度条显示
void DrawProcess(u8g2_t *u8g2)
{
	for(int i=10;i<=80;i=i+2)
	{
		u8g2_ClearBuffer(u8g2); 
	    char buff[20];
		sprintf(buff,"%d%%",(int)(i/80.0*100));
		u8g2_SetFont(u8g2,u8g2_font_ncenB18_tf);
		u8g2_DrawStr(u8g2,32,32,"u8g2");//字符显示
		u8g2_SetFont(u8g2,u8g2_font_ncenB08_tf);
		u8g2_DrawStr(u8g2,100,49,buff);//当前进度显示
		u8g2_DrawRBox(u8g2,16,40,i,10,4);//圆角填充框矩形框
		u8g2_DrawRFrame(u8g2,16,40,80,10,4);//圆角矩形
		u8g2_SendBuffer(u8g2);
	}
}

//画点
void DrawPoint(u8g2_t *u8g2)
{
	uint8_t i=0,j=0;
	
	u8g2_ClearBuffer(u8g2); 
	for(j=0;j<64;j=j+8,i=0)
	{
		for(i=0;i<128;i=i+8)
		{
			u8g2_DrawPixel(u8g2,i,j);   			
			u8g2_SendBuffer(u8g2);
		}
	}//8*16  8*8
}

//线条测试
void DrawLine(u8g2_t *u8g2)
{
	u8g2_ClearBuffer(u8g2); 
	for(int i=0;i<20;i++)
	{
		u8g2_DrawLine(u8g2,0,0,i*10,63);
		u8g2_SendBuffer(u8g2);
	}
	
	for(int i=0;i<20;i++)
	{
		u8g2_DrawLine(u8g2,128,0,128-i*10,63);
		u8g2_SendBuffer(u8g2);
	}
}


//矩形测试
void DrawBox(u8g2_t *u8g2)
{
	u8g2_ClearBuffer(u8g2);
	for(int i=0;i<31;i+=2)
	{
		u8g2_DrawFrame(u8g2,i*2,i,128-i*4,64-2*i);
		u8g2_SendBuffer(u8g2);
	}
	
	u8g2_ClearBuffer(u8g2);
	for(int i=0;i<31;i+=2)
	{
		u8g2_DrawRFrame(u8g2,i*2,i,128-i*4,64-2*i,10-i/3);
		u8g2_SendBuffer(u8g2);
	}
}


//圆形测试
void DrawCircle(u8g2_t *u8g2)
{
	for(int i=0;i<32;i=i+2)
	{
		u8g2_ClearBuffer(u8g2); 
			   	
		u8g2_DrawCircle(u8g2,32,32,i,U8G2_DRAW_ALL);//画圆
		u8g2_DrawCircle(u8g2,64,32,i,U8G2_DRAW_ALL);
		u8g2_DrawCircle(u8g2,96,32,i,U8G2_DRAW_ALL);
		
		u8g2_SendBuffer(u8g2);
	}
}


//椭圆形测试
void DrawEllipse(u8g2_t *u8g2)
{
	for(int i=0;i<32;i=i+2)
	{
		u8g2_ClearBuffer(u8g2); 
		
		u8g2_DrawEllipse(u8g2,32,32,15+i,10,U8G2_DRAW_ALL);//画椭圆
		u8g2_DrawEllipse(u8g2,64,32,15+i,10,U8G2_DRAW_ALL);//
		u8g2_DrawEllipse(u8g2,96,32,15+i,10,U8G2_DRAW_ALL);//
		
		u8g2_DrawEllipse(u8g2,64,16,10,15+i,U8G2_DRAW_ALL);//画椭圆
		u8g2_DrawEllipse(u8g2,64,32,10,15+i,U8G2_DRAW_ALL);//
		u8g2_DrawEllipse(u8g2,64,48,10,15+i,U8G2_DRAW_ALL);//
		
		u8g2_DrawFilledEllipse(u8g2,64,32,15,10,U8G2_DRAW_ALL);//画填充椭圆
		
		u8g2_SendBuffer(u8g2);
	}
}


void DrawLogo(u8g2_t *u8g2)
{
    u8g2_SetFontMode(u8g2, 1); /*字体模式选择*/
    u8g2_SetFontDirection(u8g2, 0); /*字体方向选择*/
    u8g2_SetFont(u8g2, u8g2_font_inb24_mf); /*字库选择*/  //u8g2_font_inb24_mf
    u8g2_DrawStr(u8g2, 0, 20, "U");
    
    u8g2_SetFontDirection(u8g2, 1);
    u8g2_SetFont(u8g2, u8g2_font_inb30_mn); //u8g2_font_inb30_mn
    u8g2_DrawStr(u8g2, 21,8,"8");
        
    u8g2_SetFontDirection(u8g2, 0);
    u8g2_SetFont(u8g2, u8g2_font_inb24_mf); //u8g2_font_inb24_mf
    u8g2_DrawStr(u8g2, 51,30,"g");
    u8g2_DrawStr(u8g2, 67,30,"\xb2");
    
    u8g2_DrawHLine(u8g2, 2, 35, 47);
    u8g2_DrawHLine(u8g2, 3, 36, 47);
    u8g2_DrawVLine(u8g2, 45, 32, 12);
    u8g2_DrawVLine(u8g2, 46, 33, 12);
  
    // u8g2_SetFont(u8g2, u8g2_font_4x6_tr);  //u8g2_font_4x6_tr
    // u8g2_DrawStr(u8g2, 1,54,"github.com/olikraus/u8g2");
	
	u8g2_SendBuffer(u8g2);
}

void U8g2Test(u8g2_t *u8g2)
{
	DrawProcess(u8g2);
    vTaskDelay(1);
	DrawPoint(u8g2);
    vTaskDelay(1);
	DrawLine(u8g2);
    vTaskDelay(1);
	DrawBox(u8g2);
    vTaskDelay(1);
	DrawCircle(u8g2);
    vTaskDelay(1);
	DrawEllipse(u8g2);
    vTaskDelay(1);
}









