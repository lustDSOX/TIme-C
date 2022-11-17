#include "Header.h"

main() {
	system("chcp 1251>nul");
	HANDLE hWather = {0};
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	hClock = CreateThread(NULL, NULL, Clock, NULL, CREATE_SUSPENDED, NULL);
	ResumeThread(hClock);
	char str[20];
	while (1)
	{
		scanf("%s", str);
		if (strstr(str, "stop")) {
			SuspendThread(hClock);
		}
		else if (strstr(str, "resume")) {
			ResumeThread(hClock);
		}
		else if (strstr(str, "timer")) {
			SuspendThread(hClock);
			printf("������� ���-�� ������\n");
			int n = 0;
			scanf("%d", &n);
			HANDLE hTimer = CreateThread(NULL, NULL, Timer, n, 0, NULL);
		}
		else if (strstr(str, "settings")) {
			SuspendThread(hClock);
			Settings();
		}
		else if (strstr(str, "stopwatch")) {
			SuspendThread(hClock);
			hWather = CreateThread(NULL, NULL, StopWather, NULL, 0, NULL);
		}
		else if (strstr(str, "exitstopwatch")) {
			TerminateThread(hWather,NULL);
			system("pause");
			system("cls");
			ResumeThread(hClock);
		}
		else if (strstr(str, "stopstopwatch")) {
			SuspendThread(hWather);
			system("pause");
			system("cls");
			ResumeThread(hClock);
		}
		else if (strstr(str, "resumestopwatch")) {
			SuspendThread(hClock);
			system("cls");
			ResumeThread(hWather);
		}
	}
}

void Clock() {
	time_t ttime;
	char buffer[100];
	while (1)
	{
		ttime = time(0);
		loc_time = localtime(&ttime);
		loc_time->tm_hour += correct_H;
		loc_time->tm_min += correct_M;
		strftime(buffer, 100, "%H:%M:%S", loc_time);
		SetConsoleCursorPosition(hConsole, position);
		printf("�����: %s\n", buffer);
		Sleep(100);
	}
}

void Timer(int trigger) {
	system("cls");
	time_t ttime = clock();
	int sec = 0;
	while (sec < trigger)
	{
		sec = (clock() - ttime) / CLOCKS_PER_SEC;
		system("cls");
		printf("��������: %d\n", trigger - sec);
	}
	printf("����� �����������");
	system("pause");
	system("cls");
	ExitThread(0);
}

void StopWather() {
	system("cls");
	time_t ttime = clock();
	int sec = 0;
	while (1)
	{
		sec = (clock() - ttime) / CLOCKS_PER_SEC;
		system("cls");
		printf("������ �������: %d\n",sec);
	}
	ExitThread(0);
}

void Settings() {
	char buffer[100];
	while (1)
	{
		system("cls");
		time_t ttime = time(0);
		int new_time = 0;
		loc_time = localtime(&ttime);
		loc_time->tm_hour += correct_H;
		loc_time->tm_min += correct_M;
		strftime(buffer, 100, "%H:%M", loc_time);
 		printf("������� �����: %s\n\n�������� ���� - 1\n�������� ������ - 2\n����� - 0\n", buffer);
		char c;
		scanf("%c", &c);
		switch (c)
		{
		case '0':
			system("cls");
			ResumeThread(hClock);
			return 0;
			break;
		case '1':
			printf("������� ����e �������� ��� �����\n");
			scanf("%d", &new_time);
			if (new_time > 24) {
				printf("������� ������������ ��������\n");
				break;
			}
			loc_time = localtime(&ttime);
			correct_H = new_time - loc_time->tm_hour;
			break;
		case '2':
			printf("������� ����e �������� ��� �����\n");
			scanf("%d", &new_time);
			if (new_time > 60) {
				printf("������� ������������ ��������\n");
				break;
			}
			loc_time = localtime(&ttime);
			correct_M = new_time - loc_time->tm_min;
			break;
		}
		system("cls");
	}
}

