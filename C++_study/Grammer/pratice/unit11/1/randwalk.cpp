#include<iostream>
#include<fstream>
#include<cstdlib>
#include"vector.h"
#include<ctime>

int main()
{
	using namespace std;
	using VECTOR::Vector;
	
	std::ofstream fout;
	fout.open("Randwalk.txt");
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0,0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout<<"Enter target distance(q to quit): ";
	while(cin>>target)
	{
		cout<<"Enter step length: ";
		if(!(cin>>dstep))
			break;
		fout<<"A single step is "<<dstep;
		fout<<"\nThe length with Destination is "<<target<<endl;
		while(result.magval()<target)
		{
			direction = rand()%360;
			step.reset(dstep,direction,Vector::POL);
			result = result + step;
			steps++;
			fout<<steps<<": (x,y) = "<<result.xval()<<","
				<<result.yval()<<")\n";
		}
		fout<<"After "<<steps<<" steps,following location:\n";
		fout<<result<<endl;
		result.polar_mode();
		fout<<" or\n"<<result<<endl;
		fout<<"average outward distance per step = "
			<<result.magval()/steps<<endl;
		steps = 0;
		result.reset(0.0,0.0);
		cout<<"Enter target distance(q to quit): ";		

	}
	cout<<"Bye!\n";
	fout.close();
	cin.clear();
	while(cin.get()!='\n')
		continue;
	return 0;
}

