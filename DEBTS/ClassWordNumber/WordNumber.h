#include <iostream>

class WordNumber
{
public:
	static const int N = 25;
	
	WordNumber(){}
	WordNumber(char*,int);
	void setWord(char*);
	void setNumber(int);
	char* getWord();
	int getNumber()const;

private:
	char word[N];
	int number;
};
