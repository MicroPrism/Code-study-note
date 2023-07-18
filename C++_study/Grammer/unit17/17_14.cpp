#include<iostream>

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	
	char ch;
	while(cin.get(ch))//为字符ch赋值并返回iostream & 
	{
		if(ch != '#')
			cout << ch;
		else
		{
			cin.putback(ch);//检测到ch = # 则插入回去
			break;
		}
	}
	if(!cin.eof())//返回eofbit值，到达文件尾置1
	{
		cin.get(ch);
		cout << ch << " is next input character.\n";
	}
	else
	{
		cout << "End of file reached.\n";
		std::exit(0);//status = 0 正常退出
	}
	while(cin.peek()!='#')//先检测再赋值，不需要回插
	{
		cin.get(ch);
		cout << ch;
		
	}
	if(!cin.eof())//返回eofbit值，到达文件尾置1s
	{
		cin.get(ch);
		cout << ch << " is next input character.\n";
	}
	else
		cout << "End of file reached.\n";
	return 0;
}
