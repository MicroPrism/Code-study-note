#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void print(int a[3][5], int b, int c);
void print2(int(*a)[5], int b, int c);
void test(int arr[]);
void test1(int arr[10]);
void test2(int* arr);
void test3(int* arr[20]);
void test4(int** arr);

void test5(int arr[3][5]);
//void test6(int arr[][]) {};
void test7(int arr[][5]);
void test8(int* arr);
void test9(int* arr[5]);
void test10(int(*arr)[5]);
void test11(int** arr) {};

int testa();
int Add(int a, int b);
int Sub(int a, int b);
int Cot(int(*pf)(int, int));