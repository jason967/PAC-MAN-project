/* ******************************************************
* ���α׷��� : main.c  (��ü)
* �ۼ��� : 2013041066 ������    ���� : ������(����), �����, ������, �����, ��âȣ
* �ۼ��� : 2017.5.28
* ���α׷� ���� : �����Լ�
* ���� : 7�� ť�ǵ�
********************************************************* */

#include"Pac_Man_external.h"


void main(){
	system("mode con: cols=80 lines=27"); // �ܼ�â ũ������

	PlaySound(TEXT("test.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); // ���� ���ѹݺ�
	
	CONSOLE_CURSOR_INFO curinfo; // Ŀ�������Լ�
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
	curinfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);

	Set_Place(); // �ͽ��� ��ġ��, �Ѹ��� ��ġ�� �ʱ�ȭ ���ִ� �Լ�
	Start_Menu(); // ���� UI���


	Show_map(); // �������� �����
	User_Move(); // ������� �Է¿� ���� �Ѹ�,�ͽ��� �����̰� �ϴ� �Լ�

	return 0;
}
