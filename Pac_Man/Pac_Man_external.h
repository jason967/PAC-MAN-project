/* ********************************************************************
* 프로그램명 : Pac_Man_external.h  (전체)
* 작성자 : 2013041066 서재준 (조원: 서재준, 최재웅, 한지섭, 김민지)
* 작성일 : 2017.05.28
* 프로그램 설명 : 팩맨게임 헤더
* 팀  명 : 7조 큐피디
********************************************************************* */

#pragma once

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

#define HEIGHT 25 // map
#define WIDTH 20 // map
#define TIME 250 // ui

int Player_Move(int x, int y); // 최재웅 

void Ghost_Move1(); // 최재웅, 한지섭
void Ghost_Move2(); // 최재웅, 한지섭
void Ghost_Move3(); // 최재웅, 한지섭
void Ghost_Move4(); // 최재웅, 한지섭

void Show_map(); // 안창호
void Check_Cookie(); // 안창호

void Set_Place(); //  서재준, 한지섭

void User_Move(); // 최재웅

void Init(); // 서재준

void UI(); // 김민지
void howtoplay(); // 김민지
void Intro(); // 김민지
void flash(int x, int y, char *str); // 김민지
void color(int color); // 김민지
void gotoxy(int x, int y); // 김민지
void End_credit(); // 김민지

struct user
{ // 팩맨의 위치정보
	char here_x;
	char here_y;
};

struct ghost
{ // 유령의 위치정보
	char here_x;
	char here_y;
};

struct element_value
{ // 게임요소 값 정보
	int Last_Score;
	int Cookie_Num;
};

extern int arr[HEIGHT][WIDTH]; // 맵
extern int backup[HEIGHT][WIDTH]; // 백업 맵

extern int Death; // 죽음의 정보

extern int Life; // 목숨

struct user me; // 팩맨의 구조체 변수

struct ghost vs1, vs2, vs3,vs4; // 유령의 구조체변수 4개

struct element_value score; // 요소에 접근할 구조체변수