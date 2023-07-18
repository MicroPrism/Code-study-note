#include<iostream>
using namespace std;
int main(void)
{
	char ch;
	int c1,c2;
	c1 = c2 = 0;
	while((ch = cin.get())!='$')
	//ch = cin.get() != '$'将出错
	{
		cout<<ch;
		c1++;
		if(ch = '$')
			c2++;
		cout<<ch;
	}
	cout<<"c1 = "<<c1<<", c2 = "<<c2<<endl;
	return 0;
}
