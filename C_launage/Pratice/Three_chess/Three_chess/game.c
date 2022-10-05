#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//简易菜单栏-无问题
void menu()
{
	system("cls");
	printf("\t菜单\t\t选项\t\t工具\n\n");
	printf("\t开始游戏\t");
	printf("\t结束游戏\t\n");
}

//初始化-无问题
//初始化函数，目的是将数组初始化为空格，方便打印棋盘
void Initial_Board(char a[][COL], int x, int y)
{
	int i = 0, j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			a[i][j] = ' ';
		}
	}
}

//棋盘打印函数，奇数行打印|与空格，偶数行打印---|，|打印次数小于列数，偶数行打印次数小于奇数行
//出现问题：第三列不显示；原因：内层循环为2，a[i][j]与|均只打印两次****已修正
void Display_Board(char a[][COL], int x, int y)
{
	int i = 0, j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y ; j++)
		{
			printf(" %c ", a[i][j]);
			if (j < 2)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i != x - 1)
		{
			for (j = 0; j < y; j++)
			{
				printf("---");
				if (j != y - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

//玩家落子-无问题
void gamer(char a[ROW][COL], int x, int y)//0，2坐标无法落子
{
	int i = 0, j = 0;
	while (1)
	{
		printf("玩家落子，输入落子坐标\n");
		scanf("%d %d", &i, &j);
		if (a[i-1][j-1] == ' ')//修正，将[i][j]修改
		{
			a[i-1][j-1] = 'x';
			break;
		}
		else
		{
			printf("错误的落子位置,重新落子\n");
		}
	}
}

//电脑随机落子-有问题--第一次落子出现问题
void computer(char a[ROW][COL], int x, int y)
{
	int i = 0, j = 0;
	printf("电脑落子:\n");
	while (1)
	{
		i = rand() % ROW;//此处随机值为何为0 0
		j = rand() % COL;
		if (a[i][j] == ' ')
		{
			a[i][j] = 'o';
			break;
		}
	}
}

//胜负判断函数
//出现问题：斜上下划线不判赢；解决办法：count置0，添加判断方式a[i][ROW-1-i]
int win(char a[][COL], int x, int y, char z)
{
	int i = 0, j = 0;
	int count = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			if (a[i][j] == z)
			{
				count++;
			}
			else
			{
				count = 0;
			}
		}
		if (count == 3)
		{
			return 1;
		}
		count = 0;//重新置0
	}
	for (j = 0; j < y; j++)
	{
		for (i = 0; i < x; i++)
		{
			if (a[i][j] == z)
			{
				count++;
			}
			else
			{
				count = 0;
			}
		}
		if (count == 3)
		{
			return 1;
		}
		count = 0;//重新置0
	}
	for (i = 0; i < ROW; i++)
	{
		if (a[i][i] == z)
		{
			count++;
		}
		if (count == 3)
		{
			return 1;
		}
	}
	count = 0;
	for (i = 0; i < ROW; i++)
	{
		if (a[i][ROW-1-i] == z)
		{
			count++;
		}
		if (count == 3)
		{
			return 1;
		}
	}
	return 0;
}

//游戏函数-不清楚
void game()
{
	int i = 0;
	int flag = 0;
	//棋盘大小 
	char Board[ROW][COL];
	//初始化
	Initial_Board(Board, ROW, COL);
	//打印棋盘
	Display_Board(Board, ROW, COL);
	while (i < 9)
	{
		if (i % 2 == 0)
		{
			gamer(Board, ROW, COL);
			system("cls");
			printf("玩家落子:\n");
			Display_Board(Board, ROW, COL);
			flag = win(Board, ROW, COL, 'x');
			if (flag == 1)
			{
				printf("答对~，根本难不倒他~\n");
				break;
			}
		}
		else
		{
			computer(Board, ROW, COL);
			Display_Board(Board, ROW, COL);
			flag = win(Board, ROW, COL, 'o');
			if (flag == 1)
			{
				printf("这个彬彬就是逊啦~\n");
				break;
			};
		}
		i++;
	}
	if (flag == 0)
	{
		printf("平局\n");
	}
	getchar();
	getchar();
}