#pragma once
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>//Ê¹ÓÃrandº¯Êý
#define ROW 3
#define COL 3
void menu();
void Initial_Board(char a[][COL], int x, int y);
void Display_Board(char a[][COL], int i, int j);
void gamer(char a[][COL], int x, int y);
void computer(char a[][COL], int x, int y);
void game();
int  win(char a[][COL], int x, int y, char z);
