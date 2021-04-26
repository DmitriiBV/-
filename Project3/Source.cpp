#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#include <conio.h>
#include <windows.h>
#include <iostream>
#include "stdio.h"
#include <iomanip>
#include <math.h>
#include <ctime>


using namespace std;

enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

const int N = 10;
int choice;
char stolbec[N] = { 'А','Б','В','Г','Д','Е','Ж','З','И','К' };

char e[100];

char k;
int s, c, pc_s, pc_c;
int direction, orientation;
int deck;

struct Kletka
{
	char korabl;
	char progress;

}temp[N][N] = {}, pc_temp[N][N] = {};


struct coordinates
{
	int x;
	int y;
};

struct common_flags
{
	int flag;


}motion, pc_motion_, four_deckers, three_deckers, double_deckers, single_deckers, pc_four_deckers, pc_three_deckers, pc_double_deckers, pc_single_deckers;

struct four_decker //четырехпалубник
{
	bool flag;
	coordinates deck_1;
	coordinates deck_2;
	coordinates deck_3;
	coordinates deck_4;
}four_decker, pc_four_decker;


struct three_decker_1
{
	bool flag;
	coordinates deck_1;
	coordinates deck_2;
	coordinates deck_3;
}three_decker_1, pc_three_decker_1;


struct three_decker_2
{
	bool flag;
	coordinates deck_1;
	coordinates deck_2;
	coordinates deck_3;
}three_decker_2, pc_three_decker_2;

struct double_decker_1
{
	bool flag;
	coordinates deck_1;
	coordinates deck_2;
}double_decker_1, pc_double_decker_1;

struct double_decker_2
{
	bool flag;
	coordinates deck_1;
	coordinates deck_2;
}double_decker_2, pc_double_decker_2;

struct double_decker_3
{
	bool flag;
	coordinates deck_1;
	coordinates deck_2;
}double_decker_3, pc_double_decker_3;

struct single_decker_1
{
	bool flag;
	coordinates deck_1;
	coordinates deck_2;
}single_decker_1, pc_single_decker_1;

struct single_decker_2
{
	bool flag;
	coordinates deck_1;
	coordinates deck_2;
}single_decker_2, pc_single_decker_2;

struct single_decker_3
{
	bool flag;
	coordinates deck_1;
	coordinates deck_2;
}single_decker_3, pc_single_decker_3;

struct single_decker_4
{
	bool flag;
	coordinates deck_1;
	coordinates deck_2;
}single_decker_4, pc_single_decker_4;


int pc_place_ship(int s, int c, bool direction, int deck);

int place_ship(int s, int c, bool direction, int deck);

void pc_ship_avto(int deck);

void pc_avto();

void start_game();

void finish();

int end_game();

int pc_check_of_ships();

int check_of_ships();

void pc_motion_blok(int s, int c);

void pc_motion();

void user_motion();


void ship_avto(int deck);

void ship_manual(int s, int c, bool direction, int deck);

void name_game();

void name_game_short();

void cover();

void at_first();

void manual();

void avto();

void placement_user();

void pravila_game();

void menu_game();







int main()
{
	SetConsoleTitleW(L"Морской бой");

	srand(time(0));

	motion.flag = 0;

	cover();

	menu_game();

	//SetConsoleCP(866);
	//SetConsoleOutputCP(866);



	/////////////////////////////////////////////////////



	/*

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j].korabl = 'X';

		}

	}







	ship(4);

	ship(3);
	ship(3);

	ship(2);
	ship(2);
	ship(2);

	ship(1);
	ship(1);
	ship(1);
	ship(1);



	for (int i = 0; i < 256; i++)
	{
		cout << i << " = " << (char)i << " ";
	}



	for (int i = 0; i < N; i++)
	{


		cout << "|";
		for (int j = 0; j < N; j++)
		{
			cout << "" << temp[i][j].korabl << "|";

		}
		cout << endl;
	}

	*/

	if (motion.flag == 0) {
		pc_motion();
	}
	else if (motion.flag == 1) {
		user_motion();
	}
	

	



	if ((four_deckers.flag == 0) && (three_deckers.flag == 0) && (double_deckers.flag == 0) && (single_deckers.flag == 0)) {
		finish();
		cout << endl;
		cout << "ВЫ ПРОИГРАЛИ! ";
	}
	else if ((pc_four_deckers.flag == 0) && (pc_three_deckers.flag == 0) && (pc_double_deckers.flag == 0) && (pc_single_deckers.flag == 0)) {
		finish();
		cout << endl;
		cout << "ПОЗДРАВЛЯЕМ! ВЫ ВЫЙГРАЛИ!!! ";
	}

	cout << endl;
	cout << endl;


	cout << "\t\t\t\t\t\t\t[F1] - Начать игру заново";
	cout << endl;
	cout << "\t\t\t\t\t\t\t[F2] - Выход из игры";
	
	cout << endl;
	cout << endl;

	cout << "\t\t\t\t\t\t\t\t";

	for (;;) {
		choice = _getch();
		if (choice == 59) {
			cout << "F1";
			main();
			break;
		}
		if (choice == 60) {
			cout << "F2";
			exit(1);
			break;
		}
	}

	//system("pause");

	return 0;
}

int pc_place_ship(int s, int c, bool direction, int deck)
{
	int schet = 0;

	if (direction == 0) //горизонтальная позиция корабля
	{

		if (c <= (10 - deck)) //проверка возможности вставки корабля
		{
			//cout << " input 0 ";

			if (s == 0 && c == 0) {
				//cout << " 01 ";
				for (int i = s; i <= s + 1; i++) {
					for (int j = c; j <= deck; j++) {
						if (pc_temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s == 9 && c == 0) {
				//cout << " 02 ";
				for (int i = s; i > s - 2; i--) {
					for (int j = c; j <= deck; j++) {
						if (pc_temp[i][j].korabl == ((char)254)) {
							schet++;
						}
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s == 0 && c != 0 && c != (10 - deck)) {
				//cout << " 03 ";
				for (int i = s; i <= s + 1; i++) {
					for (int j = c - 1; j <= (c - 1 + deck + 1); j++) {
						if (pc_temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s == 9 && c != 0 && c != (10 - deck)) {
				//cout << " 04 ";
				for (int i = s; i > s - 2; i--) {
					for (int j = c - 1; j <= (c - 1 + deck + 1); j++) {
						if (pc_temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s != 0 && c != 0 && s != 9 && c != (10 - deck)) {
				//cout << " 05 ";
				for (int i = s - 1; i <= s + 1; i++) {
					for (int j = c - 1; j <= (c - 1 + deck + 1); j++) {
						if (pc_temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s != 0 && c == 0 && s != 9) {
				//cout << " 06 ";
				for (int i = s - 1; i <= s + 1; i++) {
					for (int j = c; j <= deck; j++) {
						if (pc_temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s == 0 && c == (10 - deck)) {
				//cout << " 07 ";
				for (int i = s; i <= s + 1; i++) {
					for (int j = c - 1; j <= (c - 1 + deck); j++) {
						if (pc_temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s == 9 && c == (10 - deck)) {
				//cout << " 08 ";
				for (int i = s; i > s - 2; i--) {
					for (int j = c - 1; j <= (c - 1 + deck); j++) {
						if (pc_temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s != 0 && s != 9 && c == (10 - deck)) {
				//cout << " 09 ";
				for (int i = s - 1; i <= s + 1; i++) {
					for (int j = c - 1; j <= (c - 1 + deck); j++) {
						if (pc_temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}
		}

		else
		{
			return 1;
		} //ошибка нет места
	}

	else //вертикальная позиция корабля
	{

		if (s <= (10 - deck)) //проверка возможности вставки корабля
		{
			//cout << " input 1 ";

			if (c == 0 && s == 0) {
				//cout << " 11 ";
				for (int i = c; i <= c + 1; i++) {
					for (int j = s; j <= deck; j++) {
						if (pc_temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c == 9 && s == 0) {
				//cout << " 12 ";
				for (int i = c; i > c - 2; i--) {
					for (int j = s; j <= deck; j++) {
						if (pc_temp[j][i].korabl == ((char)254)) {
							schet++;
						}
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c == 0 && s != 0 && s != (10 - deck)) {
				//cout << " 13 ";
				for (int i = c; i <= c + 1; i++) {
					for (int j = s - 1; j <= (s - 1 + deck + 1); j++) {
						if (pc_temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c == 9 && s != 0 && s != (10 - deck)) {
				//cout << " 14 ";
				for (int i = c; i > c - 2; i--) {
					for (int j = s - 1; j <= (s - 1 + deck + 1); j++) {
						if (pc_temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c != 0 && s != 0 && c != 9 && s != (10 - deck)) {
				//cout << " 15 ";
				for (int i = c - 1; i <= c + 1; i++) {
					for (int j = s - 1; j <= (s - 1 + deck + 1); j++) {
						if (pc_temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c != 0 && s == 0 && c != 9) {
				//cout << " 16 ";
				for (int i = c - 1; i <= c + 1; i++) {
					for (int j = s; j <= deck; j++) {
						if (pc_temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c == 0 && s == (10 - deck)) {
				//cout << " 17 ";
				for (int i = c; i <= c + 1; i++) {
					for (int j = s - 1; j <= (s - 1 + deck); j++) {
						if (pc_temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c == 9 && s == (10 - deck)) {
				//cout << " 18 ";
				for (int i = c; i > c - 2; i--) {
					for (int j = s - 1; j <= (s - 1 + deck); j++) {
						if (pc_temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c != 0 && c != 9 && s == (10 - deck)) {
				//cout << " 19 ";
				for (int i = c - 1; i <= c + 1; i++) {
					for (int j = s - 1; j <= (s - 1 + deck); j++) {
						if (pc_temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}
		}

		else
		{
			return 1;
		} //ошибка нет места





	}





}


int place_ship(int s, int c, bool direction, int deck)
{
	int schet = 0;

	if (direction == 0) //горизонтальная позиция корабля
	{

		if (c <= (10 - deck)) //проверка возможности вставки корабля
		{
			//cout << " input 0 ";

			if (s == 0 && c == 0) {
				//cout << " 01 ";
				for (int i = s; i <= s + 1; i++) {
					for (int j = c; j <= deck; j++) {
						if (temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s == 9 && c == 0) {
				//cout << " 02 ";
				for (int i = s; i > s - 2; i--) {
					for (int j = c; j <= deck; j++) {
						if (temp[i][j].korabl == ((char)254)) {
							schet++;
						}
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s == 0 && c != 0 && c != (10 - deck)) {
				//cout << " 03 ";
				for (int i = s; i <= s + 1; i++) {
					for (int j = c - 1; j <= (c - 1 + deck + 1); j++) {
						if (temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s == 9 && c != 0 && c != (10 - deck)) {
				//cout << " 04 ";
				for (int i = s; i > s - 2; i--) {
					for (int j = c - 1; j <= (c - 1 + deck + 1); j++) {
						if (temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s != 0 && c != 0 && s != 9 && c != (10 - deck)) {
				//cout << " 05 ";
				for (int i = s - 1; i <= s + 1; i++) {
					for (int j = c - 1; j <= (c - 1 + deck + 1); j++) {
						if (temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s != 0 && c == 0 && s != 9) {
				//cout << " 06 ";
				for (int i = s - 1; i <= s + 1; i++) {
					for (int j = c; j <= deck; j++) {
						if (temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s == 0 && c == (10 - deck)) {
				//cout << " 07 ";
				for (int i = s; i <= s + 1; i++) {
					for (int j = c - 1; j <= (c - 1 + deck); j++) {
						if (temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s == 9 && c == (10 - deck)) {
				//cout << " 08 ";
				for (int i = s; i > s - 2; i--) {
					for (int j = c - 1; j <= (c - 1 + deck); j++) {
						if (temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (s != 0 && s != 9 && c == (10 - deck)) {
				//cout << " 09 ";
				for (int i = s - 1; i <= s + 1; i++) {
					for (int j = c - 1; j <= (c - 1 + deck); j++) {
						if (temp[i][j].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}
		}

		else
		{
			return 1;
		} //ошибка нет места
	}

	else //вертикальная позиция корабля
	{

		if (s <= (10 - deck)) //проверка возможности вставки корабля
		{
			//cout << " input 1 ";

			if (c == 0 && s == 0) {
				//cout << " 11 ";
				for (int i = c; i <= c + 1; i++) {
					for (int j = s; j <= deck; j++) {
						if (temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c == 9 && s == 0) {
				//cout << " 12 ";
				for (int i = c; i > c - 2; i--) {
					for (int j = s; j <= deck; j++) {
						if (temp[j][i].korabl == ((char)254)) {
							schet++;
						}
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c == 0 && s != 0 && s != (10 - deck)) {
				//cout << " 13 ";
				for (int i = c; i <= c + 1; i++) {
					for (int j = s - 1; j <= (s - 1 + deck + 1); j++) {
						if (temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c == 9 && s != 0 && s != (10 - deck)) {
				//cout << " 14 ";
				for (int i = c; i > c - 2; i--) {
					for (int j = s - 1; j <= (s - 1 + deck + 1); j++) {
						if (temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c != 0 && s != 0 && c != 9 && s != (10 - deck)) {
				//cout << " 15 ";
				for (int i = c - 1; i <= c + 1; i++) {
					for (int j = s - 1; j <= (s - 1 + deck + 1); j++) {
						if (temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c != 0 && s == 0 && c != 9) {
				//cout << " 16 ";
				for (int i = c - 1; i <= c + 1; i++) {
					for (int j = s; j <= deck; j++) {
						if (temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c == 0 && s == (10 - deck)) {
				//cout << " 17 ";
				for (int i = c; i <= c + 1; i++) {
					for (int j = s - 1; j <= (s - 1 + deck); j++) {
						if (temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c == 9 && s == (10 - deck)) {
				//cout << " 18 ";
				for (int i = c; i > c - 2; i--) {
					for (int j = s - 1; j <= (s - 1 + deck); j++) {
						if (temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}

			else if (c != 0 && c != 9 && s == (10 - deck)) {
				//cout << " 19 ";
				for (int i = c - 1; i <= c + 1; i++) {
					for (int j = s - 1; j <= (s - 1 + deck); j++) {
						if (temp[j][i].korabl == ((char)254)) { schet++; }
					}
				}
				if (schet == 0) { return 0; }
				else { return 1; }
			}
		}

		else
		{
			return 1;
		} //ошибка нет места





	}





}

void pc_ship_avto(int deck)
{
	int s, c;
	bool direction;

	pc_four_deckers.flag = pc_four_decker.flag;
	pc_three_deckers.flag = pc_three_decker_1.flag + pc_three_decker_2.flag;
	pc_double_deckers.flag = pc_double_decker_1.flag + pc_double_decker_2.flag + pc_double_decker_3.flag;
	pc_single_deckers.flag = pc_single_decker_1.flag + pc_single_decker_2.flag + pc_single_decker_3.flag + pc_single_decker_4.flag;


	//srand(time(0));



	if (deck == 1) {

		for (;;) {
			direction = rand() % 2;
			s = rand() % 10;
			c = rand() % 10;
			//cout <<"three "<< s << " " << c << " " << direction << " ";
			if (pc_place_ship(s, c, direction, deck) == 0) {
				break;
			}
			else {
				continue;
			}
		}

		if (pc_single_deckers.flag == 0) {

			if (direction == 0) {
				pc_single_decker_1.deck_1.y = s;
				pc_single_decker_1.deck_1.x = c;

				pc_temp[pc_single_decker_1.deck_1.y][pc_single_decker_1.deck_1.x].korabl = 254;

				pc_single_decker_1.flag = 1;
			}
			else {
				pc_single_decker_1.deck_1.x = c;
				pc_single_decker_1.deck_1.y = s;

				pc_temp[pc_single_decker_1.deck_1.y][pc_single_decker_1.deck_1.x].korabl = 254;

				pc_single_decker_1.flag = 1;
			}
		}

		else if (pc_single_deckers.flag == 1) {

			if (direction == 0) {
				pc_single_decker_2.deck_1.y = s;
				pc_single_decker_2.deck_1.x = c;

				pc_temp[pc_single_decker_2.deck_1.y][pc_single_decker_2.deck_1.x].korabl = 254;

				pc_single_decker_2.flag = 1;
			}
			else {
				pc_single_decker_2.deck_1.x = c;
				pc_single_decker_2.deck_1.y = s;

				pc_temp[pc_single_decker_2.deck_1.y][pc_single_decker_2.deck_1.x].korabl = 254;

				pc_single_decker_2.flag = 1;
			}
		}

		else if (pc_single_deckers.flag == 2) {

			if (direction == 0) {
				pc_single_decker_3.deck_1.y = s;
				pc_single_decker_3.deck_1.x = c;

				pc_temp[pc_single_decker_3.deck_1.y][pc_single_decker_3.deck_1.x].korabl = 254;

				pc_single_decker_3.flag = 1;
			}
			else {
				pc_single_decker_3.deck_1.x = c;
				pc_single_decker_3.deck_1.y = s;

				pc_temp[pc_single_decker_3.deck_1.y][pc_single_decker_3.deck_1.x].korabl = 254;

				pc_single_decker_3.flag = 1;
			}
		}

		else if (pc_single_deckers.flag == 3) {

			if (direction == 0) {
				pc_single_decker_4.deck_1.y = s;
				pc_single_decker_4.deck_1.x = c;

				pc_temp[pc_single_decker_4.deck_1.y][pc_single_decker_4.deck_1.x].korabl = 254;

				pc_single_decker_4.flag = 1;

			}
			else {
				pc_single_decker_4.deck_1.x = c;
				pc_single_decker_4.deck_1.y = s;

				pc_temp[pc_single_decker_4.deck_1.y][pc_single_decker_4.deck_1.x].korabl = 254;

				pc_single_decker_4.flag = 1;


			}



		}

	}

	else if (deck == 2) {

		for (;;) {
			direction = rand() % 2;
			s = rand() % 10;
			c = rand() % 10;
			//cout <<"three "<< s << " " << c << " " << direction << " ";
			if (pc_place_ship(s, c, direction, deck) == 0) {
				break;
			}
			else {
				continue;
			}
		}

		if (pc_double_deckers.flag == 0) {

			if (direction == 0) {
				pc_double_decker_1.deck_1.y = pc_double_decker_1.deck_2.y = s;
				pc_double_decker_1.deck_1.x = c;
				pc_double_decker_1.deck_2.x = pc_double_decker_1.deck_1.x + 1;

				pc_temp[pc_double_decker_1.deck_1.y][pc_double_decker_1.deck_1.x].korabl = 254;
				pc_temp[pc_double_decker_1.deck_2.y][pc_double_decker_1.deck_2.x].korabl = 254;

				pc_double_decker_1.flag = 1;
			}
			else {
				pc_double_decker_1.deck_1.x = pc_double_decker_1.deck_2.x = c;
				pc_double_decker_1.deck_1.y = s;
				pc_double_decker_1.deck_2.y = pc_double_decker_1.deck_1.y + 1;

				pc_temp[pc_double_decker_1.deck_1.y][pc_double_decker_1.deck_1.x].korabl = 254;
				pc_temp[pc_double_decker_1.deck_2.y][pc_double_decker_1.deck_2.x].korabl = 254;

				pc_double_decker_1.flag = 1;
			}
		}

		else if (pc_double_deckers.flag == 1) {

			if (direction == 0) {
				pc_double_decker_2.deck_1.y = pc_double_decker_2.deck_2.y = s;
				pc_double_decker_2.deck_1.x = c;
				pc_double_decker_2.deck_2.x = pc_double_decker_2.deck_1.x + 1;

				pc_temp[pc_double_decker_2.deck_1.y][pc_double_decker_2.deck_1.x].korabl = 254;
				pc_temp[pc_double_decker_2.deck_2.y][pc_double_decker_2.deck_2.x].korabl = 254;

				pc_double_decker_2.flag = 1;
			}
			else {
				pc_double_decker_2.deck_1.x = pc_double_decker_2.deck_2.x = c;
				pc_double_decker_2.deck_1.y = s;
				pc_double_decker_2.deck_2.y = pc_double_decker_2.deck_1.y + 1;

				pc_temp[pc_double_decker_2.deck_1.y][pc_double_decker_2.deck_1.x].korabl = 254;
				pc_temp[pc_double_decker_2.deck_2.y][pc_double_decker_2.deck_2.x].korabl = 254;

				pc_double_decker_2.flag = 1;
			}
		}

		else if (pc_double_deckers.flag == 2) {

			if (direction == 0) {
				pc_double_decker_3.deck_1.y = pc_double_decker_3.deck_2.y = s;
				pc_double_decker_3.deck_1.x = c;
				pc_double_decker_3.deck_2.x = pc_double_decker_3.deck_1.x + 1;

				pc_temp[pc_double_decker_3.deck_1.y][pc_double_decker_3.deck_1.x].korabl = 254;
				pc_temp[pc_double_decker_3.deck_2.y][pc_double_decker_3.deck_2.x].korabl = 254;

				pc_double_decker_3.flag = 1;
			}

			else {
				pc_double_decker_3.deck_1.x = pc_double_decker_3.deck_2.x = c;
				pc_double_decker_3.deck_1.y = s;
				pc_double_decker_3.deck_2.y = pc_double_decker_3.deck_1.y + 1;

				pc_temp[pc_double_decker_3.deck_1.y][pc_double_decker_3.deck_1.x].korabl = 254;
				pc_temp[pc_double_decker_3.deck_2.y][pc_double_decker_3.deck_2.x].korabl = 254;

				pc_double_decker_3.flag = 1;

			}
		}




	}

	else if (deck == 3) {

		for (;;) {
			direction = rand() % 2;
			s = rand() % 10;
			c = rand() % 10;
			//cout <<"three "<< s << " " << c << " " << direction << " ";
			if (pc_place_ship(s, c, direction, deck) == 0) {
				break;
			}
			else {
				continue;
			}
		}


		if (pc_three_deckers.flag == 0) {

			if (direction == 0) {
				pc_three_decker_1.deck_1.y = pc_three_decker_1.deck_2.y = pc_three_decker_1.deck_3.y = s;
				pc_three_decker_1.deck_1.x = c;
				pc_three_decker_1.deck_2.x = pc_three_decker_1.deck_1.x + 1;
				pc_three_decker_1.deck_3.x = pc_three_decker_1.deck_2.x + 1;

				pc_temp[pc_three_decker_1.deck_1.y][pc_three_decker_1.deck_1.x].korabl = 254;
				pc_temp[pc_three_decker_1.deck_2.y][pc_three_decker_1.deck_2.x].korabl = 254;
				pc_temp[pc_three_decker_1.deck_3.y][pc_three_decker_1.deck_3.x].korabl = 254;

				pc_three_decker_1.flag = 1;
			}
			else {
				pc_three_decker_1.deck_1.x = pc_three_decker_1.deck_2.x = pc_three_decker_1.deck_3.x = c;
				pc_three_decker_1.deck_1.y = s;
				pc_three_decker_1.deck_2.y = pc_three_decker_1.deck_1.y + 1;
				pc_three_decker_1.deck_3.y = pc_three_decker_1.deck_2.y + 1;

				pc_temp[pc_three_decker_1.deck_1.y][pc_three_decker_1.deck_1.x].korabl = 254;
				pc_temp[pc_three_decker_1.deck_2.y][pc_three_decker_1.deck_2.x].korabl = 254;
				pc_temp[pc_three_decker_1.deck_3.y][pc_three_decker_1.deck_3.x].korabl = 254;

				pc_three_decker_1.flag = 1;
			}
		}

		else if (pc_three_deckers.flag == 1) {

			if (direction == 0) {
				pc_three_decker_2.deck_1.y = pc_three_decker_2.deck_2.y = pc_three_decker_2.deck_3.y = s;
				pc_three_decker_2.deck_1.x = c;
				pc_three_decker_2.deck_2.x = pc_three_decker_2.deck_1.x + 1;
				pc_three_decker_2.deck_3.x = pc_three_decker_2.deck_2.x + 1;

				pc_temp[pc_three_decker_2.deck_1.y][pc_three_decker_2.deck_1.x].korabl = 254;
				pc_temp[pc_three_decker_2.deck_2.y][pc_three_decker_2.deck_2.x].korabl = 254;
				pc_temp[pc_three_decker_2.deck_3.y][pc_three_decker_2.deck_3.x].korabl = 254;

				pc_three_decker_2.flag = 1;
			}
			else {
				pc_three_decker_2.deck_1.x = pc_three_decker_2.deck_2.x = pc_three_decker_2.deck_3.x = c;
				pc_three_decker_2.deck_1.y = s;
				pc_three_decker_2.deck_2.y = pc_three_decker_2.deck_1.y + 1;
				pc_three_decker_2.deck_3.y = pc_three_decker_2.deck_2.y + 1;

				pc_temp[pc_three_decker_2.deck_1.y][pc_three_decker_2.deck_1.x].korabl = 254;
				pc_temp[pc_three_decker_2.deck_2.y][pc_three_decker_2.deck_2.x].korabl = 254;
				pc_temp[pc_three_decker_2.deck_3.y][pc_three_decker_2.deck_3.x].korabl = 254;

				pc_three_decker_2.flag = 1;
			}
		}





	}

	else if (deck == 4) {

		for (;;) {
			direction = rand() % 2;
			s = rand() % 10; c = rand() % 10;
			//cout << "thor " << s << " " << c << " " << direction << " ";
			if (pc_place_ship(s, c, direction, deck) == 0) {
				break;
			}
			else {
				continue;
			}
		}

		if (direction == 0) {
			pc_four_decker.deck_1.y = pc_four_decker.deck_2.y = pc_four_decker.deck_3.y = pc_four_decker.deck_4.y = s;
			pc_four_decker.deck_1.x = c;
			pc_four_decker.deck_2.x = pc_four_decker.deck_1.x + 1;
			pc_four_decker.deck_3.x = pc_four_decker.deck_2.x + 1;
			pc_four_decker.deck_4.x = pc_four_decker.deck_3.x + 1;

			pc_temp[pc_four_decker.deck_1.y][pc_four_decker.deck_1.x].korabl = 254;
			pc_temp[pc_four_decker.deck_2.y][pc_four_decker.deck_2.x].korabl = 254;
			pc_temp[pc_four_decker.deck_3.y][pc_four_decker.deck_3.x].korabl = 254;
			pc_temp[pc_four_decker.deck_4.y][pc_four_decker.deck_4.x].korabl = 254;

			pc_four_decker.flag = 1;


		}
		else {


			pc_four_decker.deck_1.x = pc_four_decker.deck_2.x = pc_four_decker.deck_3.x = pc_four_decker.deck_4.x = c;
			pc_four_decker.deck_1.y = s;
			pc_four_decker.deck_2.y = pc_four_decker.deck_1.y + 1;
			pc_four_decker.deck_3.y = pc_four_decker.deck_2.y + 1;
			pc_four_decker.deck_4.y = pc_four_decker.deck_3.y + 1;

			pc_temp[pc_four_decker.deck_1.y][pc_four_decker.deck_1.x].korabl = 254;
			pc_temp[pc_four_decker.deck_2.y][pc_four_decker.deck_2.x].korabl = 254;
			pc_temp[pc_four_decker.deck_3.y][pc_four_decker.deck_3.x].korabl = 254;
			pc_temp[pc_four_decker.deck_4.y][pc_four_decker.deck_4.x].korabl = 254;

			pc_four_decker.flag = 1;

		}



	}


	pc_four_deckers.flag = pc_four_decker.flag;
	pc_three_deckers.flag = pc_three_decker_1.flag + pc_three_decker_2.flag;
	pc_double_deckers.flag = pc_double_decker_1.flag + pc_double_decker_2.flag + pc_double_decker_3.flag;
	pc_single_deckers.flag = pc_single_decker_1.flag + pc_single_decker_2.flag + pc_single_decker_3.flag + pc_single_decker_4.flag;

}

void pc_avto() {

	pc_ship_avto(4);

	for (int i = 0; i < 2; i++) {
		pc_ship_avto(3);
	}

	for (int i = 0; i < 3; i++) {
		pc_ship_avto(2);
	}

	for (int i = 0; i < 4; i++) {
		pc_ship_avto(1);
	}

}


void start_game() {

	system("cls");

	cout << endl;
	cout << endl;

	//cout << "\t\t\t\t\t";
	cout << "\t";

	cout << "  Компьютер\t\t\t\t  Игрок";

	cout << endl;


	cout << endl;

	//cout << "\t\t\t\t\t";
	cout << "\t";


	cout << "  0 1 2 3 4 5 6 7 8 9\t\t\t  0 1 2 3 4 5 6 7 8 9\n";

	for (int i = 0; i < N; i++)
	{
		//cout << "\t\t\t\t\t";
		cout << "\t";
		cout << stolbec[i] << "";

		cout << "|";
		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		for (int j = 0; j < N; j++)
		{
			//cout << "" << pc_temp[i][j].progress << "|";
			cout << "" << pc_temp[i][j].progress << "|";
		}
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);


		cout << "\t\t\t";
		cout << stolbec[i] << "";

		cout << "|";

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		for (int j = 0; j < N; j++)
		{
			cout << "" << temp[i][j].korabl << "|";

		}
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		cout << endl;
	}

	cout << endl;

	//cout << "\t\t\t\t\t";
	cout << "\t";

	cout << "  Корабли компьютера";

	cout << "\t\t\t";

	cout << "  Корабли игрока";

	cout << endl;
	cout << endl;

	//cout << "\t\t\t\t\t  ";
	cout << "\t  ";

	//cout << "Четырехпалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << pc_four_deckers.flag << "/1";
	cout << " - ";
	cout << (char)254 << " " << (char)254 << " " << (char)254 << " " << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\t\t\t\t  ";


	//cout << "Четырехпалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << four_deckers.flag << "/1";
	cout << " - ";
	cout << (char)254 << " " << (char)254 << " " << (char)254 << " " << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << endl;
	cout << endl;

	//cout << "\t\t\t\t\t  ";
	cout << "\t  ";

	//cout << "Трехпалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << pc_three_deckers.flag << "/2";
	cout << " - ";
	cout << (char)254 << " " << (char)254 << " " << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\t\t\t\t  ";
	//cout << "Трехпалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << three_deckers.flag << "/2";
	cout << " - ";
	cout << (char)254 << " " << (char)254 << " " << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << endl;
	cout << endl;

	//cout << "\t\t\t\t\t  ";
	cout << "\t  ";

	//cout << "Двухпалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << pc_double_deckers.flag << "/3";
	cout << " - ";
	cout << (char)254 << " " << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\t\t\t\t  ";
	//cout << "Двухпалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << double_deckers.flag << "/3";
	cout << " - ";
	cout << (char)254 << " " << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << endl;
	cout << endl;

	//cout << "\t\t\t\t\t  ";
	cout << "\t  ";

	//cout << "Однопалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << pc_single_deckers.flag << "/4";
	cout << " - ";
	cout << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\t\t\t\t  ";
	//cout << "Однопалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << single_deckers.flag << "/4";
	cout << " - ";
	cout << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << endl;
}

void finish() {

	system("cls");

	cout << endl;
	cout << endl;

	cout << "\t\t\t\t\t";

	cout << "  Компьютер\t\t\t\t  Игрок";

	cout << endl;


	cout << endl;

	cout << "\t\t\t\t\t";

	cout << "  0 1 2 3 4 5 6 7 8 9\t\t\t  0 1 2 3 4 5 6 7 8 9\n";

	for (int i = 0; i < N; i++)
	{
		cout << "\t\t\t\t\t";
		cout << stolbec[i] << "";

		cout << "|";
		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		for (int j = 0; j < N; j++)
		{
			//cout << "" << pc_temp[i][j].progress << "|";
			cout << "" << pc_temp[i][j].korabl << "|";
		}
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);


		cout << "\t\t\t";
		cout << stolbec[i] << "";

		cout << "|";

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		for (int j = 0; j < N; j++)
		{
			cout << "" << temp[i][j].korabl << "|";

		}
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		cout << endl;
	}

	cout << endl;

	cout << "\t\t\t\t\t";

	cout << "  Корабли компьютера";

	cout << "\t\t\t";

	cout << "  Корабли игрока";

	cout << endl;
	cout << endl;

	cout << "\t\t\t\t\t  ";
	//cout << "Четырехпалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << pc_four_deckers.flag << "/1";
	cout << " - ";
	cout << (char)254 << " " << (char)254 << " " << (char)254 << " " << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\t\t\t\t  ";

	//cout << "Четырехпалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << four_deckers.flag << "/1";
	cout << " - ";
	cout << (char)254 << " " << (char)254 << " " << (char)254 << " " << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << endl;
	cout << endl;

	cout << "\t\t\t\t\t  ";
	//cout << "Трехпалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << pc_three_deckers.flag << "/2";
	cout << " - ";
	cout << (char)254 << " " << (char)254 << " " << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\t\t\t\t  ";
	//cout << "Трехпалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << three_deckers.flag << "/2";
	cout << " - ";
	cout << (char)254 << " " << (char)254 << " " << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << endl;
	cout << endl;

	cout << "\t\t\t\t\t  ";

	//cout << "Двухпалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << pc_double_deckers.flag << "/3";
	cout << " - ";
	cout << (char)254 << " " << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\t\t\t\t  ";
	//cout << "Двухпалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << double_deckers.flag << "/3";
	cout << " - ";
	cout << (char)254 << " " << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << endl;
	cout << endl;

	cout << "\t\t\t\t\t  ";

	//cout << "Однопалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << pc_single_deckers.flag << "/4";
	cout << " - ";
	cout << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\t\t\t\t  ";
	//cout << "Однопалубный ";
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	cout << single_deckers.flag << "/4";
	cout << " - ";
	cout << (char)254 << "";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << endl;
}


int end_game() {

	//компьютер

	if ((pc_temp[pc_four_decker.deck_1.y][pc_four_decker.deck_1.x].korabl == 'X') && (pc_temp[pc_four_decker.deck_2.y][pc_four_decker.deck_2.x].korabl == 'X')
		&& (pc_temp[pc_four_decker.deck_3.y][pc_four_decker.deck_3.x].korabl == 'X') && (pc_temp[pc_four_decker.deck_4.y][pc_four_decker.deck_4.x].korabl == 'X')) {

		if ((pc_four_decker.deck_1.y + 1 <= 9) && (pc_temp[pc_four_decker.deck_1.y + 1][pc_four_decker.deck_1.x].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_1.y + 1][pc_four_decker.deck_1.x].korabl = '.';
			pc_temp[pc_four_decker.deck_1.y + 1][pc_four_decker.deck_1.x].progress = '.';
		}

		if ((pc_four_decker.deck_1.y - 1 >= 0) && (pc_temp[pc_four_decker.deck_1.y - 1][pc_four_decker.deck_1.x].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_1.y - 1][pc_four_decker.deck_1.x].korabl = '.';
			pc_temp[pc_four_decker.deck_1.y - 1][pc_four_decker.deck_1.x].progress = '.';
		}

		if ((pc_four_decker.deck_1.x + 1 <= 9) && (pc_temp[pc_four_decker.deck_1.y][pc_four_decker.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_1.y][pc_four_decker.deck_1.x + 1].korabl = '.';
			pc_temp[pc_four_decker.deck_1.y][pc_four_decker.deck_1.x + 1].progress = '.';
		}

		if ((pc_four_decker.deck_1.x - 1 >= 0) && (pc_temp[pc_four_decker.deck_1.y][pc_four_decker.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_1.y][pc_four_decker.deck_1.x - 1].korabl = '.';
			pc_temp[pc_four_decker.deck_1.y][pc_four_decker.deck_1.x - 1].progress = '.';
		}

		if ((pc_four_decker.deck_1.y + 1 <= 9) && (pc_four_decker.deck_1.x + 1 <= 9) && (pc_temp[pc_four_decker.deck_1.y + 1][pc_four_decker.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_1.y + 1][pc_four_decker.deck_1.x + 1].korabl = '.';
			pc_temp[pc_four_decker.deck_1.y + 1][pc_four_decker.deck_1.x + 1].progress = '.';
		}

		if ((pc_four_decker.deck_1.y + 1 <= 9) && (pc_four_decker.deck_1.x - 1 >= 0) && (pc_temp[pc_four_decker.deck_1.y + 1][pc_four_decker.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_1.y + 1][pc_four_decker.deck_1.x - 1].korabl = '.';
			pc_temp[pc_four_decker.deck_1.y + 1][pc_four_decker.deck_1.x - 1].progress = '.';
		}

		if ((pc_four_decker.deck_1.y - 1 >= 0) && (pc_four_decker.deck_1.x + 1 <= 9) && (pc_temp[pc_four_decker.deck_1.y - 1][pc_four_decker.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_1.y - 1][pc_four_decker.deck_1.x + 1].korabl = '.';
			pc_temp[pc_four_decker.deck_1.y - 1][pc_four_decker.deck_1.x + 1].progress = '.';
		}

		if ((pc_four_decker.deck_1.y - 1 >= 0) && (pc_four_decker.deck_1.x - 1 >= 0) && (pc_temp[pc_four_decker.deck_1.y - 1][pc_four_decker.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_1.y - 1][pc_four_decker.deck_1.x - 1].korabl = '.';
			pc_temp[pc_four_decker.deck_1.y - 1][pc_four_decker.deck_1.x - 1].progress = '.';
		}

		//2

		if ((pc_four_decker.deck_2.y + 1 <= 9) && (pc_temp[pc_four_decker.deck_2.y + 1][pc_four_decker.deck_2.x].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_2.y + 1][pc_four_decker.deck_2.x].korabl = '.';
			pc_temp[pc_four_decker.deck_2.y + 1][pc_four_decker.deck_2.x].progress = '.';
		}

		if ((pc_four_decker.deck_2.y - 1 >= 0) && (pc_temp[pc_four_decker.deck_2.y - 1][pc_four_decker.deck_2.x].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_2.y - 1][pc_four_decker.deck_2.x].korabl = '.';
			pc_temp[pc_four_decker.deck_2.y - 1][pc_four_decker.deck_2.x].progress = '.';
		}

		if ((pc_four_decker.deck_2.x + 1 <= 9) && (pc_temp[pc_four_decker.deck_2.y][pc_four_decker.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_2.y][pc_four_decker.deck_2.x + 1].korabl = '.';
			pc_temp[pc_four_decker.deck_2.y][pc_four_decker.deck_2.x + 1].progress = '.';
		}

		if ((pc_four_decker.deck_2.x - 1 >= 0) && (pc_temp[pc_four_decker.deck_2.y][pc_four_decker.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_2.y][pc_four_decker.deck_2.x - 1].korabl = '.';
			pc_temp[pc_four_decker.deck_2.y][pc_four_decker.deck_2.x - 1].progress = '.';
		}

		if ((pc_four_decker.deck_2.y + 1 <= 9) && (pc_four_decker.deck_2.x + 1 <= 9) && (pc_temp[pc_four_decker.deck_2.y + 1][pc_four_decker.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_2.y + 1][pc_four_decker.deck_2.x + 1].korabl = '.';
			pc_temp[pc_four_decker.deck_2.y + 1][pc_four_decker.deck_2.x + 1].progress = '.';
		}

		if ((pc_four_decker.deck_2.y + 1 <= 9) && (pc_four_decker.deck_2.x - 1 >= 0) && (pc_temp[pc_four_decker.deck_2.y + 1][pc_four_decker.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_2.y + 1][pc_four_decker.deck_2.x - 1].korabl = '.';
			pc_temp[pc_four_decker.deck_2.y + 1][pc_four_decker.deck_2.x - 1].progress = '.';
		}

		if ((pc_four_decker.deck_2.y - 1 >= 0) && (pc_four_decker.deck_2.x + 1 <= 9) && (pc_temp[pc_four_decker.deck_2.y - 1][pc_four_decker.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_2.y - 1][pc_four_decker.deck_2.x + 1].korabl = '.';
			pc_temp[pc_four_decker.deck_2.y - 1][pc_four_decker.deck_2.x + 1].progress = '.';
		}

		if ((pc_four_decker.deck_2.y - 1 >= 0) && (pc_four_decker.deck_2.x - 1 >= 0) && (pc_temp[pc_four_decker.deck_2.y - 1][pc_four_decker.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_2.y - 1][pc_four_decker.deck_2.x - 1].korabl = '.';
			pc_temp[pc_four_decker.deck_2.y - 1][pc_four_decker.deck_2.x - 1].progress = '.';
		}

		//3

		if ((pc_four_decker.deck_3.y + 1 <= 9) && (pc_temp[pc_four_decker.deck_3.y + 1][pc_four_decker.deck_3.x].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_3.y + 1][pc_four_decker.deck_3.x].korabl = '.';
			pc_temp[pc_four_decker.deck_3.y + 1][pc_four_decker.deck_3.x].progress = '.';
		}

		if ((pc_four_decker.deck_3.y - 1 >= 0) && (pc_temp[pc_four_decker.deck_3.y - 1][pc_four_decker.deck_3.x].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_3.y - 1][pc_four_decker.deck_3.x].korabl = '.';
			pc_temp[pc_four_decker.deck_3.y - 1][pc_four_decker.deck_3.x].progress = '.';
		}

		if ((pc_four_decker.deck_3.x + 1 <= 9) && (pc_temp[pc_four_decker.deck_3.y][pc_four_decker.deck_3.x + 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_3.y][pc_four_decker.deck_3.x + 1].korabl = '.';
			pc_temp[pc_four_decker.deck_3.y][pc_four_decker.deck_3.x + 1].progress = '.';
		}

		if ((pc_four_decker.deck_3.x - 1 >= 0) && (pc_temp[pc_four_decker.deck_3.y][pc_four_decker.deck_3.x - 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_3.y][pc_four_decker.deck_3.x - 1].korabl = '.';
			pc_temp[pc_four_decker.deck_3.y][pc_four_decker.deck_3.x - 1].progress = '.';
		}

		if ((pc_four_decker.deck_3.y + 1 <= 9) && (pc_four_decker.deck_3.x + 1 <= 9) && (pc_temp[pc_four_decker.deck_3.y + 1][pc_four_decker.deck_3.x + 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_3.y + 1][pc_four_decker.deck_3.x + 1].korabl = '.';
			pc_temp[pc_four_decker.deck_3.y + 1][pc_four_decker.deck_3.x + 1].progress = '.';
		}

		if ((pc_four_decker.deck_3.y + 1 <= 9) && (pc_four_decker.deck_3.x - 1 >= 0) && (pc_temp[pc_four_decker.deck_3.y + 1][pc_four_decker.deck_3.x - 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_3.y + 1][pc_four_decker.deck_3.x - 1].korabl = '.';
			pc_temp[pc_four_decker.deck_3.y + 1][pc_four_decker.deck_3.x - 1].progress = '.';
		}

		if ((pc_four_decker.deck_3.y - 1 >= 0) && (pc_four_decker.deck_3.x + 1 <= 9) && (pc_temp[pc_four_decker.deck_3.y - 1][pc_four_decker.deck_3.x + 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_3.y - 1][pc_four_decker.deck_3.x + 1].korabl = '.';
			pc_temp[pc_four_decker.deck_3.y - 1][pc_four_decker.deck_3.x + 1].progress = '.';
		}

		if ((pc_four_decker.deck_3.y - 1 >= 0) && (pc_four_decker.deck_3.x - 1 >= 0) && (pc_temp[pc_four_decker.deck_3.y - 1][pc_four_decker.deck_3.x - 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_3.y - 1][pc_four_decker.deck_3.x - 1].korabl = '.';
			pc_temp[pc_four_decker.deck_3.y - 1][pc_four_decker.deck_3.x - 1].progress = '.';
		}

		//4

		if ((pc_four_decker.deck_4.y + 1 <= 9) && (pc_temp[pc_four_decker.deck_4.y + 1][pc_four_decker.deck_4.x].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_4.y + 1][pc_four_decker.deck_4.x].korabl = '.';
			pc_temp[pc_four_decker.deck_4.y + 1][pc_four_decker.deck_4.x].progress = '.';
		}

		if ((pc_four_decker.deck_4.y - 1 >= 0) && (pc_temp[pc_four_decker.deck_4.y - 1][pc_four_decker.deck_4.x].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_4.y - 1][pc_four_decker.deck_4.x].korabl = '.';
			pc_temp[pc_four_decker.deck_4.y - 1][pc_four_decker.deck_4.x].progress = '.';
		}

		if ((pc_four_decker.deck_4.x + 1 <= 9) && (pc_temp[pc_four_decker.deck_4.y][pc_four_decker.deck_4.x + 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_4.y][pc_four_decker.deck_4.x + 1].korabl = '.';
			pc_temp[pc_four_decker.deck_4.y][pc_four_decker.deck_4.x + 1].progress = '.';
		}

		if ((pc_four_decker.deck_4.x - 1 >= 0) && (pc_temp[pc_four_decker.deck_4.y][pc_four_decker.deck_4.x - 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_4.y][pc_four_decker.deck_4.x - 1].korabl = '.';
			pc_temp[pc_four_decker.deck_4.y][pc_four_decker.deck_4.x - 1].progress = '.';
		}

		if ((pc_four_decker.deck_4.y + 1 <= 9) && (pc_four_decker.deck_4.x + 1 <= 9) && (pc_temp[pc_four_decker.deck_4.y + 1][pc_four_decker.deck_4.x + 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_4.y + 1][pc_four_decker.deck_4.x + 1].korabl = '.';
			pc_temp[pc_four_decker.deck_4.y + 1][pc_four_decker.deck_4.x + 1].progress = '.';
		}

		if ((pc_four_decker.deck_4.y + 1 <= 9) && (pc_four_decker.deck_4.x - 1 >= 0) && (pc_temp[pc_four_decker.deck_4.y + 1][pc_four_decker.deck_4.x - 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_4.y + 1][pc_four_decker.deck_4.x - 1].korabl = '.';
			pc_temp[pc_four_decker.deck_4.y + 1][pc_four_decker.deck_4.x - 1].progress = '.';
		}

		if ((pc_four_decker.deck_4.y - 1 >= 0) && (pc_four_decker.deck_4.x + 1 <= 9) && (pc_temp[pc_four_decker.deck_4.y - 1][pc_four_decker.deck_4.x + 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_4.y - 1][pc_four_decker.deck_4.x + 1].korabl = '.';
			pc_temp[pc_four_decker.deck_4.y - 1][pc_four_decker.deck_4.x + 1].progress = '.';
		}

		if ((pc_four_decker.deck_4.y - 1 >= 0) && (pc_four_decker.deck_4.x - 1 >= 0) && (pc_temp[pc_four_decker.deck_4.y - 1][pc_four_decker.deck_4.x - 1].korabl != 'X')) {

			pc_temp[pc_four_decker.deck_4.y - 1][pc_four_decker.deck_4.x - 1].korabl = '.';
			pc_temp[pc_four_decker.deck_4.y - 1][pc_four_decker.deck_4.x - 1].progress = '.';
		}

		pc_four_decker.flag = 0;

	}


	if ((pc_temp[pc_three_decker_1.deck_1.y][pc_three_decker_1.deck_1.x].korabl == 'X') && (pc_temp[pc_three_decker_1.deck_2.y][pc_three_decker_1.deck_2.x].korabl == 'X')
		&& (pc_temp[pc_three_decker_1.deck_3.y][pc_three_decker_1.deck_3.x].korabl == 'X')) {

		if ((pc_three_decker_1.deck_1.y + 1 <= 9) && (pc_temp[pc_three_decker_1.deck_1.y + 1][pc_three_decker_1.deck_1.x].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_1.y + 1][pc_three_decker_1.deck_1.x].korabl = '.';
			pc_temp[pc_three_decker_1.deck_1.y + 1][pc_three_decker_1.deck_1.x].progress = '.';
		}

		if ((pc_three_decker_1.deck_1.y - 1 >= 0) && (pc_temp[pc_three_decker_1.deck_1.y - 1][pc_three_decker_1.deck_1.x].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_1.y - 1][pc_three_decker_1.deck_1.x].korabl = '.';
			pc_temp[pc_three_decker_1.deck_1.y - 1][pc_three_decker_1.deck_1.x].progress = '.';
		}

		if ((pc_three_decker_1.deck_1.x + 1 <= 9) && (pc_temp[pc_three_decker_1.deck_1.y][pc_three_decker_1.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_1.y][pc_three_decker_1.deck_1.x + 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_1.y][pc_three_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_1.x - 1 >= 0) && (pc_temp[pc_three_decker_1.deck_1.y][pc_three_decker_1.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_1.y][pc_three_decker_1.deck_1.x - 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_1.y][pc_three_decker_1.deck_1.x - 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_1.y + 1 <= 9) && (pc_three_decker_1.deck_1.x + 1 <= 9) && (pc_temp[pc_three_decker_1.deck_1.y + 1][pc_three_decker_1.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_1.y + 1][pc_three_decker_1.deck_1.x + 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_1.y + 1][pc_three_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_1.y + 1 <= 9) && (pc_three_decker_1.deck_1.x - 1 >= 0) && (pc_temp[pc_three_decker_1.deck_1.y + 1][pc_three_decker_1.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_1.y + 1][pc_three_decker_1.deck_1.x - 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_1.y + 1][pc_three_decker_1.deck_1.x - 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_1.y - 1 >= 0) && (pc_three_decker_1.deck_1.x + 1 <= 9) && (pc_temp[pc_three_decker_1.deck_1.y - 1][pc_three_decker_1.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_1.y - 1][pc_three_decker_1.deck_1.x + 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_1.y - 1][pc_three_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_1.y - 1 >= 0) && (pc_three_decker_1.deck_1.x - 1 >= 0) && (pc_temp[pc_three_decker_1.deck_1.y - 1][pc_three_decker_1.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_1.y - 1][pc_three_decker_1.deck_1.x - 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_1.y - 1][pc_three_decker_1.deck_1.x - 1].progress = '.';
		}

		//

		if ((pc_three_decker_1.deck_2.y + 1 <= 9) && (pc_temp[pc_three_decker_1.deck_2.y + 1][pc_three_decker_1.deck_2.x].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_2.y + 1][pc_three_decker_1.deck_2.x].korabl = '.';
			pc_temp[pc_three_decker_1.deck_2.y + 1][pc_three_decker_1.deck_2.x].progress = '.';
		}

		if ((pc_three_decker_1.deck_2.y - 1 >= 0) && (pc_temp[pc_three_decker_1.deck_2.y - 1][pc_three_decker_1.deck_2.x].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_2.y - 1][pc_three_decker_1.deck_2.x].korabl = '.';
			pc_temp[pc_three_decker_1.deck_2.y - 1][pc_three_decker_1.deck_2.x].progress = '.';
		}

		if ((pc_three_decker_1.deck_2.x + 1 <= 9) && (pc_temp[pc_three_decker_1.deck_2.y][pc_three_decker_1.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_2.y][pc_three_decker_1.deck_2.x + 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_2.y][pc_three_decker_1.deck_2.x + 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_2.x - 1 >= 0) && (pc_temp[pc_three_decker_1.deck_2.y][pc_three_decker_1.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_2.y][pc_three_decker_1.deck_2.x - 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_2.y][pc_three_decker_1.deck_2.x - 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_2.y + 1 <= 9) && (pc_three_decker_1.deck_2.x + 1 <= 9) && (pc_temp[pc_three_decker_1.deck_2.y + 1][pc_three_decker_1.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_2.y + 1][pc_three_decker_1.deck_2.x + 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_2.y + 1][pc_three_decker_1.deck_2.x + 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_2.y + 1 <= 9) && (pc_three_decker_1.deck_2.x - 1 >= 0) && (pc_temp[pc_three_decker_1.deck_2.y + 1][pc_three_decker_1.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_2.y + 1][pc_three_decker_1.deck_2.x - 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_2.y + 1][pc_three_decker_1.deck_2.x - 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_2.y - 1 >= 0) && (pc_three_decker_1.deck_2.x + 1 <= 9) && (pc_temp[pc_three_decker_1.deck_2.y - 1][pc_three_decker_1.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_2.y - 1][pc_three_decker_1.deck_2.x + 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_2.y - 1][pc_three_decker_1.deck_2.x + 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_2.y - 1 >= 0) && (pc_three_decker_1.deck_2.x - 1 >= 0) && (pc_temp[pc_three_decker_1.deck_2.y - 1][pc_three_decker_1.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_2.y - 1][pc_three_decker_1.deck_2.x - 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_2.y - 1][pc_three_decker_1.deck_2.x - 1].progress = '.';
		}

		//

		if ((pc_three_decker_1.deck_3.y + 1 <= 9) && (pc_temp[pc_three_decker_1.deck_3.y + 1][pc_three_decker_1.deck_3.x].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_3.y + 1][pc_three_decker_1.deck_3.x].korabl = '.';
			pc_temp[pc_three_decker_1.deck_3.y + 1][pc_three_decker_1.deck_3.x].progress = '.';
		}

		if ((pc_three_decker_1.deck_3.y - 1 >= 0) && (pc_temp[pc_three_decker_1.deck_3.y - 1][pc_three_decker_1.deck_3.x].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_3.y - 1][pc_three_decker_1.deck_3.x].korabl = '.';
			pc_temp[pc_three_decker_1.deck_3.y - 1][pc_three_decker_1.deck_3.x].progress = '.';
		}

		if ((pc_three_decker_1.deck_3.x + 1 <= 9) && (pc_temp[pc_three_decker_1.deck_3.y][pc_three_decker_1.deck_3.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_3.y][pc_three_decker_1.deck_3.x + 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_3.y][pc_three_decker_1.deck_3.x + 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_3.x - 1 >= 0) && (pc_temp[pc_three_decker_1.deck_3.y][pc_three_decker_1.deck_3.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_3.y][pc_three_decker_1.deck_3.x - 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_3.y][pc_three_decker_1.deck_3.x - 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_3.y + 1 <= 9) && (pc_three_decker_1.deck_3.x + 1 <= 9) && (pc_temp[pc_three_decker_1.deck_3.y + 1][pc_three_decker_1.deck_3.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_3.y + 1][pc_three_decker_1.deck_3.x + 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_3.y + 1][pc_three_decker_1.deck_3.x + 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_3.y + 1 <= 9) && (pc_three_decker_1.deck_3.x - 1 >= 0) && (pc_temp[pc_three_decker_1.deck_3.y + 1][pc_three_decker_1.deck_3.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_3.y + 1][pc_three_decker_1.deck_3.x - 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_3.y + 1][pc_three_decker_1.deck_3.x - 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_3.y - 1 >= 0) && (pc_three_decker_1.deck_3.x + 1 <= 9) && (pc_temp[pc_three_decker_1.deck_3.y - 1][pc_three_decker_1.deck_3.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_3.y - 1][pc_three_decker_1.deck_3.x + 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_3.y - 1][pc_three_decker_1.deck_3.x + 1].progress = '.';
		}

		if ((pc_three_decker_1.deck_3.y - 1 >= 0) && (pc_three_decker_1.deck_3.x - 1 >= 0) && (pc_temp[pc_three_decker_1.deck_3.y - 1][pc_three_decker_1.deck_3.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_1.deck_3.y - 1][pc_three_decker_1.deck_3.x - 1].korabl = '.';
			pc_temp[pc_three_decker_1.deck_3.y - 1][pc_three_decker_1.deck_3.x - 1].progress = '.';
		}

		pc_three_decker_1.flag = 0;

	}


	if ((pc_temp[pc_three_decker_2.deck_1.y][pc_three_decker_2.deck_1.x].korabl == 'X') && (pc_temp[pc_three_decker_2.deck_2.y][pc_three_decker_2.deck_2.x].korabl == 'X')
		&& (pc_temp[pc_three_decker_2.deck_3.y][pc_three_decker_2.deck_3.x].korabl == 'X')) {


		if ((pc_three_decker_2.deck_1.y + 1 <= 9) && (pc_temp[pc_three_decker_2.deck_1.y + 1][pc_three_decker_2.deck_1.x].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_1.y + 1][pc_three_decker_2.deck_1.x].korabl = '.';
			pc_temp[pc_three_decker_2.deck_1.y + 1][pc_three_decker_2.deck_1.x].progress = '.';
		}

		if ((pc_three_decker_2.deck_1.y - 1 >= 0) && (pc_temp[pc_three_decker_2.deck_1.y - 1][pc_three_decker_2.deck_1.x].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_1.y - 1][pc_three_decker_2.deck_1.x].korabl = '.';
			pc_temp[pc_three_decker_2.deck_1.y - 1][pc_three_decker_2.deck_1.x].progress = '.';
		}

		if ((pc_three_decker_2.deck_1.x + 1 <= 9) && (pc_temp[pc_three_decker_2.deck_1.y][pc_three_decker_2.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_1.y][pc_three_decker_2.deck_1.x + 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_1.y][pc_three_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_1.x - 1 >= 0) && (pc_temp[pc_three_decker_2.deck_1.y][pc_three_decker_2.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_1.y][pc_three_decker_2.deck_1.x - 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_1.y][pc_three_decker_2.deck_1.x - 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_1.y + 1 <= 9) && (pc_three_decker_2.deck_1.x + 1 <= 9) && (pc_temp[pc_three_decker_2.deck_1.y + 1][pc_three_decker_2.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_1.y + 1][pc_three_decker_2.deck_1.x + 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_1.y + 1][pc_three_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_1.y + 1 <= 9) && (pc_three_decker_2.deck_1.x - 1 >= 0) && (pc_temp[pc_three_decker_2.deck_1.y + 1][pc_three_decker_2.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_1.y + 1][pc_three_decker_2.deck_1.x - 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_1.y + 1][pc_three_decker_2.deck_1.x - 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_1.y - 1 >= 0) && (pc_three_decker_2.deck_1.x + 1 <= 9) && (pc_temp[pc_three_decker_2.deck_1.y - 1][pc_three_decker_2.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_1.y - 1][pc_three_decker_2.deck_1.x + 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_1.y - 1][pc_three_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_1.y - 1 >= 0) && (pc_three_decker_2.deck_1.x - 1 >= 0) && (pc_temp[pc_three_decker_2.deck_1.y - 1][pc_three_decker_2.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_1.y - 1][pc_three_decker_2.deck_1.x - 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_1.y - 1][pc_three_decker_2.deck_1.x - 1].progress = '.';
		}

		//

		if ((pc_three_decker_2.deck_2.y + 1 <= 9) && (pc_temp[pc_three_decker_2.deck_2.y + 1][pc_three_decker_2.deck_2.x].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_2.y + 1][pc_three_decker_2.deck_2.x].korabl = '.';
			pc_temp[pc_three_decker_2.deck_2.y + 1][pc_three_decker_2.deck_2.x].progress = '.';
		}

		if ((pc_three_decker_2.deck_2.y - 1 >= 0) && (pc_temp[pc_three_decker_2.deck_2.y - 1][pc_three_decker_2.deck_2.x].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_2.y - 1][pc_three_decker_2.deck_2.x].korabl = '.';
			pc_temp[pc_three_decker_2.deck_2.y - 1][pc_three_decker_2.deck_2.x].progress = '.';
		}

		if ((pc_three_decker_2.deck_2.x + 1 <= 9) && (pc_temp[pc_three_decker_2.deck_2.y][pc_three_decker_2.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_2.y][pc_three_decker_2.deck_2.x + 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_2.y][pc_three_decker_2.deck_2.x + 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_2.x - 1 >= 0) && (pc_temp[pc_three_decker_2.deck_2.y][pc_three_decker_2.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_2.y][pc_three_decker_2.deck_2.x - 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_2.y][pc_three_decker_2.deck_2.x - 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_2.y + 1 <= 9) && (pc_three_decker_2.deck_2.x + 1 <= 9) && (pc_temp[pc_three_decker_2.deck_2.y + 1][pc_three_decker_2.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_2.y + 1][pc_three_decker_2.deck_2.x + 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_2.y + 1][pc_three_decker_2.deck_2.x + 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_2.y + 1 <= 9) && (pc_three_decker_2.deck_2.x - 1 >= 0) && (pc_temp[pc_three_decker_2.deck_2.y + 1][pc_three_decker_2.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_2.y + 1][pc_three_decker_2.deck_2.x - 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_2.y + 1][pc_three_decker_2.deck_2.x - 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_2.y - 1 >= 0) && (pc_three_decker_2.deck_2.x + 1 <= 9) && (pc_temp[pc_three_decker_2.deck_2.y - 1][pc_three_decker_2.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_2.y - 1][pc_three_decker_2.deck_2.x + 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_2.y - 1][pc_three_decker_2.deck_2.x + 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_2.y - 1 >= 0) && (pc_three_decker_2.deck_2.x - 1 >= 0) && (pc_temp[pc_three_decker_2.deck_2.y - 1][pc_three_decker_2.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_2.y - 1][pc_three_decker_2.deck_2.x - 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_2.y - 1][pc_three_decker_2.deck_2.x - 1].progress = '.';
		}

		//

		if ((pc_three_decker_2.deck_3.y + 1 <= 9) && (pc_temp[pc_three_decker_2.deck_3.y + 1][pc_three_decker_2.deck_3.x].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_3.y + 1][pc_three_decker_2.deck_3.x].korabl = '.';
			pc_temp[pc_three_decker_2.deck_3.y + 1][pc_three_decker_2.deck_3.x].progress = '.';
		}

		if ((pc_three_decker_2.deck_3.y - 1 >= 0) && (pc_temp[pc_three_decker_2.deck_3.y - 1][pc_three_decker_2.deck_3.x].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_3.y - 1][pc_three_decker_2.deck_3.x].korabl = '.';
			pc_temp[pc_three_decker_2.deck_3.y - 1][pc_three_decker_2.deck_3.x].progress = '.';
		}

		if ((pc_three_decker_2.deck_3.x + 1 <= 9) && (pc_temp[pc_three_decker_2.deck_3.y][pc_three_decker_2.deck_3.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_3.y][pc_three_decker_2.deck_3.x + 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_3.y][pc_three_decker_2.deck_3.x + 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_3.x - 1 >= 0) && (pc_temp[pc_three_decker_2.deck_3.y][pc_three_decker_2.deck_3.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_3.y][pc_three_decker_2.deck_3.x - 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_3.y][pc_three_decker_2.deck_3.x - 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_3.y + 1 <= 9) && (pc_three_decker_2.deck_3.x + 1 <= 9) && (pc_temp[pc_three_decker_2.deck_3.y + 1][pc_three_decker_2.deck_3.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_3.y + 1][pc_three_decker_2.deck_3.x + 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_3.y + 1][pc_three_decker_2.deck_3.x + 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_3.y + 1 <= 9) && (pc_three_decker_2.deck_3.x - 1 >= 0) && (pc_temp[pc_three_decker_2.deck_3.y + 1][pc_three_decker_2.deck_3.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_3.y + 1][pc_three_decker_2.deck_3.x - 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_3.y + 1][pc_three_decker_2.deck_3.x - 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_3.y - 1 >= 0) && (pc_three_decker_2.deck_3.x + 1 <= 9) && (pc_temp[pc_three_decker_2.deck_3.y - 1][pc_three_decker_2.deck_3.x + 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_3.y - 1][pc_three_decker_2.deck_3.x + 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_3.y - 1][pc_three_decker_2.deck_3.x + 1].progress = '.';
		}

		if ((pc_three_decker_2.deck_3.y - 1 >= 0) && (pc_three_decker_2.deck_3.x - 1 >= 0) && (pc_temp[pc_three_decker_2.deck_3.y - 1][pc_three_decker_2.deck_3.x - 1].korabl != 'X')) {

			pc_temp[pc_three_decker_2.deck_3.y - 1][pc_three_decker_2.deck_3.x - 1].korabl = '.';
			pc_temp[pc_three_decker_2.deck_3.y - 1][pc_three_decker_2.deck_3.x - 1].progress = '.';
		}

		pc_three_decker_2.flag = 0;

	}


	if ((pc_temp[pc_double_decker_1.deck_1.y][pc_double_decker_1.deck_1.x].korabl == 'X') && (pc_temp[pc_double_decker_1.deck_2.y][pc_double_decker_1.deck_2.x].korabl == 'X')) {


		if ((pc_double_decker_1.deck_1.y + 1 <= 9) && (pc_temp[pc_double_decker_1.deck_1.y + 1][pc_double_decker_1.deck_1.x].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_1.y + 1][pc_double_decker_1.deck_1.x].korabl = '.';
			pc_temp[pc_double_decker_1.deck_1.y + 1][pc_double_decker_1.deck_1.x].progress = '.';
		}

		if ((pc_double_decker_1.deck_1.y - 1 >= 0) && (pc_temp[pc_double_decker_1.deck_1.y - 1][pc_double_decker_1.deck_1.x].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_1.y - 1][pc_double_decker_1.deck_1.x].korabl = '.';
			pc_temp[pc_double_decker_1.deck_1.y - 1][pc_double_decker_1.deck_1.x].progress = '.';
		}

		if ((pc_double_decker_1.deck_1.x + 1 <= 9) && (pc_temp[pc_double_decker_1.deck_1.y][pc_double_decker_1.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_1.y][pc_double_decker_1.deck_1.x + 1].korabl = '.';
			pc_temp[pc_double_decker_1.deck_1.y][pc_double_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((pc_double_decker_1.deck_1.x - 1 >= 0) && (pc_temp[pc_double_decker_1.deck_1.y][pc_double_decker_1.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_1.y][pc_double_decker_1.deck_1.x - 1].korabl = '.';
			pc_temp[pc_double_decker_1.deck_1.y][pc_double_decker_1.deck_1.x - 1].progress = '.';
		}

		if ((pc_double_decker_1.deck_1.y + 1 <= 9) && (pc_double_decker_1.deck_1.x + 1 <= 9) && (pc_temp[pc_double_decker_1.deck_1.y + 1][pc_double_decker_1.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_1.y + 1][pc_double_decker_1.deck_1.x + 1].korabl = '.';
			pc_temp[pc_double_decker_1.deck_1.y + 1][pc_double_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((pc_double_decker_1.deck_1.y + 1 <= 9) && (pc_double_decker_1.deck_1.x - 1 >= 0) && (pc_temp[pc_double_decker_1.deck_1.y + 1][pc_double_decker_1.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_1.y + 1][pc_double_decker_1.deck_1.x - 1].korabl = '.';
			pc_temp[pc_double_decker_1.deck_1.y + 1][pc_double_decker_1.deck_1.x - 1].progress = '.';
		}

		if ((pc_double_decker_1.deck_1.y - 1 >= 0) && (pc_double_decker_1.deck_1.x + 1 <= 9) && (pc_temp[pc_double_decker_1.deck_1.y - 1][pc_double_decker_1.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_1.y - 1][pc_double_decker_1.deck_1.x + 1].korabl = '.';
			pc_temp[pc_double_decker_1.deck_1.y - 1][pc_double_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((pc_double_decker_1.deck_1.y - 1 >= 0) && (pc_double_decker_1.deck_1.x - 1 >= 0) && (pc_temp[pc_double_decker_1.deck_1.y - 1][pc_double_decker_1.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_1.y - 1][pc_double_decker_1.deck_1.x - 1].korabl = '.';
			pc_temp[pc_double_decker_1.deck_1.y - 1][pc_double_decker_1.deck_1.x - 1].progress = '.';
		}

		//

		if ((pc_double_decker_1.deck_2.y + 1 <= 9) && (pc_temp[pc_double_decker_1.deck_2.y + 1][pc_double_decker_1.deck_2.x].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_2.y + 1][pc_double_decker_1.deck_2.x].korabl = '.';
			pc_temp[pc_double_decker_1.deck_2.y + 1][pc_double_decker_1.deck_2.x].progress = '.';
		}

		if ((pc_double_decker_1.deck_2.y - 1 >= 0) && (pc_temp[pc_double_decker_1.deck_2.y - 1][pc_double_decker_1.deck_2.x].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_2.y - 1][pc_double_decker_1.deck_2.x].korabl = '.';
			pc_temp[pc_double_decker_1.deck_2.y - 1][pc_double_decker_1.deck_2.x].progress = '.';
		}

		if ((pc_double_decker_1.deck_2.x + 1 <= 9) && (pc_temp[pc_double_decker_1.deck_2.y][pc_double_decker_1.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_2.y][pc_double_decker_1.deck_2.x + 1].korabl = '.';
			pc_temp[pc_double_decker_1.deck_2.y][pc_double_decker_1.deck_2.x + 1].progress = '.';
		}

		if ((pc_double_decker_1.deck_2.x - 1 >= 0) && (pc_temp[pc_double_decker_1.deck_2.y][pc_double_decker_1.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_2.y][pc_double_decker_1.deck_2.x - 1].korabl = '.';
			pc_temp[pc_double_decker_1.deck_2.y][pc_double_decker_1.deck_2.x - 1].progress = '.';
		}

		if ((pc_double_decker_1.deck_2.y + 1 <= 9) && (pc_double_decker_1.deck_2.x + 1 <= 9) && (pc_temp[pc_double_decker_1.deck_2.y + 1][pc_double_decker_1.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_2.y + 1][pc_double_decker_1.deck_2.x + 1].korabl = '.';
			pc_temp[pc_double_decker_1.deck_2.y + 1][pc_double_decker_1.deck_2.x + 1].progress = '.';
		}

		if ((pc_double_decker_1.deck_2.y + 1 <= 9) && (pc_double_decker_1.deck_2.x - 1 >= 0) && (pc_temp[pc_double_decker_1.deck_2.y + 1][pc_double_decker_1.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_2.y + 1][pc_double_decker_1.deck_2.x - 1].korabl = '.';
			pc_temp[pc_double_decker_1.deck_2.y + 1][pc_double_decker_1.deck_2.x - 1].progress = '.';
		}

		if ((pc_double_decker_1.deck_2.y - 1 >= 0) && (pc_double_decker_1.deck_2.x + 1 <= 9) && (pc_temp[pc_double_decker_1.deck_2.y - 1][pc_double_decker_1.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_2.y - 1][pc_double_decker_1.deck_2.x + 1].korabl = '.';
			pc_temp[pc_double_decker_1.deck_2.y - 1][pc_double_decker_1.deck_2.x + 1].progress = '.';
		}

		if ((pc_double_decker_1.deck_2.y - 1 >= 0) && (pc_double_decker_1.deck_2.x - 1 >= 0) && (pc_temp[pc_double_decker_1.deck_2.y - 1][pc_double_decker_1.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_1.deck_2.y - 1][pc_double_decker_1.deck_2.x - 1].korabl = '.';
			pc_temp[pc_double_decker_1.deck_2.y - 1][pc_double_decker_1.deck_2.x - 1].progress = '.';
		}

		pc_double_decker_1.flag = 0;

	}


	if ((pc_temp[pc_double_decker_2.deck_1.y][pc_double_decker_2.deck_1.x].korabl == 'X') && (pc_temp[pc_double_decker_2.deck_2.y][pc_double_decker_2.deck_2.x].korabl == 'X')) {


		if ((pc_double_decker_2.deck_1.y + 1 <= 9) && (pc_temp[pc_double_decker_2.deck_1.y + 1][pc_double_decker_2.deck_1.x].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_1.y + 1][pc_double_decker_2.deck_1.x].korabl = '.';
			pc_temp[pc_double_decker_2.deck_1.y + 1][pc_double_decker_2.deck_1.x].progress = '.';
		}

		if ((pc_double_decker_2.deck_1.y - 1 >= 0) && (pc_temp[pc_double_decker_2.deck_1.y - 1][pc_double_decker_2.deck_1.x].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_1.y - 1][pc_double_decker_2.deck_1.x].korabl = '.';
			pc_temp[pc_double_decker_2.deck_1.y - 1][pc_double_decker_2.deck_1.x].progress = '.';
		}

		if ((pc_double_decker_2.deck_1.x + 1 <= 9) && (pc_temp[pc_double_decker_2.deck_1.y][pc_double_decker_2.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_1.y][pc_double_decker_2.deck_1.x + 1].korabl = '.';
			pc_temp[pc_double_decker_2.deck_1.y][pc_double_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((pc_double_decker_2.deck_1.x - 1 >= 0) && (pc_temp[pc_double_decker_2.deck_1.y][pc_double_decker_2.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_1.y][pc_double_decker_2.deck_1.x - 1].korabl = '.';
			pc_temp[pc_double_decker_2.deck_1.y][pc_double_decker_2.deck_1.x - 1].progress = '.';
		}

		if ((pc_double_decker_2.deck_1.y + 1 <= 9) && (pc_double_decker_2.deck_1.x + 1 <= 9) && (pc_temp[pc_double_decker_2.deck_1.y + 1][pc_double_decker_2.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_1.y + 1][pc_double_decker_2.deck_1.x + 1].korabl = '.';
			pc_temp[pc_double_decker_2.deck_1.y + 1][pc_double_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((pc_double_decker_2.deck_1.y + 1 <= 9) && (pc_double_decker_2.deck_1.x - 1 >= 0) && (pc_temp[pc_double_decker_2.deck_1.y + 1][pc_double_decker_2.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_1.y + 1][pc_double_decker_2.deck_1.x - 1].korabl = '.';
			pc_temp[pc_double_decker_2.deck_1.y + 1][pc_double_decker_2.deck_1.x - 1].progress = '.';
		}

		if ((pc_double_decker_2.deck_1.y - 1 >= 0) && (pc_double_decker_2.deck_1.x + 1 <= 9) && (pc_temp[pc_double_decker_2.deck_1.y - 1][pc_double_decker_2.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_1.y - 1][pc_double_decker_2.deck_1.x + 1].korabl = '.';
			pc_temp[pc_double_decker_2.deck_1.y - 1][pc_double_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((pc_double_decker_2.deck_1.y - 1 >= 0) && (pc_double_decker_2.deck_1.x - 1 >= 0) && (pc_temp[pc_double_decker_2.deck_1.y - 1][pc_double_decker_2.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_1.y - 1][pc_double_decker_2.deck_1.x - 1].korabl = '.';
			pc_temp[pc_double_decker_2.deck_1.y - 1][pc_double_decker_2.deck_1.x - 1].progress = '.';
		}

		//

		if ((pc_double_decker_2.deck_2.y + 1 <= 9) && (pc_temp[pc_double_decker_2.deck_2.y + 1][pc_double_decker_2.deck_2.x].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_2.y + 1][pc_double_decker_2.deck_2.x].korabl = '.';
			pc_temp[pc_double_decker_2.deck_2.y + 1][pc_double_decker_2.deck_2.x].progress = '.';
		}

		if ((pc_double_decker_2.deck_2.y - 1 >= 0) && (pc_temp[pc_double_decker_2.deck_2.y - 1][pc_double_decker_2.deck_2.x].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_2.y - 1][pc_double_decker_2.deck_2.x].korabl = '.';
			pc_temp[pc_double_decker_2.deck_2.y - 1][pc_double_decker_2.deck_2.x].progress = '.';
		}

		if ((pc_double_decker_2.deck_2.x + 1 <= 9) && (pc_temp[pc_double_decker_2.deck_2.y][pc_double_decker_2.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_2.y][pc_double_decker_2.deck_2.x + 1].korabl = '.';
			pc_temp[pc_double_decker_2.deck_2.y][pc_double_decker_2.deck_2.x + 1].progress = '.';
		}

		if ((pc_double_decker_2.deck_2.x - 1 >= 0) && (pc_temp[pc_double_decker_2.deck_2.y][pc_double_decker_2.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_2.y][pc_double_decker_2.deck_2.x - 1].korabl = '.';
			pc_temp[pc_double_decker_2.deck_2.y][pc_double_decker_2.deck_2.x - 1].progress = '.';
		}

		if ((pc_double_decker_2.deck_2.y + 1 <= 9) && (pc_double_decker_2.deck_2.x + 1 <= 9) && (pc_temp[pc_double_decker_2.deck_2.y + 1][pc_double_decker_2.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_2.y + 1][pc_double_decker_2.deck_2.x + 1].korabl = '.';
			pc_temp[pc_double_decker_2.deck_2.y + 1][pc_double_decker_2.deck_2.x + 1].progress = '.';
		}

		if ((pc_double_decker_2.deck_2.y + 1 <= 9) && (pc_double_decker_2.deck_2.x - 1 >= 0) && (pc_temp[pc_double_decker_2.deck_2.y + 1][pc_double_decker_2.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_2.y + 1][pc_double_decker_2.deck_2.x - 1].korabl = '.';
			pc_temp[pc_double_decker_2.deck_2.y + 1][pc_double_decker_2.deck_2.x - 1].progress = '.';
		}

		if ((pc_double_decker_2.deck_2.y - 1 >= 0) && (pc_double_decker_2.deck_2.x + 1 <= 9) && (pc_temp[pc_double_decker_2.deck_2.y - 1][pc_double_decker_2.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_2.y - 1][pc_double_decker_2.deck_2.x + 1].korabl = '.';
			pc_temp[pc_double_decker_2.deck_2.y - 1][pc_double_decker_2.deck_2.x + 1].progress = '.';
		}

		if ((pc_double_decker_2.deck_2.y - 1 >= 0) && (pc_double_decker_2.deck_2.x - 1 >= 0) && (pc_temp[pc_double_decker_2.deck_2.y - 1][pc_double_decker_2.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_2.deck_2.y - 1][pc_double_decker_2.deck_2.x - 1].korabl = '.';
			pc_temp[pc_double_decker_2.deck_2.y - 1][pc_double_decker_2.deck_2.x - 1].progress = '.';
		}

		pc_double_decker_2.flag = 0;

	}


	if ((pc_temp[pc_double_decker_3.deck_1.y][pc_double_decker_3.deck_1.x].korabl == 'X') && (pc_temp[pc_double_decker_3.deck_2.y][pc_double_decker_3.deck_2.x].korabl == 'X')) {


		if ((pc_double_decker_3.deck_1.y + 1 <= 9) && (pc_temp[pc_double_decker_3.deck_1.y + 1][pc_double_decker_3.deck_1.x].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_1.y + 1][pc_double_decker_3.deck_1.x].korabl = '.';
			pc_temp[pc_double_decker_3.deck_1.y + 1][pc_double_decker_3.deck_1.x].progress = '.';
		}

		if ((pc_double_decker_3.deck_1.y - 1 >= 0) && (pc_temp[pc_double_decker_3.deck_1.y - 1][pc_double_decker_3.deck_1.x].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_1.y - 1][pc_double_decker_3.deck_1.x].korabl = '.';
			pc_temp[pc_double_decker_3.deck_1.y - 1][pc_double_decker_3.deck_1.x].progress = '.';
		}

		if ((pc_double_decker_3.deck_1.x + 1 <= 9) && (pc_temp[pc_double_decker_3.deck_1.y][pc_double_decker_3.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_1.y][pc_double_decker_3.deck_1.x + 1].korabl = '.';
			pc_temp[pc_double_decker_3.deck_1.y][pc_double_decker_3.deck_1.x + 1].progress = '.';
		}

		if ((pc_double_decker_3.deck_1.x - 1 >= 0) && (pc_temp[pc_double_decker_3.deck_1.y][pc_double_decker_3.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_1.y][pc_double_decker_3.deck_1.x - 1].korabl = '.';
			pc_temp[pc_double_decker_3.deck_1.y][pc_double_decker_3.deck_1.x - 1].progress = '.';
		}

		if ((pc_double_decker_3.deck_1.y + 1 <= 9) && (pc_double_decker_3.deck_1.x + 1 <= 9) && (pc_temp[pc_double_decker_3.deck_1.y + 1][pc_double_decker_3.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_1.y + 1][pc_double_decker_3.deck_1.x + 1].korabl = '.';
			pc_temp[pc_double_decker_3.deck_1.y + 1][pc_double_decker_3.deck_1.x + 1].progress = '.';
		}

		if ((pc_double_decker_3.deck_1.y + 1 <= 9) && (pc_double_decker_3.deck_1.x - 1 >= 0) && (pc_temp[pc_double_decker_3.deck_1.y + 1][pc_double_decker_3.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_1.y + 1][pc_double_decker_3.deck_1.x - 1].korabl = '.';
			pc_temp[pc_double_decker_3.deck_1.y + 1][pc_double_decker_3.deck_1.x - 1].progress = '.';
		}

		if ((pc_double_decker_3.deck_1.y - 1 >= 0) && (pc_double_decker_3.deck_1.x + 1 <= 9) && (pc_temp[pc_double_decker_3.deck_1.y - 1][pc_double_decker_3.deck_1.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_1.y - 1][pc_double_decker_3.deck_1.x + 1].korabl = '.';
			pc_temp[pc_double_decker_3.deck_1.y - 1][pc_double_decker_3.deck_1.x + 1].progress = '.';
		}

		if ((pc_double_decker_3.deck_1.y - 1 >= 0) && (pc_double_decker_3.deck_1.x - 1 >= 0) && (pc_temp[pc_double_decker_3.deck_1.y - 1][pc_double_decker_3.deck_1.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_1.y - 1][pc_double_decker_3.deck_1.x - 1].korabl = '.';
			pc_temp[pc_double_decker_3.deck_1.y - 1][pc_double_decker_3.deck_1.x - 1].progress = '.';
		}

		//

		if ((pc_double_decker_3.deck_2.y + 1 <= 9) && (pc_temp[pc_double_decker_3.deck_2.y + 1][pc_double_decker_3.deck_2.x].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_2.y + 1][pc_double_decker_3.deck_2.x].korabl = '.';
			pc_temp[pc_double_decker_3.deck_2.y + 1][pc_double_decker_3.deck_2.x].progress = '.';
		}

		if ((pc_double_decker_3.deck_2.y - 1 >= 0) && (pc_temp[pc_double_decker_3.deck_2.y - 1][pc_double_decker_3.deck_2.x].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_2.y - 1][pc_double_decker_3.deck_2.x].korabl = '.';
			pc_temp[pc_double_decker_3.deck_2.y - 1][pc_double_decker_3.deck_2.x].progress = '.';
		}

		if ((pc_double_decker_3.deck_2.x + 1 <= 9) && (pc_temp[pc_double_decker_3.deck_2.y][pc_double_decker_3.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_2.y][pc_double_decker_3.deck_2.x + 1].korabl = '.';
			pc_temp[pc_double_decker_3.deck_2.y][pc_double_decker_3.deck_2.x + 1].progress = '.';
		}

		if ((pc_double_decker_3.deck_2.x - 1 >= 0) && (pc_temp[pc_double_decker_3.deck_2.y][pc_double_decker_3.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_2.y][pc_double_decker_3.deck_2.x - 1].korabl = '.';
			pc_temp[pc_double_decker_3.deck_2.y][pc_double_decker_3.deck_2.x - 1].progress = '.';
		}

		if ((pc_double_decker_3.deck_2.y + 1 <= 9) && (pc_double_decker_3.deck_2.x + 1 <= 9) && (pc_temp[pc_double_decker_3.deck_2.y + 1][pc_double_decker_3.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_2.y + 1][pc_double_decker_3.deck_2.x + 1].korabl = '.';
			pc_temp[pc_double_decker_3.deck_2.y + 1][pc_double_decker_3.deck_2.x + 1].progress = '.';
		}

		if ((pc_double_decker_3.deck_2.y + 1 <= 9) && (pc_double_decker_3.deck_2.x - 1 >= 0) && (pc_temp[pc_double_decker_3.deck_2.y + 1][pc_double_decker_3.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_2.y + 1][pc_double_decker_3.deck_2.x - 1].korabl = '.';
			pc_temp[pc_double_decker_3.deck_2.y + 1][pc_double_decker_3.deck_2.x - 1].progress = '.';
		}

		if ((pc_double_decker_3.deck_2.y - 1 >= 0) && (pc_double_decker_3.deck_2.x + 1 <= 9) && (pc_temp[pc_double_decker_3.deck_2.y - 1][pc_double_decker_3.deck_2.x + 1].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_2.y - 1][pc_double_decker_3.deck_2.x + 1].korabl = '.';
			pc_temp[pc_double_decker_3.deck_2.y - 1][pc_double_decker_3.deck_2.x + 1].progress = '.';
		}

		if ((pc_double_decker_3.deck_2.y - 1 >= 0) && (pc_double_decker_3.deck_2.x - 1 >= 0) && (pc_temp[pc_double_decker_3.deck_2.y - 1][pc_double_decker_3.deck_2.x - 1].korabl != 'X')) {

			pc_temp[pc_double_decker_3.deck_2.y - 1][pc_double_decker_3.deck_2.x - 1].korabl = '.';
			pc_temp[pc_double_decker_3.deck_2.y - 1][pc_double_decker_3.deck_2.x - 1].progress = '.';
		}

		pc_double_decker_3.flag = 0;

	}


	if (pc_temp[pc_single_decker_1.deck_1.y][pc_single_decker_1.deck_1.x].korabl == 'X') {

		if (pc_single_decker_1.deck_1.y + 1 <= 9) {
			pc_temp[pc_single_decker_1.deck_1.y + 1][pc_single_decker_1.deck_1.x].korabl = '.';
			pc_temp[pc_single_decker_1.deck_1.y + 1][pc_single_decker_1.deck_1.x].progress = '.';
		}

		if (pc_single_decker_1.deck_1.y - 1 >= 0) {
			pc_temp[pc_single_decker_1.deck_1.y - 1][pc_single_decker_1.deck_1.x].korabl = '.';
			pc_temp[pc_single_decker_1.deck_1.y - 1][pc_single_decker_1.deck_1.x].progress = '.';
		}

		if (pc_single_decker_1.deck_1.x + 1 <= 9) {
			pc_temp[pc_single_decker_1.deck_1.y][pc_single_decker_1.deck_1.x + 1].korabl = '.';
			pc_temp[pc_single_decker_1.deck_1.y][pc_single_decker_1.deck_1.x + 1].progress = '.';
		}

		if (pc_single_decker_1.deck_1.x - 1 >= 0) {
			pc_temp[pc_single_decker_1.deck_1.y][pc_single_decker_1.deck_1.x - 1].korabl = '.';
			pc_temp[pc_single_decker_1.deck_1.y][pc_single_decker_1.deck_1.x - 1].progress = '.';
		}

		if ((pc_single_decker_1.deck_1.y + 1 <= 9) && (pc_single_decker_1.deck_1.x + 1 <= 9)) {
			pc_temp[pc_single_decker_1.deck_1.y + 1][pc_single_decker_1.deck_1.x + 1].korabl = '.';
			pc_temp[pc_single_decker_1.deck_1.y + 1][pc_single_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((pc_single_decker_1.deck_1.y + 1 <= 9) && (pc_single_decker_1.deck_1.x - 1 >= 0)) {
			pc_temp[pc_single_decker_1.deck_1.y + 1][pc_single_decker_1.deck_1.x - 1].korabl = '.';
			pc_temp[pc_single_decker_1.deck_1.y + 1][pc_single_decker_1.deck_1.x - 1].progress = '.';
		}

		if ((pc_single_decker_1.deck_1.y - 1 >= 0) && (pc_single_decker_1.deck_1.x + 1 <= 9)) {
			pc_temp[pc_single_decker_1.deck_1.y - 1][pc_single_decker_1.deck_1.x + 1].korabl = '.';
			pc_temp[pc_single_decker_1.deck_1.y - 1][pc_single_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((pc_single_decker_1.deck_1.y - 1 >= 0) && (pc_single_decker_1.deck_1.x - 1 >= 0)) {
			pc_temp[pc_single_decker_1.deck_1.y - 1][pc_single_decker_1.deck_1.x - 1].korabl = '.';
			pc_temp[pc_single_decker_1.deck_1.y - 1][pc_single_decker_1.deck_1.x - 1].progress = '.';
		}



		pc_single_decker_1.flag = 0;

	}


	if (pc_temp[pc_single_decker_2.deck_1.y][pc_single_decker_2.deck_1.x].korabl == 'X') {

		if (pc_single_decker_2.deck_1.y + 1 <= 9) {
			pc_temp[pc_single_decker_2.deck_1.y + 1][pc_single_decker_2.deck_1.x].korabl = '.';
			pc_temp[pc_single_decker_2.deck_1.y + 1][pc_single_decker_2.deck_1.x].progress = '.';
		}

		if (pc_single_decker_2.deck_1.y - 1 >= 0) {
			pc_temp[pc_single_decker_2.deck_1.y - 1][pc_single_decker_2.deck_1.x].korabl = '.';
			pc_temp[pc_single_decker_2.deck_1.y - 1][pc_single_decker_2.deck_1.x].progress = '.';
		}

		if (pc_single_decker_2.deck_1.x + 1 <= 9) {
			pc_temp[pc_single_decker_2.deck_1.y][pc_single_decker_2.deck_1.x + 1].korabl = '.';
			pc_temp[pc_single_decker_2.deck_1.y][pc_single_decker_2.deck_1.x + 1].progress = '.';
		}

		if (pc_single_decker_2.deck_1.x - 1 >= 0) {
			pc_temp[pc_single_decker_2.deck_1.y][pc_single_decker_2.deck_1.x - 1].korabl = '.';
			pc_temp[pc_single_decker_2.deck_1.y][pc_single_decker_2.deck_1.x - 1].progress = '.';
		}

		if ((pc_single_decker_2.deck_1.y + 1 <= 9) && (pc_single_decker_2.deck_1.x + 1 <= 9)) {
			pc_temp[pc_single_decker_2.deck_1.y + 1][pc_single_decker_2.deck_1.x + 1].korabl = '.';
			pc_temp[pc_single_decker_2.deck_1.y + 1][pc_single_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((pc_single_decker_2.deck_1.y + 1 <= 9) && (pc_single_decker_2.deck_1.x - 1 >= 0)) {
			pc_temp[pc_single_decker_2.deck_1.y + 1][pc_single_decker_2.deck_1.x - 1].korabl = '.';
			pc_temp[pc_single_decker_2.deck_1.y + 1][pc_single_decker_2.deck_1.x - 1].progress = '.';
		}

		if ((pc_single_decker_2.deck_1.y - 1 >= 0) && (pc_single_decker_2.deck_1.x + 1 <= 9)) {
			pc_temp[pc_single_decker_2.deck_1.y - 1][pc_single_decker_2.deck_1.x + 1].korabl = '.';
			pc_temp[pc_single_decker_2.deck_1.y - 1][pc_single_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((pc_single_decker_2.deck_1.y - 1 >= 0) && (pc_single_decker_2.deck_1.x - 1 >= 0)) {
			pc_temp[pc_single_decker_2.deck_1.y - 1][pc_single_decker_2.deck_1.x - 1].korabl = '.';
			pc_temp[pc_single_decker_2.deck_1.y - 1][pc_single_decker_2.deck_1.x - 1].progress = '.';
		}




		pc_single_decker_2.flag = 0;

	}


	if (pc_temp[pc_single_decker_3.deck_1.y][pc_single_decker_3.deck_1.x].korabl == 'X') {

		if (pc_single_decker_3.deck_1.y + 1 <= 9) {
			pc_temp[pc_single_decker_3.deck_1.y + 1][pc_single_decker_3.deck_1.x].korabl = '.';
			pc_temp[pc_single_decker_3.deck_1.y + 1][pc_single_decker_3.deck_1.x].progress = '.';
		}

		if (pc_single_decker_3.deck_1.y - 1 >= 0) {
			pc_temp[pc_single_decker_3.deck_1.y - 1][pc_single_decker_3.deck_1.x].korabl = '.';
			pc_temp[pc_single_decker_3.deck_1.y - 1][pc_single_decker_3.deck_1.x].progress = '.';
		}

		if (pc_single_decker_3.deck_1.x + 1 <= 9) {
			pc_temp[pc_single_decker_3.deck_1.y][pc_single_decker_3.deck_1.x + 1].korabl = '.';
			pc_temp[pc_single_decker_3.deck_1.y][pc_single_decker_3.deck_1.x + 1].progress = '.';
		}

		if (pc_single_decker_3.deck_1.x - 1 >= 0) {
			pc_temp[pc_single_decker_3.deck_1.y][pc_single_decker_3.deck_1.x - 1].korabl = '.';
			pc_temp[pc_single_decker_3.deck_1.y][pc_single_decker_3.deck_1.x - 1].progress = '.';
		}

		if ((pc_single_decker_3.deck_1.y + 1 <= 9) && (pc_single_decker_3.deck_1.x + 1 <= 9)) {
			pc_temp[pc_single_decker_3.deck_1.y + 1][pc_single_decker_3.deck_1.x + 1].korabl = '.';
			pc_temp[pc_single_decker_3.deck_1.y + 1][pc_single_decker_3.deck_1.x + 1].progress = '.';
		}

		if ((pc_single_decker_3.deck_1.y + 1 <= 9) && (pc_single_decker_3.deck_1.x - 1 >= 0)) {
			pc_temp[pc_single_decker_3.deck_1.y + 1][pc_single_decker_3.deck_1.x - 1].korabl = '.';
			pc_temp[pc_single_decker_3.deck_1.y + 1][pc_single_decker_3.deck_1.x - 1].progress = '.';
		}

		if ((pc_single_decker_3.deck_1.y - 1 >= 0) && (pc_single_decker_3.deck_1.x + 1 <= 9)) {
			pc_temp[pc_single_decker_3.deck_1.y - 1][pc_single_decker_3.deck_1.x + 1].korabl = '.';
			pc_temp[pc_single_decker_3.deck_1.y - 1][pc_single_decker_3.deck_1.x + 1].progress = '.';
		}

		if ((pc_single_decker_3.deck_1.y - 1 >= 0) && (pc_single_decker_3.deck_1.x - 1 >= 0)) {
			pc_temp[pc_single_decker_3.deck_1.y - 1][pc_single_decker_3.deck_1.x - 1].korabl = '.';
			pc_temp[pc_single_decker_3.deck_1.y - 1][pc_single_decker_3.deck_1.x - 1].progress = '.';
		}




		pc_single_decker_3.flag = 0;

	}


	if (pc_temp[pc_single_decker_4.deck_1.y][pc_single_decker_4.deck_1.x].korabl == 'X') {

		if (pc_single_decker_4.deck_1.y + 1 <= 9) {
			pc_temp[pc_single_decker_4.deck_1.y + 1][pc_single_decker_4.deck_1.x].korabl = '.';
			pc_temp[pc_single_decker_4.deck_1.y + 1][pc_single_decker_4.deck_1.x].progress = '.';
		}

		if (pc_single_decker_4.deck_1.y - 1 >= 0) {
			pc_temp[pc_single_decker_4.deck_1.y - 1][pc_single_decker_4.deck_1.x].korabl = '.';
			pc_temp[pc_single_decker_4.deck_1.y - 1][pc_single_decker_4.deck_1.x].progress = '.';
		}

		if (pc_single_decker_4.deck_1.x + 1 <= 9) {
			pc_temp[pc_single_decker_4.deck_1.y][pc_single_decker_4.deck_1.x + 1].korabl = '.';
			pc_temp[pc_single_decker_4.deck_1.y][pc_single_decker_4.deck_1.x + 1].progress = '.';
		}

		if (pc_single_decker_4.deck_1.x - 1 >= 0) {
			pc_temp[pc_single_decker_4.deck_1.y][pc_single_decker_4.deck_1.x - 1].korabl = '.';
			pc_temp[pc_single_decker_4.deck_1.y][pc_single_decker_4.deck_1.x - 1].progress = '.';
		}

		if ((pc_single_decker_4.deck_1.y + 1 <= 9) && (pc_single_decker_4.deck_1.x + 1 <= 9)) {
			pc_temp[pc_single_decker_4.deck_1.y + 1][pc_single_decker_4.deck_1.x + 1].korabl = '.';
			pc_temp[pc_single_decker_4.deck_1.y + 1][pc_single_decker_4.deck_1.x + 1].progress = '.';
		}

		if ((pc_single_decker_4.deck_1.y + 1 <= 9) && (pc_single_decker_4.deck_1.x - 1 >= 0)) {
			pc_temp[pc_single_decker_4.deck_1.y + 1][pc_single_decker_4.deck_1.x - 1].korabl = '.';
			pc_temp[pc_single_decker_4.deck_1.y + 1][pc_single_decker_4.deck_1.x - 1].progress = '.';
		}

		if ((pc_single_decker_4.deck_1.y - 1 >= 0) && (pc_single_decker_4.deck_1.x + 1 <= 9)) {
			pc_temp[pc_single_decker_4.deck_1.y - 1][pc_single_decker_4.deck_1.x + 1].korabl = '.';
			pc_temp[pc_single_decker_4.deck_1.y - 1][pc_single_decker_4.deck_1.x + 1].progress = '.';
		}

		if ((pc_single_decker_4.deck_1.y - 1 >= 0) && (pc_single_decker_4.deck_1.x - 1 >= 0)) {
			pc_temp[pc_single_decker_4.deck_1.y - 1][pc_single_decker_4.deck_1.x - 1].korabl = '.';
			pc_temp[pc_single_decker_4.deck_1.y - 1][pc_single_decker_4.deck_1.x - 1].progress = '.';
		}

		pc_single_decker_4.flag = 0;

	}



	pc_four_deckers.flag = pc_four_decker.flag;
	pc_three_deckers.flag = pc_three_decker_1.flag + pc_three_decker_2.flag;
	pc_double_deckers.flag = pc_double_decker_1.flag + pc_double_decker_2.flag + pc_double_decker_3.flag;
	pc_single_deckers.flag = pc_single_decker_1.flag + pc_single_decker_2.flag + pc_single_decker_3.flag + pc_single_decker_4.flag;


	//игрок


	if ((temp[four_decker.deck_1.y][four_decker.deck_1.x].korabl == 'X') && (temp[four_decker.deck_2.y][four_decker.deck_2.x].korabl == 'X')
		&& (temp[four_decker.deck_3.y][four_decker.deck_3.x].korabl == 'X') && (temp[four_decker.deck_4.y][four_decker.deck_4.x].korabl == 'X')) {

		if ((four_decker.deck_1.y + 1 <= 9) && (temp[four_decker.deck_1.y + 1][four_decker.deck_1.x].korabl != 'X')) {

			temp[four_decker.deck_1.y + 1][four_decker.deck_1.x].korabl = '.';
			temp[four_decker.deck_1.y + 1][four_decker.deck_1.x].progress = '.';
		}

		if ((four_decker.deck_1.y - 1 >= 0) && (temp[four_decker.deck_1.y - 1][four_decker.deck_1.x].korabl != 'X')) {

			temp[four_decker.deck_1.y - 1][four_decker.deck_1.x].korabl = '.';
			temp[four_decker.deck_1.y - 1][four_decker.deck_1.x].progress = '.';
		}

		if ((four_decker.deck_1.x + 1 <= 9) && (temp[four_decker.deck_1.y][four_decker.deck_1.x + 1].korabl != 'X')) {

			temp[four_decker.deck_1.y][four_decker.deck_1.x + 1].korabl = '.';
			temp[four_decker.deck_1.y][four_decker.deck_1.x + 1].progress = '.';
		}

		if ((four_decker.deck_1.x - 1 >= 0) && (temp[four_decker.deck_1.y][four_decker.deck_1.x - 1].korabl != 'X')) {

			temp[four_decker.deck_1.y][four_decker.deck_1.x - 1].korabl = '.';
			temp[four_decker.deck_1.y][four_decker.deck_1.x - 1].progress = '.';
		}

		if ((four_decker.deck_1.y + 1 <= 9) && (four_decker.deck_1.x + 1 <= 9) && (temp[four_decker.deck_1.y + 1][four_decker.deck_1.x + 1].korabl != 'X')) {

			temp[four_decker.deck_1.y + 1][four_decker.deck_1.x + 1].korabl = '.';
			temp[four_decker.deck_1.y + 1][four_decker.deck_1.x + 1].progress = '.';
		}

		if ((four_decker.deck_1.y + 1 <= 9) && (four_decker.deck_1.x - 1 >= 0) && (temp[four_decker.deck_1.y + 1][four_decker.deck_1.x - 1].korabl != 'X')) {

			temp[four_decker.deck_1.y + 1][four_decker.deck_1.x - 1].korabl = '.';
			temp[four_decker.deck_1.y + 1][four_decker.deck_1.x - 1].progress = '.';
		}

		if ((four_decker.deck_1.y - 1 >= 0) && (four_decker.deck_1.x + 1 <= 9) && (temp[four_decker.deck_1.y - 1][four_decker.deck_1.x + 1].korabl != 'X')) {

			temp[four_decker.deck_1.y - 1][four_decker.deck_1.x + 1].korabl = '.';
			temp[four_decker.deck_1.y - 1][four_decker.deck_1.x + 1].progress = '.';
		}

		if ((four_decker.deck_1.y - 1 >= 0) && (four_decker.deck_1.x - 1 >= 0) && (temp[four_decker.deck_1.y - 1][four_decker.deck_1.x - 1].korabl != 'X')) {

			temp[four_decker.deck_1.y - 1][four_decker.deck_1.x - 1].korabl = '.';
			temp[four_decker.deck_1.y - 1][four_decker.deck_1.x - 1].progress = '.';
		}

		//2

		if ((four_decker.deck_2.y + 1 <= 9) && (temp[four_decker.deck_2.y + 1][four_decker.deck_2.x].korabl != 'X')) {

			temp[four_decker.deck_2.y + 1][four_decker.deck_2.x].korabl = '.';
			temp[four_decker.deck_2.y + 1][four_decker.deck_2.x].progress = '.';
		}

		if ((four_decker.deck_2.y - 1 >= 0) && (temp[four_decker.deck_2.y - 1][four_decker.deck_2.x].korabl != 'X')) {

			temp[four_decker.deck_2.y - 1][four_decker.deck_2.x].korabl = '.';
			temp[four_decker.deck_2.y - 1][four_decker.deck_2.x].progress = '.';
		}

		if ((four_decker.deck_2.x + 1 <= 9) && (temp[four_decker.deck_2.y][four_decker.deck_2.x + 1].korabl != 'X')) {

			temp[four_decker.deck_2.y][four_decker.deck_2.x + 1].korabl = '.';
			temp[four_decker.deck_2.y][four_decker.deck_2.x + 1].progress = '.';
		}

		if ((four_decker.deck_2.x - 1 >= 0) && (temp[four_decker.deck_2.y][four_decker.deck_2.x - 1].korabl != 'X')) {

			temp[four_decker.deck_2.y][four_decker.deck_2.x - 1].korabl = '.';
			temp[four_decker.deck_2.y][four_decker.deck_2.x - 1].progress = '.';
		}

		if ((four_decker.deck_2.y + 1 <= 9) && (four_decker.deck_2.x + 1 <= 9) && (temp[four_decker.deck_2.y + 1][four_decker.deck_2.x + 1].korabl != 'X')) {

			temp[four_decker.deck_2.y + 1][four_decker.deck_2.x + 1].korabl = '.';
			temp[four_decker.deck_2.y + 1][four_decker.deck_2.x + 1].progress = '.';
		}

		if ((four_decker.deck_2.y + 1 <= 9) && (four_decker.deck_2.x - 1 >= 0) && (temp[four_decker.deck_2.y + 1][four_decker.deck_2.x - 1].korabl != 'X')) {

			temp[four_decker.deck_2.y + 1][four_decker.deck_2.x - 1].korabl = '.';
			temp[four_decker.deck_2.y + 1][four_decker.deck_2.x - 1].progress = '.';
		}

		if ((four_decker.deck_2.y - 1 >= 0) && (four_decker.deck_2.x + 1 <= 9) && (temp[four_decker.deck_2.y - 1][four_decker.deck_2.x + 1].korabl != 'X')) {

			temp[four_decker.deck_2.y - 1][four_decker.deck_2.x + 1].korabl = '.';
			temp[four_decker.deck_2.y - 1][four_decker.deck_2.x + 1].progress = '.';
		}

		if ((four_decker.deck_2.y - 1 >= 0) && (four_decker.deck_2.x - 1 >= 0) && (temp[four_decker.deck_2.y - 1][four_decker.deck_2.x - 1].korabl != 'X')) {

			temp[four_decker.deck_2.y - 1][four_decker.deck_2.x - 1].korabl = '.';
			temp[four_decker.deck_2.y - 1][four_decker.deck_2.x - 1].progress = '.';
		}

		//3

		if ((four_decker.deck_3.y + 1 <= 9) && (temp[four_decker.deck_3.y + 1][four_decker.deck_3.x].korabl != 'X')) {

			temp[four_decker.deck_3.y + 1][four_decker.deck_3.x].korabl = '.';
			temp[four_decker.deck_3.y + 1][four_decker.deck_3.x].progress = '.';
		}

		if ((four_decker.deck_3.y - 1 >= 0) && (temp[four_decker.deck_3.y - 1][four_decker.deck_3.x].korabl != 'X')) {

			temp[four_decker.deck_3.y - 1][four_decker.deck_3.x].korabl = '.';
			temp[four_decker.deck_3.y - 1][four_decker.deck_3.x].progress = '.';
		}

		if ((four_decker.deck_3.x + 1 <= 9) && (temp[four_decker.deck_3.y][four_decker.deck_3.x + 1].korabl != 'X')) {

			temp[four_decker.deck_3.y][four_decker.deck_3.x + 1].korabl = '.';
			temp[four_decker.deck_3.y][four_decker.deck_3.x + 1].progress = '.';
		}

		if ((four_decker.deck_3.x - 1 >= 0) && (temp[four_decker.deck_3.y][four_decker.deck_3.x - 1].korabl != 'X')) {

			temp[four_decker.deck_3.y][four_decker.deck_3.x - 1].korabl = '.';
			temp[four_decker.deck_3.y][four_decker.deck_3.x - 1].progress = '.';
		}

		if ((four_decker.deck_3.y + 1 <= 9) && (four_decker.deck_3.x + 1 <= 9) && (temp[four_decker.deck_3.y + 1][four_decker.deck_3.x + 1].korabl != 'X')) {

			temp[four_decker.deck_3.y + 1][four_decker.deck_3.x + 1].korabl = '.';
			temp[four_decker.deck_3.y + 1][four_decker.deck_3.x + 1].progress = '.';
		}

		if ((four_decker.deck_3.y + 1 <= 9) && (four_decker.deck_3.x - 1 >= 0) && (temp[four_decker.deck_3.y + 1][four_decker.deck_3.x - 1].korabl != 'X')) {

			temp[four_decker.deck_3.y + 1][four_decker.deck_3.x - 1].korabl = '.';
			temp[four_decker.deck_3.y + 1][four_decker.deck_3.x - 1].progress = '.';
		}

		if ((four_decker.deck_3.y - 1 >= 0) && (four_decker.deck_3.x + 1 <= 9) && (temp[four_decker.deck_3.y - 1][four_decker.deck_3.x + 1].korabl != 'X')) {

			temp[four_decker.deck_3.y - 1][four_decker.deck_3.x + 1].korabl = '.';
			temp[four_decker.deck_3.y - 1][four_decker.deck_3.x + 1].progress = '.';
		}

		if ((four_decker.deck_3.y - 1 >= 0) && (four_decker.deck_3.x - 1 >= 0) && (temp[four_decker.deck_3.y - 1][four_decker.deck_3.x - 1].korabl != 'X')) {

			temp[four_decker.deck_3.y - 1][four_decker.deck_3.x - 1].korabl = '.';
			temp[four_decker.deck_3.y - 1][four_decker.deck_3.x - 1].progress = '.';
		}

		//4

		if ((four_decker.deck_4.y + 1 <= 9) && (temp[four_decker.deck_4.y + 1][four_decker.deck_4.x].korabl != 'X')) {

			temp[four_decker.deck_4.y + 1][four_decker.deck_4.x].korabl = '.';
			temp[four_decker.deck_4.y + 1][four_decker.deck_4.x].progress = '.';
		}

		if ((four_decker.deck_4.y - 1 >= 0) && (temp[four_decker.deck_4.y - 1][four_decker.deck_4.x].korabl != 'X')) {

			temp[four_decker.deck_4.y - 1][four_decker.deck_4.x].korabl = '.';
			temp[four_decker.deck_4.y - 1][four_decker.deck_4.x].progress = '.';
		}

		if ((four_decker.deck_4.x + 1 <= 9) && (temp[four_decker.deck_4.y][four_decker.deck_4.x + 1].korabl != 'X')) {

			temp[four_decker.deck_4.y][four_decker.deck_4.x + 1].korabl = '.';
			temp[four_decker.deck_4.y][four_decker.deck_4.x + 1].progress = '.';
		}

		if ((four_decker.deck_4.x - 1 >= 0) && (temp[four_decker.deck_4.y][four_decker.deck_4.x - 1].korabl != 'X')) {

			temp[four_decker.deck_4.y][four_decker.deck_4.x - 1].korabl = '.';
			temp[four_decker.deck_4.y][four_decker.deck_4.x - 1].progress = '.';
		}

		if ((four_decker.deck_4.y + 1 <= 9) && (four_decker.deck_4.x + 1 <= 9) && (temp[four_decker.deck_4.y + 1][four_decker.deck_4.x + 1].korabl != 'X')) {

			temp[four_decker.deck_4.y + 1][four_decker.deck_4.x + 1].korabl = '.';
			temp[four_decker.deck_4.y + 1][four_decker.deck_4.x + 1].progress = '.';
		}

		if ((four_decker.deck_4.y + 1 <= 9) && (four_decker.deck_4.x - 1 >= 0) && (temp[four_decker.deck_4.y + 1][four_decker.deck_4.x - 1].korabl != 'X')) {

			temp[four_decker.deck_4.y + 1][four_decker.deck_4.x - 1].korabl = '.';
			temp[four_decker.deck_4.y + 1][four_decker.deck_4.x - 1].progress = '.';
		}

		if ((four_decker.deck_4.y - 1 >= 0) && (four_decker.deck_4.x + 1 <= 9) && (temp[four_decker.deck_4.y - 1][four_decker.deck_4.x + 1].korabl != 'X')) {

			temp[four_decker.deck_4.y - 1][four_decker.deck_4.x + 1].korabl = '.';
			temp[four_decker.deck_4.y - 1][four_decker.deck_4.x + 1].progress = '.';
		}

		if ((four_decker.deck_4.y - 1 >= 0) && (four_decker.deck_4.x - 1 >= 0) && (temp[four_decker.deck_4.y - 1][four_decker.deck_4.x - 1].korabl != 'X')) {

			temp[four_decker.deck_4.y - 1][four_decker.deck_4.x - 1].korabl = '.';
			temp[four_decker.deck_4.y - 1][four_decker.deck_4.x - 1].progress = '.';
		}

		four_decker.flag = 0;

	}


	if ((temp[three_decker_1.deck_1.y][three_decker_1.deck_1.x].korabl == 'X') && (temp[three_decker_1.deck_2.y][three_decker_1.deck_2.x].korabl == 'X')
		&& (temp[three_decker_1.deck_3.y][three_decker_1.deck_3.x].korabl == 'X')) {

		if ((three_decker_1.deck_1.y + 1 <= 9) && (temp[three_decker_1.deck_1.y + 1][three_decker_1.deck_1.x].korabl != 'X')) {

			temp[three_decker_1.deck_1.y + 1][three_decker_1.deck_1.x].korabl = '.';
			temp[three_decker_1.deck_1.y + 1][three_decker_1.deck_1.x].progress = '.';
		}

		if ((three_decker_1.deck_1.y - 1 >= 0) && (temp[three_decker_1.deck_1.y - 1][three_decker_1.deck_1.x].korabl != 'X')) {

			temp[three_decker_1.deck_1.y - 1][three_decker_1.deck_1.x].korabl = '.';
			temp[three_decker_1.deck_1.y - 1][three_decker_1.deck_1.x].progress = '.';
		}

		if ((three_decker_1.deck_1.x + 1 <= 9) && (temp[three_decker_1.deck_1.y][three_decker_1.deck_1.x + 1].korabl != 'X')) {

			temp[three_decker_1.deck_1.y][three_decker_1.deck_1.x + 1].korabl = '.';
			temp[three_decker_1.deck_1.y][three_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((three_decker_1.deck_1.x - 1 >= 0) && (temp[three_decker_1.deck_1.y][three_decker_1.deck_1.x - 1].korabl != 'X')) {

			temp[three_decker_1.deck_1.y][three_decker_1.deck_1.x - 1].korabl = '.';
			temp[three_decker_1.deck_1.y][three_decker_1.deck_1.x - 1].progress = '.';
		}

		if ((three_decker_1.deck_1.y + 1 <= 9) && (three_decker_1.deck_1.x + 1 <= 9) && (temp[three_decker_1.deck_1.y + 1][three_decker_1.deck_1.x + 1].korabl != 'X')) {

			temp[three_decker_1.deck_1.y + 1][three_decker_1.deck_1.x + 1].korabl = '.';
			temp[three_decker_1.deck_1.y + 1][three_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((three_decker_1.deck_1.y + 1 <= 9) && (three_decker_1.deck_1.x - 1 >= 0) && (temp[three_decker_1.deck_1.y + 1][three_decker_1.deck_1.x - 1].korabl != 'X')) {

			temp[three_decker_1.deck_1.y + 1][three_decker_1.deck_1.x - 1].korabl = '.';
			temp[three_decker_1.deck_1.y + 1][three_decker_1.deck_1.x - 1].progress = '.';
		}

		if ((three_decker_1.deck_1.y - 1 >= 0) && (three_decker_1.deck_1.x + 1 <= 9) && (temp[three_decker_1.deck_1.y - 1][three_decker_1.deck_1.x + 1].korabl != 'X')) {

			temp[three_decker_1.deck_1.y - 1][three_decker_1.deck_1.x + 1].korabl = '.';
			temp[three_decker_1.deck_1.y - 1][three_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((three_decker_1.deck_1.y - 1 >= 0) && (three_decker_1.deck_1.x - 1 >= 0) && (temp[three_decker_1.deck_1.y - 1][three_decker_1.deck_1.x - 1].korabl != 'X')) {

			temp[three_decker_1.deck_1.y - 1][three_decker_1.deck_1.x - 1].korabl = '.';
			temp[three_decker_1.deck_1.y - 1][three_decker_1.deck_1.x - 1].progress = '.';
		}

		//

		if ((three_decker_1.deck_2.y + 1 <= 9) && (temp[three_decker_1.deck_2.y + 1][three_decker_1.deck_2.x].korabl != 'X')) {

			temp[three_decker_1.deck_2.y + 1][three_decker_1.deck_2.x].korabl = '.';
			temp[three_decker_1.deck_2.y + 1][three_decker_1.deck_2.x].progress = '.';
		}

		if ((three_decker_1.deck_2.y - 1 >= 0) && (temp[three_decker_1.deck_2.y - 1][three_decker_1.deck_2.x].korabl != 'X')) {

			temp[three_decker_1.deck_2.y - 1][three_decker_1.deck_2.x].korabl = '.';
			temp[three_decker_1.deck_2.y - 1][three_decker_1.deck_2.x].progress = '.';
		}

		if ((three_decker_1.deck_2.x + 1 <= 9) && (temp[three_decker_1.deck_2.y][three_decker_1.deck_2.x + 1].korabl != 'X')) {

			temp[three_decker_1.deck_2.y][three_decker_1.deck_2.x + 1].korabl = '.';
			temp[three_decker_1.deck_2.y][three_decker_1.deck_2.x + 1].progress = '.';
		}

		if ((three_decker_1.deck_2.x - 1 >= 0) && (temp[three_decker_1.deck_2.y][three_decker_1.deck_2.x - 1].korabl != 'X')) {

			temp[three_decker_1.deck_2.y][three_decker_1.deck_2.x - 1].korabl = '.';
			temp[three_decker_1.deck_2.y][three_decker_1.deck_2.x - 1].progress = '.';
		}

		if ((three_decker_1.deck_2.y + 1 <= 9) && (three_decker_1.deck_2.x + 1 <= 9) && (temp[three_decker_1.deck_2.y + 1][three_decker_1.deck_2.x + 1].korabl != 'X')) {

			temp[three_decker_1.deck_2.y + 1][three_decker_1.deck_2.x + 1].korabl = '.';
			temp[three_decker_1.deck_2.y + 1][three_decker_1.deck_2.x + 1].progress = '.';
		}

		if ((three_decker_1.deck_2.y + 1 <= 9) && (three_decker_1.deck_2.x - 1 >= 0) && (temp[three_decker_1.deck_2.y + 1][three_decker_1.deck_2.x - 1].korabl != 'X')) {

			temp[three_decker_1.deck_2.y + 1][three_decker_1.deck_2.x - 1].korabl = '.';
			temp[three_decker_1.deck_2.y + 1][three_decker_1.deck_2.x - 1].progress = '.';
		}

		if ((three_decker_1.deck_2.y - 1 >= 0) && (three_decker_1.deck_2.x + 1 <= 9) && (temp[three_decker_1.deck_2.y - 1][three_decker_1.deck_2.x + 1].korabl != 'X')) {

			temp[three_decker_1.deck_2.y - 1][three_decker_1.deck_2.x + 1].korabl = '.';
			temp[three_decker_1.deck_2.y - 1][three_decker_1.deck_2.x + 1].progress = '.';
		}

		if ((three_decker_1.deck_2.y - 1 >= 0) && (three_decker_1.deck_2.x - 1 >= 0) && (temp[three_decker_1.deck_2.y - 1][three_decker_1.deck_2.x - 1].korabl != 'X')) {

			temp[three_decker_1.deck_2.y - 1][three_decker_1.deck_2.x - 1].korabl = '.';
			temp[three_decker_1.deck_2.y - 1][three_decker_1.deck_2.x - 1].progress = '.';
		}

		//

		if ((three_decker_1.deck_3.y + 1 <= 9) && (temp[three_decker_1.deck_3.y + 1][three_decker_1.deck_3.x].korabl != 'X')) {

			temp[three_decker_1.deck_3.y + 1][three_decker_1.deck_3.x].korabl = '.';
			temp[three_decker_1.deck_3.y + 1][three_decker_1.deck_3.x].progress = '.';
		}

		if ((three_decker_1.deck_3.y - 1 >= 0) && (temp[three_decker_1.deck_3.y - 1][three_decker_1.deck_3.x].korabl != 'X')) {

			temp[three_decker_1.deck_3.y - 1][three_decker_1.deck_3.x].korabl = '.';
			temp[three_decker_1.deck_3.y - 1][three_decker_1.deck_3.x].progress = '.';
		}

		if ((three_decker_1.deck_3.x + 1 <= 9) && (temp[three_decker_1.deck_3.y][three_decker_1.deck_3.x + 1].korabl != 'X')) {

			temp[three_decker_1.deck_3.y][three_decker_1.deck_3.x + 1].korabl = '.';
			temp[three_decker_1.deck_3.y][three_decker_1.deck_3.x + 1].progress = '.';
		}

		if ((three_decker_1.deck_3.x - 1 >= 0) && (temp[three_decker_1.deck_3.y][three_decker_1.deck_3.x - 1].korabl != 'X')) {

			temp[three_decker_1.deck_3.y][three_decker_1.deck_3.x - 1].korabl = '.';
			temp[three_decker_1.deck_3.y][three_decker_1.deck_3.x - 1].progress = '.';
		}

		if ((three_decker_1.deck_3.y + 1 <= 9) && (three_decker_1.deck_3.x + 1 <= 9) && (temp[three_decker_1.deck_3.y + 1][three_decker_1.deck_3.x + 1].korabl != 'X')) {

			temp[three_decker_1.deck_3.y + 1][three_decker_1.deck_3.x + 1].korabl = '.';
			temp[three_decker_1.deck_3.y + 1][three_decker_1.deck_3.x + 1].progress = '.';
		}

		if ((three_decker_1.deck_3.y + 1 <= 9) && (three_decker_1.deck_3.x - 1 >= 0) && (temp[three_decker_1.deck_3.y + 1][three_decker_1.deck_3.x - 1].korabl != 'X')) {

			temp[three_decker_1.deck_3.y + 1][three_decker_1.deck_3.x - 1].korabl = '.';
			temp[three_decker_1.deck_3.y + 1][three_decker_1.deck_3.x - 1].progress = '.';
		}

		if ((three_decker_1.deck_3.y - 1 >= 0) && (three_decker_1.deck_3.x + 1 <= 9) && (temp[three_decker_1.deck_3.y - 1][three_decker_1.deck_3.x + 1].korabl != 'X')) {

			temp[three_decker_1.deck_3.y - 1][three_decker_1.deck_3.x + 1].korabl = '.';
			temp[three_decker_1.deck_3.y - 1][three_decker_1.deck_3.x + 1].progress = '.';
		}

		if ((three_decker_1.deck_3.y - 1 >= 0) && (three_decker_1.deck_3.x - 1 >= 0) && (temp[three_decker_1.deck_3.y - 1][three_decker_1.deck_3.x - 1].korabl != 'X')) {

			temp[three_decker_1.deck_3.y - 1][three_decker_1.deck_3.x - 1].korabl = '.';
			temp[three_decker_1.deck_3.y - 1][three_decker_1.deck_3.x - 1].progress = '.';
		}

		three_decker_1.flag = 0;

	}


	if ((temp[three_decker_2.deck_1.y][three_decker_2.deck_1.x].korabl == 'X') && (temp[three_decker_2.deck_2.y][three_decker_2.deck_2.x].korabl == 'X')
		&& (temp[three_decker_2.deck_3.y][three_decker_2.deck_3.x].korabl == 'X')) {

		if ((three_decker_2.deck_1.y + 1 <= 9) && (temp[three_decker_2.deck_1.y + 1][three_decker_2.deck_1.x].korabl != 'X')) {

			temp[three_decker_2.deck_1.y + 1][three_decker_2.deck_1.x].korabl = '.';
			temp[three_decker_2.deck_1.y + 1][three_decker_2.deck_1.x].progress = '.';
		}

		if ((three_decker_2.deck_1.y - 1 >= 0) && (temp[three_decker_2.deck_1.y - 1][three_decker_2.deck_1.x].korabl != 'X')) {

			temp[three_decker_2.deck_1.y - 1][three_decker_2.deck_1.x].korabl = '.';
			temp[three_decker_2.deck_1.y - 1][three_decker_2.deck_1.x].progress = '.';
		}

		if ((three_decker_2.deck_1.x + 1 <= 9) && (temp[three_decker_2.deck_1.y][three_decker_2.deck_1.x + 1].korabl != 'X')) {

			temp[three_decker_2.deck_1.y][three_decker_2.deck_1.x + 1].korabl = '.';
			temp[three_decker_2.deck_1.y][three_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((three_decker_2.deck_1.x - 1 >= 0) && (temp[three_decker_2.deck_1.y][three_decker_2.deck_1.x - 1].korabl != 'X')) {

			temp[three_decker_2.deck_1.y][three_decker_2.deck_1.x - 1].korabl = '.';
			temp[three_decker_2.deck_1.y][three_decker_2.deck_1.x - 1].progress = '.';
		}

		if ((three_decker_2.deck_1.y + 1 <= 9) && (three_decker_2.deck_1.x + 1 <= 9) && (temp[three_decker_2.deck_1.y + 1][three_decker_2.deck_1.x + 1].korabl != 'X')) {

			temp[three_decker_2.deck_1.y + 1][three_decker_2.deck_1.x + 1].korabl = '.';
			temp[three_decker_2.deck_1.y + 1][three_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((three_decker_2.deck_1.y + 1 <= 9) && (three_decker_2.deck_1.x - 1 >= 0) && (temp[three_decker_2.deck_1.y + 1][three_decker_2.deck_1.x - 1].korabl != 'X')) {

			temp[three_decker_2.deck_1.y + 1][three_decker_2.deck_1.x - 1].korabl = '.';
			temp[three_decker_2.deck_1.y + 1][three_decker_2.deck_1.x - 1].progress = '.';
		}

		if ((three_decker_2.deck_1.y - 1 >= 0) && (three_decker_2.deck_1.x + 1 <= 9) && (temp[three_decker_2.deck_1.y - 1][three_decker_2.deck_1.x + 1].korabl != 'X')) {

			temp[three_decker_2.deck_1.y - 1][three_decker_2.deck_1.x + 1].korabl = '.';
			temp[three_decker_2.deck_1.y - 1][three_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((three_decker_2.deck_1.y - 1 >= 0) && (three_decker_2.deck_1.x - 1 >= 0) && (temp[three_decker_2.deck_1.y - 1][three_decker_2.deck_1.x - 1].korabl != 'X')) {

			temp[three_decker_2.deck_1.y - 1][three_decker_2.deck_1.x - 1].korabl = '.';
			temp[three_decker_2.deck_1.y - 1][three_decker_2.deck_1.x - 1].progress = '.';
		}

		//

		if ((three_decker_2.deck_2.y + 1 <= 9) && (temp[three_decker_2.deck_2.y + 1][three_decker_2.deck_2.x].korabl != 'X')) {

			temp[three_decker_2.deck_2.y + 1][three_decker_2.deck_2.x].korabl = '.';
			temp[three_decker_2.deck_2.y + 1][three_decker_2.deck_2.x].progress = '.';
		}

		if ((three_decker_2.deck_2.y - 1 >= 0) && (temp[three_decker_2.deck_2.y - 1][three_decker_2.deck_2.x].korabl != 'X')) {

			temp[three_decker_2.deck_2.y - 1][three_decker_2.deck_2.x].korabl = '.';
			temp[three_decker_2.deck_2.y - 1][three_decker_2.deck_2.x].progress = '.';
		}

		if ((three_decker_2.deck_2.x + 1 <= 9) && (temp[three_decker_2.deck_2.y][three_decker_2.deck_2.x + 1].korabl != 'X')) {

			temp[three_decker_2.deck_2.y][three_decker_2.deck_2.x + 1].korabl = '.';
			temp[three_decker_2.deck_2.y][three_decker_2.deck_2.x + 1].progress = '.';
		}

		if ((three_decker_2.deck_2.x - 1 >= 0) && (temp[three_decker_2.deck_2.y][three_decker_2.deck_2.x - 1].korabl != 'X')) {

			temp[three_decker_2.deck_2.y][three_decker_2.deck_2.x - 1].korabl = '.';
			temp[three_decker_2.deck_2.y][three_decker_2.deck_2.x - 1].progress = '.';
		}

		if ((three_decker_2.deck_2.y + 1 <= 9) && (three_decker_2.deck_2.x + 1 <= 9) && (temp[three_decker_2.deck_2.y + 1][three_decker_2.deck_2.x + 1].korabl != 'X')) {

			temp[three_decker_2.deck_2.y + 1][three_decker_2.deck_2.x + 1].korabl = '.';
			temp[three_decker_2.deck_2.y + 1][three_decker_2.deck_2.x + 1].progress = '.';
		}

		if ((three_decker_2.deck_2.y + 1 <= 9) && (three_decker_2.deck_2.x - 1 >= 0) && (temp[three_decker_2.deck_2.y + 1][three_decker_2.deck_2.x - 1].korabl != 'X')) {

			temp[three_decker_2.deck_2.y + 1][three_decker_2.deck_2.x - 1].korabl = '.';
			temp[three_decker_2.deck_2.y + 1][three_decker_2.deck_2.x - 1].progress = '.';
		}

		if ((three_decker_2.deck_2.y - 1 >= 0) && (three_decker_2.deck_2.x + 1 <= 9) && (temp[three_decker_2.deck_2.y - 1][three_decker_2.deck_2.x + 1].korabl != 'X')) {

			temp[three_decker_2.deck_2.y - 1][three_decker_2.deck_2.x + 1].korabl = '.';
			temp[three_decker_2.deck_2.y - 1][three_decker_2.deck_2.x + 1].progress = '.';
		}

		if ((three_decker_2.deck_2.y - 1 >= 0) && (three_decker_2.deck_2.x - 1 >= 0) && (temp[three_decker_2.deck_2.y - 1][three_decker_2.deck_2.x - 1].korabl != 'X')) {

			temp[three_decker_2.deck_2.y - 1][three_decker_2.deck_2.x - 1].korabl = '.';
			temp[three_decker_2.deck_2.y - 1][three_decker_2.deck_2.x - 1].progress = '.';
		}

		//

		if ((three_decker_2.deck_3.y + 1 <= 9) && (temp[three_decker_2.deck_3.y + 1][three_decker_2.deck_3.x].korabl != 'X')) {

			temp[three_decker_2.deck_3.y + 1][three_decker_2.deck_3.x].korabl = '.';
			temp[three_decker_2.deck_3.y + 1][three_decker_2.deck_3.x].progress = '.';
		}

		if ((three_decker_2.deck_3.y - 1 >= 0) && (temp[three_decker_2.deck_3.y - 1][three_decker_2.deck_3.x].korabl != 'X')) {

			temp[three_decker_2.deck_3.y - 1][three_decker_2.deck_3.x].korabl = '.';
			temp[three_decker_2.deck_3.y - 1][three_decker_2.deck_3.x].progress = '.';
		}

		if ((three_decker_2.deck_3.x + 1 <= 9) && (temp[three_decker_2.deck_3.y][three_decker_2.deck_3.x + 1].korabl != 'X')) {

			temp[three_decker_2.deck_3.y][three_decker_2.deck_3.x + 1].korabl = '.';
			temp[three_decker_2.deck_3.y][three_decker_2.deck_3.x + 1].progress = '.';
		}

		if ((three_decker_2.deck_3.x - 1 >= 0) && (temp[three_decker_2.deck_3.y][three_decker_2.deck_3.x - 1].korabl != 'X')) {

			temp[three_decker_2.deck_3.y][three_decker_2.deck_3.x - 1].korabl = '.';
			temp[three_decker_2.deck_3.y][three_decker_2.deck_3.x - 1].progress = '.';
		}

		if ((three_decker_2.deck_3.y + 1 <= 9) && (three_decker_2.deck_3.x + 1 <= 9) && (temp[three_decker_2.deck_3.y + 1][three_decker_2.deck_3.x + 1].korabl != 'X')) {

			temp[three_decker_2.deck_3.y + 1][three_decker_2.deck_3.x + 1].korabl = '.';
			temp[three_decker_2.deck_3.y + 1][three_decker_2.deck_3.x + 1].progress = '.';
		}

		if ((three_decker_2.deck_3.y + 1 <= 9) && (three_decker_2.deck_3.x - 1 >= 0) && (temp[three_decker_2.deck_3.y + 1][three_decker_2.deck_3.x - 1].korabl != 'X')) {

			temp[three_decker_2.deck_3.y + 1][three_decker_2.deck_3.x - 1].korabl = '.';
			temp[three_decker_2.deck_3.y + 1][three_decker_2.deck_3.x - 1].progress = '.';
		}

		if ((three_decker_2.deck_3.y - 1 >= 0) && (three_decker_2.deck_3.x + 1 <= 9) && (temp[three_decker_2.deck_3.y - 1][three_decker_2.deck_3.x + 1].korabl != 'X')) {

			temp[three_decker_2.deck_3.y - 1][three_decker_2.deck_3.x + 1].korabl = '.';
			temp[three_decker_2.deck_3.y - 1][three_decker_2.deck_3.x + 1].progress = '.';
		}

		if ((three_decker_2.deck_3.y - 1 >= 0) && (three_decker_2.deck_3.x - 1 >= 0) && (temp[three_decker_2.deck_3.y - 1][three_decker_2.deck_3.x - 1].korabl != 'X')) {

			temp[three_decker_2.deck_3.y - 1][three_decker_2.deck_3.x - 1].korabl = '.';
			temp[three_decker_2.deck_3.y - 1][three_decker_2.deck_3.x - 1].progress = '.';
		}

		three_decker_2.flag = 0;

	}


	if ((temp[double_decker_1.deck_1.y][double_decker_1.deck_1.x].korabl == 'X') && (temp[double_decker_1.deck_2.y][double_decker_1.deck_2.x].korabl == 'X')) {


		if ((double_decker_1.deck_1.y + 1 <= 9) && (temp[double_decker_1.deck_1.y + 1][double_decker_1.deck_1.x].korabl != 'X')) {

			temp[double_decker_1.deck_1.y + 1][double_decker_1.deck_1.x].korabl = '.';
			temp[double_decker_1.deck_1.y + 1][double_decker_1.deck_1.x].progress = '.';
		}

		if ((double_decker_1.deck_1.y - 1 >= 0) && (temp[double_decker_1.deck_1.y - 1][double_decker_1.deck_1.x].korabl != 'X')) {

			temp[double_decker_1.deck_1.y - 1][double_decker_1.deck_1.x].korabl = '.';
			temp[double_decker_1.deck_1.y - 1][double_decker_1.deck_1.x].progress = '.';
		}

		if ((double_decker_1.deck_1.x + 1 <= 9) && (temp[double_decker_1.deck_1.y][double_decker_1.deck_1.x + 1].korabl != 'X')) {

			temp[double_decker_1.deck_1.y][double_decker_1.deck_1.x + 1].korabl = '.';
			temp[double_decker_1.deck_1.y][double_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((double_decker_1.deck_1.x - 1 >= 0) && (temp[double_decker_1.deck_1.y][double_decker_1.deck_1.x - 1].korabl != 'X')) {

			temp[double_decker_1.deck_1.y][double_decker_1.deck_1.x - 1].korabl = '.';
			temp[double_decker_1.deck_1.y][double_decker_1.deck_1.x - 1].progress = '.';
		}

		if ((double_decker_1.deck_1.y + 1 <= 9) && (double_decker_1.deck_1.x + 1 <= 9) && (temp[double_decker_1.deck_1.y + 1][double_decker_1.deck_1.x + 1].korabl != 'X')) {

			temp[double_decker_1.deck_1.y + 1][double_decker_1.deck_1.x + 1].korabl = '.';
			temp[double_decker_1.deck_1.y + 1][double_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((double_decker_1.deck_1.y + 1 <= 9) && (double_decker_1.deck_1.x - 1 >= 0) && (temp[double_decker_1.deck_1.y + 1][double_decker_1.deck_1.x - 1].korabl != 'X')) {

			temp[double_decker_1.deck_1.y + 1][double_decker_1.deck_1.x - 1].korabl = '.';
			temp[double_decker_1.deck_1.y + 1][double_decker_1.deck_1.x - 1].progress = '.';
		}

		if ((double_decker_1.deck_1.y - 1 >= 0) && (double_decker_1.deck_1.x + 1 <= 9) && (temp[double_decker_1.deck_1.y - 1][double_decker_1.deck_1.x + 1].korabl != 'X')) {

			temp[double_decker_1.deck_1.y - 1][double_decker_1.deck_1.x + 1].korabl = '.';
			temp[double_decker_1.deck_1.y - 1][double_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((double_decker_1.deck_1.y - 1 >= 0) && (double_decker_1.deck_1.x - 1 >= 0) && (temp[double_decker_1.deck_1.y - 1][double_decker_1.deck_1.x - 1].korabl != 'X')) {

			temp[double_decker_1.deck_1.y - 1][double_decker_1.deck_1.x - 1].korabl = '.';
			temp[double_decker_1.deck_1.y - 1][double_decker_1.deck_1.x - 1].progress = '.';
		}

		//

		if ((double_decker_1.deck_2.y + 1 <= 9) && (temp[double_decker_1.deck_2.y + 1][double_decker_1.deck_2.x].korabl != 'X')) {

			temp[double_decker_1.deck_2.y + 1][double_decker_1.deck_2.x].korabl = '.';
			temp[double_decker_1.deck_2.y + 1][double_decker_1.deck_2.x].progress = '.';
		}

		if ((double_decker_1.deck_2.y - 1 >= 0) && (temp[double_decker_1.deck_2.y - 1][double_decker_1.deck_2.x].korabl != 'X')) {

			temp[double_decker_1.deck_2.y - 1][double_decker_1.deck_2.x].korabl = '.';
			temp[double_decker_1.deck_2.y - 1][double_decker_1.deck_2.x].progress = '.';
		}

		if ((double_decker_1.deck_2.x + 1 <= 9) && (temp[double_decker_1.deck_2.y][double_decker_1.deck_2.x + 1].korabl != 'X')) {

			temp[double_decker_1.deck_2.y][double_decker_1.deck_2.x + 1].korabl = '.';
			temp[double_decker_1.deck_2.y][double_decker_1.deck_2.x + 1].progress = '.';
		}

		if ((double_decker_1.deck_2.x - 1 >= 0) && (temp[double_decker_1.deck_2.y][double_decker_1.deck_2.x - 1].korabl != 'X')) {

			temp[double_decker_1.deck_2.y][double_decker_1.deck_2.x - 1].korabl = '.';
			temp[double_decker_1.deck_2.y][double_decker_1.deck_2.x - 1].progress = '.';
		}

		if ((double_decker_1.deck_2.y + 1 <= 9) && (double_decker_1.deck_2.x + 1 <= 9) && (temp[double_decker_1.deck_2.y + 1][double_decker_1.deck_2.x + 1].korabl != 'X')) {

			temp[double_decker_1.deck_2.y + 1][double_decker_1.deck_2.x + 1].korabl = '.';
			temp[double_decker_1.deck_2.y + 1][double_decker_1.deck_2.x + 1].progress = '.';
		}

		if ((double_decker_1.deck_2.y + 1 <= 9) && (double_decker_1.deck_2.x - 1 >= 0) && (temp[double_decker_1.deck_2.y + 1][double_decker_1.deck_2.x - 1].korabl != 'X')) {

			temp[double_decker_1.deck_2.y + 1][double_decker_1.deck_2.x - 1].korabl = '.';
			temp[double_decker_1.deck_2.y + 1][double_decker_1.deck_2.x - 1].progress = '.';
		}

		if ((double_decker_1.deck_2.y - 1 >= 0) && (double_decker_1.deck_2.x + 1 <= 9) && (temp[double_decker_1.deck_2.y - 1][double_decker_1.deck_2.x + 1].korabl != 'X')) {

			temp[double_decker_1.deck_2.y - 1][double_decker_1.deck_2.x + 1].korabl = '.';
			temp[double_decker_1.deck_2.y - 1][double_decker_1.deck_2.x + 1].progress = '.';
		}

		if ((double_decker_1.deck_2.y - 1 >= 0) && (double_decker_1.deck_2.x - 1 >= 0) && (temp[double_decker_1.deck_2.y - 1][double_decker_1.deck_2.x - 1].korabl != 'X')) {

			temp[double_decker_1.deck_2.y - 1][double_decker_1.deck_2.x - 1].korabl = '.';
			temp[double_decker_1.deck_2.y - 1][double_decker_1.deck_2.x - 1].progress = '.';
		}

		double_decker_1.flag = 0;

	}


	if ((temp[double_decker_2.deck_1.y][double_decker_2.deck_1.x].korabl == 'X') && (temp[double_decker_2.deck_2.y][double_decker_2.deck_2.x].korabl == 'X')) {


		if ((double_decker_2.deck_1.y + 1 <= 9) && (temp[double_decker_2.deck_1.y + 1][double_decker_2.deck_1.x].korabl != 'X')) {

			temp[double_decker_2.deck_1.y + 1][double_decker_2.deck_1.x].korabl = '.';
			temp[double_decker_2.deck_1.y + 1][double_decker_2.deck_1.x].progress = '.';
		}

		if ((double_decker_2.deck_1.y - 1 >= 0) && (temp[double_decker_2.deck_1.y - 1][double_decker_2.deck_1.x].korabl != 'X')) {

			temp[double_decker_2.deck_1.y - 1][double_decker_2.deck_1.x].korabl = '.';
			temp[double_decker_2.deck_1.y - 1][double_decker_2.deck_1.x].progress = '.';
		}

		if ((double_decker_2.deck_1.x + 1 <= 9) && (temp[double_decker_2.deck_1.y][double_decker_2.deck_1.x + 1].korabl != 'X')) {

			temp[double_decker_2.deck_1.y][double_decker_2.deck_1.x + 1].korabl = '.';
			temp[double_decker_2.deck_1.y][double_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((double_decker_2.deck_1.x - 1 >= 0) && (temp[double_decker_2.deck_1.y][double_decker_2.deck_1.x - 1].korabl != 'X')) {

			temp[double_decker_2.deck_1.y][double_decker_2.deck_1.x - 1].korabl = '.';
			temp[double_decker_2.deck_1.y][double_decker_2.deck_1.x - 1].progress = '.';
		}

		if ((double_decker_2.deck_1.y + 1 <= 9) && (double_decker_2.deck_1.x + 1 <= 9) && (temp[double_decker_2.deck_1.y + 1][double_decker_2.deck_1.x + 1].korabl != 'X')) {

			temp[double_decker_2.deck_1.y + 1][double_decker_2.deck_1.x + 1].korabl = '.';
			temp[double_decker_2.deck_1.y + 1][double_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((double_decker_2.deck_1.y + 1 <= 9) && (double_decker_2.deck_1.x - 1 >= 0) && (temp[double_decker_2.deck_1.y + 1][double_decker_2.deck_1.x - 1].korabl != 'X')) {

			temp[double_decker_2.deck_1.y + 1][double_decker_2.deck_1.x - 1].korabl = '.';
			temp[double_decker_2.deck_1.y + 1][double_decker_2.deck_1.x - 1].progress = '.';
		}

		if ((double_decker_2.deck_1.y - 1 >= 0) && (double_decker_2.deck_1.x + 1 <= 9) && (temp[double_decker_2.deck_1.y - 1][double_decker_2.deck_1.x + 1].korabl != 'X')) {

			temp[double_decker_2.deck_1.y - 1][double_decker_2.deck_1.x + 1].korabl = '.';
			temp[double_decker_2.deck_1.y - 1][double_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((double_decker_2.deck_1.y - 1 >= 0) && (double_decker_2.deck_1.x - 1 >= 0) && (temp[double_decker_2.deck_1.y - 1][double_decker_2.deck_1.x - 1].korabl != 'X')) {

			temp[double_decker_2.deck_1.y - 1][double_decker_2.deck_1.x - 1].korabl = '.';
			temp[double_decker_2.deck_1.y - 1][double_decker_2.deck_1.x - 1].progress = '.';
		}

		//

		if ((double_decker_2.deck_2.y + 1 <= 9) && (temp[double_decker_2.deck_2.y + 1][double_decker_2.deck_2.x].korabl != 'X')) {

			temp[double_decker_2.deck_2.y + 1][double_decker_2.deck_2.x].korabl = '.';
			temp[double_decker_2.deck_2.y + 1][double_decker_2.deck_2.x].progress = '.';
		}

		if ((double_decker_2.deck_2.y - 1 >= 0) && (temp[double_decker_2.deck_2.y - 1][double_decker_2.deck_2.x].korabl != 'X')) {

			temp[double_decker_2.deck_2.y - 1][double_decker_2.deck_2.x].korabl = '.';
			temp[double_decker_2.deck_2.y - 1][double_decker_2.deck_2.x].progress = '.';
		}

		if ((double_decker_2.deck_2.x + 1 <= 9) && (temp[double_decker_2.deck_2.y][double_decker_2.deck_2.x + 1].korabl != 'X')) {

			temp[double_decker_2.deck_2.y][double_decker_2.deck_2.x + 1].korabl = '.';
			temp[double_decker_2.deck_2.y][double_decker_2.deck_2.x + 1].progress = '.';
		}

		if ((double_decker_2.deck_2.x - 1 >= 0) && (temp[double_decker_2.deck_2.y][double_decker_2.deck_2.x - 1].korabl != 'X')) {

			temp[double_decker_2.deck_2.y][double_decker_2.deck_2.x - 1].korabl = '.';
			temp[double_decker_2.deck_2.y][double_decker_2.deck_2.x - 1].progress = '.';
		}

		if ((double_decker_2.deck_2.y + 1 <= 9) && (double_decker_2.deck_2.x + 1 <= 9) && (temp[double_decker_2.deck_2.y + 1][double_decker_2.deck_2.x + 1].korabl != 'X')) {

			temp[double_decker_2.deck_2.y + 1][double_decker_2.deck_2.x + 1].korabl = '.';
			temp[double_decker_2.deck_2.y + 1][double_decker_2.deck_2.x + 1].progress = '.';
		}

		if ((double_decker_2.deck_2.y + 1 <= 9) && (double_decker_2.deck_2.x - 1 >= 0) && (temp[double_decker_2.deck_2.y + 1][double_decker_2.deck_2.x - 1].korabl != 'X')) {

			temp[double_decker_2.deck_2.y + 1][double_decker_2.deck_2.x - 1].korabl = '.';
			temp[double_decker_2.deck_2.y + 1][double_decker_2.deck_2.x - 1].progress = '.';
		}

		if ((double_decker_2.deck_2.y - 1 >= 0) && (double_decker_2.deck_2.x + 1 <= 9) && (temp[double_decker_2.deck_2.y - 1][double_decker_2.deck_2.x + 1].korabl != 'X')) {

			temp[double_decker_2.deck_2.y - 1][double_decker_2.deck_2.x + 1].korabl = '.';
			temp[double_decker_2.deck_2.y - 1][double_decker_2.deck_2.x + 1].progress = '.';
		}

		if ((double_decker_2.deck_2.y - 1 >= 0) && (double_decker_2.deck_2.x - 1 >= 0) && (temp[double_decker_2.deck_2.y - 1][double_decker_2.deck_2.x - 1].korabl != 'X')) {

			temp[double_decker_2.deck_2.y - 1][double_decker_2.deck_2.x - 1].korabl = '.';
			temp[double_decker_2.deck_2.y - 1][double_decker_2.deck_2.x - 1].progress = '.';
		}

		double_decker_2.flag = 0;

	}


	if ((temp[double_decker_3.deck_1.y][double_decker_3.deck_1.x].korabl == 'X') && (temp[double_decker_3.deck_2.y][double_decker_3.deck_2.x].korabl == 'X')) {


		if ((double_decker_3.deck_1.y + 1 <= 9) && (temp[double_decker_3.deck_1.y + 1][double_decker_3.deck_1.x].korabl != 'X')) {

			temp[double_decker_3.deck_1.y + 1][double_decker_3.deck_1.x].korabl = '.';
			temp[double_decker_3.deck_1.y + 1][double_decker_3.deck_1.x].progress = '.';
		}

		if ((double_decker_3.deck_1.y - 1 >= 0) && (temp[double_decker_3.deck_1.y - 1][double_decker_3.deck_1.x].korabl != 'X')) {

			temp[double_decker_3.deck_1.y - 1][double_decker_3.deck_1.x].korabl = '.';
			temp[double_decker_3.deck_1.y - 1][double_decker_3.deck_1.x].progress = '.';
		}

		if ((double_decker_3.deck_1.x + 1 <= 9) && (temp[double_decker_3.deck_1.y][double_decker_3.deck_1.x + 1].korabl != 'X')) {

			temp[double_decker_3.deck_1.y][double_decker_3.deck_1.x + 1].korabl = '.';
			temp[double_decker_3.deck_1.y][double_decker_3.deck_1.x + 1].progress = '.';
		}

		if ((double_decker_3.deck_1.x - 1 >= 0) && (temp[double_decker_3.deck_1.y][double_decker_3.deck_1.x - 1].korabl != 'X')) {

			temp[double_decker_3.deck_1.y][double_decker_3.deck_1.x - 1].korabl = '.';
			temp[double_decker_3.deck_1.y][double_decker_3.deck_1.x - 1].progress = '.';
		}

		if ((double_decker_3.deck_1.y + 1 <= 9) && (double_decker_3.deck_1.x + 1 <= 9) && (temp[double_decker_3.deck_1.y + 1][double_decker_3.deck_1.x + 1].korabl != 'X')) {

			temp[double_decker_3.deck_1.y + 1][double_decker_3.deck_1.x + 1].korabl = '.';
			temp[double_decker_3.deck_1.y + 1][double_decker_3.deck_1.x + 1].progress = '.';
		}

		if ((double_decker_3.deck_1.y + 1 <= 9) && (double_decker_3.deck_1.x - 1 >= 0) && (temp[double_decker_3.deck_1.y + 1][double_decker_3.deck_1.x - 1].korabl != 'X')) {

			temp[double_decker_3.deck_1.y + 1][double_decker_3.deck_1.x - 1].korabl = '.';
			temp[double_decker_3.deck_1.y + 1][double_decker_3.deck_1.x - 1].progress = '.';
		}

		if ((double_decker_3.deck_1.y - 1 >= 0) && (double_decker_3.deck_1.x + 1 <= 9) && (temp[double_decker_3.deck_1.y - 1][double_decker_3.deck_1.x + 1].korabl != 'X')) {

			temp[double_decker_3.deck_1.y - 1][double_decker_3.deck_1.x + 1].korabl = '.';
			temp[double_decker_3.deck_1.y - 1][double_decker_3.deck_1.x + 1].progress = '.';
		}

		if ((double_decker_3.deck_1.y - 1 >= 0) && (double_decker_3.deck_1.x - 1 >= 0) && (temp[double_decker_3.deck_1.y - 1][double_decker_3.deck_1.x - 1].korabl != 'X')) {

			temp[double_decker_3.deck_1.y - 1][double_decker_3.deck_1.x - 1].korabl = '.';
			temp[double_decker_3.deck_1.y - 1][double_decker_3.deck_1.x - 1].progress = '.';
		}

		//

		if ((double_decker_3.deck_2.y + 1 <= 9) && (temp[double_decker_3.deck_2.y + 1][double_decker_3.deck_2.x].korabl != 'X')) {

			temp[double_decker_3.deck_2.y + 1][double_decker_3.deck_2.x].korabl = '.';
			temp[double_decker_3.deck_2.y + 1][double_decker_3.deck_2.x].progress = '.';
		}

		if ((double_decker_3.deck_2.y - 1 >= 0) && (temp[double_decker_3.deck_2.y - 1][double_decker_3.deck_2.x].korabl != 'X')) {

			temp[double_decker_3.deck_2.y - 1][double_decker_3.deck_2.x].korabl = '.';
			temp[double_decker_3.deck_2.y - 1][double_decker_3.deck_2.x].progress = '.';
		}

		if ((double_decker_3.deck_2.x + 1 <= 9) && (temp[double_decker_3.deck_2.y][double_decker_3.deck_2.x + 1].korabl != 'X')) {

			temp[double_decker_3.deck_2.y][double_decker_3.deck_2.x + 1].korabl = '.';
			temp[double_decker_3.deck_2.y][double_decker_3.deck_2.x + 1].progress = '.';
		}

		if ((double_decker_3.deck_2.x - 1 >= 0) && (temp[double_decker_3.deck_2.y][double_decker_3.deck_2.x - 1].korabl != 'X')) {

			temp[double_decker_3.deck_2.y][double_decker_3.deck_2.x - 1].korabl = '.';
			temp[double_decker_3.deck_2.y][double_decker_3.deck_2.x - 1].progress = '.';
		}

		if ((double_decker_3.deck_2.y + 1 <= 9) && (double_decker_3.deck_2.x + 1 <= 9) && (temp[double_decker_3.deck_2.y + 1][double_decker_3.deck_2.x + 1].korabl != 'X')) {

			temp[double_decker_3.deck_2.y + 1][double_decker_3.deck_2.x + 1].korabl = '.';
			temp[double_decker_3.deck_2.y + 1][double_decker_3.deck_2.x + 1].progress = '.';
		}

		if ((double_decker_3.deck_2.y + 1 <= 9) && (double_decker_3.deck_2.x - 1 >= 0) && (temp[double_decker_3.deck_2.y + 1][double_decker_3.deck_2.x - 1].korabl != 'X')) {

			temp[double_decker_3.deck_2.y + 1][double_decker_3.deck_2.x - 1].korabl = '.';
			temp[double_decker_3.deck_2.y + 1][double_decker_3.deck_2.x - 1].progress = '.';
		}

		if ((double_decker_3.deck_2.y - 1 >= 0) && (double_decker_3.deck_2.x + 1 <= 9) && (temp[double_decker_3.deck_2.y - 1][double_decker_3.deck_2.x + 1].korabl != 'X')) {

			temp[double_decker_3.deck_2.y - 1][double_decker_3.deck_2.x + 1].korabl = '.';
			temp[double_decker_3.deck_2.y - 1][double_decker_3.deck_2.x + 1].progress = '.';
		}

		if ((double_decker_3.deck_2.y - 1 >= 0) && (double_decker_3.deck_2.x - 1 >= 0) && (temp[double_decker_3.deck_2.y - 1][double_decker_3.deck_2.x - 1].korabl != 'X')) {

			temp[double_decker_3.deck_2.y - 1][double_decker_3.deck_2.x - 1].korabl = '.';
			temp[double_decker_3.deck_2.y - 1][double_decker_3.deck_2.x - 1].progress = '.';
		}

		double_decker_3.flag = 0;

	}


	if (temp[single_decker_1.deck_1.y][single_decker_1.deck_1.x].korabl == 'X') {

		if (single_decker_1.deck_1.y + 1 <= 9) {
			temp[single_decker_1.deck_1.y + 1][single_decker_1.deck_1.x].korabl = '.';
			temp[single_decker_1.deck_1.y + 1][single_decker_1.deck_1.x].progress = '.';
		}

		if (single_decker_1.deck_1.y - 1 >= 0) {
			temp[single_decker_1.deck_1.y - 1][single_decker_1.deck_1.x].korabl = '.';
			temp[single_decker_1.deck_1.y - 1][single_decker_1.deck_1.x].progress = '.';
		}

		if (single_decker_1.deck_1.x + 1 <= 9) {
			temp[single_decker_1.deck_1.y][single_decker_1.deck_1.x + 1].korabl = '.';
			temp[single_decker_1.deck_1.y][single_decker_1.deck_1.x + 1].progress = '.';
		}

		if (single_decker_1.deck_1.x - 1 >= 0) {
			temp[single_decker_1.deck_1.y][single_decker_1.deck_1.x - 1].korabl = '.';
			temp[single_decker_1.deck_1.y][single_decker_1.deck_1.x - 1].progress = '.';
		}

		if ((single_decker_1.deck_1.y + 1 <= 9) && (single_decker_1.deck_1.x + 1 <= 9)) {
			temp[single_decker_1.deck_1.y + 1][single_decker_1.deck_1.x + 1].korabl = '.';
			temp[single_decker_1.deck_1.y + 1][single_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((single_decker_1.deck_1.y + 1 <= 9) && (single_decker_1.deck_1.x - 1 >= 0)) {
			temp[single_decker_1.deck_1.y + 1][single_decker_1.deck_1.x - 1].korabl = '.';
			temp[single_decker_1.deck_1.y + 1][single_decker_1.deck_1.x - 1].progress = '.';
		}

		if ((single_decker_1.deck_1.y - 1 >= 0) && (single_decker_1.deck_1.x + 1 <= 9)) {
			temp[single_decker_1.deck_1.y - 1][single_decker_1.deck_1.x + 1].korabl = '.';
			temp[single_decker_1.deck_1.y - 1][single_decker_1.deck_1.x + 1].progress = '.';
		}

		if ((single_decker_1.deck_1.y - 1 >= 0) && (single_decker_1.deck_1.x - 1 >= 0)) {
			temp[single_decker_1.deck_1.y - 1][single_decker_1.deck_1.x - 1].korabl = '.';
			temp[single_decker_1.deck_1.y - 1][single_decker_1.deck_1.x - 1].progress = '.';
		}




		single_decker_1.flag = 0;

	}


	if (temp[single_decker_2.deck_1.y][single_decker_2.deck_1.x].korabl == 'X') {

		if (single_decker_2.deck_1.y + 1 <= 9) {
			temp[single_decker_2.deck_1.y + 1][single_decker_2.deck_1.x].korabl = '.';
			temp[single_decker_2.deck_1.y + 1][single_decker_2.deck_1.x].progress = '.';
		}

		if (single_decker_2.deck_1.y - 1 >= 0) {
			temp[single_decker_2.deck_1.y - 1][single_decker_2.deck_1.x].korabl = '.';
			temp[single_decker_2.deck_1.y - 1][single_decker_2.deck_1.x].progress = '.';
		}

		if (single_decker_2.deck_1.x + 1 <= 9) {
			temp[single_decker_2.deck_1.y][single_decker_2.deck_1.x + 1].korabl = '.';
			temp[single_decker_2.deck_1.y][single_decker_2.deck_1.x + 1].progress = '.';
		}

		if (single_decker_2.deck_1.x - 1 >= 0) {
			temp[single_decker_2.deck_1.y][single_decker_2.deck_1.x - 1].korabl = '.';
			temp[single_decker_2.deck_1.y][single_decker_2.deck_1.x - 1].progress = '.';
		}

		if ((single_decker_2.deck_1.y + 1 <= 9) && (single_decker_2.deck_1.x + 1 <= 9)) {
			temp[single_decker_2.deck_1.y + 1][single_decker_2.deck_1.x + 1].korabl = '.';
			temp[single_decker_2.deck_1.y + 1][single_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((single_decker_2.deck_1.y + 1 <= 9) && (single_decker_2.deck_1.x - 1 >= 0)) {
			temp[single_decker_2.deck_1.y + 1][single_decker_2.deck_1.x - 1].korabl = '.';
			temp[single_decker_2.deck_1.y + 1][single_decker_2.deck_1.x - 1].progress = '.';
		}

		if ((single_decker_2.deck_1.y - 1 >= 0) && (single_decker_2.deck_1.x + 1 <= 9)) {
			temp[single_decker_2.deck_1.y - 1][single_decker_2.deck_1.x + 1].korabl = '.';
			temp[single_decker_2.deck_1.y - 1][single_decker_2.deck_1.x + 1].progress = '.';
		}

		if ((single_decker_2.deck_1.y - 1 >= 0) && (single_decker_2.deck_1.x - 1 >= 0)) {
			temp[single_decker_2.deck_1.y - 1][single_decker_2.deck_1.x - 1].korabl = '.';
			temp[single_decker_2.deck_1.y - 1][single_decker_2.deck_1.x - 1].progress = '.';
		}

		single_decker_2.flag = 0;

	}


	if (temp[single_decker_3.deck_1.y][single_decker_3.deck_1.x].korabl == 'X') {

		if (single_decker_3.deck_1.y + 1 <= 9) {
			temp[single_decker_3.deck_1.y + 1][single_decker_3.deck_1.x].korabl = '.';
			temp[single_decker_3.deck_1.y + 1][single_decker_3.deck_1.x].progress = '.';
		}

		if (single_decker_3.deck_1.y - 1 >= 0) {
			temp[single_decker_3.deck_1.y - 1][single_decker_3.deck_1.x].korabl = '.';
			temp[single_decker_3.deck_1.y - 1][single_decker_3.deck_1.x].progress = '.';
		}

		if (single_decker_3.deck_1.x + 1 <= 9) {
			temp[single_decker_3.deck_1.y][single_decker_3.deck_1.x + 1].korabl = '.';
			temp[single_decker_3.deck_1.y][single_decker_3.deck_1.x + 1].progress = '.';
		}

		if (single_decker_3.deck_1.x - 1 >= 0) {
			temp[single_decker_3.deck_1.y][single_decker_3.deck_1.x - 1].korabl = '.';
			temp[single_decker_3.deck_1.y][single_decker_3.deck_1.x - 1].progress = '.';
		}

		if ((single_decker_3.deck_1.y + 1 <= 9) && (single_decker_3.deck_1.x + 1 <= 9)) {
			temp[single_decker_3.deck_1.y + 1][single_decker_3.deck_1.x + 1].korabl = '.';
			temp[single_decker_3.deck_1.y + 1][single_decker_3.deck_1.x + 1].progress = '.';
		}

		if ((single_decker_3.deck_1.y + 1 <= 9) && (single_decker_3.deck_1.x - 1 >= 0)) {
			temp[single_decker_3.deck_1.y + 1][single_decker_3.deck_1.x - 1].korabl = '.';
			temp[single_decker_3.deck_1.y + 1][single_decker_3.deck_1.x - 1].progress = '.';
		}

		if ((single_decker_3.deck_1.y - 1 >= 0) && (single_decker_3.deck_1.x + 1 <= 9)) {
			temp[single_decker_3.deck_1.y - 1][single_decker_3.deck_1.x + 1].korabl = '.';
			temp[single_decker_3.deck_1.y - 1][single_decker_3.deck_1.x + 1].progress = '.';
		}

		if ((single_decker_3.deck_1.y - 1 >= 0) && (single_decker_3.deck_1.x - 1 >= 0)) {
			temp[single_decker_3.deck_1.y - 1][single_decker_3.deck_1.x - 1].korabl = '.';
			temp[single_decker_3.deck_1.y - 1][single_decker_3.deck_1.x - 1].progress = '.';
		}



		single_decker_3.flag = 0;

	}


	if (temp[single_decker_4.deck_1.y][single_decker_4.deck_1.x].korabl == 'X') {

		if (single_decker_4.deck_1.y + 1 <= 9) {
			temp[single_decker_4.deck_1.y + 1][single_decker_4.deck_1.x].korabl = '.';
			temp[single_decker_4.deck_1.y + 1][single_decker_4.deck_1.x].progress = '.';
		}

		if (single_decker_4.deck_1.y - 1 >= 0) {
			temp[single_decker_4.deck_1.y - 1][single_decker_4.deck_1.x].korabl = '.';
			temp[single_decker_4.deck_1.y - 1][single_decker_4.deck_1.x].progress = '.';
		}

		if (single_decker_4.deck_1.x + 1 <= 9) {
			temp[single_decker_4.deck_1.y][single_decker_4.deck_1.x + 1].korabl = '.';
			temp[single_decker_4.deck_1.y][single_decker_4.deck_1.x + 1].progress = '.';
		}

		if (single_decker_4.deck_1.x - 1 >= 0) {
			temp[single_decker_4.deck_1.y][single_decker_4.deck_1.x - 1].korabl = '.';
			temp[single_decker_4.deck_1.y][single_decker_4.deck_1.x - 1].progress = '.';
		}

		if ((single_decker_4.deck_1.y + 1 <= 9) && (single_decker_4.deck_1.x + 1 <= 9)) {
			temp[single_decker_4.deck_1.y + 1][single_decker_4.deck_1.x + 1].korabl = '.';
			temp[single_decker_4.deck_1.y + 1][single_decker_4.deck_1.x + 1].progress = '.';
		}

		if ((single_decker_4.deck_1.y + 1 <= 9) && (single_decker_4.deck_1.x - 1 >= 0)) {
			temp[single_decker_4.deck_1.y + 1][single_decker_4.deck_1.x - 1].korabl = '.';
			temp[single_decker_4.deck_1.y + 1][single_decker_4.deck_1.x - 1].progress = '.';
		}

		if ((single_decker_4.deck_1.y - 1 >= 0) && (single_decker_4.deck_1.x + 1 <= 9)) {
			temp[single_decker_4.deck_1.y - 1][single_decker_4.deck_1.x + 1].korabl = '.';
			temp[single_decker_4.deck_1.y - 1][single_decker_4.deck_1.x + 1].progress = '.';
		}

		if ((single_decker_4.deck_1.y - 1 >= 0) && (single_decker_4.deck_1.x - 1 >= 0)) {
			temp[single_decker_4.deck_1.y - 1][single_decker_4.deck_1.x - 1].korabl = '.';
			temp[single_decker_4.deck_1.y - 1][single_decker_4.deck_1.x - 1].progress = '.';
		}

		single_decker_4.flag = 0;

	}



	four_deckers.flag = four_decker.flag;
	three_deckers.flag = three_decker_1.flag + three_decker_2.flag;
	double_deckers.flag = double_decker_1.flag + double_decker_2.flag + double_decker_3.flag;
	single_deckers.flag = single_decker_1.flag + single_decker_2.flag + single_decker_3.flag + single_decker_4.flag;



	//условие конца игры

	if (((four_deckers.flag == 0) && (three_deckers.flag == 0) && (double_deckers.flag == 0) && (single_deckers.flag == 0)) || ((pc_four_deckers.flag == 0) && (pc_three_deckers.flag == 0) && (pc_double_deckers.flag == 0) && (pc_single_deckers.flag == 0))) {

		return 0; //конец игры
	}

	else {

		return 1; //продолжение игры

	}


}


int pc_check_of_ships() {

	int a;

	a = four_deckers.flag + three_deckers.flag + double_deckers.flag + single_deckers.flag;

	end_game();

	if ((a - four_deckers.flag - three_deckers.flag - double_deckers.flag - single_deckers.flag) == 1) {

		return 0;

	}

	else {

		return 1;

	}

}

int check_of_ships() {

	int a;

	a = pc_four_deckers.flag + pc_three_deckers.flag + pc_double_deckers.flag + pc_single_deckers.flag;

	end_game();

	if ((a - pc_four_deckers.flag - pc_three_deckers.flag - pc_double_deckers.flag - pc_single_deckers.flag) == 1) {

		return 0;

	}

	else {

		return 1;

	}

}



void pc_motion_blok(int s, int c) {

	if ((temp[s][c].progress == '.') || (temp[s][c].progress == 'X')) {
		//повтор координат
		pc_motion();

	}

	else if (temp[s][c].korabl == ((char)254)) {

		system("cls");
		start_game();
		cout << endl;
		cout << endl;
		cout << "КОМПЬЮТЕР ХОДИТ ";
		cout << endl;


		//выводим координаты

		switch (s) {
		case 0:
			k = 'А';
			break;
		case 1:
			k = 'Б';
			break;
		case 2:
			k = 'В';
			break;
		case 3:
			k = 'Г';
			break;
		case 4:
			k = 'Д';
			break;
		case 5:
			k = 'Е';
			break;
		case 6:
			k = 'Ж';
			break;
		case 7:
			k = 'З';
			break;
		case 8:
			k = 'И';
			break;
		case 9:
			k = 'К';
			break;
		}

		cout << k << c;

		Sleep(1500);




		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		temp[s][c].korabl = 'X';
		temp[s][c].progress = 'X';
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		if (pc_check_of_ships() == 0) {
			//функциязаполнения граничных клеток точками
			end_game();

			pc_motion_.flag = 0;
			//повтор хода

			system("cls");
			start_game();
			cout << endl;
			cout << endl;
			cout << "КОМПЬЮТЕР ХОДИТ ";
			cout << endl;

			cout << k << c << " УБИЛ ";

			Sleep(1500);
			pc_motion();
		}

		else if (pc_check_of_ships() == 1) {


			pc_motion_.flag += 1;
			//повтор хода

			system("cls");
			start_game();
			cout << endl;
			cout << endl;
			cout << "КОМПЬЮТЕР ХОДИТ ";
			cout << endl;

			cout << k << c << " ПОПАЛ ";

			Sleep(1500);
			pc_motion();
		}

	}

	else if (temp[s][c].korabl != ((char)254)) {

		system("cls");
		start_game();
		cout << endl;
		cout << endl;
		cout << "КОМПЬЮТЕР ХОДИТ ";
		cout << endl;
		

		//выводим координаты

		switch (s) {
		case 0:
			k = 'А';
			break;
		case 1:
			k = 'Б';
			break;
		case 2:
			k = 'В';
			break;
		case 3:
			k = 'Г';
			break;
		case 4:
			k = 'Д';
			break;
		case 5:
			k = 'Е';
			break;
		case 6:
			k = 'Ж';
			break;
		case 7:
			k = 'З';
			break;
		case 8:
			k = 'И';
			break;
		case 9:
			k = 'К';
			break;
		}

		cout << k << c;

		Sleep(1500);

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		temp[s][c].korabl = '.';
		temp[s][c].progress = '.';
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		system("cls");
		start_game();
		cout << endl;
		cout << endl;
		cout << "КОМПЬЮТЕР ХОДИТ ";
		cout << endl;
		
		cout << k << c << " ПРОМАХ ";

		Sleep(1500);

		user_motion();
	}



}


void pc_motion() {

	/*
	system("cls");

	start_game();

	srand(time(0));

	cout << endl;
	cout << endl;

	cout << "КОМПЬЮТЕР ХОДИТ ";

	cout << endl;
	*/
	
	//условие конца игры, необходимо вставить

	if (end_game() == 0) {

		cout << endl;

	}

	else if (end_game() == 1) {

		int v; //переменная для направления выстрела

		if (pc_motion_.flag == 0) {

			if (four_deckers.flag == 1) {
				v = rand() % 26;
				if (v == 0) {
					pc_s = 0;
					pc_c = 0;
				}
				else if (v == 1) {
					pc_s = 0;
					pc_c = 4;
				}
				else if (v == 2) {
					pc_s = 0;
					pc_c = 8;
				}
				else if (v == 3) {
					pc_s = 1;
					pc_c = 1;
				}
				else if (v == 4) {
					pc_s = 1;
					pc_c = 5;
				}
				else if (v == 5) {
					pc_s = 1;
					pc_c = 9;
				}
				else if (v == 6) {
					pc_s = 2;
					pc_c = 2;
				}
				else if (v == 7) {
					pc_s = 2;
					pc_c = 6;
				}
				else if (v == 8) {
					pc_s = 3;
					pc_c = 3;
				}
				else if (v == 9) {
					pc_s = 3;
					pc_c = 7;
				}
				else if (v == 10) {
					pc_s = 4;
					pc_c = 0;
				}
				else if (v == 11) {
					pc_s = 4;
					pc_c = 4;
				}
				else if (v == 12) {
					pc_s = 4;
					pc_c = 8;
				}
				else if (v == 13) {
					pc_s = 5;
					pc_c = 1;
				}
				else if (v == 14) {
					pc_s = 5;
					pc_c = 5;
				}
				else if (v == 15) {
					pc_s = 5;
					pc_c = 9;
				}
				else if (v == 16) {
					pc_s = 6;
					pc_c = 2;
				}
				else if (v == 17) {
					pc_s = 6;
					pc_c = 6;
				}
				else if (v == 18) {
					pc_s = 7;
					pc_c = 3;
				}
				else if (v == 19) {
					pc_s = 7;
					pc_c = 7;
				}
				else if (v == 20) {
					pc_s = 8;
					pc_c = 0;
				}
				else if (v == 21) {
					pc_s = 8;
					pc_c = 4;
				}
				else if (v == 22) {
					pc_s = 8;
					pc_c = 8;
				}
				else if (v == 23) {
					pc_s = 9;
					pc_c = 1;
				}
				else if (v == 24) {
					pc_s = 9;
					pc_c = 5;
				}
				else if (v == 25) {
					pc_s = 9;
					pc_c = 9;
				}
				pc_motion_blok(pc_s, pc_c);
			}

			else if ((four_deckers.flag == 0) && (three_deckers.flag != 0)) {
				v = rand() % 26;
				if (v == 0) {
					pc_s = 0;
					pc_c = 0;
				}
				else if (v == 1) {
					pc_s = 0;
					pc_c = 3;
				}
				else if (v == 2) {
					pc_s = 0;
					pc_c = 6;
				}
				else if (v == 3) {
					pc_s = 0;
					pc_c = 9;
				}
				else if (v == 4) {
					pc_s = 1;
					pc_c = 1;
				}
				else if (v == 5) {
					pc_s = 1;
					pc_c = 4;
				}
				else if (v == 6) {
					pc_s = 1;
					pc_c = 7;
				}
				else if (v == 7) {
					pc_s = 2;
					pc_c = 2;
				}
				else if (v == 8) {
					pc_s = 2;
					pc_c = 5;
				}
				else if (v == 9) {
					pc_s = 2;
					pc_c = 8;
				}
				else if (v == 10) {
					pc_s = 3;
					pc_c = 0;
				}
				else if (v == 11) {
					pc_s = 3;
					pc_c = 3;
				}
				else if (v == 12) {
					pc_s = 3;
					pc_c = 6;
				}
				else if (v == 13) {
					pc_s = 3;
					pc_c = 9;
				}
				else if (v == 14) {
					pc_s = 4;
					pc_c = 1;
				}
				else if (v == 15) {
					pc_s = 4;
					pc_c = 4;
				}
				else if (v == 16) {
					pc_s = 4;
					pc_c = 7;
				}
				else if (v == 17) {
					pc_s = 5;
					pc_c = 2;
				}
				else if (v == 18) {
					pc_s = 5;
					pc_c = 5;
				}
				else if (v == 19) {
					pc_s = 5;
					pc_c = 8;
				}
				else if (v == 20) {
					pc_s = 6;
					pc_c = 0;
				}
				else if (v == 21) {
					pc_s = 6;
					pc_c = 3;
				}
				else if (v == 22) {
					pc_s = 6;
					pc_c = 6;
				}
				else if (v == 23) {
					pc_s = 6;
					pc_c = 9;
				}
				else if (v == 24) {
					pc_s = 7;
					pc_c = 1;
				}
				else if (v == 25) {
					pc_s = 7;
					pc_c = 4;
				}
				else if (v == 26) {
					pc_s = 7;
					pc_c = 7;
				}
				else if (v == 27) {
					pc_s = 8;
					pc_c = 2;
				}
				else if (v == 28) {
					pc_s = 8;
					pc_c = 5;
				}
				else if (v == 29) {
					pc_s = 8;
					pc_c = 8;
				}
				else if (v == 30) {
					pc_s = 9;
					pc_c = 0;
				}
				else if (v == 31) {
					pc_s = 9;
					pc_c = 3;
				}
				else if (v == 32) {
					pc_s = 9;
					pc_c = 6;
				}
				else if (v == 33) {
					pc_s = 9;
					pc_c = 9;
				}
				pc_motion_blok(pc_s, pc_c);
			}

			else if ((four_deckers.flag == 0) && (three_deckers.flag == 0) && (double_deckers.flag != 0)) {
				pc_s = rand() % 10;
				if (pc_s % 2 == 0) {
					v = rand() % 5;
					if (v == 0) {
						pc_c = 0;
					}
					else if (v == 1) {
						pc_c = 2;
					}
					else if (v == 2) {
						pc_c = 4;
					}
					else if (v == 3) {
						pc_c = 6;
					}
					else if (v == 4) {
						pc_c = 8;
					}
				}
				else{
					v = rand() % 5;
					if (v == 0) {
						pc_c = 1;
					}
					else if (v == 1) {
						pc_c = 3;
					}
					else if (v == 2) {
						pc_c = 5;
					}
					else if (v == 3) {
						pc_c = 7;
					}
					else if (v == 4) {
						pc_c = 9;
					}
				}
				pc_motion_blok(pc_s, pc_c);
			}

			else if ((four_deckers.flag == 0) && (three_deckers.flag == 0) && (double_deckers.flag == 0)) {
				pc_s = rand() % 10;
				v = rand() % 2;
				if (v == 0) {
					if (pc_s % 2 == 0) {
						v = rand() % 5;
						if (v == 0) {
							pc_c = 0;
						}
						else if (v == 1) {
							pc_c = 2;
						}
						else if (v == 2) {
							pc_c = 4;
						}
						else if (v == 3) {
							pc_c = 6;
						}
						else if (v == 4) {
							pc_c = 8;
						}
					}
					else {
						v = rand() % 5;
						if (v == 0) {
							pc_c = 1;
						}
						else if (v == 1) {
							pc_c = 3;
						}
						else if (v == 2) {
							pc_c = 5;
						}
						else if (v == 3) {
							pc_c = 7;
						}
						else if (v == 4) {
							pc_c = 9;
						}
					}
					
				}
				else if (v == 1) {
					if (pc_s % 2 == 0) {
						v = rand() % 5;
						if (v == 0) {
							pc_c = 1;
						}
						else if (v == 1) {
							pc_c = 3;
						}
						else if (v == 2) {
							pc_c = 5;
						}
						else if (v == 3) {
							pc_c = 7;
						}
						else if (v == 4) {
							pc_c = 9;
						}
					}
					else {
						v = rand() % 5;
						if (v == 0) {
							pc_c = 0;
						}
						else if (v == 1) {
							pc_c = 2;
						}
						else if (v == 2) {
							pc_c = 4;
						}
						else if (v == 3) {
							pc_c = 6;
						}
						else if (v == 4) {
							pc_c = 8;
						}
					}
					
				}




				//pc_s = rand() % 10;
				//pc_c = rand() % 10;

				pc_motion_blok(pc_s, pc_c);
			}

		}

		if (pc_motion_.flag == 1) {
			//1
			if ((pc_s == 0) && (pc_c == 0)) {
				v = rand() % 2;
				if (v == 0) {
					direction = 1;
					orientation = 1;
					pc_motion_blok((pc_s + 1), pc_c);		
				}
				else if (v == 1) {
					direction = 0;
					orientation = 1;
					pc_motion_blok((pc_s), (pc_c + 1));
				}
			}

			//2
			if ((pc_s == 0) && (pc_c != 0) && (pc_c != 9)) {
				v = rand() % 3;
				if (v == 0) {
					direction = 1;
					orientation = 1;
					pc_motion_blok((pc_s + 1), pc_c);
				}
				else if (v == 1) {
					direction = 0;
					orientation = 1;
					pc_motion_blok((pc_s), (pc_c + 1));
				}
				else if (v == 2) {
					direction = 0;
					orientation = 0;
					pc_motion_blok((pc_s), (pc_c - 1));
				}
			}

			//3
			if ((pc_s == 0) && (pc_c == 9)) {
				v = rand() % 2;
				if (v == 0) {
					direction = 1;
					orientation = 1;
					pc_motion_blok((pc_s + 1), pc_c);
				}
				else if (v == 1) {
					direction = 0;
					orientation = 0;
					pc_motion_blok((pc_s), (pc_c - 1));
				}
			}

			//4
			if ((pc_s != 0) && (pc_s != 9) && (pc_c == 0)) {
				v = rand() % 3;
				if (v == 0) {
					direction = 1;
					orientation = 1;
					pc_motion_blok((pc_s + 1), pc_c);
				}
				else if (v == 1) {
					direction = 1;
					orientation = 0;
					pc_motion_blok((pc_s - 1), (pc_c));
				}
				else if (v == 2) {
					direction = 0;
					orientation = 1;
					pc_motion_blok((pc_s), (pc_c + 1));
				}
			}

			//5
			if ((pc_s != 0) && (pc_s != 9) && (pc_c != 0) && (pc_c != 9)) {
				v = rand() % 4;
				if (v == 0) {
					direction = 1;
					orientation = 1;
					pc_motion_blok((pc_s + 1), pc_c);
				}
				else if (v == 1) {
					direction = 1;
					orientation = 0;
					pc_motion_blok((pc_s - 1), (pc_c));
				}
				else if (v == 2) {
					direction = 0;
					orientation = 1;
					pc_motion_blok((pc_s), (pc_c + 1));
				}
				else if (v == 3) {
					direction = 0;
					orientation = 0;
					pc_motion_blok((pc_s), (pc_c - 1));
				}
			}

			//6
			if ((pc_s != 0) && (pc_s != 9) && (pc_c == 9)) {
				v = rand() % 3;
				if (v == 0) {
					direction = 1;
					orientation = 1;
					pc_motion_blok((pc_s + 1), pc_c);
				}
				else if (v == 1) {
					direction = 1;
					orientation = 0;
					pc_motion_blok((pc_s - 1), (pc_c));
				}
				else if (v == 2) {
					direction = 0;
					orientation = 0;
					pc_motion_blok((pc_s), (pc_c - 1));
				}
			}

			//7
			if ((pc_s == 9) && (pc_c == 0)) {
				v = rand() % 2;
				if (v == 0) {
					direction = 1;
					orientation = 0;
					pc_motion_blok((pc_s - 1), pc_c);
				}
				else if (v == 1) {
					direction = 0;
					orientation = 1;
					pc_motion_blok((pc_s), (pc_c + 1));
				}
			}

			//8
			if ((pc_s == 9) && (pc_c != 0) && (pc_c != 9)) {
				v = rand() % 3;
				if (v == 0) {
					direction = 1;
					orientation = 0;
					pc_motion_blok((pc_s - 1), pc_c);
				}
				else if (v == 1) {
					direction = 0;
					orientation = 1;
					pc_motion_blok((pc_s), (pc_c + 1));
				}
				else if (v == 2) {
					direction = 0;
					orientation = 0;
					pc_motion_blok((pc_s), (pc_c - 1));
				}
			}

			//9
			if ((pc_s == 9) && (pc_c == 9)) {
				v = rand() % 2;
				if (v == 0) {
					direction = 1;
					orientation = 0;
					pc_motion_blok((pc_s - 1), pc_c);
				}
				else if (v == 1) {
					direction = 0;
					orientation = 0;
					pc_motion_blok((pc_s), (pc_c - 1));
				}
			}
		}

		if (pc_motion_.flag == 2) {
		
			//1+
			if ((pc_s == 0) && (pc_c == 0)) {				
				if ((direction == 1) && (orientation == 1)) {
					pc_motion_blok((pc_s + 2), pc_c);
				}
				else if ((direction == 0) && (orientation == 1)) {					
					pc_motion_blok((pc_s), (pc_c + 2));
				}
			}

			//2+
			if ((pc_s == 0) && (pc_c != 0) && (pc_c != 9)) {
				if ((direction == 1) && (orientation == 1)) {
					pc_motion_blok((pc_s + 2), pc_c);
				}
				else if ((direction == 0) && (orientation == 1)) {
					v = rand() % 2;
					if ((v == 0) && ((pc_c + 2) <= 9)) {
						pc_motion_blok((pc_s), (pc_c + 2));
					}
					else if ((v == 1) && ((pc_c - 1) >= 0)) {
						
						pc_motion_blok((pc_s), (pc_c - 1));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 0) && (orientation == 0)) {
					v = rand() % 2;
					if ((v == 0) && ((pc_c - 2) >= 0)) {
						pc_motion_blok((pc_s), (pc_c - 2));
					}
					else if ((v == 1) && ((pc_c + 1) <= 9)) {
						
						pc_motion_blok((pc_s), (pc_c + 1));
					}
					else {
						pc_motion();
					}
				}
			}

			//3+
			if ((pc_s == 0) && (pc_c == 9)) {
				if ((direction == 1) && (orientation == 1)) {
					pc_motion_blok((pc_s + 2), pc_c);
				}
				else if ((direction == 0) && (orientation == 0)) {
					pc_motion_blok((pc_s), (pc_c - 2));
				}
			}

			//4+
			if ((pc_s != 0) && (pc_s != 9) && (pc_c == 0)) {
				if ((direction == 1) && (orientation == 1)) {
					v = rand() % 2;
					if ((v == 0) && ((pc_s + 2) <= 9)) {
						pc_motion_blok((pc_s + 2), (pc_c));
					}
					else if ((v == 1) && ((pc_s - 1) >= 0)) {

						pc_motion_blok((pc_s - 1), (pc_c));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 1) && (orientation == 0)) {
					v = rand() % 2;
					if ((v == 0) && ((pc_s - 2) >= 0)) {
						pc_motion_blok((pc_s - 2), (pc_c));
					}
					else if ((v == 1) && ((pc_s + 1) <= 9)) {

						pc_motion_blok((pc_s + 1), (pc_c));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 0) && (orientation == 1)) {
					pc_motion_blok((pc_s), (pc_c + 2));
				}
			}

			//5+
			if ((pc_s != 0) && (pc_s != 9) && (pc_c != 0) && (pc_c != 9)) {
				if ((direction == 1) && (orientation == 1)) {
					v = rand() % 2;
					if ((v == 0) && ((pc_s + 2) <= 9)) {
						pc_motion_blok((pc_s + 2), (pc_c));
					}
					else if ((v == 1) && ((pc_s - 1) >= 0)) {

						pc_motion_blok((pc_s - 1), (pc_c));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 1) && (orientation == 0)) {
					v = rand() % 2;
					if ((v == 0) && ((pc_s - 2) >= 0)) {
						pc_motion_blok((pc_s - 2), (pc_c));
					}
					else if ((v == 1) && ((pc_s + 1) <= 9)) {

						pc_motion_blok((pc_s + 1), (pc_c));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 0) && (orientation == 1)) {
					v = rand() % 2;
					if ((v == 0) && ((pc_c + 2) <= 9)) {
						pc_motion_blok((pc_s), (pc_c + 2));
					}
					else if ((v == 1) && ((pc_c - 1) >= 0)) {

						pc_motion_blok((pc_s), (pc_c - 1));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 0) && (orientation == 0)) {
					v = rand() % 2;
					if ((v == 0) && ((pc_c - 2) >= 0)) {
						pc_motion_blok((pc_s), (pc_c - 2));
					}
					else if ((v == 1) && ((pc_c + 1) <= 9)) {

						pc_motion_blok((pc_s), (pc_c + 1));
					}
					else {
						pc_motion();
					}
				}
			}

			//6+
			if ((pc_s != 0) && (pc_s != 9) && (pc_c == 9)) {
				if ((direction == 1) && (orientation == 1)) {
					v = rand() % 2;
					if ((v == 0) && ((pc_s + 2) <= 9)) {
						pc_motion_blok((pc_s + 2), (pc_c));
					}
					else if ((v == 1) && ((pc_s - 1) >= 0)) {

						pc_motion_blok((pc_s - 1), (pc_c));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 1) && (orientation == 0)) {
					v = rand() % 2;
					if ((v == 0) && ((pc_s - 2) >= 0)) {
						pc_motion_blok((pc_s - 2), (pc_c));
					}
					else if ((v == 1) && ((pc_s + 1) <= 9)) {

						pc_motion_blok((pc_s + 1), (pc_c));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 0) && (orientation == 0)) {
						pc_motion_blok((pc_s), (pc_c - 2));
				}
			}

			//7+
			if ((pc_s == 9) && (pc_c == 0)) {
				if ((direction == 1) && (orientation == 0)) {
					pc_motion_blok((pc_s - 2), pc_c);
				}
				else if ((direction == 0) && (orientation == 1)) {
					pc_motion_blok((pc_s), (pc_c + 2));
				}
			}

			//8+
			if ((pc_s == 9) && (pc_c != 0) && (pc_c != 9)) {
				if ((direction == 1) && (orientation == 0)) {
						pc_motion_blok((pc_s - 2), (pc_c));
				}
				else if ((direction == 0) && (orientation == 1)) {
					v = rand() % 2;
					if ((v == 0) && ((pc_c + 2) <= 9)) {
						pc_motion_blok((pc_s), (pc_c + 2));
					}
					else if ((v == 1) && ((pc_c - 1) >= 0)) {

						pc_motion_blok((pc_s), (pc_c - 1));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 0) && (orientation == 0)) {
					v = rand() % 2;
					if ((v == 0) && ((pc_c - 2) >= 0)) {
						pc_motion_blok((pc_s), (pc_c - 2));
					}
					else if ((v == 1) && ((pc_c + 1) <= 9)) {

						pc_motion_blok((pc_s), (pc_c + 1));
					}
					else {
						pc_motion();
					}
				}
			}

			//9+
			if ((pc_s == 9) && (pc_c == 9)) {
				if ((direction == 1) && (orientation == 0)) {
					pc_motion_blok((pc_s - 2), pc_c);
				}
				else if ((direction == 0) && (orientation == 0)) {
					pc_motion_blok((pc_s), (pc_c - 2));
				}
			}
		
		
		}

		if (pc_motion_.flag == 3) {
		
			//1++
			if ((pc_s == 0) && (pc_c == 0)) {
				if ((direction == 1) && (orientation == 1)) {
					pc_motion_blok((pc_s + 3), pc_c);
				}
				else if ((direction == 0) && (orientation == 1)) {
					pc_motion_blok((pc_s), (pc_c + 3));
				}
			}

			//2++
			if ((pc_s == 0) && (pc_c != 0) && (pc_c != 9)) {
				if ((direction == 1) && (orientation == 1)) {
					pc_motion_blok((pc_s + 3), pc_c);
				}
				else if ((direction == 0) && (orientation == 1)) {
					v = rand() % 4;
					if ((v == 0) && ((pc_c + 2) <= 9)) {
						pc_motion_blok((pc_s), (pc_c + 2));
					}
					else if ((v == 1) && ((pc_c - 1) >= 0)) {

						pc_motion_blok((pc_s), (pc_c - 1));
					}
					else if ((v == 2) && ((pc_c + 3) <= 9) && (temp[pc_s][pc_c + 2].progress == 'X')) {

						pc_motion_blok((pc_s), (pc_c + 3));
					}
					else if ((v == 3) && ((pc_c - 2) >= 0) && (temp[pc_s][pc_c - 1].progress == 'X')) {

						pc_motion_blok((pc_s), (pc_c - 2));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 0) && (orientation == 0)) {
					v = rand() % 4;
					if ((v == 0) && ((pc_c - 2) >= 0)) {
						pc_motion_blok((pc_s), (pc_c - 2));
					}
					else if ((v == 1) && ((pc_c + 1) <= 9)) {

						pc_motion_blok((pc_s), (pc_c + 1));
					}

					else if ((v == 2) && ((pc_c - 3) >= 0) && (temp[pc_s][pc_c - 2].progress == 'X')) {
						pc_motion_blok((pc_s), (pc_c - 3));
					}
					else if ((v == 3) && ((pc_c + 2) <= 9) && (temp[pc_s][pc_c + 1].progress == 'X')) {

						pc_motion_blok((pc_s), (pc_c + 2));
					}
					else {
						pc_motion();
					}
				}
			}

			//3++
			if ((pc_s == 0) && (pc_c == 9)) {
				if ((direction == 1) && (orientation == 1)) {
					pc_motion_blok((pc_s + 3), pc_c);
				}
				else if ((direction == 0) && (orientation == 0)) {
					pc_motion_blok((pc_s), (pc_c - 3));
				}
			}

			//4++
			if ((pc_s != 0) && (pc_s != 9) && (pc_c == 0)) {
				if ((direction == 1) && (orientation == 1)) {
					v = rand() % 4;
					if ((v == 0) && ((pc_s + 2) <= 9)) {
						pc_motion_blok((pc_s + 2), (pc_c));
					}
					else if ((v == 1) && ((pc_s - 1) >= 0)) {
						pc_motion_blok((pc_s - 1), (pc_c));
					}
					else if ((v == 2) && ((pc_s + 3) <= 9) && (temp[pc_s + 2][pc_c].progress == 'X')) {
						pc_motion_blok((pc_s + 3), (pc_c));
					}
					else if ((v == 3) && ((pc_s - 2) >= 0) && (temp[pc_s - 1][pc_c].progress == 'X')) {
						pc_motion_blok((pc_s - 2), (pc_c));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 1) && (orientation == 0)) {
					v = rand() % 4;
					if ((v == 0) && ((pc_s - 2) >= 0)) {
						pc_motion_blok((pc_s - 2), (pc_c));
					}
					else if ((v == 1) && ((pc_s + 1) <= 9)) {
						pc_motion_blok((pc_s + 1), (pc_c));
					}
					else if ((v == 2) && ((pc_s - 3) >= 0) && (temp[pc_s - 2][pc_c].progress == 'X')) {
						pc_motion_blok((pc_s - 3), (pc_c));
					}
					else if ((v == 3) && ((pc_s + 2) <= 9) && (temp[pc_s + 1][pc_c].progress == 'X')) {
						pc_motion_blok((pc_s + 2), (pc_c));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 0) && (orientation == 1)) {
					pc_motion_blok((pc_s), (pc_c + 3));
				}
			}

			//5++
			if ((pc_s != 0) && (pc_s != 9) && (pc_c != 0) && (pc_c != 9)) {
				if ((direction == 1) && (orientation == 1)) {
					v = rand() % 4;
					if ((v == 0) && ((pc_s + 2) <= 9)) {
						pc_motion_blok((pc_s + 2), (pc_c));
					}
					else if ((v == 1) && ((pc_s - 1) >= 0)) {
						pc_motion_blok((pc_s - 1), (pc_c));
					}
					else if ((v == 2) && ((pc_s + 3) <= 9) && (temp[pc_s + 2][pc_c].progress == 'X')) {
						pc_motion_blok((pc_s + 3), (pc_c));
					}
					else if ((v == 3) && ((pc_s - 2) >= 0) && (temp[pc_s - 1][pc_c].progress == 'X')) {
						pc_motion_blok((pc_s - 2), (pc_c));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 1) && (orientation == 0)) {
					v = rand() % 4;
					if ((v == 0) && ((pc_s - 2) >= 0)) {
						pc_motion_blok((pc_s - 2), (pc_c));
					}
					else if ((v == 1) && ((pc_s + 1) <= 9)) {
						pc_motion_blok((pc_s + 1), (pc_c));
					}
					else if ((v == 2) && ((pc_s - 3) >= 0) && (temp[pc_s - 2][pc_c].progress == 'X')) {
						pc_motion_blok((pc_s - 3), (pc_c));
					}
					else if ((v == 3) && ((pc_s + 2) <= 9) && (temp[pc_s + 1][pc_c].progress == 'X')) {
						pc_motion_blok((pc_s + 2), (pc_c));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 0) && (orientation == 1)) {
					v = rand() % 4;
					if ((v == 0) && ((pc_c + 2) <= 9)) {
						pc_motion_blok((pc_s), (pc_c + 2));
					}
					else if ((v == 1) && ((pc_c - 1) >= 0)) {
						pc_motion_blok((pc_s), (pc_c - 1));
					}
					else if ((v == 2) && ((pc_c + 3) <= 9) && (temp[pc_s][pc_c + 2].progress == 'X')) {
						pc_motion_blok((pc_s), (pc_c + 3));
					}
					else if ((v == 3) && ((pc_c - 2) >= 0) && (temp[pc_s][pc_c - 1].progress == 'X')) {
						pc_motion_blok((pc_s), (pc_c - 2));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 0) && (orientation == 0)) {
					v = rand() % 4;
					if ((v == 0) && ((pc_c - 2) >= 0)) {
						pc_motion_blok((pc_s), (pc_c - 2));
					}
					else if ((v == 1) && ((pc_c + 1) <= 9)) {
						pc_motion_blok((pc_s), (pc_c + 1));
					}
					else if ((v == 2) && ((pc_c - 3) >= 0) && (temp[pc_s][pc_c - 2].progress == 'X')) {
						pc_motion_blok((pc_s), (pc_c - 3));
					}
					else if ((v == 3) && ((pc_c + 2) <= 9) && (temp[pc_s][pc_c + 1].progress == 'X')) {
						pc_motion_blok((pc_s), (pc_c + 2));
					}
					else {
						pc_motion();
					}
				}
			}

			//6++
			if ((pc_s != 0) && (pc_s != 9) && (pc_c == 9)) {
				if ((direction == 1) && (orientation == 1)) {
					v = rand() % 4;
					if ((v == 0) && ((pc_s + 2) <= 9)) {
						pc_motion_blok((pc_s + 2), (pc_c));
					}
					else if ((v == 1) && ((pc_s - 1) >= 0)) {
						pc_motion_blok((pc_s - 1), (pc_c));
					}
					else if ((v == 2) && ((pc_s + 3) <= 9) && (temp[pc_s + 2][pc_c].progress == 'X')) {
						pc_motion_blok((pc_s + 3), (pc_c));
					}
					else if ((v == 3) && ((pc_s - 2) >= 0) && (temp[pc_s - 1][pc_c].progress == 'X')) {
						pc_motion_blok((pc_s - 2), (pc_c));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 1) && (orientation == 0)) {
					v = rand() % 4;
					if ((v == 0) && ((pc_s - 2) >= 0)) {
						pc_motion_blok((pc_s - 2), (pc_c));
					}
					else if ((v == 1) && ((pc_s + 1) <= 9)) {
						pc_motion_blok((pc_s + 1), (pc_c));
					}
					else if ((v == 2) && ((pc_s - 3) >= 0) && (temp[pc_s - 2][pc_c].progress == 'X')) {
						pc_motion_blok((pc_s - 3), (pc_c));
					}
					else if ((v == 3) && ((pc_s + 2) <= 9) && (temp[pc_s + 1][pc_c].progress == 'X')) {
						pc_motion_blok((pc_s + 2), (pc_c));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 0) && (orientation == 0)) {
					pc_motion_blok((pc_s), (pc_c - 3));
				}
			}

			//7++
			if ((pc_s == 9) && (pc_c == 0)) {
				if ((direction == 1) && (orientation == 0)) {
					pc_motion_blok((pc_s - 3), pc_c);
				}
				else if ((direction == 0) && (orientation == 1)) {
					pc_motion_blok((pc_s), (pc_c + 3));
				}
			}

			//8++
			if ((pc_s == 9) && (pc_c != 0) && (pc_c != 9)) {
				if ((direction == 1) && (orientation == 0)) {
					pc_motion_blok((pc_s - 3), (pc_c));
				}
				else if ((direction == 0) && (orientation == 1)) {
					v = rand() % 4;
					if ((v == 0) && ((pc_c + 2) <= 9)) {
						pc_motion_blok((pc_s), (pc_c + 2));
					}
					else if ((v == 1) && ((pc_c - 1) >= 0)) {
						pc_motion_blok((pc_s), (pc_c - 1));
					}
					else if ((v == 2) && ((pc_c + 3) <= 9) && (temp[pc_s][pc_c + 2].progress == 'X')) {
						pc_motion_blok((pc_s), (pc_c + 3));
					}
					else if ((v == 3) && ((pc_c - 2) >= 0) && (temp[pc_s][pc_c - 1].progress == 'X')) {
						pc_motion_blok((pc_s), (pc_c - 2));
					}
					else {
						pc_motion();
					}
				}
				else if ((direction == 0) && (orientation == 0)) {
					v = rand() % 4;
					if ((v == 0) && ((pc_c - 2) >= 0)) {
						pc_motion_blok((pc_s), (pc_c - 2));
					}
					else if ((v == 1) && ((pc_c + 1) <= 9)) {
						pc_motion_blok((pc_s), (pc_c + 1));
					}
					else if ((v == 2) && ((pc_c - 3) >= 0) && (temp[pc_s][pc_c - 2].progress == 'X')) {
						pc_motion_blok((pc_s), (pc_c - 3));
					}
					else if ((v == 3) && ((pc_c + 2) <= 9) && (temp[pc_s][pc_c + 1].progress == 'X')) {
						pc_motion_blok((pc_s), (pc_c + 2));
					}
					else {
						pc_motion();
					}
				}
			}

			//9++
			if ((pc_s == 9) && (pc_c == 9)) {
				if ((direction == 1) && (orientation == 0)) {
					pc_motion_blok((pc_s - 3), pc_c);
				}
				else if ((direction == 0) && (orientation == 0)) {
					pc_motion_blok((pc_s), (pc_c - 3));
				}
			}



		
		
		}

	}
}

void user_motion() {

	
	if (end_game() == 0) {

		cout << endl;

	}

	else if (end_game() == 1) {

		system("cls");

		start_game();

		cout << endl;
		cout << endl;

		cout << "ВАШ ХОД ";


		cout << endl;

		cout << "Введите координаты выстрела [y x]: ";
		//cin >> k >> c;

		gets_s(e);

		int q = 0;

		for (int i = 0;;i++) {
		
			if (e[i] == ' ') {
				continue;
			}
			else {

				if (q == 0) {
					k = e[i];
					q++;
				}

				else if (q == 1) {
				
					c = e[i]-48;
					q++;
				}
			}

			if (e[i] == '\0') {
				break;
			}
		}

		//cout << k << " " << c;


		switch (k) {

		case 'А':
		case'а':
			s = 0;
			break;
		case 'Б':
		case'б':
			s = 1;
			break;
		case 'В':
		case'в':
			s = 2;
			break;
		case 'Г':
		case'г':
			s = 3;
			break;
		case 'Д':
		case'д':
			s = 4;
			break;
		case 'Е':
		case'е':
			s = 5;
			break;
		case 'Ж':
		case'ж':
			s = 6;
			break;
		case 'З':
		case'з':
			s = 7;
			break;
		case 'И':
		case'и':
			s = 8;
			break;
		case 'К':
		case'к':
			s = 9;
			break;
		default: s = 10;
			break;
		}

		if (s == 10 || c < 0 || c>9) {
			cout << endl;
			cout << "Ошибка!!! Введены некорректные данные";
			Sleep(1000);
			user_motion();
		}

		else if ((pc_temp[s][c].progress == '.') || (pc_temp[s][c].progress == 'X')) {
			//повтор координат
			cout << endl;
			cout << "Ошибка!!! Повтор координат";
			Sleep(1000);

			user_motion();

		}

		else if (pc_temp[s][c].korabl == ((char)254)) {

			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			pc_temp[s][c].korabl = 'X';
			pc_temp[s][c].progress = 'X';
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

			if (check_of_ships() == 0) {
				
				Sleep(1500);

				//повтор хода
				end_game();

				system("cls");
				start_game();
				cout << endl;
				cout << endl;
				cout << "ВАШ ХОД ";
				cout << endl;

				cout << "Введите координаты выстрела [y x]: ";
				cout << k << c << " УБИЛ ";

				Sleep(1500);
				user_motion();


				
		
			}

			else if (check_of_ships() == 1) {


				

				Sleep(1500);

				//повтор хода
				end_game();

				system("cls");
				start_game();
				cout << endl;
				cout << endl;
				cout << "ВАШ ХОД ";
				cout << endl;

				cout << "Введите координаты выстрела [y x]: ";
				cout << k << c << " ПОПАЛ ";

				Sleep(1500);
				user_motion();
			}


		}

		else if (pc_temp[s][c].korabl != ((char)254)) {

			SetConsoleCP(866);
			SetConsoleOutputCP(866);
			pc_temp[s][c].korabl = '.';
			pc_temp[s][c].progress = '.';
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

			Sleep(1500);

			//повтор хода
			end_game();

			system("cls");
			start_game();
			cout << endl;
			cout << endl;
			cout << "ВАШ ХОД ";
			cout << endl;

			cout << "Введите координаты выстрела [y x]: ";
			cout << k << c << " ПРОМАХ ";

			Sleep(1500);
			
			pc_motion();
		}

	}









}










void ship_avto(int deck)
{
	int s, c;
	bool direction;

	four_deckers.flag = four_decker.flag;
	three_deckers.flag = three_decker_1.flag + three_decker_2.flag;
	double_deckers.flag = double_decker_1.flag + double_decker_2.flag + double_decker_3.flag;
	single_deckers.flag = single_decker_1.flag + single_decker_2.flag + single_decker_3.flag + single_decker_4.flag;


	//srand(time(0));



	if (deck == 1) {

		for (;;) {
			direction = rand() % 2;
			s = rand() % 10;
			c = rand() % 10;
			//cout <<"three "<< s << " " << c << " " << direction << " ";
			if (place_ship(s, c, direction, deck) == 0) {
				break;
			}
			else {
				continue;
			}
		}

		if (single_deckers.flag == 0) {

			if (direction == 0) {
				single_decker_1.deck_1.y = s;
				single_decker_1.deck_1.x = c;

				temp[single_decker_1.deck_1.y][single_decker_1.deck_1.x].korabl = 254;

				single_decker_1.flag = 1;
			}
			else {
				single_decker_1.deck_1.x = c;
				single_decker_1.deck_1.y = s;

				temp[single_decker_1.deck_1.y][single_decker_1.deck_1.x].korabl = 254;

				single_decker_1.flag = 1;
			}
		}

		else if (single_deckers.flag == 1) {

			if (direction == 0) {
				single_decker_2.deck_1.y = s;
				single_decker_2.deck_1.x = c;

				temp[single_decker_2.deck_1.y][single_decker_2.deck_1.x].korabl = 254;

				single_decker_2.flag = 1;
			}
			else {
				single_decker_2.deck_1.x = c;
				single_decker_2.deck_1.y = s;

				temp[single_decker_2.deck_1.y][single_decker_2.deck_1.x].korabl = 254;

				single_decker_2.flag = 1;
			}
		}

		else if (single_deckers.flag == 2) {

			if (direction == 0) {
				single_decker_3.deck_1.y = s;
				single_decker_3.deck_1.x = c;

				temp[single_decker_3.deck_1.y][single_decker_3.deck_1.x].korabl = 254;

				single_decker_3.flag = 1;
			}
			else {
				single_decker_3.deck_1.x = c;
				single_decker_3.deck_1.y = s;

				temp[single_decker_3.deck_1.y][single_decker_3.deck_1.x].korabl = 254;

				single_decker_3.flag = 1;
			}
		}

		else if (single_deckers.flag == 3) {

			if (direction == 0) {
				single_decker_4.deck_1.y = s;
				single_decker_4.deck_1.x = c;

				temp[single_decker_4.deck_1.y][single_decker_4.deck_1.x].korabl = 254;

				single_decker_4.flag = 1;

			}
			else {
				single_decker_4.deck_1.x = c;
				single_decker_4.deck_1.y = s;

				temp[single_decker_4.deck_1.y][single_decker_4.deck_1.x].korabl = 254;

				single_decker_4.flag = 1;


			}



		}

	}

	else if (deck == 2) {

		for (;;) {
			direction = rand() % 2;
			s = rand() % 10;
			c = rand() % 10;
			//cout <<"three "<< s << " " << c << " " << direction << " ";
			if (place_ship(s, c, direction, deck) == 0) {
				break;
			}
			else {
				continue;
			}
		}

		if (double_deckers.flag == 0) {

			if (direction == 0) {
				double_decker_1.deck_1.y = double_decker_1.deck_2.y = s;
				double_decker_1.deck_1.x = c;
				double_decker_1.deck_2.x = double_decker_1.deck_1.x + 1;

				temp[double_decker_1.deck_1.y][double_decker_1.deck_1.x].korabl = 254;
				temp[double_decker_1.deck_2.y][double_decker_1.deck_2.x].korabl = 254;

				double_decker_1.flag = 1;
			}
			else {
				double_decker_1.deck_1.x = double_decker_1.deck_2.x = c;
				double_decker_1.deck_1.y = s;
				double_decker_1.deck_2.y = double_decker_1.deck_1.y + 1;

				temp[double_decker_1.deck_1.y][double_decker_1.deck_1.x].korabl = 254;
				temp[double_decker_1.deck_2.y][double_decker_1.deck_2.x].korabl = 254;

				double_decker_1.flag = 1;
			}
		}

		else if (double_deckers.flag == 1) {

			if (direction == 0) {
				double_decker_2.deck_1.y = double_decker_2.deck_2.y = s;
				double_decker_2.deck_1.x = c;
				double_decker_2.deck_2.x = double_decker_2.deck_1.x + 1;

				temp[double_decker_2.deck_1.y][double_decker_2.deck_1.x].korabl = 254;
				temp[double_decker_2.deck_2.y][double_decker_2.deck_2.x].korabl = 254;

				double_decker_2.flag = 1;
			}
			else {
				double_decker_2.deck_1.x = double_decker_2.deck_2.x = c;
				double_decker_2.deck_1.y = s;
				double_decker_2.deck_2.y = double_decker_2.deck_1.y + 1;

				temp[double_decker_2.deck_1.y][double_decker_2.deck_1.x].korabl = 254;
				temp[double_decker_2.deck_2.y][double_decker_2.deck_2.x].korabl = 254;

				double_decker_2.flag = 1;
			}
		}

		else if (double_deckers.flag == 2) {

			if (direction == 0) {
				double_decker_3.deck_1.y = double_decker_3.deck_2.y = s;
				double_decker_3.deck_1.x = c;
				double_decker_3.deck_2.x = double_decker_3.deck_1.x + 1;

				temp[double_decker_3.deck_1.y][double_decker_3.deck_1.x].korabl = 254;
				temp[double_decker_3.deck_2.y][double_decker_3.deck_2.x].korabl = 254;

				double_decker_3.flag = 1;
			}

			else {
				double_decker_3.deck_1.x = double_decker_3.deck_2.x = c;
				double_decker_3.deck_1.y = s;
				double_decker_3.deck_2.y = double_decker_3.deck_1.y + 1;

				temp[double_decker_3.deck_1.y][double_decker_3.deck_1.x].korabl = 254;
				temp[double_decker_3.deck_2.y][double_decker_3.deck_2.x].korabl = 254;

				double_decker_3.flag = 1;

			}
		}




	}

	else if (deck == 3) {

		for (;;) {
			direction = rand() % 2;
			s = rand() % 10;
			c = rand() % 10;
			//cout <<"three "<< s << " " << c << " " << direction << " ";
			if (place_ship(s, c, direction, deck) == 0) {
				break;
			}
			else {
				continue;
			}
		}


		if (three_deckers.flag == 0) {

			if (direction == 0) {
				three_decker_1.deck_1.y = three_decker_1.deck_2.y = three_decker_1.deck_3.y = s;
				three_decker_1.deck_1.x = c;
				three_decker_1.deck_2.x = three_decker_1.deck_1.x + 1;
				three_decker_1.deck_3.x = three_decker_1.deck_2.x + 1;

				temp[three_decker_1.deck_1.y][three_decker_1.deck_1.x].korabl = 254;
				temp[three_decker_1.deck_2.y][three_decker_1.deck_2.x].korabl = 254;
				temp[three_decker_1.deck_3.y][three_decker_1.deck_3.x].korabl = 254;

				three_decker_1.flag = 1;
			}
			else {
				three_decker_1.deck_1.x = three_decker_1.deck_2.x = three_decker_1.deck_3.x = c;
				three_decker_1.deck_1.y = s;
				three_decker_1.deck_2.y = three_decker_1.deck_1.y + 1;
				three_decker_1.deck_3.y = three_decker_1.deck_2.y + 1;

				temp[three_decker_1.deck_1.y][three_decker_1.deck_1.x].korabl = 254;
				temp[three_decker_1.deck_2.y][three_decker_1.deck_2.x].korabl = 254;
				temp[three_decker_1.deck_3.y][three_decker_1.deck_3.x].korabl = 254;

				three_decker_1.flag = 1;
			}
		}

		else if (three_deckers.flag == 1) {

			if (direction == 0) {
				three_decker_2.deck_1.y = three_decker_2.deck_2.y = three_decker_2.deck_3.y = s;
				three_decker_2.deck_1.x = c;
				three_decker_2.deck_2.x = three_decker_2.deck_1.x + 1;
				three_decker_2.deck_3.x = three_decker_2.deck_2.x + 1;

				temp[three_decker_2.deck_1.y][three_decker_2.deck_1.x].korabl = 254;
				temp[three_decker_2.deck_2.y][three_decker_2.deck_2.x].korabl = 254;
				temp[three_decker_2.deck_3.y][three_decker_2.deck_3.x].korabl = 254;

				three_decker_2.flag = 1;
			}
			else {
				three_decker_2.deck_1.x = three_decker_2.deck_2.x = three_decker_2.deck_3.x = c;
				three_decker_2.deck_1.y = s;
				three_decker_2.deck_2.y = three_decker_2.deck_1.y + 1;
				three_decker_2.deck_3.y = three_decker_2.deck_2.y + 1;

				temp[three_decker_2.deck_1.y][three_decker_2.deck_1.x].korabl = 254;
				temp[three_decker_2.deck_2.y][three_decker_2.deck_2.x].korabl = 254;
				temp[three_decker_2.deck_3.y][three_decker_2.deck_3.x].korabl = 254;

				three_decker_2.flag = 1;
			}
		}





	}

	else if (deck == 4) {

		for (;;) {
			direction = rand() % 2;
			s = rand() % 10; c = rand() % 10;
			//cout << "thor " << s << " " << c << " " << direction << " ";
			if (place_ship(s, c, direction, deck) == 0) {
				break;
			}
			else {
				continue;
			}
		}

		if (direction == 0) {
			four_decker.deck_1.y = four_decker.deck_2.y = four_decker.deck_3.y = four_decker.deck_4.y = s;
			four_decker.deck_1.x = c;
			four_decker.deck_2.x = four_decker.deck_1.x + 1;
			four_decker.deck_3.x = four_decker.deck_2.x + 1;
			four_decker.deck_4.x = four_decker.deck_3.x + 1;

			temp[four_decker.deck_1.y][four_decker.deck_1.x].korabl = 254;
			temp[four_decker.deck_2.y][four_decker.deck_2.x].korabl = 254;
			temp[four_decker.deck_3.y][four_decker.deck_3.x].korabl = 254;
			temp[four_decker.deck_4.y][four_decker.deck_4.x].korabl = 254;

			four_decker.flag = 1;


		}
		else {


			four_decker.deck_1.x = four_decker.deck_2.x = four_decker.deck_3.x = four_decker.deck_4.x = c;
			four_decker.deck_1.y = s;
			four_decker.deck_2.y = four_decker.deck_1.y + 1;
			four_decker.deck_3.y = four_decker.deck_2.y + 1;
			four_decker.deck_4.y = four_decker.deck_3.y + 1;

			temp[four_decker.deck_1.y][four_decker.deck_1.x].korabl = 254;
			temp[four_decker.deck_2.y][four_decker.deck_2.x].korabl = 254;
			temp[four_decker.deck_3.y][four_decker.deck_3.x].korabl = 254;
			temp[four_decker.deck_4.y][four_decker.deck_4.x].korabl = 254;

			four_decker.flag = 1;

		}



	}


	four_deckers.flag = four_decker.flag;
	three_deckers.flag = three_decker_1.flag + three_decker_2.flag;
	double_deckers.flag = double_decker_1.flag + double_decker_2.flag + double_decker_3.flag;
	single_deckers.flag = single_decker_1.flag + single_decker_2.flag + single_decker_3.flag + single_decker_4.flag;

}

void ship_manual(int s, int c, bool direction, int deck)
{
	four_deckers.flag = four_decker.flag;
	three_deckers.flag = three_decker_1.flag + three_decker_2.flag;
	double_deckers.flag = double_decker_1.flag + double_decker_2.flag + double_decker_3.flag;
	single_deckers.flag = single_decker_1.flag + single_decker_2.flag + single_decker_3.flag + single_decker_4.flag;



	



	if (deck == 1) {



		if (single_deckers.flag == 0) {

			if (direction == 0) {
				single_decker_1.deck_1.y = s;
				single_decker_1.deck_1.x = c;

				temp[single_decker_1.deck_1.y][single_decker_1.deck_1.x].korabl = 254;

				single_decker_1.flag = 1;
			}
			else {
				single_decker_1.deck_1.x = c;
				single_decker_1.deck_1.y = s;

				temp[single_decker_1.deck_1.y][single_decker_1.deck_1.x].korabl = 254;

				single_decker_1.flag = 1;
			}
		}

		else if (single_deckers.flag == 1) {

			if (direction == 0) {
				single_decker_2.deck_1.y = s;
				single_decker_2.deck_1.x = c;

				temp[single_decker_2.deck_1.y][single_decker_2.deck_1.x].korabl = 254;

				single_decker_2.flag = 1;
			}
			else {
				single_decker_2.deck_1.x = c;
				single_decker_2.deck_1.y = s;

				temp[single_decker_2.deck_1.y][single_decker_2.deck_1.x].korabl = 254;

				single_decker_2.flag = 1;
			}
		}

		else if (single_deckers.flag == 2) {

			if (direction == 0) {
				single_decker_3.deck_1.y = s;
				single_decker_3.deck_1.x = c;

				temp[single_decker_3.deck_1.y][single_decker_3.deck_1.x].korabl = 254;

				single_decker_3.flag = 1;
			}
			else {
				single_decker_3.deck_1.x = c;
				single_decker_3.deck_1.y = s;

				temp[single_decker_3.deck_1.y][single_decker_3.deck_1.x].korabl = 254;

				single_decker_3.flag = 1;
			}
		}

		else if (single_deckers.flag == 3) {

			if (direction == 0) {
				single_decker_4.deck_1.y = s;
				single_decker_4.deck_1.x = c;

				temp[single_decker_4.deck_1.y][single_decker_4.deck_1.x].korabl = 254;

				single_decker_4.flag = 1;

			}
			else {
				single_decker_4.deck_1.x = c;
				single_decker_4.deck_1.y = s;

				temp[single_decker_4.deck_1.y][single_decker_4.deck_1.x].korabl = 254;

				single_decker_4.flag = 1;


			}



		}

	}

	else if (deck == 2) {



		if (double_deckers.flag == 0) {

			if (direction == 0) {
				double_decker_1.deck_1.y = double_decker_1.deck_2.y = s;
				double_decker_1.deck_1.x = c;
				double_decker_1.deck_2.x = double_decker_1.deck_1.x + 1;

				temp[double_decker_1.deck_1.y][double_decker_1.deck_1.x].korabl = 254;
				temp[double_decker_1.deck_2.y][double_decker_1.deck_2.x].korabl = 254;

				double_decker_1.flag = 1;
			}
			else {
				double_decker_1.deck_1.x = double_decker_1.deck_2.x = c;
				double_decker_1.deck_1.y = s;
				double_decker_1.deck_2.y = double_decker_1.deck_1.y + 1;

				temp[double_decker_1.deck_1.y][double_decker_1.deck_1.x].korabl = 254;
				temp[double_decker_1.deck_2.y][double_decker_1.deck_2.x].korabl = 254;

				double_decker_1.flag = 1;
			}
		}

		else if (double_deckers.flag == 1) {

			if (direction == 0) {
				double_decker_2.deck_1.y = double_decker_2.deck_2.y = s;
				double_decker_2.deck_1.x = c;
				double_decker_2.deck_2.x = double_decker_2.deck_1.x + 1;

				temp[double_decker_2.deck_1.y][double_decker_2.deck_1.x].korabl = 254;
				temp[double_decker_2.deck_2.y][double_decker_2.deck_2.x].korabl = 254;

				double_decker_2.flag = 1;
			}
			else {
				double_decker_2.deck_1.x = double_decker_2.deck_2.x = c;
				double_decker_2.deck_1.y = s;
				double_decker_2.deck_2.y = double_decker_2.deck_1.y + 1;

				temp[double_decker_2.deck_1.y][double_decker_2.deck_1.x].korabl = 254;
				temp[double_decker_2.deck_2.y][double_decker_2.deck_2.x].korabl = 254;

				double_decker_2.flag = 1;
			}
		}

		else if (double_deckers.flag == 2) {

			if (direction == 0) {
				double_decker_3.deck_1.y = double_decker_3.deck_2.y = s;
				double_decker_3.deck_1.x = c;
				double_decker_3.deck_2.x = double_decker_3.deck_1.x + 1;

				temp[double_decker_3.deck_1.y][double_decker_3.deck_1.x].korabl = 254;
				temp[double_decker_3.deck_2.y][double_decker_3.deck_2.x].korabl = 254;

				double_decker_3.flag = 1;
			}

			else {
				double_decker_3.deck_1.x = double_decker_3.deck_2.x = c;
				double_decker_3.deck_1.y = s;
				double_decker_3.deck_2.y = double_decker_3.deck_1.y + 1;

				temp[double_decker_3.deck_1.y][double_decker_3.deck_1.x].korabl = 254;
				temp[double_decker_3.deck_2.y][double_decker_3.deck_2.x].korabl = 254;

				double_decker_3.flag = 1;

			}
		}




	}

	else if (deck == 3) {




		if (three_deckers.flag == 0) {

			if (direction == 0) {
				three_decker_1.deck_1.y = three_decker_1.deck_2.y = three_decker_1.deck_3.y = s;
				three_decker_1.deck_1.x = c;
				three_decker_1.deck_2.x = three_decker_1.deck_1.x + 1;
				three_decker_1.deck_3.x = three_decker_1.deck_2.x + 1;

				temp[three_decker_1.deck_1.y][three_decker_1.deck_1.x].korabl = 254;
				temp[three_decker_1.deck_2.y][three_decker_1.deck_2.x].korabl = 254;
				temp[three_decker_1.deck_3.y][three_decker_1.deck_3.x].korabl = 254;

				three_decker_1.flag = 1;
			}
			else {
				three_decker_1.deck_1.x = three_decker_1.deck_2.x = three_decker_1.deck_3.x = c;
				three_decker_1.deck_1.y = s;
				three_decker_1.deck_2.y = three_decker_1.deck_1.y + 1;
				three_decker_1.deck_3.y = three_decker_1.deck_2.y + 1;

				temp[three_decker_1.deck_1.y][three_decker_1.deck_1.x].korabl = 254;
				temp[three_decker_1.deck_2.y][three_decker_1.deck_2.x].korabl = 254;
				temp[three_decker_1.deck_3.y][three_decker_1.deck_3.x].korabl = 254;

				three_decker_1.flag = 1;
			}
		}

		else if (three_deckers.flag == 1) {

			if (direction == 0) {
				three_decker_2.deck_1.y = three_decker_2.deck_2.y = three_decker_2.deck_3.y = s;
				three_decker_2.deck_1.x = c;
				three_decker_2.deck_2.x = three_decker_2.deck_1.x + 1;
				three_decker_2.deck_3.x = three_decker_2.deck_2.x + 1;

				temp[three_decker_2.deck_1.y][three_decker_2.deck_1.x].korabl = 254;
				temp[three_decker_2.deck_2.y][three_decker_2.deck_2.x].korabl = 254;
				temp[three_decker_2.deck_3.y][three_decker_2.deck_3.x].korabl = 254;

				three_decker_2.flag = 1;
			}
			else {
				three_decker_2.deck_1.x = three_decker_2.deck_2.x = three_decker_2.deck_3.x = c;
				three_decker_2.deck_1.y = s;
				three_decker_2.deck_2.y = three_decker_2.deck_1.y + 1;
				three_decker_2.deck_3.y = three_decker_2.deck_2.y + 1;

				temp[three_decker_2.deck_1.y][three_decker_2.deck_1.x].korabl = 254;
				temp[three_decker_2.deck_2.y][three_decker_2.deck_2.x].korabl = 254;
				temp[three_decker_2.deck_3.y][three_decker_2.deck_3.x].korabl = 254;

				three_decker_2.flag = 1;
			}
		}





	}

	else if (deck == 4) {



		if (direction == 0) {
			four_decker.deck_1.y = four_decker.deck_2.y = four_decker.deck_3.y = four_decker.deck_4.y = s;
			four_decker.deck_1.x = c;
			four_decker.deck_2.x = four_decker.deck_1.x + 1;
			four_decker.deck_3.x = four_decker.deck_2.x + 1;
			four_decker.deck_4.x = four_decker.deck_3.x + 1;

			temp[four_decker.deck_1.y][four_decker.deck_1.x].korabl = 254;
			temp[four_decker.deck_2.y][four_decker.deck_2.x].korabl = 254;
			temp[four_decker.deck_3.y][four_decker.deck_3.x].korabl = 254;
			temp[four_decker.deck_4.y][four_decker.deck_4.x].korabl = 254;

			four_decker.flag = 1;


		}
		else {


			four_decker.deck_1.x = four_decker.deck_2.x = four_decker.deck_3.x = four_decker.deck_4.x = c;
			four_decker.deck_1.y = s;
			four_decker.deck_2.y = four_decker.deck_1.y + 1;
			four_decker.deck_3.y = four_decker.deck_2.y + 1;
			four_decker.deck_4.y = four_decker.deck_3.y + 1;

			temp[four_decker.deck_1.y][four_decker.deck_1.x].korabl = 254;
			temp[four_decker.deck_2.y][four_decker.deck_2.x].korabl = 254;
			temp[four_decker.deck_3.y][four_decker.deck_3.x].korabl = 254;
			temp[four_decker.deck_4.y][four_decker.deck_4.x].korabl = 254;

			four_decker.flag = 1;

		}



	}

	four_deckers.flag = four_decker.flag;
	three_deckers.flag = three_decker_1.flag + three_decker_2.flag;
	double_deckers.flag = double_decker_1.flag + double_decker_2.flag + double_decker_3.flag;
	single_deckers.flag = single_decker_1.flag + single_decker_2.flag + single_decker_3.flag + single_decker_4.flag;

}

void name_game() {

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	cout << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;



	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0
		<< " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0
		<< " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;


	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;


	cout << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;


	cout << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;


	cout << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;


	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " ";


	cout << endl;
	cout << endl;


	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;


	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;


}

void name_game_short() {

	cout << endl;


	cout << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;




	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0
		<< " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0
		<< " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;



	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;



	cout << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;



	cout << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;



	cout << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;



	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " ";


	cout << endl;



	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;



	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;


}

void cover()
{
	system("cls");

	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	/*Получение дескриптора*/
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_FONT_INFOEX fontInfo;

	// эта строка нужна
	fontInfo.cbSize = sizeof(fontInfo);

	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);

	// это неправильное использование функции
	//wcsncpy(L"Lucida Console", fontInfo.FaceName, LF_FACESIZE);

	wcscpy(fontInfo.FaceName, L"Lucida Console");

	fontInfo.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);

	/*Цвет всего фона - белый. Цвет всего текста - черный*/
	system("color 14");

	/*Цвет символов - желтый. Цвет фона - темно-серый*/
	SetConsoleTextAttribute(hConsole, (WORD)((1 << 4) | 14));


	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	Sleep(200);
	cout << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;


	Sleep(190);
	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0
		<< " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0
		<< " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;

	Sleep(180);
	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;

	Sleep(170);
	cout << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;

	Sleep(160);
	cout << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;

	Sleep(150);
	cout << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;

	Sleep(140);
	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " ";


	cout << endl;
	cout << endl;

	Sleep(130);
	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;

	Sleep(120);
	cout << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " "
		<< (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " "
		<< (char)0 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " " << (char)0 << " " << (char)219 << " " << (char)219 << " " << (char)0 << " "
		<< (char)0 << " " << (char)219 << " " << (char)219 << " ";

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	cout << "\t\t\t\t\t\t";
	system("pause");



	////////////////////////////////////////



}

void at_first() {

	four_decker.flag = 0;

	three_decker_1.flag = 0;
	three_decker_2.flag = 0;

	double_decker_1.flag = 0;
	double_decker_2.flag = 0;
	double_decker_3.flag = 0;

	single_decker_1.flag = 0;
	single_decker_2.flag = 0;
	single_decker_3.flag = 0;
	single_decker_4.flag = 0;

	four_deckers.flag = four_decker.flag;
	three_deckers.flag = three_decker_1.flag + three_decker_2.flag;
	double_deckers.flag = double_decker_1.flag + double_decker_2.flag + double_decker_3.flag;
	single_deckers.flag = single_decker_1.flag + single_decker_2.flag + single_decker_3.flag + single_decker_4.flag;

	pc_four_decker.flag = 0;

	pc_three_decker_1.flag = 0;
	pc_three_decker_2.flag = 0;

	pc_double_decker_1.flag = 0;
	pc_double_decker_2.flag = 0;
	pc_double_decker_3.flag = 0;

	pc_single_decker_1.flag = 0;
	pc_single_decker_2.flag = 0;
	pc_single_decker_3.flag = 0;
	pc_single_decker_4.flag = 0;

	pc_four_deckers.flag = pc_four_decker.flag;
	pc_three_deckers.flag = pc_three_decker_1.flag + pc_three_decker_2.flag;
	pc_double_deckers.flag = pc_double_decker_1.flag + pc_double_decker_2.flag + pc_double_decker_3.flag;
	pc_single_deckers.flag = pc_single_decker_1.flag + pc_single_decker_2.flag + pc_single_decker_3.flag + pc_single_decker_4.flag;





	for (int i = 0; i < N; i++)
	{

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		for (int j = 0; j < N; j++)
		{
			temp[i][j].korabl = (char)0;

		}
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

	}

	for (int i = 0; i < N; i++)
	{

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		for (int j = 0; j < N; j++)
		{
			temp[i][j].progress = (char)0;

		}
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

	}



	for (int i = 0; i < N; i++)
	{

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		for (int j = 0; j < N; j++)
		{
			pc_temp[i][j].korabl = (char)0;

		}
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

	}

	for (int i = 0; i < N; i++)
	{

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		for (int j = 0; j < N; j++)
		{
			pc_temp[i][j].progress = (char)0;

		}
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

	}



}

void manual() {

	system("cls");

	cout << "\tРАССТАНОВКА КОРАБЛЕЙ ИГРОКА \n\n";

	cout << endl;

	cout << "\t";

	cout << "  0 1 2 3 4 5 6 7 8 9\n";

	for (int i = 0; i < N; i++)
	{
		cout << "\t";
		cout << stolbec[i] << "";

		cout << "|";

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		for (int j = 0; j < N; j++)
		{
			cout << "" << temp[i][j].korabl << "|";

		}
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);


		if (i == 1) {

			cout << "\t\t";
			//cout << "Четырехпалубный ";

			SetConsoleCP(866);
			SetConsoleOutputCP(866);

			cout << (char)254 << " " << (char)254 << " " << (char)254 << " " << (char)254 << " ";
			cout << " X ";
			cout << four_deckers.flag;

			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

		}

		if (i == 3) {

			cout << "\t\t";
			//cout << "Трехпалубный ";

			SetConsoleCP(866);
			SetConsoleOutputCP(866);

			cout << (char)254 << " " << (char)254 << " " << (char)254 << " ";
			cout << "\t X ";
			cout << three_deckers.flag;

			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

		}

		if (i == 5) {

			cout << "\t\t";
			//cout << "Двухпалубный ";

			SetConsoleCP(866);
			SetConsoleOutputCP(866);

			cout << (char)254 << " " << (char)254 << " ";
			cout << "\t X ";
			cout << double_deckers.flag;

			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

		}

		if (i == 7) {

			cout << "\t\t";
			//cout << "Однопалубный ";

			SetConsoleCP(866);
			SetConsoleOutputCP(866);

			cout << (char)254 << " ";
			cout << "\t X ";
			cout << single_deckers.flag;

			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);

		}




		cout << endl;
	}

	if ((four_deckers.flag == 1) && (three_deckers.flag == 2) && (double_deckers.flag == 3) && (single_deckers.flag == 4))

	{


		cout << endl;
		cout << endl;

		cout << "\t[F1] - Начать игру ";

		cout << endl;
		cout << endl;

		cout << "\t[Esc] - Назад";

		cout << endl;

		cout << "\t";

		for (;;)

		{

			choice = _getch();


			if (choice == 59)

			{
				cout << "F1";
				start_game();
				break;
			}



			if (choice == 27)
			{
				cout << "Esc";
				placement_user();
				break;

			}

		}
	}

	else {

		cout << endl;
		cout << endl;

		cout << "Введите [через пробел] начальные координаты корабля[y x], расположение [0 - горизонтально, 1 - вериткально], количество палуб [от 1 до 4]\nнапример [А 5 0 4]:  ";
		//cin >> k >> c >> direction >> deck;

		gets_s(e);

		int q = 0;

		for (int i = 0;; i++) {

			if (e[i] == ' ') {
				continue;
			}
			else {

				if (q == 0) {
					k = e[i];
					q++;
				}

				else if (q == 1) {

					c = e[i] - 48;
					q++;
				}

				else if (q == 2) {

					direction = e[i] - 48;
					q++;
				}

				else if (q == 3) {

					deck = e[i] - 48;
					q++;
				}

			}

			if (e[i] == '\0') {
				break;
			}
		}


		








		switch (k) {

		case 'А':
		case'а':
			s = 0;
			break;
		case 'Б':
		case'б':
			s = 1;
			break;
		case 'В':
		case'в':
			s = 2;
			break;
		case 'Г':
		case'г':
			s = 3;
			break;
		case 'Д':
		case'д':
			s = 4;
			break;
		case 'Е':
		case'е':
			s = 5;
			break;
		case 'Ж':
		case'ж':
			s = 6;
			break;
		case 'З':
		case'з':
			s = 7;
			break;
		case 'И':
		case'и':
			s = 8;
			break;
		case 'К':
		case'к':
			s = 9;
			break;
		default: s = 10;
			break;
		}

		if (s == 10 || c < 0 || c>9 || direction != (int)0 && direction != (int)1 || deck < 1 || deck>4) {
			cout << endl;
			cout << "Ошибка!!! Введены некорректные данные";
			Sleep(1000);
			manual();
		}

		else if (((four_deckers.flag == 1) && (deck == 4)) || ((three_deckers.flag == 2) && (deck == 3)) || ((double_deckers.flag == 3) && (deck == 2)) || ((single_deckers.flag == 4) && (deck == 1))) {

			cout << endl;
			cout << "Ошибка!!! Недопустимое количество кораблей данного типа";
			Sleep(1000);
			manual();

		}


		else if (place_ship(s, c, direction, deck) == 0) {

			ship_manual(s, c, direction, deck);
			manual();

		}

		else if (place_ship(s, c, direction, deck) == 1) {

			cout << endl;
			cout << "Ошибка!!! Введены некорректные координаты";
			Sleep(1000);
			manual();


		}





	}
}

void avto() {

	at_first();

	ship_avto(4);

	for (int i = 0; i < 2; i++) {
		ship_avto(3);
	}

	for (int i = 0; i < 3; i++) {
		ship_avto(2);
	}

	for (int i = 0; i < 4; i++) {
		ship_avto(1);
	}

	system("cls");

	cout << "\tРАССТАНОВКА КОРАБЛЕЙ ИГРОКА \n\n";

	cout << endl;

	cout << "\t";

	cout << "  0 1 2 3 4 5 6 7 8 9\n";

	for (int i = 0; i < N; i++)
	{
		cout << "\t";
		cout << stolbec[i] << "";

		cout << "|";

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		for (int j = 0; j < N; j++)
		{
			cout << "" << temp[i][j].korabl << "|";

		}
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		cout << endl;
	}

	cout << endl;
	cout << endl;

	cout << "\t[F1] - Начать игру \n\n\t[F2] - Автоматическая установка повторить";

	cout << endl;
	cout << endl;

	cout << "\t[Esc] - Назад";

	cout << endl;

	cout << "\t";

	for (;;) {

		choice = _getch();


		if (choice == 59)

		{
			cout << "F1";
			pc_avto();
			//start_game();
			break;
		}

		if (choice == 60)
		{
			cout << "F2";
			//Sleep(1000);
			avto();
			break;
		}

		if (choice == 27)
		{
			cout << "Esc";
			placement_user();
			break;

		}

	}




}

void placement_user() {

	at_first();

	system("cls");

	cout << "\tРАССТАНОВКА КОРАБЛЕЙ ИГРОКА \n\n";

	cout << endl;

	cout << "\t";

	cout << "  0 1 2 3 4 5 6 7 8 9\n";

	for (int i = 0; i < N; i++)
	{
		cout << "\t";
		cout << stolbec[i] << "";

		cout << "|";

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		for (int j = 0; j < N; j++)
		{
			cout << "" << temp[i][j].korabl << "|";

		}
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		cout << endl;
	}

	cout << endl;
	cout << endl;

	cout << "\t[F1] - Ручная установка \n\n\t[F2] - Автоматическая установка ";

	cout << "\n\n\t[Esc] - Назад в главное меню ";

	cout << endl;

	cout << "\t";

	for (;;) {

		choice = _getch();


		if (choice == 59)

		{
			cout << "F1";
			manual();
			break;
		}


		if (choice == 60)
		{
			cout << "F2";
			//Sleep(1000);
			avto();
			break;
		}

		if (choice == 27)
		{
			cout << "Esc";
			menu_game();
			break;

		}
	}


}

void pravila_game() {

	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	system("cls");

	name_game_short();

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\n\t\t\t\t\t\t\t\tПРАВИЛА ИГРЫ\n\n";

	cout << "\t\t\tЦель игры – «потопить» все корабли, находящиеся на игровом поле.\n"
		<< "\t\tИгровое поле представляет собой квадрат, состоящий из 10 строк и 10 столбцов.\n"
		<< "\t\tСтроки обозначены буквами русского алфавита от А до К, а столбцы – арабскими цифрами от 0 до 9.\n"
		<< "\t\tНа игровом поле хаотично расположены корабли: 4 однопалубных, 3 двухпалубных, 2 трехпалубных и 1 четырехпалубный.\n"
		<< "\t\tНа поле не допускается соприкосновение соседних кораблей углами и сторонами.\n";





	char A[N][N] = {};

	char B[N][N] = { 254,0,254,254,254,0,254,254,0,254,
					254,0,0,0,0,0,0,0,0,254,
					254,0,254,254,0,0,0,0,0,0,
					254,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,0,0,0,0,
					254,0,0,0,0,0,0,0,0,0,
					254,0,0,0,254,0,0,0,254,0,
					254,0,0,0,0,0,0,0,0,0,
					0,0,0,0,0,0,254,0,0,0,
					0,0,254,0,0,0,0,0,0,0 };

	cout << endl;

	cout << "\t\t\t\t\t";

	cout << "  0 1 2 3 4 5 6 7 8 9\t\t\t  0 1 2 3 4 5 6 7 8 9\n";

	for (int i = 0; i < N; i++)
	{
		cout << "\t\t\t\t\t";
		cout << stolbec[i] << "";

		cout << "|";
		for (int j = 0; j < N; j++)
		{
			cout << "" << A[i][j] << "|";

		}

		cout << "\t\t\t";
		cout << stolbec[i] << "";

		cout << "|";

		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		for (int j = 0; j < N; j++)
		{
			cout << "" << B[i][j] << "|";

		}
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		cout << endl;
	}

	cout << endl;

	cout << "\t\t\t\t\t[Esc] - Назад в меню игры\t\t[F4] - Выход из игры ";

	cout << endl;

	cout << "\t\t\t\t\t\t\t\t\t";

	for (;;) {

		choice = _getch();


		if (choice == 62)
		{
			cout << "F4";
			exit(1);
			break;
		}

		if (choice == 27)
		{
			cout << "Esc";
			menu_game();
			break;
		}

	}
}

void menu_game() {

	system("cls");

	SetConsoleCP(866);
	SetConsoleOutputCP(866);

	name_game();

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*Получение дескриптора*/
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_FONT_INFOEX fontInfo;

	// эта строка нужна
	fontInfo.cbSize = sizeof(fontInfo);

	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);

	// это неправильное использование функции
	//wcsncpy(L"Lucida Console", fontInfo.FaceName, LF_FACESIZE);

	wcscpy(fontInfo.FaceName, L"Lucida Console");

	fontInfo.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);

	/*Цвет всего фона - белый. Цвет всего текста - черный*/
	system("color 14");

	/*Цвет символов - желтый. Цвет фона - темно-серый*/
	SetConsoleTextAttribute(hConsole, (WORD)((1 << 4) | 14));



	cout << endl;
	cout << endl;

	cout << "\t\t\t\t\t\t\t\tМЕНЮ ИГРЫ";

	cout << endl;
	cout << endl;

	cout << "\t\t\t\t\t\t\t[F1] - Игрок начинает первым";
	cout << endl;
	cout << "\t\t\t\t\t\t\t[F2] - Компьютер начинает первым";
	cout << endl;
	cout << "\t\t\t\t\t\t\t[F3] - Правила игры";
	cout << endl;
	cout << "\t\t\t\t\t\t\t[F4] - Выход из игры";

	cout << endl;
	cout << endl;

	cout << "\t\t\t\t\t\t\t\t";






	for (;;) {

		choice = _getch();



		if (choice == 59)

		{
			cout << "F1";
			motion.flag = 1;
			placement_user();
			break;
		}


		if (choice == 60)
		{
			cout << "F2";
			motion.flag = 0;
			placement_user();
			break;
		}

		if (choice == 61)
		{
			cout << "F3";
			pravila_game();
			break;
		}

		if (choice == 62)
		{
			cout << "F4";
			exit(1);
			break;
		}



	}



}








