#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define WM_CHAR  
#include<stdio.h>
#include<windows.h>
#include<time.h>
COORD position = { 0,0 };
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
HANDLE hConsole;
void Clock();
void Cursor();