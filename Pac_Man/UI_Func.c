/* ******************************************************
* ���α׷��� : UI_Func.c  (��ü)
* �ۼ��� : 2016039026 �����    ���� : ������(����), �����, ������, �����, ��âȣ
* �ۼ��� : 2017.5.28
* ���α׷� ���� : �ִϸ��̼� ȿ���� ���� �Լ�����
* ���� : 7�� ť�ǵ�
********************************************************* */

#include "Pac_Man_external.h"



void flash(int x, int y, char *str) {
	char str2[30]; // �����Ÿ����ϴ� ȿ��
	strcpy(str2, str);
	gotoxy(x, y);
	printf("%20s", " ");
	Sleep(TIME);
	gotoxy(x, y);
	printf("%s", str2);
	Sleep(TIME);
}


void color(int color) { // ���� ������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}