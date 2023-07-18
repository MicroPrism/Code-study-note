#include<iostream>
using namespace std;

struct job
{
	char name[40];
	double salary;
	float floor;
};
template<typename T>
void Swap(T&,T&);
void Show(job &j);
template<> 
void Swap<job>(job &j1,job & j2);

int main()
{
	job ha1 = {"yong",2222,11.3},ha2 = {"zhe",10000,333.3};
	Show(ha1);
	Show(ha2);
	Swap(ha1,ha2);
	Show(ha1);
	Show(ha2);
	return 0;
}
template<typename T>
void Swap(T &a,T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
template<> void Swap<job>(job &j1,job & j2)
{
	double t1;
	float t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
	//Swap(j1.salary,j2.salary);
	//Swap(j1.floor,j2.floor);
}
void Show( job &j)
{
	cout<<j.name<<" : $"<<j.salary<<" on floor "<<j.floor<<endl;
}
