#include<iostream>
#include<string>

struct free1
{
	std::string name;
	int made;
	int attempts;
	float percent; 
};

void Set_pc(free1 & );
void Display(const free1 &);
free1 & Acculate(free1 &,const free1 &);

int main(void)
{
	using namespace std;
	free1 one = {"A",13,14};
	free1 two = {"B",10,16};
	free1 three = {"C",7,9};
	free1 four = {"D",5,9};
	free1 five = {"E",6,14};
	free1 team = {"Total",0,0};
	free1 dup;
	
	Set_pc(one);
	Display(one);
	Acculate(team,one);
	Display(team);
	Display(Acculate(team,two));
	Acculate(Acculate(team,three),four);
	Display(team);
	dup = Acculate(team,five);
	Display(dup);
	Display(team);	
	return 0;
}
void Set_pc(free1 & ft)
{
	if(ft.attempts!=0)
		ft.percent =100.0*(float) ft.made / (float)ft.attempts;
	else
		ft.percent = 0;
}
void Display(const free1 &ft)
{
	using namespace std;
	cout<<ft.name<<endl;
	cout<<ft.made<<"\t"<<ft.attempts<<"\t"<<ft.percent<<endl;
}
free1 & Acculate(free1 & target,const free1 & source)
{
	free1 *pt = new free1;
   	 *pt = target;
  	  return *pt;
}
