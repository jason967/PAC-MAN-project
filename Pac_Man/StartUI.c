/* ******************************************************
* 프로그램명 : StartUI.c  (전체)
* 작성자 : 2016039026 김민지    조원 : 서재준(팀장), 최재웅, 한지섭, 김민지, 안창호
* 작성일 : 2017.5.28
* 프로그램 설명 : 게임 구동 시 필요한 UI들을 만들어 놓은 소스파일
* 팀명 : 7조 큐피디
********************************************************* */

#include "Pac_Man_external.h"

void UI() { // 게임진행시 출력되는 화면
	printf("\n\n\n\n\n\n\n");
	printf("	      ______    ___    ____           ___  ___  ____ __     _ \n");
	printf("	      | ___ ＼/ _  | /  __ |          |  |/  | / _  || ＼  | |\n");
	printf("	      | |_/  / /_| ||  /  |/  ______  |      |/ /_| ||   ＼| |\n");
	printf("	      |  __/ |  _  ||  |     |______| | | /| ||  _  ||       |\n");
	printf("	      | |    | | | ||  |__/|          | |  | || | | || |＼   |\n");
	printf("	      |_|    |_| |_/ ＼____/          |_|  |_/|_| |_/|_|  ＼_|\n");
}

int Start_Menu() {  // 프로그램을 시작했을때 1,2 선택하는 화면
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

void howtoplay() { // 게임플레이 방법에대한 도움말
	printf("\n\n\n");
	printf(" .-..-. .--. .-.   .-.  .-----. .--.   .---. .-.    .--. .-..-. .--. \n");
	printf(" : :; :: ,. :: :.-.: :  `-. .-': ,. :  : .; :: :   : .; :: :: ::_,. :\n");
	printf(" :    :: :: :: :: :: :    : :  : :: :  :  _.': :   :    :`.  .'  ,','\n");
	printf(" : :: :: :; :: `' `' ;    : :  : :; :  : :   : :__ : :: : .' ;  :_;  \n");
	printf(" :_;:_;`.__.' `.,`.,'     :_;  `.__.'  :_;   :___.':_;:_;:_,'   :_; \n\n");
	printf("   ┌─< Key Instructions >──────────────┐\n");
	printf("   │                │                                │\n");
	printf("   │                │                                │\n");
	printf("   │                │ ⊙ : Player - It's you!        │\n");
	printf("   │   △   : w     │ Ω : Ghost  - Avoid if         │\n");
	printf("   │ ◁  ▷ : a / d │ · : Cookie - Score +10        │\n");
	printf("   │   ▽   : s     │ ♣ : Fruit  - Score +100       │\n");
	printf("   │                │ ♥ : Life   - If all exhausted,│\n");
	printf("   │                │the game ends.                  │\n");
	printf("   │                │                                │\n");
	printf("   └────────┴────────────────┘\n");
	printf("\n");
	gotoxy(40, 25);
}

void Intro() { // 프로그램 실행시 바로 뜨는 화면에서 애니메이션 효과가있는 ui
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
	int i; // 클리어 실패시 뜨는 화면
	char str[30] = { "터어어어어얼렸구나!!!" };
	printf("\n\n\n\n\n\n\n\n");
	printf("	 ______    ___   ___  ___ _____      ____  _    _  _____  ____    \n");
	printf("	/  ___  | / _  | |  |/  ||  ___|   /  _  || |  | ||  ___|| ___ ＼ \n");
	printf("	| |   |_|/ /_| | |      || |___    | | | || |  | || |___ | |_/  / \n");
	printf("	| | |_ ＼|  _  | | | /| ||  ___|   | | | || |  | ||  ___||     /  \n");
	printf("	| |___| || | | | | |  | || |___    | |_/ /| ＼/  || |___ | |＼ ＼ \n");
	printf("	＼_____/ |_| |_/ |_|  |_/|_____/   ＼___/  ＼___/ |____/ |_|  ＼_|\n");

	gotoxy(27, 16);
	printf("＿人人人人人人人人人人人＿\n");
	gotoxy(27, 18);
	printf(">                        <\n");
	gotoxy(27, 20);
	printf("￣Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^￣\n");

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

void CLEAR() { // 클리어 했을 시 뜨는 화면
	char str1[30] = { "┌(*´∀｀*)┘" };
	char str2[30] = { "└(*´∀｀*)┐" };

	printf("\n\n\n\n\n\n\n\n");
	printf("		       ____    _      _____   ___   ____    \n");
	printf("		     /  __ ＼| |    |  ___| / _  || ___ ＼ \n");
	printf("		     | |  | /| |    | |___ / /_| || |_/  / \n");
	printf("		     | |     | |    |  ___||  _  ||     /  \n");
	printf("		     | ＼__/|| |____| |___ | | | || |＼ ＼ \n");
	printf("		      ＼____/|_____/|_____/|_| |_/|_|  ＼_|\n");

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

void End_credit() { // 엔딩크레딧
	printf("\n\n\n");
	printf("         ______    ___    ____           ___  ___  ____ __     _ \n");
	printf("         | ___ ＼/ _  | /  __ |          |  |/  | / _  || ＼  | |\n");
	printf("         | |_/  / /_| ||  /  |/  ______  |      |/ /_| ||   ＼| |\n");
	printf("         |  __/ |  _  ||  |     |______| | | /| ||  _  ||       |\n");
	printf("         | |    | | | ||  |__/|          | |  | || | | || |＼   |\n");
	printf("         |_|    |_| |_/ ＼____/          |_|  |_/|_| |_/|_|  ＼_|");

	gotoxy(10, 9);
	printf("______________________________________________________");
	gotoxy(24, 11);
	printf("      ENDING CREDIT      ");
	gotoxy(10, 12);
	printf("______________________________________________________");
	gotoxy(24, 14);
	printf("프로그램 총괄 팀장 : 서재준");
	gotoxy(24, 16);
	printf("UI   설계  /  구현 : 김민지");
	gotoxy(24, 18);
	printf("이동 설계  /  구현 : 최재웅");
	gotoxy(24, 20);
	printf("이동 설계  /  구현 : 한지섭");
	gotoxy(24, 22);
	printf("요소 설계  /  구현 : 안창호");

	printf("\n");
	gotoxy(40, 25);
}