﻿

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <stddef.h>


#include <gdiplus.h>
#include <assert.h>

using namespace Gdiplus;

// Reference to the GDI+ static library).
#pragma comment (lib,"Gdiplus.lib")



void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void myLine(int x1, int y1, int x2, int y2,int color1,int color2,int color3,int &width) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen =CreatePen(PS_SOLID,width,RGB(color1,color2,color3)); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	ReleaseDC(console_handle, device_context);  
}
void myRect(int x1, int y1, int x2, int y2,int color1,int color2,int color3,int &width)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,width,RGB(color1,color2,color3)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(color1,color2,color3)); //Fill color is black
	SelectObject(device_context,brush);
	
	Rectangle(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context); 
}
void ymyRect(int x1, int y1, int x2, int y2,int color1,int color2,int color3,int &width)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,width,RGB(color1,color2,color3)); 
    SelectObject(device_context,pen);
	//HBRUSH brush = ::CreateSolidBrush(RGB(0,0,0)); //Fill color is black
	HGDIOBJ brush  = GetStockObject(HOLLOW_BRUSH);
	SelectObject(device_context,brush);
	
	Rectangle(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context); 
}
void myEllipse(int x1, int y1, int x2, int y2,int color1, int color2, int color3,int &width)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,width,RGB(color1,color2,color3)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(color1,color2,color3));  //Fill color is black
	//HGDIOBJ brush  = GetStockObject(HOLLOW_BRUSH);
	SelectObject(device_context,brush);
	Ellipse(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context);

}
void ymyEllipse(int x1, int y1, int x2, int y2,int color1, int color2, int color3,int &width)
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,width,RGB(color1,color2,color3)); 
    SelectObject(device_context,pen);
	//HBRUSH brush = ::CreateSolidBrush(RGB(0,0,0));  //Fill color is black
		HGDIOBJ brush  = GetStockObject(HOLLOW_BRUSH);
	SelectObject(device_context,brush);
	Ellipse(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context);

}

