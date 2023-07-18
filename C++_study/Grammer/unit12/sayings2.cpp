#include<iostream>
#include<cstdlib>
#include<ctime>
#include"string.h"
const int ArSize = 10;
const int MaxLen = 81;

int main()
{
	using namespace std;
	String name;
	cout << name <<", plz enter "<< ArSize
		<<" short sayings<empty line to quit>:\n";
	String sayings[ArSize];
	char temp[MaxLen];
	int i;
	for (i = 0 ; i < ArSize ; i++)
	{
		cout<<"#"<<i + 1<<": ";
		cin.get(temp,MaxLen);
		while(cin && cin.get() != '\n')
			continue;
		if(!cin || temp[0] == '\0')//empety-line?
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if(total > 0)
	{
		cout<<"Here are you sayings:\n";
		for(i = 0 ; i < total ; i++)
			cout<<sayings[i]<<endl;
		String * shortest = &sayings[0];
		String * first = &sayings[0];
		for(i = 1; i < total;i++)
		{
			if(sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if(sayings[i] < *first)
				first = &sayings[i];
		}
		cout << "Shortest saying: "<< *shortest << endl;
		cout << "First alphabetically: "<< *first << endl;
		srand(time(0));
		int choice = rand() % total;
		String * favorite = new String(sayings[choice]);
		cout<<"My favorite saying:\n"<<*favorite << endl;
		delete favorite;
	}
	else
		cout << "No Input!\n";
	cout << "Bye.\n";
	return 0;
}
