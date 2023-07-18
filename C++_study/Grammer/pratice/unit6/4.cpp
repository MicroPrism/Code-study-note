#include<iostream>

using namespace std;

const int strize = 20;

/*****************/
struct bop
{
	char fullname[strize];
	char title[strize];
	char bopname[strize];
	int preference;
};
/****************/
void Menu(void);
void Choice(int*,char*,struct bop*);
void Display_byname(struct bop*);
void Display_bytitle(struct bop*);
void Display_bybopname(struct bop*);
void Display_bypreference(struct bop*);

/****************/
int main(void)
{
//	using namespace std;
	struct bop text[10]={
				{"Wimp Ma","AA","Cat",1},
				{},
				{"Raki Pat","AAA","Dog",1},
				{}
	};
	struct bop *pb = text;
	char ch;
	int flag = 1;
	Menu();
	Choice(&flag,&ch,pb);
	return 0;
}
void Menu()
{
	cout<<"Display by \n"
		<<"a)name\t"<<"b)title\t"<<"c)bopname\t"
		<<"d)preference\t"<<"q)quit\t"<<endl;
}
void Choice(int* a,char* ch,struct bop *pt)
{
	while(*a)
	{
		*a = 0;
		cin.get(*ch).get();
		switch(*ch)
		{
		case 'a':Display_byname(pt);break;
		case 'b':Display_bytitle(pt);break;
		case 'c':Display_bybopname(pt);break;
		case 'd':Display_bypreference(pt);break;
		case 'q':cout<<"Bye~"<<endl;break;
		default :cout<<"Enter a,b,c,d or q:"<<endl;
			*a = 1;break;
		}
	}
}
void Display_byname(struct bop *b)
{
	int i = 0;
	for(i;i<10;i++)
	{
		cout<<(b+i)->fullname<<endl;
	}
}
void Display_bytitle(struct bop *b)
{
        int i = 0;
        for(i;i<10;i++)
        {
		cout<<(b+i)->title<<endl;
	}
}
void Display_bybopname(struct bop *b)
{
        int i = 0;
        for(i;i<10;i++)
        {
                cout<<(b+i)->bopname<<endl;
        }
}
void Display_bypreference(struct bop *b)
{
        int i = 0;
        for(i;i<10;i++)
        {
                cout<<(b+i)->fullname<<"\t"<<(b+i)->title<<endl;
        }
}
