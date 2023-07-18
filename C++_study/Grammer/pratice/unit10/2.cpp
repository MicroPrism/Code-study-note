#include <iostream>
//using namespace std;
#include"2.h"
int main()
{
	using std::cout;
	using std::string;
	using std::endl;
	Person one;
	Person two("Smythecraft");
	Person three("dds","san");
	two.Show();
	cout<<endl;
	two.FormalShow();
	return 0;
}
