/* ******************************************************
* 프로그램명 : Move_Player_Ghost.c  (User_Move, Player_Move)
* 작성자 : 2013041049 최재웅    조원 : 서재준(팀장), 최재웅, 한지섭, 김민지, 안창호
* 작성일 : 2017.5.28
* 프로그램 설명 : User_Move, Player_Move 함수를 사용하여 사용자의 입력에따른 팩맨의 이동구현
* 팀명 : 7조 큐피디
********************************************************* */

#include "Pac_Man_external.h"
void User_Move()
{ // 팩맨움직임 조작
	int key = 0;
	system("cls");
	howtoplay(); // 조작방법
	system("pause");
	system("cls");
	// 사용자의 입력에따른 이동
	while (1)
	{
		Check_Cookie(); // 쿠키 개수 체크
		Show_map();
		if (kbhit()) do { key = getch(); } while (key == 224); //키 입력받음
		Sleep(40);
		switch (key) // 사용자의 키보드로부터 방향(키)을 입력 받는다
		{
		case 'w': // w입력시 북쪽을 향함
		{
			Player_Move(me.here_x - 1, me.here_y); // 팩맨의 위치에서 x값을 -1 해서 보내주면 북쪽으로 이동
			break;
		}
		case 'a': // a 입력시 서쪽을 향함
		{
			Player_Move(me.here_x, me.here_y - 1); // 팩맨의 위치에서 y값을 -1 해서 보내주면 서쪽으로 이동
			break;
		}
		case 's': // s 입력시 남쪽을 향함
		{
			Player_Move(me.here_x + 1, me.here_y); // 팩맨의 위치에서 x값을 +1 해서 보내주면 남쪽으로 이동
			break;
		}
		case 'd': // d 입력시 동쪽을 향함
		{
			Player_Move(me.here_x, me.here_y + 1); // 팩맨의 위치에서 y값을 +1 해서 보내주면 동쪽으로 이동
			break;
		}
		}
		if (Death == -10) // 만약 Life가 0이 되었다면 전역변수 Death가 -10을 반환하여 실패상태로 돌입
		{
			system("cls"); // 화면 클리어
			GAMEOVER(); // 게임오버 ui 출력
			system("cls"); // 화면 클리어
			Init();
			Start_Menu(); // 시작 메뉴로 다시 돌아감
		}
		if (score.Cookie_Num == 0) // 만약 쿠키갯수가 0이 되었다면 성공상태로 돌입
		{
			system("cls"); // 화면 클리어
			CLEAR(); // 게임 클리어 ui 출력
			system("cls"); // 화면 클리어
			Init();
			Start_Menu(); // 생명은 3으로 다시 초기화된다.
		}
	}
}

int Player_Move(int x, int y)
{

	Ghost_Move1(); // 귀신1의 이동
	Ghost_Move2(); // 귀신2의 이동
	Ghost_Move3(); // 귀신3의 이동
	Ghost_Move4(); // 귀신4의 이동

	if (arr[x][y] == 1)
		return FALSE; // 만약 해당좌표가 1(벽)이면 갈 수없다는 표시로 실패를 리턴한다

	arr[me.here_x][me.here_y] = 0; // 움직이고 난 곳의 해당 좌표에 0(공백)을 출력한다
	me.here_x = x; // 동서남북중 받아온 위치중 x값을 팩맨의 좌표로 넣는다.
	me.here_y = y; // 동서남북중 받아온 위치중 y값을 팩맨의 좌표로 넣는다.

	if (arr[me.here_x][me.here_y] == 5) // 만약 움직인좌표가 5(쿠키)라면?
	{
		arr[me.here_x][me.here_y] = 3; // 해당좌표로 팩맨이 이동한다
		score.Last_Score += 10; // 쿠키먹으면 10점
		score.Cookie_Num -= 1; // 쿠키가 사라졌으니 갯수 -1씩
		gotoxy(53, 15); // 쿠키출력 위치로 커서이동
		printf("남은먹이 : %d", score.Cookie_Num); // 해당위치에 해당 값 출력
		gotoxy(53, 13);
		printf("점수 : %d  ", score.Last_Score); // 최초 스코어 출력
	}
	if (arr[me.here_x][me.here_y] == 9) // 만약 움직인좌표가 9(하트)라면?
	{
		arr[me.here_x][me.here_y] = 3; // 해당좌표로 팩맨이 이동한다
		Life += 1;
		gotoxy(53, 15); // 쿠키출력 위치로 커서이동
		printf("남은먹이 : %d", score.Cookie_Num); // 해당위치에 해당 값 출력
		gotoxy(53, 13);
		printf("점수 : %d  ", score.Last_Score); // 최초 스코어 출력
	}
	if (arr[me.here_x][me.here_y] == 4) // 만약 클로버를 만나면
	{
		arr[me.here_x][me.here_y] = 3; // 해당좌표로 팩맨이 이동한다
		score.Last_Score += 100; // 점수 100점이 올라간다.

	}
	if (arr[me.here_x][me.here_y] == 2|| arr[me.here_x][me.here_y] == 6|| arr[me.here_x][me.here_y] == 7|| arr[me.here_x][me.here_y] == 8) // 유령을 만났을때
	{
		arr[me.here_x][me.here_y] = 3; // 해당좌표로 팩맨이 이동한다.
		Life -= 1; // 라이프가 -1 깎인다.
		if (Life == 0) // 만약 라이프가 0이 된다면
		{
			Death = -10; // 데스판별값 -10을 저장후
			return TRUE; // 종료 값 반환
		}
	}
	if (score.Cookie_Num == 99 || (score.Cookie_Num == 9))
		system("cls");

	arr[me.here_x][me.here_y] = 3; // 해당 요소를 거치지않고 그대로 갔다면 해당좌표로 팩맨을 이동
	Show_map(); // 2차원 배열의 요소가 바뀌고 출력실행
	return TRUE;
}

/* ******************************************************
* 프로그램명 : Move_Player_Ghost.c  (Ghost_Move1~4)
* 작성자 : 2013041049 최재웅 2013041057 한지섭  조원 : 서재준(팀장), 최재웅, 한지섭, 김민지, 안창호
* 작성일 : 2017.5.28
* 프로그램 설명 : 팩맨의 이동에따른 유령의 움직임 구현
* 팀명 : 7조 큐피디
********************************************************* */

void Ghost_Move1()
{
	int x;

	srand((unsigned)time(NULL));
	x = 0;
	x = rand() % 8 + 1;
	// 1동  2서  3남  4북
	switch (x)
	{
	case 1:
	{
		if (arr[vs1.here_x][vs1.here_y + 1] == 1)      //벽에 막힘
			break;
		
		if (arr[vs1.here_x][vs1.here_y + 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		
		if (arr[vs1.here_x][vs1.here_y + 1] == 0)      //먹이가 바닥에 없는 경우
		{
			arr[vs1.here_x][++vs1.here_y] = 2;
			arr[vs1.here_x][vs1.here_y - 1] = 0;
			break;
		}
		if (arr[vs1.here_x][vs1.here_y + 1] == 2|| arr[vs1.here_x][vs1.here_y + 1] == 6 || arr[vs1.here_x][vs1.here_y + 1] == 7 || arr[vs1.here_x][vs1.here_y + 1] == 8 )      //귀신을 만난 경우
		{
			break;
		}
		if (arr[vs1.here_x][vs1.here_y + 1] == 4)      //'클로버'가 바닥에 존재하는 경우
		{
			arr[vs1.here_x][++vs1.here_y] = 2;
			arr[vs1.here_x][vs1.here_y - 1] = 4;
			break;
		}
		if (arr[vs1.here_x][vs1.here_y + 1] == 9)      //'하트'가 바닥에 존재하는 경우
		{
			arr[vs1.here_x][++vs1.here_y] = 2;
			arr[vs1.here_x][vs1.here_y - 1] = 9;
			break;
		}

		arr[vs1.here_x][++vs1.here_y] = 2;
		arr[vs1.here_x][vs1.here_y - 1] = 5;
		break;
	}

	case 2:
	{
		if (arr[vs1.here_x][vs1.here_y - 1] == 1)
			break;

		if (arr[vs1.here_x][vs1.here_y - 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs1.here_x][vs1.here_y - 1] == 0)
		{
			arr[vs1.here_x][--vs1.here_y] = 2;
			arr[vs1.here_x][vs1.here_y + 1] = 0;
			break;
		}

		if (arr[vs1.here_x][vs1.here_y - 1] == 2|| arr[vs1.here_x][vs1.here_y - 1] == 6 || arr[vs1.here_x][vs1.here_y - 1] == 7 || arr[vs1.here_x][vs1.here_y - 1] == 8  )
		{
			break;
		}
		if (arr[vs1.here_x][vs1.here_y - 1] == 4)
		{
			arr[vs1.here_x][--vs1.here_y] = 2;
			arr[vs1.here_x][vs1.here_y + 1] = 4;
			break;
		}
		arr[vs1.here_x][--vs1.here_y] = 2;
		arr[vs1.here_x][vs1.here_y + 1] = 5;
		break;

	}
	case 3:
	{
		if (arr[vs1.here_x + 1][vs1.here_y] == 1)
			break;

		if (arr[vs1.here_x+1][vs1.here_y ] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		if (arr[vs1.here_x + 1][vs1.here_y] == 0)
		{
			arr[++vs1.here_x][vs1.here_y] = 2;
			arr[vs1.here_x - 1][vs1.here_y] = 0;
			break;
		}
		if (arr[vs1.here_x + 1][vs1.here_y] == 2|| arr[vs1.here_x + 1][vs1.here_y] == 6 || arr[vs1.here_x + 1][vs1.here_y] == 7 || arr[vs1.here_x + 1][vs1.here_y] == 8  )
		{
			break;
		}
		if (arr[vs1.here_x + 1][vs1.here_y] == 4)
		{
			arr[++vs1.here_x][vs1.here_y] = 2;
			arr[vs1.here_x - 1][vs1.here_y] = 4;
			break;
		}
		arr[++vs1.here_x][vs1.here_y] = 2;
		arr[vs1.here_x - 1][vs1.here_y] = 5;
		break;

	}
	case 4:
	{
		if (arr[vs1.here_x - 1][vs1.here_y] == 1)
			break;

		if (arr[vs1.here_x-1][vs1.here_y ] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		if (arr[vs1.here_x - 1][vs1.here_y] == 0)
		{
			arr[--vs1.here_x][vs1.here_y] = 2;
			arr[vs1.here_x + 1][vs1.here_y] = 0;
			break;
		}
		if (arr[vs1.here_x - 1][vs1.here_y] == 2|| arr[vs1.here_x - 1][vs1.here_y] == 6 || arr[vs1.here_x - 1][vs1.here_y] == 7 || arr[vs1.here_x - 1][vs1.here_y] == 8  )
		{
			break;
		}
		if (arr[vs1.here_x - 1][vs1.here_y] == 4)
		{
			arr[--vs1.here_x][vs1.here_y] = 2;
			arr[vs1.here_x + 1][vs1.here_y] = 4;
			break;
		}
		arr[--vs1.here_x][vs1.here_y] = 2;
		arr[vs1.here_x + 1][vs1.here_y] = 5;
		break;

	}
	case 7:
	{
		if (arr[vs1.here_x][vs1.here_y + 1] == 1)      //벽에 막힘
			break;

		if (arr[vs1.here_x][vs1.here_y + 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs1.here_x][vs1.here_y + 1] == 0)      //먹이가 바닥에 없는 경우
		{
			arr[vs1.here_x][++vs1.here_y] = 2;
			arr[vs1.here_x][vs1.here_y - 1] = 0;
			break;
		}
		if (arr[vs1.here_x][vs1.here_y + 1] == 2 || arr[vs1.here_x][vs1.here_y + 1] == 6 || arr[vs1.here_x][vs1.here_y + 1] == 7 || arr[vs1.here_x][vs1.here_y + 1] == 8)      //귀신을 만난 경우
		{
			break;
		}
		if (arr[vs1.here_x][vs1.here_y + 1] == 4)      //'클로버'가 바닥에 존재하는 경우
		{
			arr[vs1.here_x][++vs1.here_y] = 2;
			arr[vs1.here_x][vs1.here_y - 1] = 4;
			break;
		}

		arr[vs1.here_x][++vs1.here_y] = 2;
		arr[vs1.here_x][vs1.here_y - 1] = 5;
		break;
	}

	case 5:
	{
		if (arr[vs1.here_x][vs1.here_y - 1] == 1)
			break;

		if (arr[vs1.here_x][vs1.here_y - 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs1.here_x][vs1.here_y - 1] == 0)
		{
			arr[vs1.here_x][--vs1.here_y] = 2;
			arr[vs1.here_x][vs1.here_y + 1] = 0;
			break;
		}

		if (arr[vs1.here_x][vs1.here_y - 1] == 2 || arr[vs1.here_x][vs1.here_y - 1] == 6 || arr[vs1.here_x][vs1.here_y - 1] == 7 || arr[vs1.here_x][vs1.here_y - 1] == 8)
		{
			break;
		}
		if (arr[vs1.here_x][vs1.here_y - 1] == 4)
		{
			arr[vs1.here_x][--vs1.here_y] = 2;
			arr[vs1.here_x][vs1.here_y + 1] = 4;
			break;
		}
		arr[vs1.here_x][--vs1.here_y] = 2;
		arr[vs1.here_x][vs1.here_y + 1] = 5;
		break;

	}
	case 8:
	{
		if (arr[vs1.here_x + 1][vs1.here_y] == 1)
			break;

		if (arr[vs1.here_x + 1][vs1.here_y] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		if (arr[vs1.here_x + 1][vs1.here_y] == 0)
		{
			arr[++vs1.here_x][vs1.here_y] = 2;
			arr[vs1.here_x - 1][vs1.here_y] = 0;
			break;
		}
		if (arr[vs1.here_x + 1][vs1.here_y] == 2 || arr[vs1.here_x + 1][vs1.here_y] == 6 || arr[vs1.here_x + 1][vs1.here_y] == 7 || arr[vs1.here_x + 1][vs1.here_y] == 8)
		{
			break;
		}
		if (arr[vs1.here_x + 1][vs1.here_y] == 4)
		{
			arr[++vs1.here_x][vs1.here_y] = 2;
			arr[vs1.here_x - 1][vs1.here_y] = 4;
			break;
		}
		arr[++vs1.here_x][vs1.here_y] = 2;
		arr[vs1.here_x - 1][vs1.here_y] = 5;
		break;

	}
	case 6:
	{
		if (arr[vs1.here_x - 1][vs1.here_y] == 1)
			break;

		if (arr[vs1.here_x - 1][vs1.here_y] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		if (arr[vs1.here_x - 1][vs1.here_y] == 0)
		{
			arr[--vs1.here_x][vs1.here_y] = 2;
			arr[vs1.here_x + 1][vs1.here_y] = 0;
			break;
		}
		if (arr[vs1.here_x - 1][vs1.here_y] == 2 || arr[vs1.here_x - 1][vs1.here_y] == 6 || arr[vs1.here_x - 1][vs1.here_y] == 7 || arr[vs1.here_x - 1][vs1.here_y] == 8)
		{
			break;
		}
		if (arr[vs1.here_x - 1][vs1.here_y] == 4)
		{
			arr[--vs1.here_x][vs1.here_y] = 2;
			arr[vs1.here_x + 1][vs1.here_y] = 4;
			break;
		}
		arr[--vs1.here_x][vs1.here_y] = 2;
		arr[vs1.here_x + 1][vs1.here_y] = 5;
		break;

	}
	}


}

void Ghost_Move2()
{ 
	int x;

	srand((unsigned)time(NULL));
	x = 0;
	x = rand() % 4 + 1;
	// 1동  2서  3남  4북
	switch (x)
	{
	case 1:
	{
		if (arr[vs2.here_x][vs2.here_y + 1] == 1)      //벽에 막힘
			break;

		if (arr[vs2.here_x][vs2.here_y + 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs2.here_x][vs2.here_y + 1] == 0)      //먹이가 바닥에 없는 경우
		{
			arr[vs2.here_x][++vs2.here_y] = 6;
			arr[vs2.here_x][vs2.here_y - 1] = 0;
			break;
		}
		if (arr[vs2.here_x][vs2.here_y + 1] == 6|| arr[vs1.here_x - 1][vs1.here_y] == 2 || arr[vs1.here_x - 1][vs1.here_y] == 7 || arr[vs1.here_x - 1][vs1.here_y] == 8 )      //먹이가 바닥에 없는 경우
		{
			break;
		}
		if (arr[vs2.here_x][vs2.here_y + 1] == 4)      //'클로버'가 바닥에 존재하는 경우
		{
			arr[vs2.here_x][++vs2.here_y] = 6;
			arr[vs2.here_x][vs2.here_y - 1] = 4;
			break;
		}

		arr[vs2.here_x][++vs2.here_y] = 6;
		arr[vs2.here_x][vs2.here_y - 1] = 5;
		break;
	}

	case 2:
	{
		if (arr[vs2.here_x][vs2.here_y - 1] == 1)
			break;

		if (arr[vs2.here_x][vs2.here_y - 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs2.here_x][vs2.here_y - 1] == 0)
		{
			arr[vs2.here_x][--vs2.here_y] = 6;
			arr[vs2.here_x][vs2.here_y + 1] = 0;
			break;
		}

		if (arr[vs2.here_x][vs2.here_y - 1] == 6|| arr[vs2.here_x][vs2.here_y - 1] == 2 || arr[vs2.here_x][vs2.here_y - 1] == 7 || arr[vs2.here_x][vs2.here_y - 1] == 8)
		{
			break;
		}

		if (arr[vs2.here_x][vs2.here_y - 1] == 4)
		{
			arr[vs2.here_x][--vs2.here_y] = 6;
			arr[vs2.here_x][vs2.here_y + 1] = 4;
			break;
		}
		arr[vs2.here_x][--vs2.here_y] = 6;
		arr[vs2.here_x][vs2.here_y + 1] = 5;
		break;

	}

	case 3:
	{
		if (arr[vs2.here_x + 1][vs2.here_y] == 1)
			break;

		if (arr[vs2.here_x+1][vs2.here_y] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		if (arr[vs2.here_x + 1][vs2.here_y] == 0)
		{
			arr[++vs2.here_x][vs2.here_y] = 6;
			arr[vs2.here_x - 1][vs2.here_y] = 0;
			break;
		}
		if (arr[vs2.here_x + 1][vs2.here_y] == 6|| arr[vs2.here_x + 1][vs2.here_y] == 2 || arr[vs2.here_x + 1][vs2.here_y] == 7 || arr[vs2.here_x + 1][vs2.here_y] == 8)
		{
			break;
		}
		if (arr[vs2.here_x + 1][vs2.here_y] == 4)
		{
			arr[++vs2.here_x][vs2.here_y] = 6;
			arr[vs2.here_x - 1][vs2.here_y] = 4;
			break;
		}
		arr[++vs2.here_x][vs2.here_y] = 6;
		arr[vs2.here_x - 1][vs2.here_y] = 5;
		break;

	}
	case 4:
	{
		if (arr[vs2.here_x - 1][vs2.here_y] == 1)
			break;

		if (arr[vs2.here_x-1][vs2.here_y ] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs2.here_x - 1][vs2.here_y] == 0)
		{
			arr[--vs2.here_x][vs2.here_y] = 6;
			arr[vs2.here_x + 1][vs2.here_y] = 0;
			break;
		}
		if (arr[vs2.here_x - 1][vs2.here_y] == 6|| arr[vs2.here_x - 1][vs2.here_y] == 2 || arr[vs2.here_x - 1][vs2.here_y] == 7 || arr[vs2.here_x - 1][vs2.here_y] == 8)
		{
			break;
		}
		if (arr[vs2.here_x - 1][vs2.here_y] == 4)
		{
			arr[--vs2.here_x][vs2.here_y] = 6;
			arr[vs2.here_x + 1][vs2.here_y] = 4;
			break;
		}
		arr[--vs2.here_x][vs2.here_y] = 6;
		arr[vs2.here_x + 1][vs2.here_y] = 5;
		break;

	}
	case 8:
	{
		if (arr[vs2.here_x][vs2.here_y + 1] == 1)      //벽에 막힘
			break;

		if (arr[vs2.here_x][vs2.here_y + 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs2.here_x][vs2.here_y + 1] == 0)      //먹이가 바닥에 없는 경우
		{
			arr[vs2.here_x][++vs2.here_y] = 6;
			arr[vs2.here_x][vs2.here_y - 1] = 0;
			break;
		}
		if (arr[vs2.here_x][vs2.here_y + 1] == 6 || arr[vs1.here_x - 1][vs1.here_y] == 2 || arr[vs1.here_x - 1][vs1.here_y] == 7 || arr[vs1.here_x - 1][vs1.here_y] == 8)      //먹이가 바닥에 없는 경우
		{
			break;
		}
		if (arr[vs2.here_x][vs2.here_y + 1] == 4)      //'클로버'가 바닥에 존재하는 경우
		{
			arr[vs2.here_x][++vs2.here_y] = 6;
			arr[vs2.here_x][vs2.here_y - 1] = 4;
			break;
		}

		arr[vs2.here_x][++vs2.here_y] = 6;
		arr[vs2.here_x][vs2.here_y - 1] = 5;
		break;
	}

	case 5:
	{
		if (arr[vs2.here_x][vs2.here_y - 1] == 1)
			break;

		if (arr[vs2.here_x][vs2.here_y - 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs2.here_x][vs2.here_y - 1] == 0)
		{
			arr[vs2.here_x][--vs2.here_y] = 6;
			arr[vs2.here_x][vs2.here_y + 1] = 0;
			break;
		}

		if (arr[vs2.here_x][vs2.here_y - 1] == 6 || arr[vs2.here_x][vs2.here_y - 1] == 2 || arr[vs2.here_x][vs2.here_y - 1] == 7 || arr[vs2.here_x][vs2.here_y - 1] == 8)
		{
			break;
		}

		if (arr[vs2.here_x][vs2.here_y - 1] == 4)
		{
			arr[vs2.here_x][--vs2.here_y] = 6;
			arr[vs2.here_x][vs2.here_y + 1] = 4;
			break;
		}
		arr[vs2.here_x][--vs2.here_y] = 6;
		arr[vs2.here_x][vs2.here_y + 1] = 5;
		break;

	}

	case 7:
	{
		if (arr[vs2.here_x + 1][vs2.here_y] == 1)
			break;

		if (arr[vs2.here_x + 1][vs2.here_y] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		if (arr[vs2.here_x + 1][vs2.here_y] == 0)
		{
			arr[++vs2.here_x][vs2.here_y] = 6;
			arr[vs2.here_x - 1][vs2.here_y] = 0;
			break;
		}
		if (arr[vs2.here_x + 1][vs2.here_y] == 6 || arr[vs2.here_x + 1][vs2.here_y] == 2 || arr[vs2.here_x + 1][vs2.here_y] == 7 || arr[vs2.here_x + 1][vs2.here_y] == 8)
		{
			break;
		}
		if (arr[vs2.here_x + 1][vs2.here_y] == 4)
		{
			arr[++vs2.here_x][vs2.here_y] = 6;
			arr[vs2.here_x - 1][vs2.here_y] = 4;
			break;
		}
		arr[++vs2.here_x][vs2.here_y] = 6;
		arr[vs2.here_x - 1][vs2.here_y] = 5;
		break;

	}
	case 6:
	{
		if (arr[vs2.here_x - 1][vs2.here_y] == 1)
			break;

		if (arr[vs2.here_x - 1][vs2.here_y] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs2.here_x - 1][vs2.here_y] == 0)
		{
			arr[--vs2.here_x][vs2.here_y] = 6;
			arr[vs2.here_x + 1][vs2.here_y] = 0;
			break;
		}
		if (arr[vs2.here_x - 1][vs2.here_y] == 6 || arr[vs2.here_x - 1][vs2.here_y] == 2 || arr[vs2.here_x - 1][vs2.here_y] == 7 || arr[vs2.here_x - 1][vs2.here_y] == 8)
		{
			break;
		}
		if (arr[vs2.here_x - 1][vs2.here_y] == 4)
		{
			arr[--vs2.here_x][vs2.here_y] = 6;
			arr[vs2.here_x + 1][vs2.here_y] = 4;
			break;
		}
		arr[--vs2.here_x][vs2.here_y] = 6;
		arr[vs2.here_x + 1][vs2.here_y] = 5;
		break;

	}
	}
}
void Ghost_Move3()
{
	int x, temp;

	srand((unsigned)time(NULL));
	x = 0;
	x = rand() % 4 + 1;
	// 1동  2서  3남  4북
	switch (x)
	{
	case 1:
	{
		if (arr[vs3.here_x][vs3.here_y + 1] == 1)      //벽에 막힘
			break;

		if (arr[vs3.here_x][vs3.here_y + 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs3.here_x][vs3.here_y + 1] == 0)      //먹이가 바닥에 없는 경우
		{
			arr[vs3.here_x][++vs3.here_y] = 7;
			arr[vs3.here_x][vs3.here_y - 1] = 0;
			break;
		}
		if (arr[vs3.here_x][vs3.here_y + 1] == 7|| arr[vs3.here_x][vs3.here_y + 1] == 2 || arr[vs3.here_x][vs3.here_y + 1] == 6 || arr[vs3.here_x][vs3.here_y + 1] == 8)      //귀신 마주쳤을 때
		{
			break;
		}
		if (arr[vs3.here_x][vs3.here_y + 1] == 4)      //'클로버'가 바닥에 존재하는 경우
		{
			arr[vs3.here_x][++vs3.here_y] = 7;
			arr[vs3.here_x][vs3.here_y - 1] = 4;
			break;
		}

		arr[vs3.here_x][++vs3.here_y] = 7;
		arr[vs3.here_x][vs3.here_y - 1] = 5;
		break;
	}

	case 2:
	{
		if (arr[vs3.here_x][vs3.here_y - 1] == 1)
			break;
		if (arr[vs3.here_x][vs3.here_y - 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs3.here_x][vs3.here_y - 1] == 0)
		{
			arr[vs3.here_x][--vs3.here_y] = 7;
			arr[vs3.here_x][vs3.here_y + 1] = 0;
			break;
		}

		if (arr[vs3.here_x][vs3.here_y - 1] == 7|| arr[vs3.here_x][vs3.here_y - 1] == 2 || arr[vs3.here_x][vs3.here_y - 1] == 6 || arr[vs3.here_x][vs3.here_y - 1] == 8)
		{
			break;
		}

		if (arr[vs3.here_x][vs3.here_y - 1] == 4)
		{
			arr[vs3.here_x][--vs3.here_y] = 7;
			arr[vs3.here_x][vs3.here_y + 1] = 4;
			break;
		}
		arr[vs3.here_x][--vs3.here_y] = 7;
		arr[vs3.here_x][vs3.here_y + 1] = 5;
		break;

	}

	case 3:
	{
		if (arr[vs3.here_x + 1][vs3.here_y] == 1)
			break;

		if (arr[vs3.here_x+1][vs3.here_y] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		if (arr[vs3.here_x + 1][vs3.here_y] == 0)
		{
			arr[++vs3.here_x][vs3.here_y] = 7;
			arr[vs3.here_x - 1][vs3.here_y] = 0;
			break;
		}
		if (arr[vs3.here_x + 1][vs3.here_y] == 2|| arr[vs3.here_x + 1][vs3.here_y] == 6 || arr[vs3.here_x + 1][vs3.here_y] == 7 || arr[vs3.here_x + 1][vs3.here_y] == 8)
		{
			break;
		}
		if (arr[vs3.here_x + 1][vs3.here_y] == 4)
		{
			arr[++vs3.here_x][vs3.here_y] = 7;
			arr[vs3.here_x - 1][vs3.here_y] = 4;
			break;
		}
		arr[++vs3.here_x][vs3.here_y] = 7;
		arr[vs3.here_x - 1][vs3.here_y] = 5;
		break;

	}
	case 4:
	{
		if (arr[vs3.here_x - 1][vs3.here_y] == 1)
			break;

		if (arr[vs3.here_x-1][vs3.here_y ] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}

			break;
		}
		if (arr[vs3.here_x - 1][vs3.here_y] == 0)
		{
			arr[--vs3.here_x][vs3.here_y] = 7;
			arr[vs3.here_x + 1][vs3.here_y] = 0;
			break;
		}
		if (arr[vs3.here_x - 1][vs3.here_y] == 7|| arr[vs3.here_x - 1][vs3.here_y] == 2 || arr[vs3.here_x - 1][vs3.here_y] == 6 || arr[vs3.here_x - 1][vs3.here_y] == 8)
		{
			break;
		}
		if (arr[vs3.here_x - 1][vs3.here_y] == 4)
		{
			arr[--vs3.here_x][vs3.here_y] = 7;
			arr[vs3.here_x + 1][vs3.here_y] = 4;
			break;
		}
		arr[--vs3.here_x][vs3.here_y] = 7;
		arr[vs3.here_x + 1][vs3.here_y] = 5;
		break;

	}
	case 8:
	{
		if (arr[vs3.here_x][vs3.here_y + 1] == 1)      //벽에 막힘
			break;

		if (arr[vs3.here_x][vs3.here_y + 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs3.here_x][vs3.here_y + 1] == 0)      //먹이가 바닥에 없는 경우
		{
			arr[vs3.here_x][++vs3.here_y] = 7;
			arr[vs3.here_x][vs3.here_y - 1] = 0;
			break;
		}
		if (arr[vs3.here_x][vs3.here_y + 1] == 7 || arr[vs3.here_x][vs3.here_y + 1] == 2 || arr[vs3.here_x][vs3.here_y + 1] == 6 || arr[vs3.here_x][vs3.here_y + 1] == 8)      //귀신 마주쳤을 때
		{
			break;
		}
		if (arr[vs3.here_x][vs3.here_y + 1] == 4)      //'클로버'가 바닥에 존재하는 경우
		{
			arr[vs3.here_x][++vs3.here_y] = 7;
			arr[vs3.here_x][vs3.here_y - 1] = 4;
			break;
		}

		arr[vs3.here_x][++vs3.here_y] = 7;
		arr[vs3.here_x][vs3.here_y - 1] = 5;
		break;
	}

	case 6:
	{
		if (arr[vs3.here_x][vs3.here_y - 1] == 1)
			break;
		if (arr[vs3.here_x][vs3.here_y - 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs3.here_x][vs3.here_y - 1] == 0)
		{
			arr[vs3.here_x][--vs3.here_y] = 7;
			arr[vs3.here_x][vs3.here_y + 1] = 0;
			break;
		}

		if (arr[vs3.here_x][vs3.here_y - 1] == 7 || arr[vs3.here_x][vs3.here_y - 1] == 2 || arr[vs3.here_x][vs3.here_y - 1] == 6 || arr[vs3.here_x][vs3.here_y - 1] == 8)
		{
			break;
		}

		if (arr[vs3.here_x][vs3.here_y - 1] == 4)
		{
			arr[vs3.here_x][--vs3.here_y] = 7;
			arr[vs3.here_x][vs3.here_y + 1] = 4;
			break;
		}
		arr[vs3.here_x][--vs3.here_y] = 7;
		arr[vs3.here_x][vs3.here_y + 1] = 5;
		break;

	}

	case 5:
	{
		if (arr[vs3.here_x + 1][vs3.here_y] == 1)
			break;

		if (arr[vs3.here_x + 1][vs3.here_y] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		if (arr[vs3.here_x + 1][vs3.here_y] == 0)
		{
			arr[++vs3.here_x][vs3.here_y] = 7;
			arr[vs3.here_x - 1][vs3.here_y] = 0;
			break;
		}
		if (arr[vs3.here_x + 1][vs3.here_y] == 2 || arr[vs3.here_x + 1][vs3.here_y] == 6 || arr[vs3.here_x + 1][vs3.here_y] == 7 || arr[vs3.here_x + 1][vs3.here_y] == 8)
		{
			break;
		}
		if (arr[vs3.here_x + 1][vs3.here_y] == 4)
		{
			arr[++vs3.here_x][vs3.here_y] = 7;
			arr[vs3.here_x - 1][vs3.here_y] = 4;
			break;
		}
		arr[++vs3.here_x][vs3.here_y] = 7;
		arr[vs3.here_x - 1][vs3.here_y] = 5;
		break;

	}
	case 7:
	{
		if (arr[vs3.here_x - 1][vs3.here_y] == 1)
			break;

		if (arr[vs3.here_x - 1][vs3.here_y] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}

			break;
		}
		if (arr[vs3.here_x - 1][vs3.here_y] == 0)
		{
			arr[--vs3.here_x][vs3.here_y] = 7;
			arr[vs3.here_x + 1][vs3.here_y] = 0;
			break;
		}
		if (arr[vs3.here_x - 1][vs3.here_y] == 7 || arr[vs3.here_x - 1][vs3.here_y] == 2 || arr[vs3.here_x - 1][vs3.here_y] == 6 || arr[vs3.here_x - 1][vs3.here_y] == 8)
		{
			break;
		}
		if (arr[vs3.here_x - 1][vs3.here_y] == 4)
		{
			arr[--vs3.here_x][vs3.here_y] = 7;
			arr[vs3.here_x + 1][vs3.here_y] = 4;
			break;
		}
		arr[--vs3.here_x][vs3.here_y] = 7;
		arr[vs3.here_x + 1][vs3.here_y] = 5;
		break;

	}

	}
}
void Ghost_Move4()
{
	int x, temp;

	srand((unsigned)time(NULL));
	x = 0;
	x = rand() % 4 + 1;
	// 1동  2서  3남  4북
	switch (x)
	{
	case 1:
	{
		if (arr[vs4.here_x][vs4.here_y + 1] == 1)      //벽에 막힘
			break;

		if (arr[vs4.here_x][vs4.here_y + 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs4.here_x][vs4.here_y + 1] == 0)      //먹이가 바닥에 없는 경우
		{
			arr[vs4.here_x][++vs4.here_y] = 8;
			arr[vs4.here_x][vs4.here_y - 1] = 0;
			break;
		}
		if (arr[vs4.here_x][vs4.here_y + 1] == 8|| arr[vs4.here_x][vs4.here_y + 1] == 2 || arr[vs4.here_x][vs4.here_y + 1] == 6 || arr[vs4.here_x][vs4.here_y + 1] == 7)      //귀신 마주쳤을 때
		{
			break;
		}
		if (arr[vs4.here_x][vs4.here_y + 1] == 4)      //'클로버'가 바닥에 존재하는 경우
		{
			arr[vs4.here_x][++vs4.here_y] = 8;
			arr[vs4.here_x][vs4.here_y - 1] = 4;
			break;
		}

		arr[vs4.here_x][++vs4.here_y] = 8;
		arr[vs4.here_x][vs4.here_y - 1] = 5;
		break;
	}

	case 2:
	{
		if (arr[vs4.here_x][vs4.here_y - 1] == 1)
			break;

		if (arr[vs4.here_x][vs4.here_y - 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs4.here_x][vs4.here_y - 1] == 0)
		{
			arr[vs4.here_x][--vs4.here_y] = 8;
			arr[vs4.here_x][vs4.here_y + 1] = 0;
			break;
		}

		if (arr[vs4.here_x][vs4.here_y - 1] == 8|| arr[vs4.here_x][vs4.here_y - 1] == 2 || arr[vs4.here_x][vs4.here_y - 1] == 6 || arr[vs4.here_x][vs4.here_y - 1] == 7)
		{
			break;
		}

		if (arr[vs4.here_x][vs4.here_y - 1] == 4)
		{
			arr[vs4.here_x][--vs4.here_y] = 8;
			arr[vs4.here_x][vs4.here_y + 1] = 4;
			break;
		}
		arr[vs4.here_x][--vs4.here_y] = 8;
		arr[vs4.here_x][vs4.here_y + 1] = 5;
		break;

	}

	case 3:
	{
		if (arr[vs4.here_x + 1][vs4.here_y] == 1)
			break;

		if (arr[vs4.here_x+1][vs4.here_y] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		if (arr[vs4.here_x + 1][vs4.here_y] == 0)
		{
			arr[++vs4.here_x][vs4.here_y] = 8;
			arr[vs4.here_x - 1][vs4.here_y] = 0;
			break;
		}
		if (arr[vs4.here_x + 1][vs4.here_y] == 8|| arr[vs4.here_x + 1][vs4.here_y] == 2 || arr[vs4.here_x + 1][vs4.here_y] == 6 || arr[vs4.here_x + 1][vs4.here_y] == 7)
		{
			break;
		}
		if (arr[vs4.here_x + 1][vs4.here_y] == 4)
		{
			arr[++vs4.here_x][vs4.here_y] = 8;
			arr[vs4.here_x - 1][vs4.here_y] = 4;
			break;
		}
		arr[++vs4.here_x][vs4.here_y] = 8;
		arr[vs4.here_x - 1][vs4.here_y] = 5;
		break;

	}
	case 4:
	{
		if (arr[vs4.here_x - 1][vs4.here_y] == 1)
			break;

		if (arr[vs4.here_x-1][vs4.here_y] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		if (arr[vs4.here_x - 1][vs4.here_y] == 0)
		{
			arr[--vs4.here_x][vs4.here_y] = 8;
			arr[vs4.here_x + 1][vs4.here_y] = 0;
			break;
		}
		if (arr[vs4.here_x - 1][vs4.here_y] == 8|| arr[vs4.here_x - 1][vs4.here_y] == 2 || arr[vs4.here_x - 1][vs4.here_y] == 6 || arr[vs4.here_x - 1][vs4.here_y] == 7)
		{
			break;
		}
		if (arr[vs4.here_x - 1][vs4.here_y] == 4)
		{
			arr[--vs4.here_x][vs4.here_y] = 8;
			arr[vs4.here_x + 1][vs4.here_y] = 4;
			break;
		}
		arr[--vs4.here_x][vs4.here_y] = 8;
		arr[vs4.here_x + 1][vs4.here_y] = 5;
		break;

	}
	case 7:
	{
		if (arr[vs4.here_x][vs4.here_y + 1] == 1)      //벽에 막힘
			break;

		if (arr[vs4.here_x][vs4.here_y + 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs4.here_x][vs4.here_y + 1] == 0)      //먹이가 바닥에 없는 경우
		{
			arr[vs4.here_x][++vs4.here_y] = 8;
			arr[vs4.here_x][vs4.here_y - 1] = 0;
			break;
		}
		if (arr[vs4.here_x][vs4.here_y + 1] == 8 || arr[vs4.here_x][vs4.here_y + 1] == 2 || arr[vs4.here_x][vs4.here_y + 1] == 6 || arr[vs4.here_x][vs4.here_y + 1] == 7)      //귀신 마주쳤을 때
		{
			break;
		}
		if (arr[vs4.here_x][vs4.here_y + 1] == 4)      //'클로버'가 바닥에 존재하는 경우
		{
			arr[vs4.here_x][++vs4.here_y] = 8;
			arr[vs4.here_x][vs4.here_y - 1] = 4;
			break;
		}

		arr[vs4.here_x][++vs4.here_y] = 8;
		arr[vs4.here_x][vs4.here_y - 1] = 5;
		break;
	}

	case 6:
	{
		if (arr[vs4.here_x][vs4.here_y - 1] == 1)
			break;

		if (arr[vs4.here_x][vs4.here_y - 1] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}

		if (arr[vs4.here_x][vs4.here_y - 1] == 0)
		{
			arr[vs4.here_x][--vs4.here_y] = 8;
			arr[vs4.here_x][vs4.here_y + 1] = 0;
			break;
		}

		if (arr[vs4.here_x][vs4.here_y - 1] == 8 || arr[vs4.here_x][vs4.here_y - 1] == 2 || arr[vs4.here_x][vs4.here_y - 1] == 6 || arr[vs4.here_x][vs4.here_y - 1] == 7)
		{
			break;
		}

		if (arr[vs4.here_x][vs4.here_y - 1] == 4)
		{
			arr[vs4.here_x][--vs4.here_y] = 8;
			arr[vs4.here_x][vs4.here_y + 1] = 4;
			break;
		}
		arr[vs4.here_x][--vs4.here_y] = 8;
		arr[vs4.here_x][vs4.here_y + 1] = 5;
		break;

	}

	case 5:
	{
		if (arr[vs4.here_x + 1][vs4.here_y] == 1)
			break;

		if (arr[vs4.here_x + 1][vs4.here_y] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		if (arr[vs4.here_x + 1][vs4.here_y] == 0)
		{
			arr[++vs4.here_x][vs4.here_y] = 8;
			arr[vs4.here_x - 1][vs4.here_y] = 0;
			break;
		}
		if (arr[vs4.here_x + 1][vs4.here_y] == 8 || arr[vs4.here_x + 1][vs4.here_y] == 2 || arr[vs4.here_x + 1][vs4.here_y] == 6 || arr[vs4.here_x + 1][vs4.here_y] == 7)
		{
			break;
		}
		if (arr[vs4.here_x + 1][vs4.here_y] == 4)
		{
			arr[++vs4.here_x][vs4.here_y] = 8;
			arr[vs4.here_x - 1][vs4.here_y] = 4;
			break;
		}
		arr[++vs4.here_x][vs4.here_y] = 8;
		arr[vs4.here_x - 1][vs4.here_y] = 5;
		break;

	}
	case 8:
	{
		if (arr[vs4.here_x - 1][vs4.here_y] == 1)
			break;

		if (arr[vs4.here_x - 1][vs4.here_y] == 3)//플레이어를 만났을 때
		{
			Life -= 1; // 라이프가 -1 깎인다.
			if (Life == 0) // 만약 라이프가 0이 된다면
			{
				Death = -10; // 데스판별값 -10을 저장후
				return TRUE; // 종료 값 반환
			}
			break;
		}
		if (arr[vs4.here_x - 1][vs4.here_y] == 0)
		{
			arr[--vs4.here_x][vs4.here_y] = 8;
			arr[vs4.here_x + 1][vs4.here_y] = 0;
			break;
		}
		if (arr[vs4.here_x - 1][vs4.here_y] == 8 || arr[vs4.here_x - 1][vs4.here_y] == 2 || arr[vs4.here_x - 1][vs4.here_y] == 6 || arr[vs4.here_x - 1][vs4.here_y] == 7)
		{
			break;
		}
		if (arr[vs4.here_x - 1][vs4.here_y] == 4)
		{
			arr[--vs4.here_x][vs4.here_y] = 8;
			arr[vs4.here_x + 1][vs4.here_y] = 4;
			break;
		}
		arr[--vs4.here_x][vs4.here_y] = 8;
		arr[vs4.here_x + 1][vs4.here_y] = 5;
		break;

	}

	}
}
