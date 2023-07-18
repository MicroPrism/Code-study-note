#include<iostream>
#include"6.h"
int main()
{
	Move a;
	a.showmove();
	a.reset(2,3);
	a.showmove();
	Move te(1,1);
	Move b = a.add(te);
	b.showmove();
	return 0;
}
