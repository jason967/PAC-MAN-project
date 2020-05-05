/* ******************************************************
* 프로그램명 : Set_Element.c  (전체)
* 작성자 : 2013041022 안창호    조원 : 서재준(팀장), 최재웅, 한지섭, 김민지, 안창호
* 작성일 : 2017.5.28
* 프로그램 설명 : 오브젝트의 각종 초기화를 담당하는 프로그램
* 팀명 : 7조 큐피디
********************************************************* */

#include "Pac_Man_external.h"

void Check_Cookie() 
{ // 쿠키갯수저장
	score.Cookie_Num = 0; // 한번 호출될때마다 0으로 초기화 후 갯수 세기
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (arr[j][i] == 5)
				score.Cookie_Num += 1; // 0*0~ WIDTH*HEIGHT 까지 각 배열의 요소를 돌면서 쿠키(5)가 나올때마다 +1
		}
	}
}

void Set_Place()
{ // 팩맨과 유령의 위치를 정한다
	me.here_x = 1;
	me.here_y = 1;
	arr[me.here_x][me.here_y] = 3; // 해당 좌표에 팩맨을 넣는다

	vs1.here_x = 13; // 해당좌표에 귀신을 배치시킨다
	vs1.here_y = 8;
	vs2.here_x = 11;
	vs2.here_y = 8;
	vs3.here_x = 11;
	vs3.here_y = 11;
	vs4.here_x = 13;
	vs4.here_y = 11;

	arr[vs1.here_x][vs1.here_y] = 2;
	arr[vs2.here_x][vs2.here_y] = 6;
	arr[vs3.here_x][vs3.here_y] = 7; // 해당 좌표에 유령을 넣는다
	arr[vs4.here_x][vs4.here_y] = 8;
}

void Init() { // 재시작 시 오브젝트 초기화
	int i, j;

	for (i = 0; i < HEIGHT; i++)
		for (j = 0; j < WIDTH; j++)
			arr[i][j] = backup[i][j];

	Life = 3;
	Death = 0;
	score.Last_Score = 0;

	Check_Cookie();
	Set_Place();
}