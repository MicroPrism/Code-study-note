#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

int main()
{
	int flag = 1;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		int i = 0;
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("\n\t开始游戏\n");
			game();//电脑落子出现问题
			break;
		case 0:
			printf("\t退出游戏\n");
			flag = 0;
			break;
		default:
			printf("\tFBI!Open the door!\n");
			getchar();
			getchar();
		}
		if (flag == 0)
		{
			break;
		}
	} while ( 1 );
	return 0;
}