#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
//1.计算阶乘之和

//int main()
//{
//	int i = 0, j = 0;
//	int n = 0,m=1,sum=0;
//	scanf("%d",&n);
//	for (i = 1; i <= n; i++)
//	{
//		m *= i;
//		sum += m;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//2.在有序数组内查找数据

//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 ,'\0'};
//	printf("%lld\n",sizeof(arr1)/sizeof(arr1[0]));
//	//printf("%lld\n",strlen(arr));strlen用以计算字符串的长度
//	char arr[] = { "cab24333" };//此处若定义为int型数组结果会出问题
//	printf("%lld\n", strlen(arr));
//	return 0;
//}

//优化前initial[mid]参与运算

//int main()
//{
//	int i = 0;//计数变量，防止死循环
//	int initial[] = { 1,2,3,4,5,6,7,9 };
//	int left = 0;
//	int	right = sizeof(initial) / sizeof(initial[0])-1;//元素个数并转换为下标
//	int mid = (left + right) / 2;
//	int obj = 0;
//	scanf("%d", &obj);
//	while (mid < right)//此处while循环无法查取最右端的数字，因为（7+8）/2=7死循环
//	{
//		if (initial[mid] < obj)
//		{
//			left = mid;
//		}
//		else if (initial[mid] > obj)
//		{
//			right = mid;
//		}
//		else
//		{
//			printf("查找到目标数据%d，下标为%d\n", obj, mid);
//			break;
//		}
//		mid = (left + right) / 2;
//		//if (mid == right - 1)//加入此判断语句可以识别最右端的数据，但非数组内数据会输出错误
//		//{
//		//	i++;
//		//	if (2 == i)
//		//	{
//		//		mid = initial[mid + 1] == obj ? mid + 1 : right;
//		//		break;
//		//	}
//		//}
//		if (mid-1 == 0)//判断是否是最左端的0-2死循环情况，如果出现，直接进行下一步循环
//		{
//			continue;
//		}
//		if (mid == 0)//确定是最左端情况，输出即可
//		{
//			printf("查找到目标数据%d，下标为%d\n", obj, mid);
//			break;
//		}
//		if (mid == right - 1)//发现mid与right临近时即出现死循环
//		{
//			i = initial[mid + 1] == obj ? 1 : 0;
//			if (i)
//			{
//				printf("查找到目标数据%d，下标为%d\n", obj, mid + 1);
//				break;
//			}
//			else
//			{
//				printf("未搜索到数据%d\n",obj);
//				break;
//			}
//		}
//	}
//	return 0;
//}

//优化后代码

//int main()
//{
//	int initial[] = { 1,2,3,4,5,6,7,9 };
//	int left = 0;
//	int	right = sizeof(initial) / sizeof(initial[0])-1;//元素个数并转换为下标
//	
//	int obj = 0;
//	scanf("%d", &obj);
//	while (left <= right)
//	{
//		int mid= (left + right) / 2;
//		if (initial[mid] < obj)//判断之后只需要使用剩下的数据，initial[mid]不再参与运算
//		{
//			left = mid + 1;
//			//判断之后mid对应的数不符合要求就不再参与计算，因此不会出现left、mid、right相邻导致死循环
//			//如果查询非数组内数据，会出现mid=left=right的情况，再循环一次就会出现left=right+1的情况
//			//一定不会出现死循环
//		}
//		else if (initial[mid] > obj)
//		{
//			right = mid-1;
//		}
//		else
//		{
//			printf("查找到目标数据%d，下标为%d\n", obj, mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到此数据");
//	}
//}

//3.数组间的元素值复制

//int main()
//{
//	char arr1[] = "welcome to bit !!!!!!!";
//	int sz = sizeof(arr1) / sizeof(arr1[0]);//由于是使用双引号进行初始化，需要使用strlen计算长度
//	int left = 0;
//	int right = sz - 2;
//	//当然，sizeof(arr1)/size(arr1[0]);的形式会考虑‘\0’
//	char arr2[] = "######################";
//	while (left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//		Sleep(1000);
//		//delay(1000);51可以用delay
//		system("cls");
//	}
//	printf("%s\n", arr2);
//	return 0;
//}

//4.字符串比较-密码比较

//int main()
//{
//	int i = 0;
//	char password[20] = {0};//定义为password[]={0};时，变长数组，报错，但能得到正确结果
//	for (i = 0; i < 3; i++)
//	{
//		printf("Please input the password for this computer:\n");
//		scanf("%s", password);
//		if (strcmp(password, "123456")==0)//strcmp-字符减法，只有两字符串结果相同才为0,串1更长则返回大于0的
//		{
//			printf("Right!\n");
//			break;
//		}
//		else
//		{
//			printf("Error!\n");
//		}
//	}
//	return 0;
//}

//5.猜数游戏

int menu()
{
	printf("1.开始游戏\n");
	printf("2.结束游戏\n");
	return 0;
}
int play()//游戏函数：生成随机数并比较
{
	int i = rand()%100+1;//注意，rand是伪随机，每次都生成相同的值，因此需要使用srand
	int number = 0;
	int count = 0;
	while (number != i)
	{
		printf("plz input the number possible:\n");
		scanf("%d",&number);
		if (i < number)
		{	
			printf("太大了\n");
		}
		else if(i>number)
		{
			printf("太小了\n");
		}
		else
		{
			printf("根本难不倒他！\n");;
		}
		count++;
	}
	printf("%d次猜出答案\n",count);
	return 0;
}

int main()
{
	int i = 1;//判断是否结束游戏
	srand((unsigned int)time(NULL));//以变化的时间戳作为种子，转换为u_int型，srand是取随机数
	do 
	{
		menu();
		int input = 0;//判断是否继续游戏
		scanf("%d",&input);
		system("cls");
		switch (input)
		{
		case 1:
			play();
			break;
		case 2:
			i = 0;
			break;
		default:
			break;
		}
	} while (i);
	return 0;
}