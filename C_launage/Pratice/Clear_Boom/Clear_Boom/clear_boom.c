#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

int main()
{
	int play_flag = 0;
	char Area[ROW][COL];
	srand((unsigned int)time(NULL));
	printf("正在加载......\n");
	Sleep(2000);
	do
	{
		system("cls");
		menu();
		int standard[ROW][COL];//标志
		initial_std(standard,1);
		printf("按1开始游戏;按2退出游戏;\n");
		scanf("%d", &play_flag);
		switch (play_flag)
		{
		case 1:
			printf("正在生成地图...\n");
			Sleep(2000);
			game(Area,standard);
			getchar();//处理回车，不直接进死循环
			getchar();
			break;
		case 2:
			printf("退出游戏\n");
			Sleep(1000);
			return 0;
		default:
			printf("FBI! Open the door!\n");
			break;
		}
		
	} while (1);
	return 0;
}