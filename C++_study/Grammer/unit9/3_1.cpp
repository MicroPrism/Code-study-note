#include <iostream>
int tom = 3;
int dick = 30;
static int harry = 300;
void remote_access();

int main()
{
	using namespace std;
	cout<<"main() address Tom: "<<&tom<<" Dick : "<<&dick<<endl;
	cout<<"harry: "<<&harry<<endl;
	remote_access();
	return 0;
}
