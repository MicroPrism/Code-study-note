#include <iostream>
struct chaff
{
	char dross[20];
	int slag;
};
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	chaff arr[100];
	chaff *pc = new(arr) chaff [2];
	for(int i = 0;i<2;i++)
	{
		cin.getline((pc+i)->dross,20);
		cin>>(pc+i)->slag;
		cin.get();
	}
	for(int i = 0;i<2;i++)
	{
		cout<<(pc+i)->dross<<endl;
		cout<<(pc+i)->slag<<endl;
	}
	chaff *pc2 = new chaff[2];
	for(int i = 0;i<2;i++)
	{
		cin.getline((pc2+i)->dross,20);
		cin>>(pc2+i)->slag;
		cin.get();
	}
	for(int i = 0;i<2;i++)
	{
		cout<<(pc2+i)->dross<<endl;
		cout<<(pc2+i)->slag<<endl;
	}
	delete [] pc2;
	return 0;
}
