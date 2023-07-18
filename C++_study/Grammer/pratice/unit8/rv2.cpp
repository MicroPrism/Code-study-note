#include<iostream>

void song(const char* name = "O.My PaPa",int time = 1);
int main()
{
	using namespace std;
	int input;
	char pname[20];
	cin>>input;
	cin.get();
	cin.getline(pname,20);
	song();
	song(pname,input);
	return 0;
}
void song(const char *name,int time)
{
	std::cout<<name<<" / "<<time<<std::endl;
}
