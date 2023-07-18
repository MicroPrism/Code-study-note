#include<iostream>
#include<cctype>
#include"5.h"
int main()
{
	using namespace std;
	Stack st;
	char ch;
	customer po;
	cout<<"Please enter A to add a purchase order,\n"
		<<"P to process a P0,or Q to quit.\n";
	while(cin>>ch && toupper(ch)!='Q')
	{
		while(cin.get()!='\n')
			continue;
		if(!isalpha(ch))
		{
			cout<<'\a';
			continue;
		}
		switch(ch)
		{
			case 'A':
			case 'a':cout<<"Enter a P0 number to add: ";
				cin.getline(po.fullname,35);
				cin>>po.payment;
				if(st.isfull())
					cout<<"Warning! Stack is full!\n";
				else 
					st.push(po);
				break;
			case 'p':
			case 'P':if(st.isempty())
					cout<<"Warning! Stack is empty!\n";
				else
					st.pop();
				break;
		}
		cout<<"Please enter A to add a purchase order,\n"
			<<"P to process a P0,or Q to quit.\n";
	}
	cout<<"Bye\n";
	return 0;
}
