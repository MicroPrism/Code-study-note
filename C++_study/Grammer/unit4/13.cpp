#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	char animal[20] = "bear";
	const char *bird = "wren";
	char *ps;
	cout<<animal<<" and "<<bird<<"\n";
	cout<<"Enter a kind of animal "<<endl;
	cin.getline(animal,20);
	ps = animal;
	cout<<ps<<"!\n";
	cout<<"Before using strcpy() : \n";
	cout<<animal<<" at "<<(int *)animal<<endl;
	cout<<ps<<" at "<<(int *)ps<<endl;

	ps = new char[strlen(animal)+1];
	strcpy(ps,animal);
	cout<<"after copy : \n";
	cout<<animal<<" at "<<(int*)animal<<endl;
	cout<<ps<<" at "<<(int *)ps<<endl;
	delete [] ps;
	return 0;
}
