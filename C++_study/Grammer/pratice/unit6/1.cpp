#include<iostream>
#include<cctype>
int main(void)
{
	using namespace std;
	string str1;
	char ch;
	while((ch=cin.get())!='@')
		str1+=ch;
	int size = str1.size();
	for(int i = 0; i<size;i++)
	{
		if(isupper(str1[i]))
		{
			str1[i]+=32;
		}
		else if(islower(str1[i]))
		{
			str1[i]-=32;
		}
	}
	cout<<"After changes string :"<<str1<<endl;
	return 0;
}
