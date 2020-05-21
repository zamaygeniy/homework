#include <iostream>
#include <string.h>
#include "wordnumber.h"
#include <fstream>

using namespace std;

void preprocess(char*, int*);
bool cmp(ifstream &, char*, int, int);
int search(char*, char*, int*);
void transfer(const char*, const char*, const char*);
int findlength(ifstream &);
void read(const char*);
wordnumber* setobj(char*, int);

int main() {
    transfer("D:\\new.bin","D:\\list.txt","D:\\text.txt");
    read("D:\\new.bin");
    return 0;
}

void  preprocess(char* pattern, int* alphabet) {
    int length = strlen(pattern);
    for (int i = 0; i < 256; i++)
        alphabet[i] = length;
    for (int i = 0; i < length - 1; i++)
        alphabet[pattern[i]] = length - 1 - i;
}

bool cmp(ifstream &text, char* pattern, int length, int skip) {
    int i = length;
    text.seekg(skip);
    for (int j = 0; j <= i; ++j ) {
        if (text.get() != pattern[j])
            return false;
    }
    return true;
}

int search(char* pattern, const char* textpath, int* alphabet) {
    int patternlength = strlen(pattern)-1;
    ifstream text(textpath);
    int textlength = findlength(text);
    int skip = 0, counter = 0;
    while (textlength - skip >= patternlength) {
        if (cmp(text, pattern, patternlength, skip)) {
            skip++;
            counter++;
        } else {
            text.seekg(skip + patternlength);
            skip = skip + alphabet[text.get()];
        }
    }
    text.close();
    return counter;
}

void transfer(const char* destination, const char* listpath, const char* textpath) {
    ofstream out(destination, ios::binary);
    ifstream list(listpath);
    int* alphabet = new int[256];
    char* pattern = new char[wordnumber::N]{ 0 };
    int sizebuff = sizeof(wordnumber);
    wordnumber* bufferobj;
    while (!list.eof()){
        list.getline(pattern, sizebuff);
        preprocess(pattern, alphabet);
        int counter = search(pattern, textpath, alphabet);
        bufferobj = setobj(pattern, counter);
        out.write((char*)bufferobj, sizebuff);
        delete bufferobj;
    }
    list.close();
    out.close();
    delete [] alphabet;
    delete [] pattern;
}

int findlength(ifstream &in){
    int pointer = in.tellg();
    in.seekg(0, ios::end);
    int n = in.tellg();
    in.seekg(pointer);
    return n-1;
}

void read(const char* source) {
    ifstream in(source, ios::binary);
    int sizebuff = sizeof(wordnumber);
    wordnumber* bufferobj = new wordnumber();
    while (in.read((char*)bufferobj, sizebuff)) {
        cout << bufferobj->getword() << '\t' << bufferobj->getnumber() << endl;
    }
    in.close();
}

wordnumber* setobj(char* word, int counter) {
    wordnumber* obj = new wordnumber();
    obj->setword(word);
    obj->setnumber(counter);
    return obj;
} 
