#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
void file_it(ostream & os,double fo ,const double fe[],int n);


const int LIMIT = 5;
int main()
{
	ofstream fout;
	const char* fn = "ep-data.txt";
	fout.open(fn);
	if(!fout.is_open())
	{
		cout<<"Can't open"<<fn<<". Bye."<<endl;
		exit(EXIT_FAILURE);
	}
	double object;
	cout<<"Enter focal lengths of your telescope :";
	cin>>object;
	double eps[LIMIT];
	cout<<"Enter the focal lengths,in mm,of "<<LIMIT<<" eyepieces :"<<endl;
	for(int i = 0; i<LIMIT ;i++)
	{
		cout<<"Eyepiece #"<<i+1<<" : ";
		cin>>eps[i];
	}
	file_it(fout,object,eps,LIMIT);
	file_it(cout,object,eps,LIMIT);
	return 0;
}
void file_it(ostream & os,double fo ,const double fe[],int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);
	os.precision(0);
	os<<"Focal length of objective :"<<fo<<" mm.";
	os.setf(ios::showpoint);
	os.precision(1);
	//os.width(12);
	os.width(24);
	os<<" f.1. eyepiece";
	os.width(15);
	os << "magnification"<<endl;
	for(int i = 0; i < n; i++)
	{
		os.width(12);
		os<<fe[i];
		os.width(15);
		os<<int(fo/fe[i]+0.5)<<endl;
	}
	os.setf(initial);
}
