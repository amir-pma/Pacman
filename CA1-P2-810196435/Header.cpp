/*Amir Pourmohammadali 810196435*/
#include "Header.h"//tarif ketabkhooneye tarif shode
void initScreen(void)//fullscreen kardan
{
	COORD coord;
	HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(stdHandle, CONSOLE_FULLSCREEN_MODE, &coord);
}//end initscreen
void gotoxy(int x, int y)//taghir makaan cursor
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}//end gotoxy
void tablef(int row, int column, int cellchar)//keshidan jadval
{
	int table[ROWS_PER_TABLE + 1][COLUMN_PER_TABLE + 1][2] = { { { { 1 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 1 }, { 1 } }, { { 0 }, { 1 } }, { { 1 }, { 0 } } }, { { { 1 }, { 0 } }, { { 0 }, { 0 } }, { { 1 }, { 0 } }, { { 0 }, { 0 } }, { { 0 }, { 1 } }, { { 1 }, { 0 } }, { { 1 }, { 0 } } }, { { { 1 }, { 0 } }, { { 0 }, { 0 } }, { { 0 }, { 1 } }, { { 1 }, { 0 } }, { { 0 }, { 0 } }, { { 0 }, { 0 } }, { { 1 }, { 0 } } }, { { { 1 }, { 1 } }, { { 1 }, { 0 } }, { { 0 }, { 0 } }, { { 0 }, { 1 } }, { { 1 }, { 0 } }, { { 0 }, { 0 } }, { { 1 }, { 0 } } }, { { { 1 }, { 0 } }, { { 0 }, { 1 } }, { { 0 }, { 0 } }, { { 0 }, { 0 } }, { { 0 }, { 1 } }, { { 1 }, { 0 } }, { { 1 }, { 0 } } }, { { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 0 } } } };//araye sebodi baraye moshakhas kardan khotoot jadval
	for (int i = 0; i <= ROWS_PER_TABLE; i++)//harkat dar radif ha
	{
		for (int j = 0; j <= COLUMN_PER_TABLE; j++)//harkat dar sotoon ha
		{
			if (table[i][j][0] == 0 && table[i][j][1] == 0)//barresi halat haaye momken baraye har khoone
			{
				gotoxy(CELL_WIDTH*j, (CELL_WIDTH / 2 + 1)*i);//keshidan khat avval
				if (j == COLUMN_PER_TABLE && i == ROWS_PER_TABLE)
					printf("-");
				for (int y = 1; y <= (CELL_WIDTH / 2 + 1); y++)//baghie khotoot
				{
					for (int x = 1; x <= CELL_WIDTH; x++)
					{
						printf(" ");
					}//end for
					if (y != (CELL_WIDTH / 2 + 1))
						gotoxy(CELL_WIDTH*j, (CELL_WIDTH / 2 + 1)*i + y);//bordan be khat bad
				}//end for
			}//end if
			if (table[i][j][0] == 0 && table[i][j][1] == 1)
			{
				gotoxy(CELL_WIDTH*j, (CELL_WIDTH / 2 + 1)*i);
				for (int x = 1; x <= CELL_WIDTH; x++)//keshidan khat avval
				{
					printf("-");
				}//end for
				gotoxy(CELL_WIDTH*j, (CELL_WIDTH / 2 + 1)*i + 1);
				for (int y = 1; y <= (CELL_WIDTH / 2); y++)//baghie khotoot
				{
					for (int x = 1; x <= CELL_WIDTH; x++)
					{
						printf(" ");
					}//end for
					if (y != (CELL_WIDTH / 2))
						gotoxy(CELL_WIDTH*j, (CELL_WIDTH / 2 + 1)*i + 1 + y);//bordan be khat baduju
				}//end for
			}//end if
			if (table[i][j][0] == 1 && table[i][j][1] == 0)
			{
				gotoxy(CELL_WIDTH*j, (CELL_WIDTH / 2 + 1)*i);
				for (int y = 1; y <= (CELL_WIDTH / 2 + 1); y++)
				{
					printf("|");
					for (int x = 1; x <= CELL_WIDTH - 1; x++)
					{
						printf(" ");
					}//end for
					if (y != (CELL_WIDTH / 2 + 1))
						gotoxy(CELL_WIDTH*j, (CELL_WIDTH / 2 + 1)*i + y);//bordan be khat baduju
				}//end for
			}//end if
			if (table[i][j][0] == 1 && table[i][j][1] == 1)
			{
				gotoxy(CELL_WIDTH*j, (CELL_WIDTH / 2 + 1)*i);
				for (int x = 1; x <= CELL_WIDTH; x++)
				{
					printf("-");
				}//end for
				gotoxy(CELL_WIDTH*j, (CELL_WIDTH / 2 + 1)*i + 1);
				for (int y = 1; y <= (CELL_WIDTH / 2); y++)
				{
					printf("|");
					for (int x = 1; x <= CELL_WIDTH - 1; x++)
					{
						printf(" ");
					}//end for
					if (y != (CELL_WIDTH / 2))
						gotoxy(CELL_WIDTH*j, (CELL_WIDTH / 2 + 1)*i + 1 + y);//bordan be khat baduju
				}//end for
			}//end if
		}//end for
		printf("\n");
	}//end for
}//end tablef
void packmanf(int dx, int dy,int zavie, char jahat)//keshidan packman
{	
	double shib = tan((double)zavie  * Pi / 360);//shib khat haye dahane packman
	gotoxy(dx - (CELL_WIDTH - 2) / 2, dy - (CELL_WIDTH - 3) / 2);
	for (int j = 1; j <= CELL_WIDTH/2; j++)
	{
		for (int i = 1; i <= CELL_WIDTH-1; i++)
		{
			switch (jahat)//barresi jahat va keshidan packman motenaseb ba oon
			{
			case 's'://rast
				if ((Zarib*(i - (CELL_WIDTH - 2) / 2)*(i - (CELL_WIDTH - 2) / 2) + (j - (CELL_WIDTH - 6) / 2) *(j - (CELL_WIDTH - 6) / 2) < (PACMAN_RADIUS - 2)*(PACMAN_RADIUS - 2)) && (shib*(i - (CELL_WIDTH - 2) / 2) <= abs(j - (CELL_WIDTH - 6) / 2)))//shart bevojood amadan packman
					printf("*");
				else
					printf(" ");
				break;
			case 'a'://chap
				if ((Zarib*(i - (CELL_WIDTH - 2) / 2)*(i - (CELL_WIDTH - 2) / 2) + (j - (CELL_WIDTH - 6) / 2) *(j - (CELL_WIDTH - 6) / 2) < (PACMAN_RADIUS - 2)*(PACMAN_RADIUS - 2)) && (shib*(i - (CELL_WIDTH - 2) / 2) >= -abs(j - 4)))//shart bevojood amadan packman
					printf("*");
				else
					printf(" ");
				break;
			case 'z'://pain
				if ((Zarib*(i - (CELL_WIDTH - 2) / 2)*(i - (CELL_WIDTH - 2) / 2) + (j - (CELL_WIDTH - 6) / 2) *(j - (CELL_WIDTH - 6) / 2) < (PACMAN_RADIUS - 2)*(PACMAN_RADIUS - 2)) && (shib*(j - (CELL_WIDTH - 6) / 2) <= abs(i - (CELL_WIDTH - 2) / 2)))//shart bevojood amadan packman
					printf("*");
				else
					printf(" ");
				break;
			case 'w'://bala
				if ((Zarib*(i - (CELL_WIDTH - 2) / 2)*(i - (CELL_WIDTH - 2) / 2) + (j - (CELL_WIDTH - 6) / 2) *(j - (CELL_WIDTH - 6) / 2) < (PACMAN_RADIUS - 2)*(PACMAN_RADIUS - 2)) && (shib*(j - (CELL_WIDTH - 6) / 2) >= -abs(i - (CELL_WIDTH - 2) / 2)))//shart bevojood amadan packman
					printf("*");
				else
					printf(" ");
				break;
			default:
				break;
			}//end switch
		}//end for
		gotoxy(dx - (CELL_WIDTH - 2) / 2, dy - (CELL_WIDTH - 4) / 2 + j);
	}//end for
	gotoxy(0, (CELL_WIDTH / 2 + 1)*ROWS_PER_TABLE + 5);
}//end packmanf
int waitAndGetDirection(int waitTime, char *direction)//sabr kardan be oon andaze va gereftan jahat
{
	DWORD start_time, check_time;
	start_time = GetTickCount();
	check_time = start_time + waitTime; //GetTickTime returns time in miliseconds
	char ch = 0;
	char hit = 0;

	while (check_time>GetTickCount())
	{
		if (_kbhit())//daryaft jahat jadid
		{
			hit = 1;
			ch = _getch();
			if (ch == 0)
				ch = _getch();
			break;
		}//end if
	}//end while
	if (ch != *direction && (ch == 'w' || ch == 'z' || ch == 'a' || ch == 's'))//check kardan jahat jadid
	{
		*direction = ch;
		return 1;
	}//end if
	else
		return 0;

}//end waitandgetdirection
void game(void)//draw opening mouth packman and ghost and set their next location
{
	int table[ROWS_PER_TABLE + 1][COLUMN_PER_TABLE + 1][3] = { { { { 1 }, { 1 }, { 1 } }, { { 0 }, { 1 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 1 }, { 1 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 1 }, { 0 }, { 0 } } }, { { { 1 }, { 0 }, { 0 } }, { { 0 }, { 0 }, { 0 } }, { { 1 }, { 0 }, { 0 } }, { { 0 }, { 0 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 1 }, { 0 }, { 0 } }, { { 1 }, { 0 }, { 0 } } }, { { { 1 }, { 0 }, { 0 } }, { { 0 }, { 0 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 1 }, { 0 }, { 0 } }, { { 0 }, { 0 }, { 0 } }, { { 0 }, { 0 }, { 0 } }, { { 1 }, { 0 }, { 0 } } }, { { { 1 }, { 1 }, { 0 } }, { { 1 }, { 0 }, { 0 } }, { { 0 }, { 0 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 1 }, { 0 }, { 0 } }, { { 0 }, { 0 }, { 0 } }, { { 1 }, { 0 }, { 0 } } }, { { { 1 }, { 0 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 0 }, { 0 }, { 0 } }, { { 0 }, { 0 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 1 }, { 0 }, { 0 } }, { { 1 }, { 0 }, { 0 } } }, { { { 0 }, { 1 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 0 }, { 1 }, { 0 } }, { { 0 }, { 0 }, { 0 } } } };//tarif araye sebodi baraye keshidan jadval
	int dx = (CELL_WIDTH) / 2, dy = (CELL_WIDTH - 2) / 2, count = 1, gx1 = CELL_WIDTH*(COLUMN_PER_TABLE - 1) + 2, gx2 = CELL_WIDTH*(COLUMN_PER_TABLE - 2) + 2, gy1 = 1, gy2 = (CELL_WIDTH + 2) / 2 * (ROWS_PER_TABLE-1)+1;//tarif moteghayer ha
	char direction = 's';
	packmanf(dx, dy, 0, 's');//keshidan packman avvalie
	gotoxy(0, (CELL_WIDTH / 2 + 1)*ROWS_PER_TABLE + 5);
	printf("Your score is:  %d", count);//neshan dadan emtiaaze avvalie
	int i=1;
	for (int i = 1; i <= CELL_WIDTH*(COLUMN_PER_TABLE - 1) + 1; i += CELL_WIDTH)//keshidan kolooche ha
	{
		for (int j = 1; j <= (CELL_WIDTH + 2) / 2 * (ROWS_PER_TABLE - 1) + 1; j += (CELL_WIDTH + 2) / 2)
		{
				gotoxy(i + (CELL_WIDTH - 4) / 2, j + (CELL_WIDTH - 10) / 2);
				printf("@@");
				gotoxy(i + (CELL_WIDTH - 4) / 2, j + (CELL_WIDTH - 8) / 2);
				printf("@@");
		}//end for
	}//end for
	while (true)
	{
		ghostdrawer(gx1, gy1);//keshidan ghost ha
		ghostdrawer(gx2, gy2);
		if (i != 1)//moshakhas kardan makan badi packman
		{
			if (direction == 's' && table[(dy - ((CELL_WIDTH - 2) / 2)) / ((CELL_WIDTH + 2) / 2)][(dx - ((CELL_WIDTH) / 2)) / CELL_WIDTH + 1][0] == 0)
				dx += CELL_WIDTH;
			if (direction == 'a' && table[(dy - ((CELL_WIDTH - 2) / 2)) / ((CELL_WIDTH + 2) / 2)][(dx - ((CELL_WIDTH) / 2)) / CELL_WIDTH][0] == 0)
				dx -= CELL_WIDTH;
			if (direction == 'w' && table[(dy - ((CELL_WIDTH - 2) / 2)) / ((CELL_WIDTH + 2) / 2)][(dx - ((CELL_WIDTH) / 2)) / CELL_WIDTH][1] == 0)
				dy -= ((CELL_WIDTH + 2) / 2);
			if (direction == 'z' && table[(dy - ((CELL_WIDTH - 2) / 2)) / ((CELL_WIDTH + 2) / 2) + 1][(dx - ((CELL_WIDTH) / 2)) / CELL_WIDTH][1] == 0)
				dy += ((CELL_WIDTH + 2) / 2);

			if (table[(dy - ((CELL_WIDTH - 2) / 2)) / ((CELL_WIDTH + 2) / 2)][(dx - ((CELL_WIDTH) / 2)) / CELL_WIDTH ][2] == 0)//shemordan emtiaaz
			{
				table[(dy - ((CELL_WIDTH - 2) / 2)) / ((CELL_WIDTH + 2) / 2)][(dx - ((CELL_WIDTH) / 2)) / CELL_WIDTH ][2] = 1;
				count++;
			}//end if
		}//end if
		int xp = (dx - ((CELL_WIDTH) / 2)) / CELL_WIDTH, yp = (dy - ((CELL_WIDTH - 2) / 2)) / ((CELL_WIDTH + 2) / 2), xg1 = (gx1 - 2) / CELL_WIDTH, xg2 = (gx2 - 2) / CELL_WIDTH, yg1 = (gy1 - 1) / ((CELL_WIDTH + 2) / 2), yg2 = (gy2 - 1) / ((CELL_WIDTH + 2) / 2);
		if ((count == ROWS_PER_TABLE*COLUMN_PER_TABLE) || (xp == xg1 && yp == yg1) || (xp == xg2 && yp == yg2))
			break;//kharej shodan az baazi darsoorat khordan tamam emtiaaza ya barkhord ba rooh ha
		gotoxy(0, (CELL_WIDTH / 2 + 1)*ROWS_PER_TABLE + 5);
		printf("Your score is:  %d", count);//namayesh emtiaaz
		for (int i = 0; i <= 120; i = i + 5)//baaz kardan dahan packman
		{
			packmanf(dx, dy, i, direction);
			waitAndGetDirection(15, &direction);
		}//end for
		for (int i = 90; i >= 0; i = i - 5)//baste kardan dahan packman
		{

			packmanf(dx, dy, i, direction);
			waitAndGetDirection(15, &direction);
		}//end for
		cleaner(dx - ((CELL_WIDTH - 2) / 2), dy - ((CELL_WIDTH - 4) / 2));//pak kardan packman va ghost marhaleye ghabl
		cleaner(gx1 - 1, gy1);
		cleaner(gx2 - 1, gy2);
		if (table[(gy1 - 1) / ((CELL_WIDTH + 2) / 2)][(gx1 - 1) / CELL_WIDTH][2] == 0)//bargardandan kolooche haye pak shode darhal clearcell kardan ghost ha
		{
			gotoxy(gx1 + ((CELL_WIDTH - 4) / 2), gy1 + ((CELL_WIDTH - 10) / 2));
			printf("@@");
			gotoxy(gx1 + ((CELL_WIDTH - 4) / 2), gy1 + ((CELL_WIDTH - 8) / 2));
			printf("@@");
		}//end if
		if (table[(gy2 - 1) / ((CELL_WIDTH + 2) / 2)][(gx2 - 1) / CELL_WIDTH][2] == 0)
		{
			gotoxy(gx2 + ((CELL_WIDTH - 4) / 2), gy2 + ((CELL_WIDTH - 10) / 2));
			printf("@@");
			gotoxy(gx2 + ((CELL_WIDTH - 4) / 2), gy2 + ((CELL_WIDTH - 8) / 2));
			printf("@@");
		}//end if
		int g1area, g2area, parea;
		if ((xg1 == 0 && yg1 == 3) || (xg1 == 0 && yg1 == 4) || (xg1 == 1 && yg1 == 4) || (xg1 == 2 && yg1 == 4))//barresie inke rooh ha va packman dar kodam nahie az jadval hastand
			g1area = 1;
		if ((xg1 == 0 && yg1 == 0) || (xg1 == 0 && yg1 == 1) || (xg1 == 0 && yg1 == 2) || (xg1 == 1 && yg1 == 1) || (xg1 == 1 && yg1 == 2) || (xg1 == 1 && yg1 == 3) || (xg1 == 2 && yg1 == 2) || (xg1 == 2 && yg1 == 3) || (xg1 == 3 && yg1 == 3) || (xg1 == 3 && yg1 == 4) || (xg1 == 4 && yg1 == 4))
			g1area = 2;
		if ((xg1 == 1 && yg1 == 0) || (xg1 == 2 && yg1 == 0) || (xg1 == 3 && yg1 == 0) || (xg1 == 2 && yg1 == 1) || (xg1 == 3 && yg1 == 1) || (xg1 == 4 && yg1 == 1) || (xg1 == 3 && yg1 == 2) || (xg1 == 4 && yg1 == 2) || (xg1 == 4 && yg1 == 3) || (xg1 == 5 && yg1 == 3) || (xg1 == 5 && yg1 == 4))
			g1area = 3;
		if ((xg1 == 4 && yg1 == 0) || (xg1 == 5 && yg1 == 0) || (xg1 == 5 && yg1 == 1) || (xg1 == 5 && yg1 == 2))
			g1area = 4;
		if ((xg2 == 0 && yg2 == 3) || (xg2 == 0 && yg2 == 4) || (xg2 == 1 && yg2 == 4) || (xg2 == 2 && yg2 == 4))
			g2area = 1;
		if ((xg2 == 0 && yg2 == 0) || (xg2 == 0 && yg2 == 1) || (xg2 == 0 && yg2 == 2) || (xg2 == 1 && yg2 == 1) || (xg2 == 1 && yg2 == 2) || (xg2 == 1 && yg2 == 3) || (xg2 == 2 && yg2 == 2) || (xg2 == 2 && yg2 == 3) || (xg2 == 3 && yg2 == 3) || (xg2 == 3 && yg2 == 4) || (xg2 == 4 && yg2 == 4))
			g2area = 2;
		if ((xg2 == 1 && yg2 == 0) || (xg2 == 2 && yg2 == 0) || (xg2 == 3 && yg2 == 0) || (xg2 == 2 && yg2 == 1) || (xg2 == 3 && yg2 == 1) || (xg2 == 4 && yg2 == 1) || (xg2 == 3 && yg2 == 2) || (xg2 == 4 && yg2 == 2) || (xg2 == 4 && yg2 == 3) || (xg2 == 5 && yg2 == 3) || (xg2 == 5 && yg2 == 4))
			g2area = 3;
		if ((xg2 == 4 && yg2 == 0) || (xg2 == 5 && yg2 == 0) || (xg2 == 5 && yg2 == 1) || (xg2 == 5 && yg2 == 2))
			g2area = 4;
		if ((xp == 0 && yp == 3) || (xp == 0 && yp == 4) || (xp == 1 && yp == 4) || (xp == 2 && yp == 4))
			parea = 1;
		if ((xp == 0 && yp == 0) || (xp == 0 && yp == 1) || (xp == 0 && yp == 2) || (xp == 1 && yp == 1) || (xp == 1 && yp == 2) || (xp == 1 && yp == 3) || (xp == 2 && yp == 2) || (xp == 2 && yp == 3) || (xp == 3 && yp == 3) || (xp == 3 && yp == 4) || (xp == 4 && yp == 4))
			parea = 2;
		if ((xp == 1 && yp == 0) || (xp == 2 && yp == 0) || (xp == 3 && yp == 0) || (xp == 2 && yp == 1) || (xp == 3 && yp == 1) || (xp == 4 && yp == 1) || (xp == 3 && yp == 2) || (xp == 4 && yp == 2) || (xp == 4 && yp == 3) || (xp == 5 && yp == 3) || (xp == 5 && yp == 4))
			parea = 3;
		if ((xp == 4 && yp == 0) || (xp == 5 && yp == 0) || (xp == 5 && yp == 1) || (xp == 5 && yp == 2))
			parea = 4;
		if ((xg1 == 5 && yg1 == 2) && (parea == 1 || parea == 2 || parea == 3))//taghier nahie baraye bazi khoone ha baraye gir nakardan rooh ha
			g1area = 3;
		if ((xg1 == 1 && yg1 == 0) && (parea == 1 || parea == 2))
			g1area = 2;
		if ((xg1 == 2 && yg1 == 4) && (parea == 4 || parea == 2 || parea == 3))
			g1area = 2;
		if ((xg2 == 5 && yg2 == 2) && (parea == 1 || parea == 2 || parea == 3))
			g2area = 3;
		if ((xg2 == 1 && yg2 == 0) && (parea == 1 || parea == 2))
			g2area = 2;
		if ((xg2 == 2 && yg2 == 4) && (parea == 4 || parea == 2 || parea == 3))
			g2area = 2;
		if ((g1area == 1 && parea == 1) || (g1area == 2 && parea == 2) || (g1area == 3 && parea == 3) || (g1area == 4 && parea == 4))//barresi halat haye mokhtalef nahie haye packman va ghost ha
		{
			if (closefinder(xg1, yg1, xp, yp) == 'r' && !(xp==xg1+1 && yg1==yp && direction=='a'))//barresi nazdiktarin khoone va inke packman az dakhel rooh rad nashavad va taghir mogheyat rooh motenaseb ba oon
				gx1 += CELL_WIDTH;
			if (closefinder(xg1, yg1, xp, yp) == 'l' && !(xp == xg1 - 1 && yg1 == yp && direction == 's'))
				gx1 -= CELL_WIDTH;
			if (closefinder(xg1, yg1, xp, yp) == 'u' && !(xp == xg1  && yg1-1 == yp && direction == 'z'))
				gy1 -= ((CELL_WIDTH + 2) / 2);
			if (closefinder(xg1, yg1, xp, yp) == 'd' && !(xp == xg1 && yg1 +1== yp && direction == 'w'))
				gy1 += ((CELL_WIDTH + 2) / 2);
		}//end if
		if ((g1area == 1 && parea == 2) || (g1area == 1 && parea == 3) || (g1area == 1 && parea == 4) || (g1area == 2 && parea == 1))
		{
			if (closefinder(xg1, yg1, 2, 4) == 'r' && !(xp == xg1 + 1 && yg1 == yp && direction == 'a'))
				gx1 += CELL_WIDTH;
			if (closefinder(xg1, yg1, 2, 4) == 'l' && !(xp == xg1 - 1 && yg1 == yp && direction == 's'))
				gx1 -= CELL_WIDTH;
			if (closefinder(xg1, yg1, 2, 4) == 'u'&& !(xp == xg1  && yg1 - 1 == yp && direction == 'z'))
				gy1 -= ((CELL_WIDTH + 2) / 2);
			if (closefinder(xg1, yg1, 2, 4) == 'd'&& !(xp == xg1 && yg1 + 1 == yp && direction == 'w'))
				gy1 += ((CELL_WIDTH + 2) / 2);
		}//end if
		if ((g1area == 2 && parea == 3) || (g1area == 2 && parea == 4) || (g1area == 3 && parea == 1) || (g1area == 3 && parea == 2))
		{
			if (closefinder(xg1, yg1, 1, 0) == 'r' && !(xp == xg1 + 1 && yg1 == yp && direction == 'a'))
				gx1 += CELL_WIDTH;
			if (closefinder(xg1, yg1, 1, 0) == 'l' && !(xp == xg1 - 1 && yg1 == yp && direction == 's'))
				gx1 -= CELL_WIDTH;
			if (closefinder(xg1, yg1, 1, 0) == 'u'&& !(xp == xg1  && yg1 - 1 == yp && direction == 'z'))
				gy1 -= ((CELL_WIDTH + 2) / 2);
			if (closefinder(xg1, yg1, 1, 0) == 'd'&& !(xp == xg1 && yg1 + 1 == yp && direction == 'w'))
				gy1 += ((CELL_WIDTH + 2) / 2);
		}//end if
		if ((g1area == 4 && parea == 1) || (g1area == 4 && parea == 2) || (g1area == 4 && parea == 3) || (g1area == 3 && parea == 4))
		{
			if (closefinder(xg1, yg1, 5, 2) == 'r' && !(xp == xg1 + 1 && yg1 == yp && direction == 'a'))
				gx1 += CELL_WIDTH;
			if (closefinder(xg1, yg1, 5, 2) == 'l' && !(xp == xg1 - 1 && yg1 == yp && direction == 's'))
				gx1 -= CELL_WIDTH;
			if (closefinder(xg1, yg1, 5, 2) == 'u'&& !(xp == xg1  && yg1 - 1 == yp && direction == 'z'))
				gy1 -= ((CELL_WIDTH + 2) / 2);
			if (closefinder(xg1, yg1, 5, 2) == 'd'&& !(xp == xg1 && yg1 + 1 == yp && direction == 'w'))
				gy1 += ((CELL_WIDTH + 2) / 2);
		}//end if
		xp = (dx - ((CELL_WIDTH) / 2)) / CELL_WIDTH, yp = (dy - ((CELL_WIDTH - 2) / 2)) / ((CELL_WIDTH + 2) / 2), xg1 = (gx1 - 2) / CELL_WIDTH, xg2 = (gx2 - 2) / CELL_WIDTH, yg1 = (gy1 - 1) / ((CELL_WIDTH + 2) / 2), yg2 = (gy2 - 1) / ((CELL_WIDTH + 2) / 2);
		if ((g2area == 1 && parea == 1) || (g2area == 2 && parea == 2) || (g2area == 3 && parea == 3) || (g2area == 4 && parea == 4))
		{
			if (closefinder(xg2, yg2, xp, yp) == 'r' && !(xp == xg2 + 1 && yg2 == yp && direction == 'a') && !(xg1 - 1 == xg2 && yg1 == yg2))
				gx2 += CELL_WIDTH;
			if (closefinder(xg2, yg2, xp, yp) == 'l' && !(xp == xg2 - 1 && yg2 == yp && direction == 's') && !(xg1 + 1 == xg2 && yg1 == yg2))
				gx2 -= CELL_WIDTH;
			if (closefinder(xg2, yg2, xp, yp) == 'u' && !(xp == xg2  && yg2 - 1 == yp && direction == 'z') && !(xg1 == xg2 && yg1 + 1 == yg2))
				gy2 -= ((CELL_WIDTH + 2) / 2);
			if (closefinder(xg2, yg2, xp, yp) == 'd' && !(xp == xg2 && yg2 + 1 == yp && direction == 'w') && !(xg1 == xg2 && yg1 - 1 == yg2))
				gy2 += ((CELL_WIDTH + 2) / 2);
		}//end if
		if ((g2area == 1 && parea == 2) || (g2area == 1 && parea == 3) || (g2area == 1 && parea == 4) || (g2area == 2 && parea == 1))
		{
			if (closefinder(xg2, yg2, 2, 4) == 'r' && !(xp == xg2 + 1 && yg2 == yp && direction == 'a') && !(xg1 - 1 == xg2 && yg1 == yg2))
				gx2 += CELL_WIDTH;
			if (closefinder(xg2, yg2, 2, 4) == 'l' && !(xp == xg2 - 1 && yg2 == yp && direction == 's') && !(xg1 + 1 == xg2 && yg1 == yg2))
				gx2 -= CELL_WIDTH;
			if (closefinder(xg2, yg2, 2, 4) == 'u'&& !(xp == xg2  && yg2 - 1 == yp && direction == 'z') && !(xg1 == xg2 && yg1 + 1 == yg2))
				gy2 -= ((CELL_WIDTH + 2) / 2);
			if (closefinder(xg2, yg2, 2, 4) == 'd'&& !(xp == xg2 && yg2 + 1 == yp && direction == 'w') && !(xg1 == xg2 && yg1 - 1 == yg2))
				gy2 += ((CELL_WIDTH + 2) / 2);
		}//end if
		if ((g2area == 2 && parea == 3) || (g2area == 2 && parea == 4) || (g2area == 3 && parea == 1) || (g2area == 3 && parea == 2))
		{
			if (closefinder(xg2, yg2, 1, 0) == 'r' && !(xp == xg2 + 1 && yg2 == yp && direction == 'a') && !(xg1 - 1 == xg2 && yg1 == yg2))
				gx2 += CELL_WIDTH;
			if (closefinder(xg2, yg2, 1, 0) == 'l' && !(xp == xg2 - 1 && yg2 == yp && direction == 's') && !(xg1 + 1 == xg2 && yg1 == yg2))
				gx2 -= CELL_WIDTH;
			if (closefinder(xg2, yg2, 1, 0) == 'u'&& !(xp == xg2  && yg2 - 1 == yp && direction == 'z') && !(xg1 == xg2 && yg1 + 1 == yg2))
				gy2 -= ((CELL_WIDTH + 2) / 2);
			if (closefinder(xg2, yg2, 1, 0) == 'd'&& !(xp == xg2 && yg2 + 1 == yp && direction == 'w') && !(xg1 == xg2 && yg1 - 1 == yg2))
				gy2 += ((CELL_WIDTH + 2) / 2);
		}//end if
		if ((g2area == 4 && parea == 1) || (g2area == 4 && parea == 2) || (g2area == 4 && parea == 3) || (g2area == 3 && parea == 4))
		{
			if (closefinder(xg2, yg2, 5, 2) == 'r' && !(xp == xg2 + 1 && yg2 == yp && direction == 'a') && !(xg1==xg2+1 && yg1==yg2))
				gx2 += CELL_WIDTH;
			if (closefinder(xg2, yg2, 5, 2) == 'l' && !(xp == xg2 - 1 && yg2 == yp && direction == 's') && !(xg1  == xg2-1 && yg1 == yg2))
				gx2 -= CELL_WIDTH;
			if (closefinder(xg2, yg2, 5, 2) == 'u'&& !(xp == xg2  && yg2 - 1 == yp && direction == 'z') && !(xg1  == xg2 && yg1 == yg2-1))
				gy2 -= ((CELL_WIDTH + 2) / 2);
			if (closefinder(xg2, yg2, 5, 2) == 'd'&& !(xp == xg2 && yg2 + 1 == yp && direction == 'w') && !(xg1 == xg2 && yg1 == yg2+1))
				gy2 += ((CELL_WIDTH + 2) / 2);
		}//end if
		i++;
		if ((xp == xg1 + 1 && yg1 == yp && direction == 'a') || (xp == xg1 - 1 && yg1 == yp && direction == 's') || (xp == xg1  && yg1 - 1 == yp && direction == 'z') || (xp == xg1 && yg1 + 1 == yp && direction == 'w') || (xp == xg2 + 1 && yg2 == yp && direction == 'a') || (xp == xg2 - 1 && yg2 == yp && direction == 's') || (xp == xg2  && yg2 - 1 == yp && direction == 'z') || (xp == xg2 && yg2 + 1 == yp && direction == 'w'))//agar rooh va packman shakh be shakh shodan ye emtiaz kam kon
			count--;
	}//end while
	gotoxy(0, 0);//khali kardan safhe ba space
	for (int j = 1; j <= ((CELL_WIDTH + 2) / 2)*ROWS_PER_TABLE+10; j++)
	{
		for (int i = 1; i <= CELL_WIDTH*COLUMN_PER_TABLE+10; i++)
		{
			printf(" ");
		}//end for
		printf("\n");
	}//end for
	
	gotoxy((CELL_WIDTH*COLUMN_PER_TABLE - 4) / 2, ((CELL_WIDTH + 2) / 2)*ROWS_PER_TABLE/2);
	if (count == ROWS_PER_TABLE*COLUMN_PER_TABLE)//namayesh emtiaz nahayi
		printf("You won   Your final score is:  %d", count);
	else
		printf("Game over   Your final score is:  %d", count);
}//end game
void ghostdrawer(int gx1,int gy1)//keshidan rooh
{
	gotoxy(gx1-1, gy1);
	printf("    ^^^^^");
	gotoxy(gx1-1, gy1+1);
	printf("  ^^^^^^^^^");
	gotoxy(gx1-1, gy1+2);
	printf("  ^()^^^()^");
	gotoxy(gx1-1, gy1+3);
	printf("  ^^^^^^^^^");
	gotoxy(gx1-1, gy1+4);
	printf("  ^^^^^^^^^");
	gotoxy(gx1-1, gy1+5);
	printf("  ^^^^^^^^^");
	gotoxy(gx1-1, gy1+6);
	printf("  ^ ^ ^ ^ ^");
}
void cleaner(int x, int y)//pak kardan khoone packman va rooh ghabli
{
	gotoxy(x, y);
	for (int i = 1; i <= CELL_WIDTH/2; i++)
	{
		for (int j = 1; j <= CELL_WIDTH-2; j++)
		{
			printf(" ");
		}//end for
		gotoxy(x, y + i);
	}//end for
	
}//end cleaner
char closefinder(int xg, int yg, int x, int y)//find the closest cell from the cells around ghost to packman
{
	int table[ROWS_PER_TABLE + 1][COLUMN_PER_TABLE + 1][2] = { { { { 1 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 1 }, { 1 } }, { { 0 }, { 1 } }, { { 1 }, { 0 } } }, { { { 1 }, { 0 } }, { { 0 }, { 0 } }, { { 1 }, { 0 } }, { { 0 }, { 0 } }, { { 0 }, { 1 } }, { { 1 }, { 0 } }, { { 1 }, { 0 } } }, { { { 1 }, { 0 } }, { { 0 }, { 0 } }, { { 0 }, { 1 } }, { { 1 }, { 0 } }, { { 0 }, { 0 } }, { { 0 }, { 0 } }, { { 1 }, { 0 } } }, { { { 1 }, { 1 } }, { { 1 }, { 0 } }, { { 0 }, { 0 } }, { { 0 }, { 1 } }, { { 1 }, { 0 } }, { { 0 }, { 0 } }, { { 1 }, { 0 } } }, { { { 1 }, { 0 } }, { { 0 }, { 1 } }, { { 0 }, { 0 } }, { { 0 }, { 0 } }, { { 0 }, { 1 } }, { { 1 }, { 0 } }, { { 1 }, { 0 } } }, { { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 1 } }, { { 0 }, { 0 } } } };
	int right = (xg+1 - x)*(xg+1 - x) + (y - yg)*(y - yg);//bedast avardan faseleye khoone haye atraafe rooh az makan khaste shode
	int left = (xg-1 - x)*(xg-1 - x) + (y - yg)*(y - yg);
	int up = (x - xg)*(x - xg) + (yg-1 - y)*(yg-1 - y);
	int down = (x - xg)*(x - xg) + (yg+1 - y)*(yg+1 - y);
	if (right <= left && right <= up && right <= down)//barresi inke kodaam khoone fasele ash kamtar ast
	{
		if (table[yg][xg+1][0] == 0)
			return 'r';
		else if (left <= up && left <= down)//barresi dovomin kootah tarin faasele
		{
			if (table[yg][xg][0] == 0)
				return 'l';
			else if (up <= down)//barresi sevvomin kootah tarin faasele
			{
				if (table[yg][xg][1] == 0)
					return 'u';
			}//end else if
			else
				return 'd';
		}//end else if
		else if (up <= left && up <= down)
		{
			if (table[yg][xg][1] == 0)
				return 'u';
			else if (left <= down)
			{
				if (table[yg][xg][0] == 0)
					return 'l';
			}//end else if
			else
				return 'd';
		}//end else if
		else if (down <= up && down <= left)
		{
			if (table[yg+1][xg][1] == 0)
				return 'd';
			else if (up <= left)
			{
				if (table[yg][xg][1] == 0)
					return 'u';
			}//end else if
			else
				return 'l';
		}//end else if
	}//end if
	if (left <= right && left <= up && left <= down)
	{
		if (table[yg ][xg][0] == 0)
			return 'l';
		else if (right <= up && right <= down)
		{
			if (table[yg][xg+1][0] == 0)
				return 'r';
			else if (up <= down)
			{
				if (table[yg][xg][1] == 0)
					return 'u';
				
			}//end else if
			else
				return 'd';
		}//end else if
		else if (up <= right && up <= down)
		{
			if (table[yg][xg][1] == 0)
				return 'u';
			else if (right <= down)
			{
				if (table[yg][xg+1][0] == 0)
					return 'r';
				
			}//end else if
			else
				return 'd';
		}//end else if
		else if (down <= up && down <= right)
		{
			if (table[yg+1][xg][1] == 0)
				return 'd';
			else if (up <= right)
			{
				if (table[yg][xg][1] == 0)
					return 'u';
				
			}//end else if
			else
				return 'r';
		}//end else if
	}//end if
	if (up <= left && up <= right && up <= down)
	{
		if (table[yg ][xg][1] == 0)
			return 'u';
		else if (left <= right && left <= down)
		{
			if (table[yg][xg][0] == 0)
				return 'l';
			else if (right <= down)
			{
				if (table[yg][xg+1][0] == 0)
					return 'r';
				
			}//end else if
			else
				return 'd';

		}//end else if
		else if (right <= left && right <= down)
		{
			if (table[yg][xg + 1][0] == 0)
				return 'r';
			else if (left <= down)
			{
				if (table[yg][xg][0] == 0)
					return 'l';
				
			}//end else if
			else
				return 'd';
		}//end else if
		else if (down <= right && down <= left)
		{
			if (table[yg + 1][xg][1] == 0)
				return 'd';
			else if (right <= left)
			{
				if (table[yg][xg + 1][0] == 0)
					return 'r';
				
			}//end else if
			else
				return 'l';
		}//end else if
	}//end if
	if (down <= left && down <= up && down <= right)
	{
		if (table[yg + 1][xg][1] == 0)
			return 'd';
		else if (left <= right && left <= up)
		{
			if (table[yg][xg][0] == 0)
				return 'l';
			else if (right <= up)
			{
				if (table[yg][xg + 1][0] == 0)
					return 'r';
				
			}//end else if
			else
				return 'u';

		}//end else if
		else if (right <= left && right <= down)
		{
			if (table[yg][xg + 1][0] == 0)
				return 'r';
			else if (left <= up)
			{
				if (table[yg][xg][0] == 0)
					return 'l';
				
			}//end else if
			else
				return 'u';
		}//end else if
		else if (up <= right && up <= left)
		{
			if (table[yg][xg][1] == 0)
				return 'u';
			else if (right <= left)
			{
				if (table[yg][xg + 1][0] == 0)
					return 'r';
				
			}//end else if
			else
				return 'l';
		}//end else if
	}//end if
}//end close finder