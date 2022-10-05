#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define ROW 10
#define COL 10
void menu();
void Initial_Area(char Area[][COL]);
void Display_Area(char Area[][COL], int standard[][COL]);
void Refine_Area(char Area[][COL]);
int Count(char Area[][COL], int i, int j);
void game(char Area[][COL],int standard[][COL]);
int win(int standard[][COL], char Area[][COL]);
void Play_Input(char Area[][COL], int standard[][COL]);
void initial_std(int standard[][COL], int a);
int count1(int standard[][COL], char Area[][COL]);