#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

int main()
{
	int play_flag = 0;
	char Area[ROW][COL];
	srand((unsigned int)time(NULL));
	printf("���ڼ���......\n");
	Sleep(2000);
	do
	{
		system("cls");
		menu();
		int standard[ROW][COL];//��־
		initial_std(standard,1);
		printf("��1��ʼ��Ϸ;��2�˳���Ϸ;\n");
		scanf("%d", &play_flag);
		switch (play_flag)
		{
		case 1:
			printf("�������ɵ�ͼ...\n");
			Sleep(2000);
			game(Area,standard);
			getchar();//����س�����ֱ�ӽ���ѭ��
			getchar();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			Sleep(1000);
			return 0;
		default:
			printf("FBI! Open the door!\n");
			break;
		}
		
	} while (1);
	return 0;
}