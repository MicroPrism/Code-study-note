#ifndef UNIT_10_7_
#define UNIT_10_7_
class Plorg
{
private:
	static const int MAX = 20;
	char name[MAX];
	int CI;
public:
	Plorg();
	Plorg(const char  *p_name,int p_CI);
	~Plorg();
	void show() const;
	void set_CI(int a);
};
#endif
