#include<iostream>
#include<cctype>
#include"3.h"
int main()
{
	using namespace std;
	Stack st;
	char ch;
	unsigned long po;
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
				cin>>po;
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
					cout<<"PO # "<<po<<" Popped\n";
				break;
		}
		cout<<"Please enter A to add a purchase order,\n"
			<<"P to process a P0,or Q to quit.\n";
	}
	cout<<"Bye\n";
	return 0;
}
