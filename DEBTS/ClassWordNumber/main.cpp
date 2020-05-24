#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "WordNumber.h"

using namespace std;

void transfer(const char*, const char*);
void read(const char*);
WordNumber* parse(char*);

int main() {
	transfer("destination.txt", "source.txt");
	read("destination.txt");
}

void transfer(const char* destinationPath, const char* sourcePath) {
	ofstream out(destinationPath, ios::binary);
	ifstream in(sourcePath);
	char* buffer = new char[WordNumber::N]{ 0 };
	int bufferNumber = 0, sizeBuff = sizeof(WordNumber);
	WordNumber* bufferObj;

	while (!in.eof()) {
		in.getline(buffer, sizeBuff);
		bufferObj = parse(buffer);
		out.write((char*)bufferObj, sizeBuff);
		delete bufferObj;
	}

	in.close();
	out.close();
	delete[]buffer;
}

void read(const char* source) {
	ifstream in(source, ios::binary);
	int sizeBuff = sizeof(WordNumber);
	WordNumber* bufferObj = new WordNumber();

	while (in.read((char*)bufferObj, sizeBuff)) {
		cout << bufferObj->getWord() << '\t' << bufferObj->getNumber() << endl;
	}

	in.close();
}

WordNumber* parse(char* source) {
	char* word = new char[strlen(source)]{ 0 };
	char* numberChar = new char[strlen(source)]{ 0 };
	int  numberInt = 0;
	char* p = strchr(source, ' ');

	strncpy(word, source, (p - source));

	strcpy(numberChar, p + 1);
	numberInt = atoi(numberChar);

	WordNumber* obj = new WordNumber();

	obj->setWord(word);
	obj->setNumber(numberInt);
	
	return obj;
}
