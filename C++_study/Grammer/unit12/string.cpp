#include<cstring>
#include"string.h"

using std::cout;
int String::num_strings = 0;

String::String()
{
	len = 0;
	//str = nullptr;空指针
	str = new char[1];
	str[0]='\0';
	num_strings++;
}
String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str,s);
	num_strings++;
	cout<<num_strings<<": \""<<str<<"\"object created\n";
}
String::~String()
{
	--num_strings;
	delete [] str;
}

String::String(const String & st)//copy-structure function
{
	num_strings++;
	len = st.len;
	str = new char [len+1];
	std::strcpy(str,st.str);
	cout<<num_strings<<": \""<<str<<"\"object created\n";
}
String & String::operator=(const String & st)
{
	if(this == &st)//*this为内容,自身赋值应考虑地址
		return *this;
	delete [] str;
	len = st.len;
	str = new char [len+1];
	std::strcpy(str,st.str);
	return *this;
}
bool operator<(const String & st1,const String & st2)
{
	/*if(std::strcmp(st1.str,st2.str))
		return true;
	else
		return false;
		*/
	return (std::strcmp(st1.str,st2.str) < 0 );//直接返回布尔值
}
bool operator>(const String & st1,const String & st2)
{
	return st2<st1;
}
bool operator==(const String & st1,const String & st2)
{
	return (std::strcmp(st1.str,st2.str) == 0);
}
std::istream & operator>>(std::istream & is,String & st)
{
	//os<<st.str<<std::endl;指针/字符串无法直接赋值，需要通过中间数组
	char temp[String::CINLIMIT];//static 加上限定符
	is.get(temp,String::CINLIMIT);
	if(is)
		st = temp;
	while(is && is.get()!='\n')
		continue;
	return is;
}
std::ostream & operator<<(std::ostream & os,const String & st)
{
	os<<st.str;
	return os;
}
char & String::operator[](int i)
{
	return str[i];
}
const char & String::operator[](int i) const
{
	return str[i];
}
//static int String::HowMany(){return num_strings;}声明内加static
int String::HowMany(){return num_strings;}
String & String::operator=(const char* st)
{
	delete [] str;
	len = strlen(st);
	str = new char [len+1];
	std::strcpy(str,st);
	return *this;
}
