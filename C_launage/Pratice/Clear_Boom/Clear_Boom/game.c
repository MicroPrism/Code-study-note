#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	system("cls");
	printf("\t�˵�\t\tѡ��\t\t����\n\n");
	printf(" \t��ʼ��Ϸ\t");
	printf("\t������Ϸ\t\t--by˧˧\n\n");
	printf("\t*:δ����\tX���ѱ��\tը������10\n\n");
	printf("�밴��ȷ�ĸ�ʽ����\n\n");
}
//��ʼ��
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
//��ӡ
//�������⣺δ��ӡ����
//����취�������ж����
void Display_Area(char Area[][COL],int standard[][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			//���ж�ֻ����չʾ
			if (standard[i][j])//���������δ��ѡ�������ӡ*�������ѡ�У���ӡ������ֵ
			{
				////��ʼ�����������ȷ
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
					printf("X  ");//���
				}
				else
				{
					printf("*  ");
				}
			}
			else//��ѡ�����
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
//�����10��������ֵ��������Count��������
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
				Area[i][j] = Count(Area, i, j);//ĳ��ֱֵ�ӷ������ַ�o
			}
		}
	}

}

//��ը��λ��λ����ը��������
//�����������⣺����ֵ��Ϊ73������
//ԭ��:���������ڲ���������������˱��������յĽ��Ϊ�ܺ�
//λ�ã�Refine_Area�����ڲ�������ֵ��Count��������
//����취��ʹ�ã����������βΣ�Count����ʱ����ȷ��������Ϊ����
int Count(char Area[][COL],int i,int j)
{
	int m = 0, n = 0;
	int count = 0;//����

	if (i == 0)//��������3*3��Ԫ����ը������
	{
		if (j == 0)//���Ͻ�
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
		else if (j == COL-1)//���Ͻ�
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
		else//��һ��
					{
						for (m = 0; m < 2; m++)//��������
						{
							for (n =j-1 ; n<=j+1; n++)//����
							{
								if (Area[i+m][n] == 'o')
								{
									count++;
								}
							}
						}
					}
	}
	else if (i == ROW-1)//����β��3*3��Ԫ����ը������
	{
		if (j == 0)//���½�
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
		else if (j == COL-1)//���½����
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
//��Ϸ����
void game(char Area[][COL],int standard[][COL])
{
	Initial_Area(Area);
	Display_Area(Area,standard);
	printf("\n");
	//�öδ�������ã��鿴���¸�ֵ�Ƿ���ȷ
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
		printf("������һ��10*10�����꣬�ÿո�ָ");
		scanf("%d %d", &i, &j);
		printf("\n");
		printf("��������1���������0��");//����
		scanf("%d", &rever);
		printf("\n");
			if (i > 0 && i <= 10 && j <= 10 && j > 0)
			{
				i--;
				j--;
				if (standard[i][j] == 1)//ѡ�����������
				{
					if(rever==1)
					{
						if (Area[i][j] == 'o')
						{
							initial_std(standard, 0);
							Display_Area(Area, standard);//Ŀ������ʾ����Ԫ��
							printf("BOOM!��Ϸ����~\n");
							printf("���������ѷ��~\n");
							break;
							getchar();
							getchar();
						}
						else
						{
							standard[i][j] = 0;
							printf("�´��㲻����ô������~\n");
						}
						Display_Area(Area, standard);
					}
					else//��Ǻ���
					{
						printf("��ǳɹ�\n");
						standard[i][j] = 2;//��Ǳ�־
						Display_Area(Area, standard);
					}

				}
				else if (standard[i][j] == 2 && rever == 0)
				{
					printf("ȡ�����\n");
					standard[i][j] = 1;
					Display_Area(Area, standard);
				}
				else
				{
					printf("404 NOT FONUND��������ѡ������\n");
				}
				if (win(standard,Area))//�ж��Ƿ�ʤ��
				{
					printf("�ҳ��������Ӯ�ˣ������´ξͲ�һ����~\n");
					break;
				}
			}
			else
			{
				printf("����������Ⱑ~--����ǿ\n");
			}

			printf("ʣ��ը������%d��\n", count1(standard, Area));
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