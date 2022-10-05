#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	system("cls");
	printf("\t菜单\t\t选项\t\t工具\n\n");
	printf(" \t开始游戏\t");
	printf("\t结束游戏\t\t--by帅帅\n\n");
	printf("\t*:未翻开\tX：已标记\t炸弹数：10\n\n");
	printf("请按正确的格式输入\n\n");
}
//初始化
void Initial_Area(char Area[][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			Area[i][j] = '*';
		}
	}
}
//打印
//出现问题：未打印数字
//解决办法：增加判断语句
void Display_Area(char Area[][COL],int standard[][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			//该判断只用于展示
			if (standard[i][j])//这个坐标尚未被选择过，打印*；如果被选中，打印本来的值
			{
				////初始情况，计算正确
				// if (Area[i][j] == '*' || Area[i][j] == 'o')
				//{
				//	printf("%c  ", Area[i][j]);
				//}
				//else
				//{
				//	/*printf("*  ");*/
				//	printf("%d  ",Area[i][j]);
				//}
				if (standard[i][j] == 2)
				{
					printf("X  ");//标记
				}
				else
				{
					printf("*  ");
				}
			}
			else//被选择过的
			{
				if ( Area[i][j] == 'o')
				{
					printf("%c  ", Area[i][j]);
				}
				else
				{
					/*printf("*  ");*/
					printf("%d  ",Area[i][j]);
				}
			}
		}
		printf("\n");
	}
}
//随机对10个数赋初值，并调用Count函数计数
void Refine_Area(char Area[][COL])
{
	int a = 0, b = 0,sum=0;
	int i = 0, j=0;
	do
	{
		a = rand() % ROW;
		b = rand() % ROW;
		if (Area[a][b] == '*')
		{
			Area[a][b] = 'o';
			sum++;
		}

	} while (sum < 10);
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (Area[i][j] != 'o')
			{
				Area[i][j] = Count(Area, i, j);//某个值直接返回了字符o
			}
		}
	}

}

//非炸弹位单位格内炸弹数计数
//计数出现问题：返回值均为73？？，
//原因:计数函数内部对整个数组进行了遍历，最终的结果为总和
//位置：Refine_Area函数内部计数赋值与Count函数计数
//解决办法：使用，增加两个形参，Count技术时，以确定的坐标为参照
int Count(char Area[][COL],int i,int j)
{
	int m = 0, n = 0;
	int count = 0;//计数

	if (i == 0)//计算首行3*3单元格内炸弹个数
	{
		if (j == 0)//左上角
					{
						for (m = 0; m < 2; m++)
						{
							for (n = 0; n < 2; n++)
							{
								if (Area[i+m][j+n] == 'o')
								{
									count++;
								}
							}
						}
					}
		else if (j == COL-1)//右上角
					{
						for (m = 0; m < 2; m++)
						{
							for (n = 0; n < 2; n++)
							{
								if (Area[i+m][j-n] == 'o')
								{
									count++;
								}
							}
						}
					}
		else//第一行
					{
						for (m = 0; m < 2; m++)//上下两行
						{
							for (n =j-1 ; n<=j+1; n++)//三列
							{
								if (Area[i+m][n] == 'o')
								{
									count++;
								}
							}
						}
					}
	}
	else if (i == ROW-1)//计算尾行3*3单元格内炸弹个数
	{
		if (j == 0)//左下角
					{
						for (m = 0; m < 2 ; m++)
						{
							for (n = 0; n < 2; n++)
							{
								if (Area[i-m][j+n] == 'o')
								{
									count++;
								}
							}
						}
					}
		else if (j == COL-1)//右下角情况
					{
						for (m = 0; m < 2; m++)
						{
							for ( n = 0; n < 2; n++)
							{
								if (Area[i-m][j-n] == 'o')
								{
									count++;
								}
							}
						}
					}
		else
		{
			for (m = 0; m < 2; m++)
						{
							for (n = j-1; n <=j+ 1; n++)
							{
								if (Area[i-m][n] == 'o')
								{
									count++;
								}
							}
						}
		}
	}
	else if (j == 0)
				{
					for (m = i-1; m <=i+1; m++)
					{
						for (n = 0; n <=1; n++)
						{
							if (Area[m][n+j] == 'o')
							{
								count++;
							}
						}
					}
				}
	else if (j == COL - 1)
				{
					for (m = i - 1; m <= i + 1; m++)
					{
						for (n = 0; n <= 1; n++)
						{
							if (Area[m][j - n] == 'o')
							{
								count++;
							}
						}
					}
				}
	else
				{
					for (m = i-1; m <=i+1; m++)
					{
						for (n = j - 1; n <= j + 1; n++)
						{
							if (Area[m][n] == 'o')
							{
								count++;
							}
						}
					}
				}
	return count;
 }		
//游戏函数
void game(char Area[][COL],int standard[][COL])
{
	Initial_Area(Area);
	Display_Area(Area,standard);
	printf("\n");
	//该段代码调试用，查看重新赋值是否正确
	Refine_Area(Area);
	//initial_std(standard, 0);
	//Display_Area(Area, standard);
	//printf("\n");
	//initial_std(standard, 1);
	Play_Input(Area,standard);
}
void Play_Input(char Area[][COL],int standard[][COL])
{
	int i = 0, j = 0,rever=0;
	while (1)
	{
		printf("请输入一个10*10的坐标，用空格分割：");
		scanf("%d %d", &i, &j);
		printf("\n");
		printf("翻开它按1，标记它按0：");//新增
		scanf("%d", &rever);
		printf("\n");
			if (i > 0 && i <= 10 && j <= 10 && j > 0)
			{
				i--;
				j--;
				if (standard[i][j] == 1)//选择的是新坐标
				{
					if(rever==1)
					{
						if (Area[i][j] == 'o')
						{
							initial_std(standard, 0);
							Display_Area(Area, standard);//目的是显示所有元素
							printf("BOOM!游戏结束~\n");
							printf("这个彬彬就是逊啦~\n");
							break;
							getchar();
							getchar();
						}
						else
						{
							standard[i][j] = 0;
							printf("下次你不会这么走运了~\n");
						}
						Display_Area(Area, standard);
					}
					else//标记函数
					{
						printf("标记成功\n");
						standard[i][j] = 2;//标记标志
						Display_Area(Area, standard);
					}

				}
				else if (standard[i][j] == 2 && rever == 0)
				{
					printf("取消标记\n");
					standard[i][j] = 1;
					Display_Area(Area, standard);
				}
				else
				{
					printf("404 NOT FONUND，请重新选择坐标\n");
				}
				if (win(standard,Area))//判断是否胜利
				{
					printf("我承认这次你赢了，不过下次就不一定了~\n");
					break;
				}
			}
			else
			{
				printf("你这秤有问题啊~--刘华强\n");
			}

			printf("剩余炸弹数：%d个\n", count1(standard, Area));
	}
}
int count1(int standard[][COL], char Area[][COL])
{
	int i = 0, j = 0, count = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (standard[i][j] == 1 && Area[i][j] == 'o')
			{
				count++;
			}
		}
	}
	return count;
}
int win(int standard[][COL],char Area[][COL])
{
	int i = 0, j = 0;
	int sum1 = 0, sum2 = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (standard[i][j] == 2&& Area[i][j] == 'o')
			{
				sum1++;
			}
			if (standard[i][j] == 0 && Area[i][j] != 'o')
			{
				sum2++;
			}
		}
	}
	if (sum1 == 10||sum2==90)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void initial_std(int standard[][COL],int a)
{
	int x = 0, y = 0;
	for (x = 0; x < ROW; x++)
	{
		for (y = 0; y < COL; y++)
		{
			standard[x][y] = a;
		}
	}
}