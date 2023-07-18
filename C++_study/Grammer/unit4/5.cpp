#include <iostream>

int main(void)
{
	using namespace std;
	char ch1[20],ch2[20]="jajuar";
	string str1,str2 = "panther";
	cout<<"Enter a kind of feline :";
	cin>>ch1;
	cout<<"Another feline :";
	cin>>str1;
	cout<<"here some feline:\n "<<ch1<<" "<<ch2<<" "
		<<str1<<" "<<str2<<endl;
	cout<<"The third in :"<<ch2<<" is "<<ch2[2]<<endl;
	cout<<"The third in :"<<str2<<" is "<<str2[2]<<endl;

	cout<<endl;
	string str3;
	str3 = "plz";
	cout<<"str3 = :"<<str3<<endl;
	str3 += "give me a cup";
	cout<<"str3 + = \"give me a cup\",str3 = : "<<str3<<endl;
	return 0;
}
