#include<iostream>

int main(void)
{
	using namespace std;
	cout<<"please enter one of the flowing choices:\n"
		<<"c) caarnivore\t"<<"p) pianist\n"
		<<"t)tree\t\t"<<"g)game"<<endl;
	char ch;
	int flag=1;
	while(flag)
	{
		flag=0;
		cin.get(ch).get();
		switch (ch)
		{
			case 'c':cout<<"carnivore"<<endl;break;
			case 'p':cout<<"pianist"<<endl;break;
			case 't':cout<<"tree"<<endl;break;
			case 'g':cout<<"game"<<endl;break;
			default :flag = 1;cout<<"c,p,t or g :";break;
		}
	}
	return 0;
}
