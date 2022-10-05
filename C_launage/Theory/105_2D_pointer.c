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
	printf("%d\n", sizeof(a[0]));//16  每行起始都是一个一维数组
	printf("%d\n", sizeof(a[0]+1));//4/8  指向第一行第2个元素，是地址，解引用后才是元素
	//a[0]没有放到sizeof里，也没有取地址，默认为a[0]首元素的地址，对比一维数组若a[10],a是首元素地址
	printf("%d\n", sizeof(*(a[0] + 1)));//4  解引用是元素
	printf("%d\n", sizeof(a + 1));//4/8	此处a没有取地址，也没有直接放入sizeof内部，则是二维数组首元素地址，即第一行地址
	//a+1是第二行地址
	printf("%d\n", sizeof(*(a + 1)));//16  *(a+1)=a[1],即二维数组第二行，计算得16
	printf("%d\n", sizeof(&a[0] + 1));//4/8  &a[0]表示第一行的地址，再+1，指向第二行，等同于a+1,首个元素+1，指向下一个元素
	printf("%d\n", sizeof(*(&a[0] + 1)));//16	二维数组的第二个元素地址解引用，是整个第二行
	printf("%d\n", sizeof(*a));//16 没有取地址，证明a是首个元素，即第一行
	printf("%d\n", sizeof(a[3]));//16  sizeof不运算，即不看值属性，只看类型属性，a[3]=a+3,是第三行，超出了数组但是没有越界访问
	
	//假设结构体地址为0x10 00 00 00
	printf("%p\n", p + 0x01);//p+1,移动一个结构体，20个字节，0x10 00 00 14
	printf("%p\n", (unsigned long)p + 0x01);//0x10 00 00 01,强制转换为long数据进行数据运算
	printf("%p\n", (unsigned long*)p + 0x01);//0x10 00 00 04

	int b[4] = { 1,2,3,4 };
	int* ptr = (int*)(&b + 1);//&a+1跳到数组a后的字节，转换为整形指针ptr[-1]，往前移动一字节，输出4
	int* ptr2 = (int*)((int)b + 1);//首元素地址转换为int型再加1，再变回指针，相当于移动一个字节0x000010->16；17+1=17->0x000011
	printf("%x %x", ptr[-1], *ptr2);

	int c[3][2] = { (0,1),(2,3),(4,5) };
	int* p;
	p = c[0];//p=*(a+0)  c[0]是c数组第一行的首地址
	printf("%d\n", p[0]);//*(*(a+0)+0)=1

	int crr[5][5];
	int(*pcrr)[4];
	pcrr = crr;
	printf("%p,%d\n", &pcrr[4][2] - &crr[4][2], &pcrr[4][2] - &crr[4][2]);
	// &pcrr[4][2] - &crr[4][2]指针相减是-4，补码形式存储，若以%d打印，打印原码，若以%p打印，打印-4的补码FFFFFFFC

	char* drr[] = { "abc","def","xyz" };
	char** pd = drr;
	pd++;
	printf("%s\n", *pd);//drr内部是三个初始化过的字符指针，pd为d的第一个元素地址&drr[0],pd++,指向第二个元素，地址
	//*pd打印def

	char* err[] = { "enter","new","point","first" };
	char** pe[] = { err + 3,err + 2, err + 1 ,err };
	char*** ppe = pe;
	//ppe->pe首地址，pe->err数组，err内存储的也是地址
	printf("%s\n", **++ppe);//point ppe指向pe[1],解引用得到err+2，再解引用打印point  
	printf("%s\n", *-- * ++ppe + 3);//ER	++ppe，ppe指向pe[2],解引用得到err+1，即err[1]；
	//再--得&err[0],+3相当于把指针向后移3，指向er而非enter
	printf("%s\n", *ppe[-2] + 3);//st
	printf("%s\n", ppe[-1][-1]+1);//ew	*(*(ppe-1)-1))+1 


	return 0;
}