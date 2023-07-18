#include<iostream>

using namespace std;

typedef int pp(int *a,int *b);
typedef int (*p_test)(int *a,int *b);

int test(int*,int*);

int main(void)
{
	pp *ptest = test;
	p_test pptest = &test;
	int x,y;
	cout<<"Enter two number :";
	cin>>x>>y;
	int max = (*ptest)(&x,&y);
	cout<<"The max is :"<<max<<endl;

	max = pptest(&x,&y);
	cout<<"The max is :"<<max<<endl;
	return 0;
}
int test(int* a,int *b)
{
	if(*a > *b)
	{	int temp = *a;
		*a = *b;
		*b = temp;
	}
	return  *b;
}
