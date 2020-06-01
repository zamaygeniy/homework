#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

typedef int(*Comparer)(int, int);
void sorting(const char*, Comparer);
void initFileFromConsole(const char*);
int ascending(int, int);
void readBinary(const char*,const char*);
void swap(int&, int&);

int main()
{
	initFileFromConsole("source.bin");
	readBinary("source.bin","Source array: ");
	cout << endl;
	sorting("source.bin", ascending);
	readBinary("source.bin","Resulting array: ");
	cout << endl;
	system("pause");
}
void readBinary(const char* path,const char* text)
{
	ifstream in(path, ios::binary | ios::in);
	if(!in.is_open())
	{
		throw "file can't be opened ";
	}
	if (!in)
	{
		throw "file not found ";
	}
	if (!in.peek())
	{
		throw "empty file ";
	}
	int a,numb = in.tellg() / sizeof(int);
	cout << text << endl;
	while (in.read((char*)&a, sizeof a))
	{
		cout << a <<'\t';
	}
	in.close();
}
void initFileFromConsole(const char* path)
{
	ofstream out(path,ios::binary|ios::out);
	if (!out.is_open())
	{
		throw "file can't be opened ";
	}
	if (!out)
	{
		throw "file not found ";
	}
	cout << "Enter number of numbers: ";
	int number, a;
	cin >> number;
	cout << "Enter array: ";
	if (number <= 0)
	{
		throw "invalid argument";
	}
	while (number)
	{
		cin >> a;
		out.write((char*)&a, sizeof a); //Çàïèñûâàåì â ôàéë ÷èñëî a
		number--;
	}
	out.close();
}
void sorting(const char* path, Comparer comparer)
{
	fstream out(path, ios::binary | ios::ate | ios::out | ios::in);
	if (!out.is_open())
	{
		throw "file can't be opened ";
	}
	if (!out)
	{
		throw "file not found ";
	}
	comparer = ascending;
	int arrj;
	int length = out.tellp();
	for (int i = length - 4; i >= 0; i-=4)
	{
		for (long int j = 0; j < i; j+=4)
		{
			out.seekg(j);
			int arrj;
			out.read((char*)&arrj, sizeof arrj);
			int arrj4;
			out.read((char*)&arrj4, sizeof arrj4);
			if (comparer(arrj4, arrj) > 0)
			{
				swap(arrj4, arrj);
				out.seekp(j);
				out.write((char*)&arrj, sizeof arrj);
				out.seekp(j + 4);
				out.write((char*)&arrj4, sizeof arrj4);
			}
			else
			{
				out.seekp(j);
				out.write((char*)&arrj, sizeof arrj);
				out.seekp(j + 4);
				out.write((char*)&arrj4, sizeof arrj4);
			}

		}
	}
}
int ascending(int a, int b)
{
	if (b - a > 0)
	{
		return 1;
	}
	if (b - a == 0)
	{
		return 0;
	}
	if (b - a < 0)
	{
		return -1;
	}
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;

}
