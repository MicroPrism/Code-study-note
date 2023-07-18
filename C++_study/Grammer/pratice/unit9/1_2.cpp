#include<iostream>
#include"1.h"
int main()
{
	golf ann,andy;
	const char *pname ="Youngs";
	int ha = 10;
	setgolf(ann,pname,ha);
	showgolf(ann);
	while(setgolf(andy))
	{
		showgolf(andy);
		handicap(andy,10);
		showgolf(andy);
	}
	return 0;
}
