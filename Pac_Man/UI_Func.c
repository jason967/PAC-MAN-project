/* ******************************************************
* 프로그램명 : UI_Func.c  (전체)
* 작성자 : 2016039026 김민지    조원 : 서재준(팀장), 최재웅, 한지섭, 김민지, 안창호
* 작성일 : 2017.5.28
* 프로그램 설명 : 애니메이션 효과를 위한 함수정의
* 팀명 : 7조 큐피디
********************************************************* */

#include "Pac_Man_external.h"



void flash(int x, int y, char *str) {
	char str2[30]; // 깜빡거리게하는 효과
	strcpy(str2, str);
	gotoxy(x, y);
	printf("%20s", " ");
	Sleep(TIME);
	gotoxy(x, y);
	printf("%s", str2);
	Sleep(TIME);
}


void color(int color) { // 색깔 입히기
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}