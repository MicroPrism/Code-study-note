//文件
#include<iostream>
#include<fstream>
int main(void)
{
	using namespace std;
	char automobile[50];
	int year;
	double a_price;
	double b_price;

	ofstream outFile;
	outFile.open("carinfo.txt");
	cout<<"Enter the make and model of automobile: ";
	cin.getline(automobile,50);
	cout<<"Enter the model year: ";
	cin>>year;
	cout<<"Enter the original asking price: ";
	cin>>a_price;
	b_price = 0.913 * a_price;

	cout<<fixed;//一般方式表示浮点数，而非科学技术法
	cout.precision(2);//保留两位小数点精度
	cout.setf(ios_base::showpoint);//强制显示小数点后的0
	cout<<"Make and model: "<<automobile<<endl;
	cout<<"Year: "<<year<<endl;
	cout<<"was asking: "<<a_price<<endl;
	cout<<"Now asking: "<<b_price<<endl;

	outFile<<fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile<<"Make and model: "<<automobile<<endl;
	outFile<<"Year: "<<year<<endl;
	outFile<<"was asking: "<<a_price<<endl;
	outFile<<"Now asking: "<<b_price<<endl;
	outFile.close();
	return 0;
}
