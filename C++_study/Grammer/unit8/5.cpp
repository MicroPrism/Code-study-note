#include<iostream>
#include <string>
using namespace std;

string cp1(const string & s1,const string & s2);
string &cp2(string &s1,const string &s2);
//string & cp3(const string &s1,const string &s2);

int main()
{
	string input,output,copy;
	getline(cin,input);
	copy = input;
	cout<<"Original string :"<<input<<endl;
	output = cp1(input,"***");
	cout<<"Cp1 : "<<output<<endl;
	cout<<"Original string :"<<input<<endl;
	output = cp2(input,"///");
	cout<<"Cp2 : "<<output<<endl;	
	cout<<"Original string :"<<input<<endl;
	/*output = cp3(copy,"!!!");
	cout<<"Cp3 : "<<output<<endl;	
	cout<<"Original string :"<<endl;*/
	return 0;
}
string cp1(const string & s1,const string & s2)
{
	string temp = s2+s1+s2;
	return temp;
}
string &cp2(string &s1,const string &s2)
{
	s1 = s2 + s1 +s2;
	return s1;
}
/*string & cp3(const string &s1,const string &s2)
{
	string temp ;
	temp = s2+s1+s2;
	return temp;
}*/
