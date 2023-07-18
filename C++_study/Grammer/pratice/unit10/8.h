#ifndef UNIT_10_8_
#define UNIT_10_8_
class List
{
private:
	typedef int Item;
	enum {MAX = 20};
	int top;
	Item array[MAX];
	void add(int a){a++;};
	
public:
	List();
	List(int a);
	~List();
	void add_data(Item a);
	bool isfull() const;
	bool isempty() const;
	//void visit(void (*pf)(int & a));
};
#endif
