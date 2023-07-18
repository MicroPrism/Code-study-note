#include<iostream>
#include<string>
#include<fstream>
using namespace std;//string
struct donate
{
	string name;
	double money;
};
int main(void)
{
	ifstream inFile;
	string filename;
	getline(cin,filename);
	inFile.open(filename);
	if(!inFile.is_open())
	{
		cout<<"Can't open file :"<<filename<<endl;
		exit(EXIT_FAILURE);
	}

	int sum;
	inFile >> sum;
	if(sum <= 0)
		exit(EXIT_FAILURE);
	inFile.get();//消耗回车

	auto pd = new donate [sum];
	int i = 0;
//	while(!inFile.eof()&&i<sum)
	for(i=0;!inFile.eof() && i < sum;i++)
	{
		getline(inFile,(pd+i)->name);
		inFile>>(pd+i)->money;
		//i++;
		inFile.get();
	}
	cout<<"Total :"<<sum<<endl;
	int count_g=0,count=0;
	cout<<"----------Grand patrons-----------"<<endl;
	for(i = 0;i < sum;i++)
	{
	if((pd+i)->money>10000)
	{
		cout<<(pd+i)->name<<"\t"<<(pd+i)->money<<endl;
		count_g++;
	}
	}
	if(count_g==0)
		cout<<"None."<<endl;
	cout<<"-------------patrons-----------"<<endl;
	for( i = 0;i<sum;i++)
	{
	if((pd+i)->money<10000)
        {
	        cout<<(pd+i)->name<<"\t"<<(pd+i)->money<<endl;
        	count++;
	}
	}
	if(!count)
		cout<<"None."<<endl;
	return 0;
}
