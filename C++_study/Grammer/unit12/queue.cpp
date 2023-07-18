#include"queue.h"
#include<cstdlib>

Queue::Queue(int qs):qsize(qs)
{
	front = rear = NULL;//0 or nullptr
	items = 0;
	//qsize = qs;
	//qs为const int型，应在构造函数体执行前赋值，声明为引用的类成员也应如此
	//初始化工作是在对象创建前完成的，此时还未执行括号内代码
	
}
Queue::~Queue()
{
	Node* temp;
	while(front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}
bool Queue::isempty() const
{
	return items == 0;
}
bool Queue::isfull() const
{
	return items == qsize;
}

bool Queue::enqueue(const Item & item)
{
	if(isfull())
		return false;
	Node * add = new Node;
	add->item = item;
	add->next = NULL;
	items ++;
	if(front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;//the end point to new address
	return true;
}
bool Queue::dequeue(Item & item)
{
	if(front == NULL)
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if(items == 0)
		rear = NULL;
	return true;
}
int Queue::queuecount() const
{
	return items;
}
void Customer::set(long when)
{
	processtime = std::rand()%3 + 1;
	arrive = when;
}
