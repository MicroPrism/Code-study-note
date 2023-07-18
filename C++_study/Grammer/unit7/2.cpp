#include<iostream>
const int Max = 5;

/*******************************/
int fill_array(double arr[],double *end);
void show_array(const double arr[],int n);
void revalue(double r,double arr[],int n);


/******************************/
int main(void)
{
	using namespace std;
	double properties[Max];

	int size = fill_array(properties,properties+Max);
	show_array(properties,size);
	if(size > 0)
	{
		cout<<"Enter revaluation factor: ";
		double factor;
		while(!(cin>>factor))
		{
			cin.clear();
			while(cin.get()!='\n')
				continue;
			cout<<"Bad input;reinput :";
		}
		revalue(factor,properties,size);
		show_array(properties,size);
	}
	cout<<"Done."<<endl;
	return 0;
}
void revalue(double r, double arr[], int n)
{
	for(int i = 0; i < n;i++ )
		arr[i] *= r;
}
void show_array(const double arr[],int n)
{
	using namespace std;
	for(int i = 0;i < n; i++ )
	{
		cout<<"Property #"<< i + 1<<" :";
		cout<<arr[i]<<endl;
	}
}
int fill_array(double arr[],double* end)
{
    using namespace std;
    double * pt;
    double temp;
    for(pt = arr;pt < end;pt++)
    {
        cout<<"Enter a value#"<<pt-arr+1<<" :";
        cin>>temp;
        if(!cin)
        {
            cin.clear();
            while(cin.get()!='\n')
                continue;
            break;
        }
        else if(temp<0)
        	break;
        *pt = temp;
    }
    return pt-arr;
}
