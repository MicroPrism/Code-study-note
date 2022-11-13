/*
	code 1 of chapter practice 3
*/
#include <iostream>

int main(void)
{
	using namespace std;
	cout<<"plz input you yingchi :";
	int inch,yingcun;
	cin>>inch;
	cout<<"plz input you yingcun :";
	cin>>yingcun;
	cout<<"plz input weight : "<<endl;
	double weight;
	cin>>weight;
	const int FOOT_TO_INCH = 12;
	const double FOOT_TO_MI = 0.0254;
	const double FOOT_TO_KG = 2.2;
	double height = ( inch * FOOT_TO_INCH + yingcun) * FOOT_TO_MI;
	double weigh = weight / FOOT_TO_KG;
	double bmi = weigh / (height * height);
	cout<<"Your BMI is : "<<bmi<<endl;
	return 0;
}
