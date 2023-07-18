#include<iostream>
#include<cctype>
#include"1.h"
void setgolf(golf & g,const char * name,int hc)
{
	int i;
	for( i = 0;i<Len&&*(name+i);i++)
		g.fullname[i] = *(name+i);
	g.fullname[i]='\0';
	g.handicap = hc;
}
int setgolf(golf & g)
{
	using std::cin;
	int i,flag_space=0;
	std::cout<<"Enter fullname : ";
	cin.getline(g.fullname,Len);
	for(i = 0;i<Len&&g.fullname[i];i++)
	{
		if(!isspace(g.fullname[i]))
		flag_space = 1;
	}
	std::cout<<"Enter handicap : ";
	cin>>g.handicap;
	if(flag_space) return 1;
	else return 0;
}
void handicap(golf & g,int hc)
{
	g.handicap = hc;
}
void showgolf(const golf & g)
{
	using std::cout;
	using std::endl;
	cout<<g.fullname<<endl;
	cout<<g.handicap<<endl;
}
