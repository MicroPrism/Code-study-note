#include<iostream>
#include<fstream>
#include<cstdlib>

int main(void)
{
	using namespace std;
	string name;
	ifstream inFile;
	cout<<"Enter filename: ";
	getline(cin,name);
	inFile.open(name);
	if(!inFile.is_open())
	{
		cout<<"Could not open the file "<<name<<endl;
		cout<<"Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0;
	inFile>>value;
	while(inFile.good())
	{
		++count;
		sum+= value;
		inFile>>value;
	}
	if(inFile.eof())
		cout<<"Enter of file reached.\n";
	else if(inFile.fail())
		cout<<"input terminated by daya mismatch.\n";
	else
		cout<<"input terminated for unknown reason.\n";
	if(count == 0)
		cout<<"No data processed.\n";
	else
	{
		cout<<"items read: "<<count<<endl;
		cout<<"Sum: "<<sum<<endl;
		cout<<"Average: "<<sum/count<<endl;
	}
	inFile.close();
	return 0;
}

