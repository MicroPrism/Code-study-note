#include<iostream>

int Input(int [],int);
void Show(const int [],int);
double Average(const int [],int);

int main(void)
{
	using namespace std;
	const int SIZE = 10;
	int player[SIZE];
	int length = Input(player,SIZE);
	Show(player,length);
	double aver_play1 = Average(player,length);
	cout<<"The average score is :"<<aver_play1<<endl;
}
int Input(int score[],int size)
{
	using namespace std;
	int i,temp;
	for(i = 0; i < size ; i++)
	{
		cout<<"Enter a score #"<< i + 1<<": ";
		cin>>temp;
		if(!cin)
		{
			cin.clear();
			while(cin.get() != '\n');
			i--;
			continue;
		}
		if(temp < 0)
			break;
		score[i] = temp;
	}
	return  i;
}
void Show(const int score[],int size)
{
	std::cout<<"The score is :";
	for(int i = 0;i < size; i++)
		std::cout<<score[i]<<"\t";
	std::cout<<std::endl;
}
double Average(const int score[],int size)
{
	double total;
	for(int i = 0; i < size ;i++)
		total += score[i];
	double aver =  total / size;
	return aver;
}
