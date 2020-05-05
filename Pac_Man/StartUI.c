/* ******************************************************
* ���α׷��� : StartUI.c  (��ü)
* �ۼ��� : 2016039026 �����    ���� : ������(����), �����, ������, �����, ��âȣ
* �ۼ��� : 2017.5.28
* ���α׷� ���� : ���� ���� �� �ʿ��� UI���� ����� ���� �ҽ�����
* ���� : 7�� ť�ǵ�
********************************************************* */

#include "Pac_Man_external.h"

void UI() { // ��������� ��µǴ� ȭ��
	printf("\n\n\n\n\n\n\n");
	printf("	      ______    ___    ____           ___  ___  ____ __     _ \n");
	printf("	      | ___ ��/ _  | /  __ |          |  |/  | / _  || ��  | |\n");
	printf("	      | |_/  / /_| ||  /  |/  ______  |      |/ /_| ||   ��| |\n");
	printf("	      |  __/ |  _  ||  |     |______| | | /| ||  _  ||       |\n");
	printf("	      | |    | | | ||  |__/|          | |  | || | | || |��   |\n");
	printf("	      |_|    |_| |_/ ��____/          |_|  |_/|_| |_/|_|  ��_|\n");
}

int Start_Menu() {  // ���α׷��� ���������� 1,2 �����ϴ� ȭ��
	int select = 0;

	while (1) {
		UI();
		Intro();
		system("pause");
		system("cls");

		UI();
		gotoxy(31, 15);
		printf("---- < MENU > ----\n");
		gotoxy(24, 18);
		printf("1. PLAY (Explanation of game)\n");
		gotoxy(24, 19);
		printf("2. EXIT\n");
		gotoxy(22, 21);
		printf("Select : ");

		scanf("%d", &select);

		system("cls");

		switch (select)
		{
		case 1:
			return 0;
		case 2:
			End_credit();
			system("pause");

		default: exit(1);
		}
	}
}

void howtoplay() { // �����÷��� ��������� ����
	printf("\n\n\n");
	printf(" .-..-. .--. .-.   .-.  .-----. .--.   .---. .-.    .--. .-..-. .--. \n");
	printf(" : :; :: ,. :: :.-.: :  `-. .-': ,. :  : .; :: :   : .; :: :: ::_,. :\n");
	printf(" :    :: :: :: :: :: :    : :  : :: :  :  _.': :   :    :`.  .'  ,','\n");
	printf(" : :: :: :; :: `' `' ;    : :  : :; :  : :   : :__ : :: : .' ;  :_;  \n");
	printf(" :_;:_;`.__.' `.,`.,'     :_;  `.__.'  :_;   :___.':_;:_;:_,'   :_; \n\n");
	printf("   ����< Key Instructions >������������������������������\n");
	printf("   ��                ��                                ��\n");
	printf("   ��                ��                                ��\n");
	printf("   ��                �� �� : Player - It's you!        ��\n");
	printf("   ��   ��   : w     �� �� : Ghost  - Avoid if         ��\n");
	printf("   �� ��  �� : a / d �� �� : Cookie - Score +10        ��\n");
	printf("   ��   ��   : s     �� �� : Fruit  - Score +100       ��\n");
	printf("   ��                �� �� : Life   - If all exhausted,��\n");
	printf("   ��                ��the game ends.                  ��\n");
	printf("   ��                ��                                ��\n");
	printf("   ������������������������������������������������������\n");
	printf("\n");
	gotoxy(40, 25);
}

void Intro() { // ���α׷� ����� �ٷ� �ߴ� ȭ�鿡�� �ִϸ��̼� ȿ�����ִ� ui
	char str[30] = { "< TEAM::CUPD >" };

	while (1) {
		if (_kbhit()) {
			if (getch() != NULL) {
				color(7);
				printf("\n\n\t\t    ");
				break;
			}
		}
		else {
			color(14);
			flash(31, 15, str);
		}
	}
}

void GAMEOVER() {
	int i; // Ŭ���� ���н� �ߴ� ȭ��
	char str[30] = { "�;�����ȱ���!!!" };
	printf("\n\n\n\n\n\n\n\n");
	printf("	 ______    ___   ___  ___ _____      ____  _    _  _____  ____    \n");
	printf("	/  ___  | / _  | |  |/  ||  ___|   /  _  || |  | ||  ___|| ___ �� \n");
	printf("	| |   |_|/ /_| | |      || |___    | | | || |  | || |___ | |_/  / \n");
	printf("	| | |_ ��|  _  | | | /| ||  ___|   | | | || |  | ||  ___||     /  \n");
	printf("	| |___| || | | | | |  | || |___    | |_/ /| ��/  || |___ | |�� �� \n");
	printf("	��_____/ |_| |_/ |_|  |_/|_____/   ��___/  ��___/ |____/ |_|  ��_|\n");

	gotoxy(27, 16);
	printf("�����������������������ѣ�\n");
	gotoxy(27, 18);
	printf(">                        <\n");
	gotoxy(27, 20);
	printf("��Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^��\n");

	gotoxy(30, 18);
	for (i = 0; i < 30; i++) {
		if (str[i] == NULL) break;

		printf("%c", str[i]);
		Sleep(80);
	}
	printf("\n");
	gotoxy(40, 25);
	system("pause");
}

void CLEAR() { // Ŭ���� ���� �� �ߴ� ȭ��
	char str1[30] = { "��(*������*)��" };
	char str2[30] = { "��(*������*)��" };

	printf("\n\n\n\n\n\n\n\n");
	printf("		       ____    _      _____   ___   ____    \n");
	printf("		     /  __ ��| |    |  ___| / _  || ___ �� \n");
	printf("		     | |  | /| |    | |___ / /_| || |_/  / \n");
	printf("		     | |     | |    |  ___||  _  ||     /  \n");
	printf("		     | ��__/|| |____| |___ | | | || |�� �� \n");
	printf("		      ��____/|_____/|_____/|_| |_/|_|  ��_|\n");

	while (1) {
		if (_kbhit()) {
			if (getch() != NULL) {
				color(7);
				printf("\n");
				gotoxy(40, 25);
				break;
			}
		}
		else {
			gotoxy(33, 16);
			printf("%s", str1);
			Sleep(TIME);
			gotoxy(33, 16);
			printf("%s", str2);
			Sleep(TIME);
		}
	}
	Sleep(2000);
}

void End_credit() { // ����ũ����
	printf("\n\n\n");
	printf("         ______    ___    ____           ___  ___  ____ __     _ \n");
	printf("         | ___ ��/ _  | /  __ |          |  |/  | / _  || ��  | |\n");
	printf("         | |_/  / /_| ||  /  |/  ______  |      |/ /_| ||   ��| |\n");
	printf("         |  __/ |  _  ||  |     |______| | | /| ||  _  ||       |\n");
	printf("         | |    | | | ||  |__/|          | |  | || | | || |��   |\n");
	printf("         |_|    |_| |_/ ��____/          |_|  |_/|_| |_/|_|  ��_|");

	gotoxy(10, 9);
	printf("______________________________________________________");
	gotoxy(24, 11);
	printf("      ENDING CREDIT      ");
	gotoxy(10, 12);
	printf("______________________________________________________");
	gotoxy(24, 14);
	printf("���α׷� �Ѱ� ���� : ������");
	gotoxy(24, 16);
	printf("UI   ����  /  ���� : �����");
	gotoxy(24, 18);
	printf("�̵� ����  /  ���� : �����");
	gotoxy(24, 20);
	printf("�̵� ����  /  ���� : ������");
	gotoxy(24, 22);
	printf("��� ����  /  ���� : ��âȣ");

	printf("\n");
	gotoxy(40, 25);
}