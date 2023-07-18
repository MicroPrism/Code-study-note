#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
	cout<<"what is your name? ";
	char *ps = new char [20];
	char temp[20];
	cin.getline(temp,20);
	strcpy(ps,temp);
//	cout<<*ps<<endl;
//	delete [] ps;
	cout<<"last name ? ";
	char name[20];
	cin.getline(name,20);
//	cout<<name<<endl;
	cout<<"your age? ";
	int age;
	cin>>age;
	cout<<"Name : "<<*ps;
        delete [] ps;
	cout<<","<<name<<endl;
	cout<<"Age : "<<age<<endl;
	return 0;
}
