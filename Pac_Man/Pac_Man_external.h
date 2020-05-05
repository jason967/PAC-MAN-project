/* ********************************************************************
* ���α׷��� : Pac_Man_external.h  (��ü)
* �ۼ��� : 2013041066 ������ (����: ������, �����, ������, �����)
* �ۼ��� : 2017.05.28
* ���α׷� ���� : �Ѹǰ��� ���
* ��  �� : 7�� ť�ǵ�
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

int Player_Move(int x, int y); // ����� 

void Ghost_Move1(); // �����, ������
void Ghost_Move2(); // �����, ������
void Ghost_Move3(); // �����, ������
void Ghost_Move4(); // �����, ������

void Show_map(); // ��âȣ
void Check_Cookie(); // ��âȣ

void Set_Place(); //  ������, ������

void User_Move(); // �����

void Init(); // ������

void UI(); // �����
void howtoplay(); // �����
void Intro(); // �����
void flash(int x, int y, char *str); // �����
void color(int color); // �����
void gotoxy(int x, int y); // �����
void End_credit(); // �����

struct user
{ // �Ѹ��� ��ġ����
	char here_x;
	char here_y;
};

struct ghost
{ // ������ ��ġ����
	char here_x;
	char here_y;
};

struct element_value
{ // ���ӿ�� �� ����
	int Last_Score;
	int Cookie_Num;
};

extern int arr[HEIGHT][WIDTH]; // ��
extern int backup[HEIGHT][WIDTH]; // ��� ��

extern int Death; // ������ ����

extern int Life; // ���

struct user me; // �Ѹ��� ����ü ����

struct ghost vs1, vs2, vs3,vs4; // ������ ����ü���� 4��

struct element_value score; // ��ҿ� ������ ����ü����