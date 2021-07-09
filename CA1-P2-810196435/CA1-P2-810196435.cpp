/*Amir Pourmohammadali 810196435*/
#define _CRT_SECURE_NO_WARNINGS/*baraye error nadadan scanf*/
#include <stdio.h>//tarif ketabkhoone ha
#include <math.h>
#include "Header.h"
void main()
{
	initScreen();//fullscreen kardan safhe
	tablef (ROWS_PER_TABLE, COLUMN_PER_TABLE, CELL_WIDTH);//keshidan jadval
	game();//game play codes
	gotoxy(0, (CELL_WIDTH / 2 + 1)*ROWS_PER_TABLE+5);//bordan cursor be pain safhe dar akhar baazi baraye zibaayi!!
}//main end