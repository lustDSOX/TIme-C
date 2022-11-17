#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define WM_CHAR  
#include<stdio.h>
#include<windows.h>
#include<time.h>
COORD position = { 0,0 };
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
HANDLE hConsole;
struct tm* loc_time;
int correct_H = 0;
int correct_M = 0;
HANDLE hClock;
void StopWather();
void Clock();
void Timer(int);
void Settings();