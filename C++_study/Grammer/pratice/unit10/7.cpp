#include<iostream>
#include"7.h"
Plorg::Plorg()
{
	const char *pname = "Plorga";
	for(int i = 0; *pname != '\0'&& i < MAX;i++)
		name[i] = pname[i];
	CI = 50; 
}
Plorg::Plorg(const char pname[],int pCI)
{
	for(int i = 0; pname[i]!='\0'&& i < MAX; i++)
		name[i] = pname[i];
	CI = pCI; 
}
Plorg::~Plorg(){};
void Plorg::show() const
{
	std::cout<<"Name: "<<name<<std::endl;
	std::cout<<"CI: "<<CI<<std::endl;
}
void Plorg::set_CI(int a)
{
	CI = a;
}
