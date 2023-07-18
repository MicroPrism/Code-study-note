#include<iostream>

using namespace std;

int main(void)
{
	char name[20] = {"youngs coco"};
	char *pname=name;
	char (*pname1)[20] = &name;
	cout<<"pname->name,pname[1] is : "<<*(pname+1)<<endl;
	cout<<"pname1->&name,(*pname1)[1] is : "<<(*pname1)[1]<<endl;;
//	cout<<"pname1->&name,*pname[1] is : "<<*pname[1];
	return 0;
}
