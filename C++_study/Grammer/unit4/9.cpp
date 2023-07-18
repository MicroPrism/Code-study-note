#include <iostream>

using namespace std;

struct pal
{
	int type;
	char brand[20];
	union
	{
	long id_num;
	char id_char[20];
	};
};

int main(void)
{
	pal yang;
	cout<<"input a number : "<<endl;
	cin>>yang.type;
	if(yang.type==1)
		cin>>yang.id_num;
	else
		cin>>yang.id_char;
	return 0;
}
