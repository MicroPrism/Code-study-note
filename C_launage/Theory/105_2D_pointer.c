#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;
int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48=3*4*4
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16  ÿ����ʼ����һ��һά����
	printf("%d\n", sizeof(a[0]+1));//4/8  ָ���һ�е�2��Ԫ�أ��ǵ�ַ�������ú����Ԫ��
	//a[0]û�зŵ�sizeof�Ҳû��ȡ��ַ��Ĭ��Ϊa[0]��Ԫ�صĵ�ַ���Ա�һά������a[10],a����Ԫ�ص�ַ
	printf("%d\n", sizeof(*(a[0] + 1)));//4  ��������Ԫ��
	printf("%d\n", sizeof(a + 1));//4/8	�˴�aû��ȡ��ַ��Ҳû��ֱ�ӷ���sizeof�ڲ������Ƕ�ά������Ԫ�ص�ַ������һ�е�ַ
	//a+1�ǵڶ��е�ַ
	printf("%d\n", sizeof(*(a + 1)));//16  *(a+1)=a[1],����ά����ڶ��У������16
	printf("%d\n", sizeof(&a[0] + 1));//4/8  &a[0]��ʾ��һ�еĵ�ַ����+1��ָ��ڶ��У���ͬ��a+1,�׸�Ԫ��+1��ָ����һ��Ԫ��
	printf("%d\n", sizeof(*(&a[0] + 1)));//16	��ά����ĵڶ���Ԫ�ص�ַ�����ã��������ڶ���
	printf("%d\n", sizeof(*a));//16 û��ȡ��ַ��֤��a���׸�Ԫ�أ�����һ��
	printf("%d\n", sizeof(a[3]));//16  sizeof�����㣬������ֵ���ԣ�ֻ���������ԣ�a[3]=a+3,�ǵ����У����������鵫��û��Խ�����
	
	//����ṹ���ַΪ0x10 00 00 00
	printf("%p\n", p + 0x01);//p+1,�ƶ�һ���ṹ�壬20���ֽڣ�0x10 00 00 14
	printf("%p\n", (unsigned long)p + 0x01);//0x10 00 00 01,ǿ��ת��Ϊlong���ݽ�����������
	printf("%p\n", (unsigned long*)p + 0x01);//0x10 00 00 04

	int b[4] = { 1,2,3,4 };
	int* ptr = (int*)(&b + 1);//&a+1��������a����ֽڣ�ת��Ϊ����ָ��ptr[-1]����ǰ�ƶ�һ�ֽڣ����4
	int* ptr2 = (int*)((int)b + 1);//��Ԫ�ص�ַת��Ϊint���ټ�1���ٱ��ָ�룬�൱���ƶ�һ���ֽ�0x000010->16��17+1=17->0x000011
	printf("%x %x", ptr[-1], *ptr2);

	int c[3][2] = { (0,1),(2,3),(4,5) };
	int* p;
	p = c[0];//p=*(a+0)  c[0]��c�����һ�е��׵�ַ
	printf("%d\n", p[0]);//*(*(a+0)+0)=1

	int crr[5][5];
	int(*pcrr)[4];
	pcrr = crr;
	printf("%p,%d\n", &pcrr[4][2] - &crr[4][2], &pcrr[4][2] - &crr[4][2]);
	// &pcrr[4][2] - &crr[4][2]ָ�������-4��������ʽ�洢������%d��ӡ����ӡԭ�룬����%p��ӡ����ӡ-4�Ĳ���FFFFFFFC

	char* drr[] = { "abc","def","xyz" };
	char** pd = drr;
	pd++;
	printf("%s\n", *pd);//drr�ڲ���������ʼ�������ַ�ָ�룬pdΪd�ĵ�һ��Ԫ�ص�ַ&drr[0],pd++,ָ��ڶ���Ԫ�أ���ַ
	//*pd��ӡdef

	char* err[] = { "enter","new","point","first" };
	char** pe[] = { err + 3,err + 2, err + 1 ,err };
	char*** ppe = pe;
	//ppe->pe�׵�ַ��pe->err���飬err�ڴ洢��Ҳ�ǵ�ַ
	printf("%s\n", **++ppe);//point ppeָ��pe[1],�����õõ�err+2���ٽ����ô�ӡpoint  
	printf("%s\n", *-- * ++ppe + 3);//ER	++ppe��ppeָ��pe[2],�����õõ�err+1����err[1]��
	//��--��&err[0],+3�൱�ڰ�ָ�������3��ָ��er����enter
	printf("%s\n", *ppe[-2] + 3);//st
	printf("%s\n", ppe[-1][-1]+1);//ew	*(*(ppe-1)-1))+1 


	return 0;
}