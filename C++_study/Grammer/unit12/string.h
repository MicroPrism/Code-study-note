#include<iostream>
#ifndef STRING_H_
#define STRING_H_
class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIMIT = 80;//类内常量
	//enum {CINLIMIT = 80};
public:
	String();
	String(const char * s);
	String(const String & st);
	~String();
	String & operator=(const String & st);
	String & operator=(const char* st);
	friend std::ostream & operator<<(std::ostream & os,
		const String & st);
	int length() const{return len;}
	friend bool operator<(const String & st1,const String & st2);
	friend bool operator>(const String & st1,const String & st2);
	friend bool operator==(const String & st1,const String & st2);
	friend std::istream & operator>>(std::istream & is,String & st);
	
	char & operator[](int i);//st[i]等价于st.operator[](i)
	const char & operator[](int i) const;//功能同上一个语句，操作对象为const
	static int HowMany();//{return num_strings;};
};
#endif
