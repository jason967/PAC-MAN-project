/* ******************************************************
* 프로그램명 : Show_Map.c  (전체)
* 작성자 : 2013041022 안창호    조원 : 서재준(팀장), 최재웅, 한지섭, 김민지, 안창호
* 작성일 : 2017.5.28
* 프로그램 설명 : 맵 출력을 해주는 프로그램
* 팀명 : 7조 큐피디
********************************************************* */

#include "Pac_Man_external.h"

void Show_map()
{

	//만약 arr[?][?] == 0 -> " "
	//0 -> " "
	//1 -> "ㅁ"
	//2 -> "귀신" 만나면 죽음
	//3 -> "팩맨"
	//4 -> "클로버"   아이템으로하자
	//5 -> "." 쿠키
	gotoxy(40, 6);
	printf(" ___  ___  ___         __ __  ___  _ __ ");
	gotoxy(40, 7);
	printf("| .  | . ||  _>  ___  |  |  || . || ＼ |");
	gotoxy(40, 8);
	printf("|  _/|   || <__ |___| |     ||   ||    |");
	gotoxy(40, 9);
	printf("|_|  |_|_|`___/       |_|_|_||_|_||_＼_|");
	gotoxy(40, 11);
	printf("________________________________________");
	gotoxy(53, 13);
	printf("점수 : %d", score.Last_Score); // 최초 스코어 출력
	gotoxy(53, 14);
	switch (Life) {
	case 1: printf("♥♡♡♡♡"); break;
	case 2: printf("♥♥♡♡♡"); break;
	case 3: printf("♥♥♥♡♡"); break;
	case 4: printf("♥♥♥♥♡"); break;
	case 5: printf("♥♥♥♥♥"); break;
	}

	gotoxy(53, 15);
	printf("남은먹이 : %d", score.Cookie_Num); // 최초 먹이
	gotoxy(40, 17);
	printf("________________________________________");

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++) 
		{ // 2차원배열 만큼 출력
			gotoxy(i * 2, j); // 한칸에 2Byte씩 차지하여 2칸씩 이동
			if (arr[j][i] == 0) // 만약 0이라면 
			{
				printf(" "); // 공백출력
			}
			else if (arr[j][i] == 1) // 만약 1이라면
			{
				color(9); // 색깔변화
				printf("□"); // ㅁ출력
				color(7); // 색깔변화
			}
			else if (arr[j][i] == 2) // 만약 2라면
			{
				color(3);
				printf("Ω"); // 귀신출력
				color(7);
			}
			else if (arr[j][i] == 6) // 만약 6라면
			{
				color(4);
				printf("Ω"); // 귀신출력
				color(7);
			}
			else if (arr[j][i] == 7) // 만약 7라면
			{
				color(5);
				printf("Ω"); // 귀신출력
				color(7);
			}
			else if (arr[j][i] == 8) // 만약 8라면
			{
				color(8);
				printf("Ω"); // 귀신출력
				color(7);
			}
			else if (arr[j][i] == 3) // 만약 9이라면
			{
				color(14);
				printf("⊙"); // 팩맨 출력
				color(7);
			}
			else if (arr[j][i] == 4) // 만약 4라면
			{
				color(10);
				printf("♧"); // 점수 100을 올리는 클로버 출력
				color(7);
			}
			else if (arr[j][i] == 5) // 만약 5라면
			{
				printf("·"); // 점수 1을 올리는 쿠키를 출력
			}
			else if (arr[j][i] == 9) // 만약 9라면
			{
				color(12);
				printf("♥"); // 라이프 1을 올리는 하트출력
				color(7);
			}
		}
	}

}