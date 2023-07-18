#include<iostream>
#include"tabtenn1.h"

TabTennisPlayer::TabTennisPlayer(const string & fn,
	const string & ln,bool ht):firstname(fn),lastname(ln),hasTable(ht)
{}
void TabTennisPlayer::Name() const
{
	std::cout << lastname << " , " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r,const string & fn,
			const string & ln,bool ht):TabTennisPlayer(fn,ln,ht) 
{
	rating = r;
}
RatedPlayer::RatedPlayer(unsigned int r,const TabTennisPlayer & tp):TabTennisPlayer(tp),rating(r) 
{
	
}
			
