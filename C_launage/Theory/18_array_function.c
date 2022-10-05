//�ⳤ��
int  sz_length(char* a)
{
	int count = 0;
	while (*a != '\0')
	{
		a++;
		count++;
	}
	return count;
}

//ѭ������������ֵ��ÿ����һ�Σ�ָ�������һ��
//<=���б𣬿���ȷ���м������Խ�����������ż�������ܿ��ǵ�
void rever_array(char* a)
{
	int i = 0;
	int temp = 0;
	int sz = sz_length(a);
	int left = 0, right = sz - 1;
	for (i = 0; i <= (left + right) / 2; i++)
	{
		temp = *(a + i);//�ı�ָ������
		*(a + i) = *(a + right - i);
		*(a + right - i) = temp;
	}
}

//�ݹ��Զ��庯��
//ÿ�εݹ��Ȱѵ�һλȡ���������һλ�����ڵ�һλ��ĩλ�á�\0��
//�����ж�a+1��ָ����ƣ��ж��ַ������ȣ��ַ�������С��2��ʣ��0����1���ͽ���
void rever_array1(char* a)
{
	char temp = *a;//char temp = 0;
	int sz = sz_length(a);
	*a = *(a + sz - 1);
	*(a + sz - 1) = '\0';
	if (sz_length(a + 1) >= 2)
	{
		rever_array1(a + 1);
	}
	*(a + sz - 1) = temp;
}

//x^yָ������
double my_Pow(int x, int y)
{
	if (y == 0)
	{
		return 1.0;
	}
	else if (y > 0)
	{
		return (x * my_Pow(x, y - 1));
	}
	else
	{
		return 1.0 / (my_Pow(x, -y));
	}
}

//����ð�����򷽷�
void Bubble_arrange1(int a[], int sz)//�β�a������ָ��
{
	int i = 0, j = 0, temp = 0;
	//int sz = sizeof(a) / sizeof(a[0]);//a��ָ�룬sizeof(a)=4
	for (i = 0; i < sz - 1; i++)//ð�ݵ�������һ��ð��һ����������Ҫsz-1��
	{
		int flag = 1;
		for (j = 0; j < sz - 1 - i; j++)//�����ֵð�ݵ���󣬲��Ҳ��ٲ�������Ƚ�
		{
			if (a[j] < a[j + 1])//��ֵ����������Сֵ
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 0;//�ж�һ�˴�ѭ�����Ƿ�û���κν�����û���κν���˵���Ѿ�������������
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
void Bubble_arrange2(int* a, int sz)
{
	int i = 0, j = 0, temp = 0;
	//int sz = sizeof(a) / sizeof(a[0]);//a��ָ�룬sizeof(a)=4
	for (i = 0; i < sz - 1; i++)//ð�ݵ�������һ��ð��һ����������Ҫsz-1��
	{
		int flag = 1;
		for (j = 0; j < sz - 1 - i; j++)//�����ֵð�ݵ���󣬲��Ҳ��ٲ�������Ƚ�
		{
			if (*(a + j) < *(a + j + 1))//��ֵ����������Сֵ
			{
				temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
				flag = 0;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
//������ʹ��ָ��+ƫ��������ֱ��ʹ������Ԫ�أ�ֻ�ڽ����жϺ�ֵ����ʱ�õĵ�
//������ѭ������
//ð�ݣ�һ�δ�ѭ��ֻ�ܳ���һ����n������Ҫn-1�δ�ѭ��
//Сѭ�������ڲ������Ƚϣ�n�����Ƚ�n-1�Σ��ⲿ��ѭ��ѭ��һ����һ�������ڲ���Ӧ���ٱȽϴ���