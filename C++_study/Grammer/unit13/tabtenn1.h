#ifndef TABTENN_H_
#define TABTENN_H_
#include<string>
using std::string;
class TabTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TabTennisPlayer(const string & fn = "none",
			const string & ln = "none",
			bool ht = false);
	void Name() const;
	bool Hastable() const {return hasTable;};
	void ResetTable(bool v){hasTable = v;}
};
class RatedPlayer : public TabTennisPlayer
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0,
			const string & fn = "none",
			const string & ln = "none",
			bool ht = false);
	RatedPlayer(unsigned int r,const TabTennisPlayer & tb);
	unsigned int Rating() const{return rating;}
	void ResetRating(unsigned int r){rating = r;}
};

#endif
