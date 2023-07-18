#include<iostream>
#include<cstring>
using namespace std;
struct stringy
{
	char *str;
	int act;
};
void set(stringy & a,char * b);
void show(const stringy & a,int n = 1);
void show(char* a,int n = 1);
void show(const char* a);


int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany,testing);
	
	show(beany);
	show(beany,2);
	cout<<"\n";
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing,3);
	cout<<"\n";
	show("Done!");
	cout<<"\n";
	return 0;
}
void set(stringy & a,char * b)
{
	int size = strlen(b);
	char * temp = new char[size + 1];
	for(int i = 0;i<size&&*(b+i);i++)
	{
		*(temp+i) = *(b+i); 
	}
	*(temp + size) = '\0';
	a.str = temp;
	a.act = size;
}
void show(const stringy & a,int n)
{
	for(int i = 0;i < n; i++ )
	{
		cout<<a.str[i];
	}
}
void show(char* a,int n)
{
	for(int i = 0;i < n; i++ )
	{
		cout<<a[i];
	}
}
void show(const char* a)
{
	for(int i = 0; a[i] ; i++ )
	{
		cout<<a[i];
	}
}
