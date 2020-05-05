/* ******************************************************
* 프로그램명 : main.c  (전체)
* 작성자 : 2013041066 서재준    조원 : 서재준(팀장), 최재웅, 한지섭, 김민지, 안창호
* 작성일 : 2017.5.28
* 프로그램 설명 : 메인함수
* 팀명 : 7조 큐피디
********************************************************* */

#include"Pac_Man_external.h"


void main(){
	system("mode con: cols=80 lines=27"); // 콘솔창 크기정의

	PlaySound(TEXT("test.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); // 사운드 무한반복
	
	CONSOLE_CURSOR_INFO curinfo; // 커서제거함수
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
	curinfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);

	Set_Place(); // 귀신의 위치와, 팩맨의 위치를 초기화 해주는 함수
	Start_Menu(); // 각종 UI출력


	Show_map(); // 값에따른 맵출력
	User_Move(); // 사용자의 입력에 따라 팩맨,귀신을 움직이게 하는 함수

	return 0;
}
