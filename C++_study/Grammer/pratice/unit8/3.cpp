#include<iostream>
using namespace std;

void low_to_upper(string &);

int main()
{
	string ax;
	while(getline(cin,ax))
	{
		if(ax[0] =='q')
			break;
		else
		{
			low_to_upper(ax);
			cout<<ax<<endl;
		}
	}
	return 0;
}
void low_to_upper(string & a)
{
	for(int i = 0;a[i];i++)
		a[i] = toupper(a[i]);
}
