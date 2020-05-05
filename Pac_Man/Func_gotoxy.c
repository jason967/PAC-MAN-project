/* ******************************************************
* 프로그램명 : Func_gotoxy.c  (전체)
* 작성자 : 2016039026 김민지    조원 : 서재준(팀장), 최재웅, 한지섭, 김민지, 안창호
* 작성일 : 2017.5.28
* 프로그램 설명 : 콘솔 커서를 해당 좌표로 이동시키는 함수 
* 팀명 : 7조 큐피디
********************************************************* */

#include "Pac_Man_external.h"

void gotoxy(int x, int y) 
{ // 콘솔의 커서를 해당 좌표로 이동시키는 함수
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
