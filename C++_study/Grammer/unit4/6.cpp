#include <iostream>
#include <string>//c++ string
#include <cstring>//c strlen
int main(void)
{
	using namespace std;
	char ch1[20],ch2[20]="jajuar";
	string str1,str2 = "panther";
	strcpy(ch1,ch2);
	str1 = str2;
	cout<<"ch :  "<<ch1<<" "<<ch2<<" "
		<<str1<<" "<<str2<<endl;
	str1 += " past";
	strcat(ch1,"juice");
	int len1 = str1.size();
	int len2 = strlen(ch1);
	cout<<"str1 : "<<str1<<" / "<<len1<<endl;
	cout<<"str2 : "<<ch1<<" / "<<len2<<endl;
	return 0;
}
