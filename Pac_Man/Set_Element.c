/* ******************************************************
* ���α׷��� : Set_Element.c  (��ü)
* �ۼ��� : 2013041022 ��âȣ    ���� : ������(����), �����, ������, �����, ��âȣ
* �ۼ��� : 2017.5.28
* ���α׷� ���� : ������Ʈ�� ���� �ʱ�ȭ�� ����ϴ� ���α׷�
* ���� : 7�� ť�ǵ�
********************************************************* */

#include "Pac_Man_external.h"

void Check_Cookie() 
{ // ��Ű��������
	score.Cookie_Num = 0; // �ѹ� ȣ��ɶ����� 0���� �ʱ�ȭ �� ���� ����
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (arr[j][i] == 5)
				score.Cookie_Num += 1; // 0*0~ WIDTH*HEIGHT ���� �� �迭�� ��Ҹ� ���鼭 ��Ű(5)�� ���ö����� +1
		}
	}
}

void Set_Place()
{ // �Ѹǰ� ������ ��ġ�� ���Ѵ�
	me.here_x = 1;
	me.here_y = 1;
	arr[me.here_x][me.here_y] = 3; // �ش� ��ǥ�� �Ѹ��� �ִ´�

	vs1.here_x = 13; // �ش���ǥ�� �ͽ��� ��ġ��Ų��
	vs1.here_y = 8;
	vs2.here_x = 11;
	vs2.here_y = 8;
	vs3.here_x = 11;
	vs3.here_y = 11;
	vs4.here_x = 13;
	vs4.here_y = 11;

	arr[vs1.here_x][vs1.here_y] = 2;
	arr[vs2.here_x][vs2.here_y] = 6;
	arr[vs3.here_x][vs3.here_y] = 7; // �ش� ��ǥ�� ������ �ִ´�
	arr[vs4.here_x][vs4.here_y] = 8;
}

void Init() { // ����� �� ������Ʈ �ʱ�ȭ
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