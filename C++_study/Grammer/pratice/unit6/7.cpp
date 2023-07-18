#include<iostream>
#include<cstring>
int main(void)
{
	using namespace std;
	char input[100];
	int voweles,consonants,others;
	int flag_word = 1;
	for(int i = 0;(input[i] = cin.get())!='q';i++)
	{
		;
	}
	//getline(cin,input);
	for(int i = 0;input[i]!='q';i++)
	{
		if(isspace(input[i]))
		{
			flag_word = 1;
		}
		else if(isalpha(input[i]) && flag_word)
		{
			switch(input[i])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':voweles++;flag_word = 0;break;
			default :consonants++;flag_word = 0;break;
			}
		}
		else if(flag_word)
		{
			others++;
			flag_word=0;
		}
	}
	cout<<voweles<<" words beginning with vowels."<<endl;
	cout<<consonants<<" word beginning with consonants."<<endl;
	cout<<others<<" word beginning with others."<<endl;
	return 0;
}
