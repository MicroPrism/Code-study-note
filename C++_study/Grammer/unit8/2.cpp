#include<iostream>

void swap1(int&,int&);
void swap2(int*,int*);
void swap3(int,int);

int main(void)
{
	using namespace std;
	int ax1 = 100,ax2 = 200;
	swap1(ax1,ax2);
	cout<<ax1<<" / "<<ax2<<endl;
	swap2(&ax1,&ax2);
	cout<<ax1<<" / "<<ax2<<endl;
	swap3(ax1,ax2);
	cout<<ax1<<" / "<<ax2<<endl;
	return 0;
}
void swap1(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void swap2(int* a,int* b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}
void swap3(int a,int b)
{
        int temp = a;
        a = b;
        b = temp;
}


