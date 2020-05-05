/* ******************************************************
* ���α׷��� : Move_Player_Ghost.c  (User_Move, Player_Move)
* �ۼ��� : 2013041049 �����    ���� : ������(����), �����, ������, �����, ��âȣ
* �ۼ��� : 2017.5.28
* ���α׷� ���� : User_Move, Player_Move �Լ��� ����Ͽ� ������� �Է¿����� �Ѹ��� �̵�����
* ���� : 7�� ť�ǵ�
********************************************************* */

#include "Pac_Man_external.h"
void User_Move()
{ // �Ѹǿ����� ����
	int key = 0;
	system("cls");
	howtoplay(); // ���۹��
	system("pause");
	system("cls");
	// ������� �Է¿����� �̵�
	while (1)
	{
		Check_Cookie(); // ��Ű ���� üũ
		Show_map();
		if (kbhit()) do { key = getch(); } while (key == 224); //Ű �Է¹���
		Sleep(40);
		switch (key) // ������� Ű����κ��� ����(Ű)�� �Է� �޴´�
		{
		case 'w': // w�Է½� ������ ����
		{
			Player_Move(me.here_x - 1, me.here_y); // �Ѹ��� ��ġ���� x���� -1 �ؼ� �����ָ� �������� �̵�
			break;
		}
		case 'a': // a �Է½� ������ ����
		{
			Player_Move(me.here_x, me.here_y - 1); // �Ѹ��� ��ġ���� y���� -1 �ؼ� �����ָ� �������� �̵�
			break;
		}
		case 's': // s �Է½� ������ ����
		{
			Player_Move(me.here_x + 1, me.here_y); // �Ѹ��� ��ġ���� x���� +1 �ؼ� �����ָ� �������� �̵�
			break;
		}
		case 'd': // d �Է½� ������ ����
		{
			Player_Move(me.here_x, me.here_y + 1); // �Ѹ��� ��ġ���� y���� +1 �ؼ� �����ָ� �������� �̵�
			break;
		}
		}
		if (Death == -10) // ���� Life�� 0�� �Ǿ��ٸ� �������� Death�� -10�� ��ȯ�Ͽ� ���л��·� ����
		{
			system("cls"); // ȭ�� Ŭ����
			GAMEOVER(); // ���ӿ��� ui ���
			system("cls"); // ȭ�� Ŭ����
			Init();
			Start_Menu(); // ���� �޴��� �ٽ� ���ư�
		}
		if (score.Cookie_Num == 0) // ���� ��Ű������ 0�� �Ǿ��ٸ� �������·� ����
		{
			system("cls"); // ȭ�� Ŭ����
			CLEAR(); // ���� Ŭ���� ui ���
			system("cls"); // ȭ�� Ŭ����
			Init();
			Start_Menu(); // ������ 3���� �ٽ� �ʱ�ȭ�ȴ�.
		}
	}
}

int Player_Move(int x, int y)
{

	Ghost_Move1(); // �ͽ�1�� �̵�
	Ghost_Move2(); // �ͽ�2�� �̵�
	Ghost_Move3(); // �ͽ�3�� �̵�
	Ghost_Move4(); // �ͽ�4�� �̵�

	if (arr[x][y] == 1)
		return FALSE; // ���� �ش���ǥ�� 1(��)�̸� �� �����ٴ� ǥ�÷� ���и� �����Ѵ�

	arr[me.here_x][me.here_y] = 0; // �����̰� �� ���� �ش� ��ǥ�� 0(����)�� ����Ѵ�
	me.here_x = x; // ���������� �޾ƿ� ��ġ�� x���� �Ѹ��� ��ǥ�� �ִ´�.
	me.here_y = y; // ���������� �޾ƿ� ��ġ�� y���� �Ѹ��� ��ǥ�� �ִ´�.

	if (arr[me.here_x][me.here_y] == 5) // ���� ��������ǥ�� 5(��Ű)���?
	{
		arr[me.here_x][me.here_y] = 3; // �ش���ǥ�� �Ѹ��� �̵��Ѵ�
		score.Last_Score += 10; // ��Ű������ 10��
		score.Cookie_Num -= 1; // ��Ű�� ��������� ���� -1��
		gotoxy(53, 15); // ��Ű��� ��ġ�� Ŀ���̵�
		printf("�������� : %d", score.Cookie_Num); // �ش���ġ�� �ش� �� ���
		gotoxy(53, 13);
		printf("���� : %d  ", score.Last_Score); // ���� ���ھ� ���
	}
	if (arr[me.here_x][me.here_y] == 9) // ���� ��������ǥ�� 9(��Ʈ)���?
	{
		arr[me.here_x][me.here_y] = 3; // �ش���ǥ�� �Ѹ��� �̵��Ѵ�
		Life += 1;
		gotoxy(53, 15); // ��Ű��� ��ġ�� Ŀ���̵�
		printf("�������� : %d", score.Cookie_Num); // �ش���ġ�� �ش� �� ���
		gotoxy(53, 13);
		printf("���� : %d  ", score.Last_Score); // ���� ���ھ� ���
	}
	if (arr[me.here_x][me.here_y] == 4) // ���� Ŭ�ι��� ������
	{
		arr[me.here_x][me.here_y] = 3; // �ش���ǥ�� �Ѹ��� �̵��Ѵ�
		score.Last_Score += 100; // ���� 100���� �ö󰣴�.

	}
	if (arr[me.here_x][me.here_y] == 2|| arr[me.here_x][me.here_y] == 6|| arr[me.here_x][me.here_y] == 7|| arr[me.here_x][me.here_y] == 8) // ������ ��������
	{
		arr[me.here_x][me.here_y] = 3; // �ش���ǥ�� �Ѹ��� �̵��Ѵ�.
		Life -= 1; // �������� -1 ���δ�.
		if (Life == 0) // ���� �������� 0�� �ȴٸ�
		{
			Death = -10; // �����Ǻ��� -10�� ������
			return TRUE; // ���� �� ��ȯ
		}
	}
	if (score.Cookie_Num == 99 || (score.Cookie_Num == 9))
		system("cls");

	arr[me.here_x][me.here_y] = 3; // �ش� ��Ҹ� ��ġ���ʰ� �״�� ���ٸ� �ش���ǥ�� �Ѹ��� �̵�
	Show_map(); // 2���� �迭�� ��Ұ� �ٲ�� ��½���
	return TRUE;
}

/* ******************************************************
* ���α׷��� : Move_Player_Ghost.c  (Ghost_Move1~4)
* �ۼ��� : 2013041049 ����� 2013041057 ������  ���� : ������(����), �����, ������, �����, ��âȣ
* �ۼ��� : 2017.5.28
* ���α׷� ���� : �Ѹ��� �̵������� ������ ������ ����
* ���� : 7�� ť�ǵ�
********************************************************* */

void Ghost_Move1()
{
	int x;

	srand((unsigned)time(NULL));
	x = 0;
	x = rand() % 8 + 1;
	// 1��  2��  3��  4��
	switch (x)
	{
	case 1:
	{
		if (arr[vs1.here_x][vs1.here_y + 1] == 1)      //���� ����
			break;
		
		if (arr[vs1.here_x][vs1.here_y + 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
			}
			break;
		}
		
		if (arr[vs1.here_x][vs1.here_y + 1] == 0)      //���̰� �ٴڿ� ���� ���
		{
			arr[vs1.here_x][++vs1.here_y] = 2;
			arr[vs1.here_x][vs1.here_y - 1] = 0;
			break;
		}
		if (arr[vs1.here_x][vs1.here_y + 1] == 2|| arr[vs1.here_x][vs1.here_y + 1] == 6 || arr[vs1.here_x][vs1.here_y + 1] == 7 || arr[vs1.here_x][vs1.here_y + 1] == 8 )      //�ͽ��� ���� ���
		{
			break;
		}
		if (arr[vs1.here_x][vs1.here_y + 1] == 4)      //'Ŭ�ι�'�� �ٴڿ� �����ϴ� ���
		{
			arr[vs1.here_x][++vs1.here_y] = 2;
			arr[vs1.here_x][vs1.here_y - 1] = 4;
			break;
		}
		if (arr[vs1.here_x][vs1.here_y + 1] == 9)      //'��Ʈ'�� �ٴڿ� �����ϴ� ���
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

		if (arr[vs1.here_x][vs1.here_y - 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs1.here_x+1][vs1.here_y ] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs1.here_x-1][vs1.here_y ] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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
		if (arr[vs1.here_x][vs1.here_y + 1] == 1)      //���� ����
			break;

		if (arr[vs1.here_x][vs1.here_y + 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
			}
			break;
		}

		if (arr[vs1.here_x][vs1.here_y + 1] == 0)      //���̰� �ٴڿ� ���� ���
		{
			arr[vs1.here_x][++vs1.here_y] = 2;
			arr[vs1.here_x][vs1.here_y - 1] = 0;
			break;
		}
		if (arr[vs1.here_x][vs1.here_y + 1] == 2 || arr[vs1.here_x][vs1.here_y + 1] == 6 || arr[vs1.here_x][vs1.here_y + 1] == 7 || arr[vs1.here_x][vs1.here_y + 1] == 8)      //�ͽ��� ���� ���
		{
			break;
		}
		if (arr[vs1.here_x][vs1.here_y + 1] == 4)      //'Ŭ�ι�'�� �ٴڿ� �����ϴ� ���
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

		if (arr[vs1.here_x][vs1.here_y - 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs1.here_x + 1][vs1.here_y] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs1.here_x - 1][vs1.here_y] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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
	// 1��  2��  3��  4��
	switch (x)
	{
	case 1:
	{
		if (arr[vs2.here_x][vs2.here_y + 1] == 1)      //���� ����
			break;

		if (arr[vs2.here_x][vs2.here_y + 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
			}
			break;
		}

		if (arr[vs2.here_x][vs2.here_y + 1] == 0)      //���̰� �ٴڿ� ���� ���
		{
			arr[vs2.here_x][++vs2.here_y] = 6;
			arr[vs2.here_x][vs2.here_y - 1] = 0;
			break;
		}
		if (arr[vs2.here_x][vs2.here_y + 1] == 6|| arr[vs1.here_x - 1][vs1.here_y] == 2 || arr[vs1.here_x - 1][vs1.here_y] == 7 || arr[vs1.here_x - 1][vs1.here_y] == 8 )      //���̰� �ٴڿ� ���� ���
		{
			break;
		}
		if (arr[vs2.here_x][vs2.here_y + 1] == 4)      //'Ŭ�ι�'�� �ٴڿ� �����ϴ� ���
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

		if (arr[vs2.here_x][vs2.here_y - 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs2.here_x+1][vs2.here_y] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs2.here_x-1][vs2.here_y ] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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
		if (arr[vs2.here_x][vs2.here_y + 1] == 1)      //���� ����
			break;

		if (arr[vs2.here_x][vs2.here_y + 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
			}
			break;
		}

		if (arr[vs2.here_x][vs2.here_y + 1] == 0)      //���̰� �ٴڿ� ���� ���
		{
			arr[vs2.here_x][++vs2.here_y] = 6;
			arr[vs2.here_x][vs2.here_y - 1] = 0;
			break;
		}
		if (arr[vs2.here_x][vs2.here_y + 1] == 6 || arr[vs1.here_x - 1][vs1.here_y] == 2 || arr[vs1.here_x - 1][vs1.here_y] == 7 || arr[vs1.here_x - 1][vs1.here_y] == 8)      //���̰� �ٴڿ� ���� ���
		{
			break;
		}
		if (arr[vs2.here_x][vs2.here_y + 1] == 4)      //'Ŭ�ι�'�� �ٴڿ� �����ϴ� ���
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

		if (arr[vs2.here_x][vs2.here_y - 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs2.here_x + 1][vs2.here_y] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs2.here_x - 1][vs2.here_y] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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
	// 1��  2��  3��  4��
	switch (x)
	{
	case 1:
	{
		if (arr[vs3.here_x][vs3.here_y + 1] == 1)      //���� ����
			break;

		if (arr[vs3.here_x][vs3.here_y + 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
			}
			break;
		}

		if (arr[vs3.here_x][vs3.here_y + 1] == 0)      //���̰� �ٴڿ� ���� ���
		{
			arr[vs3.here_x][++vs3.here_y] = 7;
			arr[vs3.here_x][vs3.here_y - 1] = 0;
			break;
		}
		if (arr[vs3.here_x][vs3.here_y + 1] == 7|| arr[vs3.here_x][vs3.here_y + 1] == 2 || arr[vs3.here_x][vs3.here_y + 1] == 6 || arr[vs3.here_x][vs3.here_y + 1] == 8)      //�ͽ� �������� ��
		{
			break;
		}
		if (arr[vs3.here_x][vs3.here_y + 1] == 4)      //'Ŭ�ι�'�� �ٴڿ� �����ϴ� ���
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
		if (arr[vs3.here_x][vs3.here_y - 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs3.here_x+1][vs3.here_y] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs3.here_x-1][vs3.here_y ] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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
		if (arr[vs3.here_x][vs3.here_y + 1] == 1)      //���� ����
			break;

		if (arr[vs3.here_x][vs3.here_y + 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
			}
			break;
		}

		if (arr[vs3.here_x][vs3.here_y + 1] == 0)      //���̰� �ٴڿ� ���� ���
		{
			arr[vs3.here_x][++vs3.here_y] = 7;
			arr[vs3.here_x][vs3.here_y - 1] = 0;
			break;
		}
		if (arr[vs3.here_x][vs3.here_y + 1] == 7 || arr[vs3.here_x][vs3.here_y + 1] == 2 || arr[vs3.here_x][vs3.here_y + 1] == 6 || arr[vs3.here_x][vs3.here_y + 1] == 8)      //�ͽ� �������� ��
		{
			break;
		}
		if (arr[vs3.here_x][vs3.here_y + 1] == 4)      //'Ŭ�ι�'�� �ٴڿ� �����ϴ� ���
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
		if (arr[vs3.here_x][vs3.here_y - 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs3.here_x + 1][vs3.here_y] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs3.here_x - 1][vs3.here_y] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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
	// 1��  2��  3��  4��
	switch (x)
	{
	case 1:
	{
		if (arr[vs4.here_x][vs4.here_y + 1] == 1)      //���� ����
			break;

		if (arr[vs4.here_x][vs4.here_y + 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
			}
			break;
		}

		if (arr[vs4.here_x][vs4.here_y + 1] == 0)      //���̰� �ٴڿ� ���� ���
		{
			arr[vs4.here_x][++vs4.here_y] = 8;
			arr[vs4.here_x][vs4.here_y - 1] = 0;
			break;
		}
		if (arr[vs4.here_x][vs4.here_y + 1] == 8|| arr[vs4.here_x][vs4.here_y + 1] == 2 || arr[vs4.here_x][vs4.here_y + 1] == 6 || arr[vs4.here_x][vs4.here_y + 1] == 7)      //�ͽ� �������� ��
		{
			break;
		}
		if (arr[vs4.here_x][vs4.here_y + 1] == 4)      //'Ŭ�ι�'�� �ٴڿ� �����ϴ� ���
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

		if (arr[vs4.here_x][vs4.here_y - 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs4.here_x+1][vs4.here_y] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs4.here_x-1][vs4.here_y] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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
		if (arr[vs4.here_x][vs4.here_y + 1] == 1)      //���� ����
			break;

		if (arr[vs4.here_x][vs4.here_y + 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
			}
			break;
		}

		if (arr[vs4.here_x][vs4.here_y + 1] == 0)      //���̰� �ٴڿ� ���� ���
		{
			arr[vs4.here_x][++vs4.here_y] = 8;
			arr[vs4.here_x][vs4.here_y - 1] = 0;
			break;
		}
		if (arr[vs4.here_x][vs4.here_y + 1] == 8 || arr[vs4.here_x][vs4.here_y + 1] == 2 || arr[vs4.here_x][vs4.here_y + 1] == 6 || arr[vs4.here_x][vs4.here_y + 1] == 7)      //�ͽ� �������� ��
		{
			break;
		}
		if (arr[vs4.here_x][vs4.here_y + 1] == 4)      //'Ŭ�ι�'�� �ٴڿ� �����ϴ� ���
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

		if (arr[vs4.here_x][vs4.here_y - 1] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs4.here_x + 1][vs4.here_y] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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

		if (arr[vs4.here_x - 1][vs4.here_y] == 3)//�÷��̾ ������ ��
		{
			Life -= 1; // �������� -1 ���δ�.
			if (Life == 0) // ���� �������� 0�� �ȴٸ�
			{
				Death = -10; // �����Ǻ��� -10�� ������
				return TRUE; // ���� �� ��ȯ
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
