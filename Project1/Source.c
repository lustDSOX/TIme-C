#include "Header.h"

main() {
	system("chcp 1251>nul");
	hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hClock = CreateThread(NULL, NULL, Clock, NULL, CREATE_SUSPENDED, NULL);
	ResumeThread(hClock);
	char str[20];
	while (1)
	{
		scanf("%s", str);
		if (strstr(str, "stop")) {
			SuspendThread(hClock);
		}
		else if (strstr(str, "start")) {
			ResumeThread(hClock);
		}
		else if (strstr(str, "timer")) {
			SuspendThread(hClock);
			printf("Введите кол-во секунд\n");
			int n = 0;
			scanf("%d", &n);
			HANDLE hTimer = CreateThread(NULL, NULL, Timer, n, 0, NULL);
		}
	}
}

void Clock() {
	time_t ttime;
	struct tm* loc_time;
	char buffer[100];
	while (1)
	{
		Sleep(300);
		ttime = time(0);
		loc_time = localtime(&ttime);
		strftime(buffer, 100, "%H:%M:%S", loc_time);
		SetConsoleCursorPosition(hConsole,position);
		printf("Время: %s\n", buffer);
	}
}

void Timer(int trigger) {
	system("cls");
	time_t ttime = clock();
	int sec = 0;
	while (sec < trigger)
	{
		Sleep(300);
		sec = (clock() - ttime) / CLOCKS_PER_SEC;
		system("cls");
		printf("Осталось: %d\n",trigger-sec);
	}
	printf("Время зокончилось");
	system("cls");
	ExitThread(0);
}


