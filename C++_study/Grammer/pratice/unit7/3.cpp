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

void Show(const struct box);
void Volume(struct box*);

int main(void)
{
	box phone;
	cout<<"maker name is ? ";
	cin.getline(phone.maker,40);
	cout<<"Enter height,width and length in sequence : ";
	cin>>phone.height>>phone.width>>phone.length;
	Volume(&phone);
	Show(phone);
	return 0;
}
void Show(const struct box a)
{
	using namespace std;
	cout<<"The maker is :"<<a.maker<<"\n"
	<<"The height is :"<<a.height<<"\n"
	<<"The width is :"<<a.width<<"\n"
	<<"The length is :"<<a.length<<"\n"
	<<"The volume is :"<<a.volume<<endl;
}
void Volume(struct box* a)
{
	a->volume = a->height * a->width * a->length;
}
