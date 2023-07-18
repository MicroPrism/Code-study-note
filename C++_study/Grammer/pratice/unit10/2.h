#ifndef UNIT_10_2_
#define UNIT_10_2_

#include<iostream>
class Person
{
//using namespace std;
private:
	//using namespace std;
	enum{ LIMIT = 25};
	std::string lname;
	//string lname;
	char fname[LIMIT];
public:
	Person(){lname = "";fname[0] = '\0';}
	Person(const std::string & ln,const char * fn = "Heyyou");
	~Person();
	void Show() const;
	void FormalShow() const;
};
#endif
