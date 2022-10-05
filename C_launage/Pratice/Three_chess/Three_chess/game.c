#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//���ײ˵���-������
void menu()
{
	system("cls");
	printf("\t�˵�\t\tѡ��\t\t����\n\n");
	printf("\t��ʼ��Ϸ\t");
	printf("\t������Ϸ\t\n");
}

//��ʼ��-������
//��ʼ��������Ŀ���ǽ������ʼ��Ϊ�ո񣬷����ӡ����
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

//���̴�ӡ�����������д�ӡ|��ո�ż���д�ӡ---|��|��ӡ����С��������ż���д�ӡ����С��������
//�������⣺�����в���ʾ��ԭ���ڲ�ѭ��Ϊ2��a[i][j]��|��ֻ��ӡ����****������
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

//�������-������
void gamer(char a[ROW][COL], int x, int y)//0��2�����޷�����
{
	int i = 0, j = 0;
	while (1)
	{
		printf("������ӣ�������������\n");
		scanf("%d %d", &i, &j);
		if (a[i-1][j-1] == ' ')//��������[i][j]�޸�
		{
			a[i-1][j-1] = 'x';
			break;
		}
		else
		{
			printf("���������λ��,��������\n");
		}
	}
}

//�����������-������--��һ�����ӳ�������
void computer(char a[ROW][COL], int x, int y)
{
	int i = 0, j = 0;
	printf("��������:\n");
	while (1)
	{
		i = rand() % ROW;//�˴����ֵΪ��Ϊ0 0
		j = rand() % COL;
		if (a[i][j] == ' ')
		{
			a[i][j] = 'o';
			break;
		}
	}
}

//ʤ���жϺ���
//�������⣺б���»��߲���Ӯ������취��count��0������жϷ�ʽa[i][ROW-1-i]
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
		count = 0;//������0
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
		count = 0;//������0
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

//��Ϸ����-�����
void game()
{
	int i = 0;
	int flag = 0;
	//���̴�С 
	char Board[ROW][COL];
	//��ʼ��
	Initial_Board(Board, ROW, COL);
	//��ӡ����
	Display_Board(Board, ROW, COL);
	while (i < 9)
	{
		if (i % 2 == 0)
		{
			gamer(Board, ROW, COL);
			system("cls");
			printf("�������:\n");
			Display_Board(Board, ROW, COL);
			flag = win(Board, ROW, COL, 'x');
			if (flag == 1)
			{
				printf("���~�������Ѳ�����~\n");
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
				printf("���������ѷ��~\n");
				break;
			};
		}
		i++;
	}
	if (flag == 0)
	{
		printf("ƽ��\n");
	}
	getchar();
	getchar();
}