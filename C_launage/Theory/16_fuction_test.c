void test()
{
	printf("hh");
}
int get_max(int a, int b)
{
	if (a>b)
	{
		return a;
	}
	else 
	{
		return b;
	}
}
//2.ֵ��������

int swap1(int a, int b)//��ֵ������������ı�ʵ�ε�ֵ��ֻ���ڴ����βε�ʱ������ֵ��ʵ����ȶ��ѣ�
{//�β��ڵ��õ�ʱ��ŷ����ڴ�ռ�
	int temp = a;
	b = a;
	a = temp;
	return 0;
}

int swap2(int* pa, int* pb)//��ַ�������ı��ַ�ڴ�ŵ�����
{
	int temp = *pa;
	*pb = *pa;
	*pa = temp;
	return 0;
}
//������Ҫ����ԭ����ֵ��Ҫ��ַ��ֻ��ʹ��ֵ��ֵ�Ϳ���

int is_prime(int i,int j)//�ж��Ƿ�����������ӡ�������ǹ����һ��
{
	int a = 0, b = 0,count=0;
	for (a = i; a<=j; a ++)
	{
		for (b = 2; b <=sqrt(a); b++)
		{
			if (a % b == 0)
			{
				break;
			}
		}
		if (b > sqrt(a))
		{
			printf("����%d\n", a);
			count++;
		}
	}
	return count;
}
int is_leap_year(int a)//�ж��Ƿ�Ϊ����ĺ���
{
	if (((a % 4 == 0) && (a % 100) != 0) || (a % 400 == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
	//return ((a % 4 == 0) && (a % 100) != 0) || (a % 400 == 0));Ҳ���Խ����ʽ������أ�ʵ���ж�
}
//���ַ�����
int baniary_search(int a[], int k, int s)
{
	int left = 0, right = s, mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] < k)
		{
			left = mid + 1;
		}
		else if (a[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}