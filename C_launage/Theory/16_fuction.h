#pragma once
#include<math.h>
#include<stdio.h>
void test();
int get_max(int a, int b);
int swap1(int a, int b);
int swap2(int* pa, int* pb);
int is_prime(int i, int j);
int is_leap_year(int a);
int baniary_search(int a[], int k, int s);
//函数声明，确定返回类型，函数名与变量类型
//函数声明一般放在使用之前，放在头文件中
//创建一个.h文件专门用于函数声明