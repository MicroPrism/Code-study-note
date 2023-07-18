#include<iostream>
#include<fstream>

using namespace std;

int main(void)
{
	ifstream inFile;
	string name;
	getline(cin,name);
	inFile.open(name);
	if(!inFile.is_open())
	{
		cout<<"can't open the file :"<<name<<endl;
		exit(EXIT_FAILURE);
	}
	char ch;
	int count;
	while(inFile.get(ch))
	{
		++count;
	}
	if(inFile.eof())
		cout<<"Input of file reached."<<endl;
	else if(inFile.fail())
		cout<<"Input terminated by data mismatch."<<endl;
	else
		cout<<"Unknown error.\n";
	if(count == 0)
		cout<<"No data processed.";
	else
		cout<<"Total char is :"<<count<<endl;
	return 0;
}
