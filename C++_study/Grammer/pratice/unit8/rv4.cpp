#include<iostream>
using namespace std;
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void Showbox(const box & a);
void Setbox_volume(box & a);
int main()
{
	box a = {"accc",168.3,50.2,3.0};
	Showbox(a);
	Setbox_volume(a);
	Showbox(a);
	return 0;
}
void Showbox(const box & a)
{
	cout<<a.maker<<"\t"
	<<a.height<<"\t"
	<<a.width<<"\t"
	<<a.length<<"\t"
	<<a.volume<<"\n";
}
void Setbox_volume(box & a)
{
	a.volume = a.length*a.width*a.height;
}
