#include<iostream>

int Fill_array(double [],int);
void Show_array(const double [],int);
void Reverse_array(double [],int);

int main(void)
{
	using namespace std;
	const int SIZE = 10;
	double input[SIZE];
	int actual_size = Fill_array(input,SIZE);
	cout<<actual_size<<endl;
	Show_array(input,actual_size);
	Reverse_array(input,actual_size);
	Show_array(input,actual_size);
	return 0;
}
int Fill_array(double arr[],int size)
{
	using namespace std;
	int count;
	for(int i = 0;i < size;i++)
	{
		cout<<"Enter number #"<<i+1<<" : ";
		if(!(cin>>arr[i]))
		{
			cin.clear();
			while(cin.get()!='\n')
				continue;
			break;
		}
		count++;
	}
	return count;
}
void Show_array(const double arr[],int size)
{
	for(int i = 0;i < size ;i++)
		std::cout<<arr[i]<<"\t";
	std::cout<<"\n";
}
void Reverse_array(double arr[],int size)
{
	for(int i = 1; i <= (size-1)/2 ;i++)
	{
		double temp = arr[i];
		arr[i] = arr[size - i -1];
		arr[size-i-1] = temp;
	}
}
