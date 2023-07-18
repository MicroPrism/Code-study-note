#include<iostream>
using namespace std;
void printstr(char *,int n = 0);
int amount;
int main(void)
{
	char a[50];
	cin.getline(a,50);
	char b[20] = "AAA";
	int n;
	while(cin>>n)
	{
		printstr(a,n);
		printstr(b);
	}
	return 0;
}
void printstr(char * pa,int n )
{
	if(n == 0)
		cout<<pa<<endl;	
	else
		for(int i = 0;i<amount;i++)
			cout<<pa<<endl;
	amount ++;
}
