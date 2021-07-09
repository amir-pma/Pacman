/*Amir Pourmohammadali 810196435*/
#define _CRT_SECURE_NO_WARNINGS/*baraye eror nadadan scanf*/
#include <stdio.h>/*tarif ketabkhoone ha*/
#include <math.h>
#include <windows.h>
#include <conio.h>
#define Zarib 0.8//tarif saabet ha
#define Pi 3.14159265
#define PACMAN_RADIUS 6
#define ROWS_PER_TABLE 5
#define COLUMN_PER_TABLE 6
#define CELL_WIDTH 14

//Sets console screen to full screen
//Use this function at the beginning of your program in main()
void initScreen(void);
//The following function manipulates cursor position
void gotoxy(int x, int y);
//This function will wait for "waitTime" milliseconds and get the new direction from the keybord
//100<waitTime<250 
//Use this function between printing the pacman shapes in a single cell
//If the direction is changed the return value is 1 else the return value is 0
int waitAndGetDirection(int waitTime, char *direction);
void packmanf(int dx, int dy,int zavie, char jahat);//packman drawer
void tablef(int row, int column, int cellchar);//table drawer
void game(void);//draw opening mouth packman and ghost and set their next location
void cleaner(int dx, int dy);//clear cell
void ghostdrawer(int dx,int dy);//ghost drawer
char closefinder(int xg, int yg, int x, int y);//find the closest cell from the cells around ghost to packman