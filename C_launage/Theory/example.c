#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
//1.����׳�֮��

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

//2.�����������ڲ�������

//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 ,'\0'};
//	printf("%lld\n",sizeof(arr1)/sizeof(arr1[0]));
//	//printf("%lld\n",strlen(arr));strlen���Լ����ַ����ĳ���
//	char arr[] = { "cab24333" };//�˴�������Ϊint���������������
//	printf("%lld\n", strlen(arr));
//	return 0;
//}

//�Ż�ǰinitial[mid]��������

//int main()
//{
//	int i = 0;//������������ֹ��ѭ��
//	int initial[] = { 1,2,3,4,5,6,7,9 };
//	int left = 0;
//	int	right = sizeof(initial) / sizeof(initial[0])-1;//Ԫ�ظ�����ת��Ϊ�±�
//	int mid = (left + right) / 2;
//	int obj = 0;
//	scanf("%d", &obj);
//	while (mid < right)//�˴�whileѭ���޷���ȡ���Ҷ˵����֣���Ϊ��7+8��/2=7��ѭ��
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
//			printf("���ҵ�Ŀ������%d���±�Ϊ%d\n", obj, mid);
//			break;
//		}
//		mid = (left + right) / 2;
//		//if (mid == right - 1)//������ж�������ʶ�����Ҷ˵����ݣ��������������ݻ��������
//		//{
//		//	i++;
//		//	if (2 == i)
//		//	{
//		//		mid = initial[mid + 1] == obj ? mid + 1 : right;
//		//		break;
//		//	}
//		//}
//		if (mid-1 == 0)//�ж��Ƿ�������˵�0-2��ѭ�������������֣�ֱ�ӽ�����һ��ѭ��
//		{
//			continue;
//		}
//		if (mid == 0)//ȷ���������������������
//		{
//			printf("���ҵ�Ŀ������%d���±�Ϊ%d\n", obj, mid);
//			break;
//		}
//		if (mid == right - 1)//����mid��right�ٽ�ʱ��������ѭ��
//		{
//			i = initial[mid + 1] == obj ? 1 : 0;
//			if (i)
//			{
//				printf("���ҵ�Ŀ������%d���±�Ϊ%d\n", obj, mid + 1);
//				break;
//			}
//			else
//			{
//				printf("δ����������%d\n",obj);
//				break;
//			}
//		}
//	}
//	return 0;
//}

//�Ż������

//int main()
//{
//	int initial[] = { 1,2,3,4,5,6,7,9 };
//	int left = 0;
//	int	right = sizeof(initial) / sizeof(initial[0])-1;//Ԫ�ظ�����ת��Ϊ�±�
//	
//	int obj = 0;
//	scanf("%d", &obj);
//	while (left <= right)
//	{
//		int mid= (left + right) / 2;
//		if (initial[mid] < obj)//�ж�֮��ֻ��Ҫʹ��ʣ�µ����ݣ�initial[mid]���ٲ�������
//		{
//			left = mid + 1;
//			//�ж�֮��mid��Ӧ����������Ҫ��Ͳ��ٲ�����㣬��˲������left��mid��right���ڵ�����ѭ��
//			//�����ѯ�����������ݣ������mid=left=right���������ѭ��һ�ξͻ����left=right+1�����
//			//һ�����������ѭ��
//		}
//		else if (initial[mid] > obj)
//		{
//			right = mid-1;
//		}
//		else
//		{
//			printf("���ҵ�Ŀ������%d���±�Ϊ%d\n", obj, mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ���������");
//	}
//}

//3.������Ԫ��ֵ����

//int main()
//{
//	char arr1[] = "welcome to bit !!!!!!!";
//	int sz = sizeof(arr1) / sizeof(arr1[0]);//������ʹ��˫���Ž��г�ʼ������Ҫʹ��strlen���㳤��
//	int left = 0;
//	int right = sz - 2;
//	//��Ȼ��sizeof(arr1)/size(arr1[0]);����ʽ�ῼ�ǡ�\0��
//	char arr2[] = "######################";
//	while (left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//		Sleep(1000);
//		//delay(1000);51������delay
//		system("cls");
//	}
//	printf("%s\n", arr2);
//	return 0;
//}

//4.�ַ����Ƚ�-����Ƚ�

//int main()
//{
//	int i = 0;
//	char password[20] = {0};//����Ϊpassword[]={0};ʱ���䳤���飬�������ܵõ���ȷ���
//	for (i = 0; i < 3; i++)
//	{
//		printf("Please input the password for this computer:\n");
//		scanf("%s", password);
//		if (strcmp(password, "123456")==0)//strcmp-�ַ�������ֻ�����ַ��������ͬ��Ϊ0,��1�����򷵻ش���0��
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

//5.������Ϸ

int menu()
{
	printf("1.��ʼ��Ϸ\n");
	printf("2.������Ϸ\n");
	return 0;
}
int play()//��Ϸ������������������Ƚ�
{
	int i = rand()%100+1;//ע�⣬rand��α�����ÿ�ζ�������ͬ��ֵ�������Ҫʹ��srand
	int number = 0;
	int count = 0;
	while (number != i)
	{
		printf("plz input the number possible:\n");
		scanf("%d",&number);
		if (i < number)
		{	
			printf("̫����\n");
		}
		else if(i>number)
		{
			printf("̫С��\n");
		}
		else
		{
			printf("�����Ѳ�������\n");;
		}
		count++;
	}
	printf("%d�β³���\n",count);
	return 0;
}

int main()
{
	int i = 1;//�ж��Ƿ������Ϸ
	srand((unsigned int)time(NULL));//�Ա仯��ʱ�����Ϊ���ӣ�ת��Ϊu_int�ͣ�srand��ȡ�����
	do 
	{
		menu();
		int input = 0;//�ж��Ƿ������Ϸ
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