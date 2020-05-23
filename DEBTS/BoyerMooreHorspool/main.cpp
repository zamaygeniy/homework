#include <iostream>
#include <string.h>
#include "WordNumber.h"
#include <fstream>
#include <ctime>

using namespace std;

void preprocess(char*, int*); //заполнения массива скипов
bool cmp(ifstream &, char*, int, int); //сравнение подстрок
int search(char*, const char*, int*); //поиск подстроки
void transfer(const char*, const char*, const char*); //основной код
int findLength(ifstream &); //длина текста
void read(const char*); //чтение из bin
WordNumber* setObject(char*, int);

int main() {
    transfer("new.bin","list.txt","text.txt");          //поиск и запись
    read("new.bin");                                                      //чтение из бинарника
    cout << "/////////////////\n" << "runtime = " << clock()/1000.0 << endl;     //время работы
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

int search(char* pattern, const char* textPath, int* alphabet) {
    int patternLength = strlen(pattern)-1;
    ifstream text(textPath);
    int textLength = findLength(text);
    int skip = 0, counter = 0;
    while (textLength - skip >= patternLength) {
        if (cmp(text, pattern, patternLength, skip)) {
            skip++;
            counter++;
        } else {
            text.seekg(skip + patternLength);
            skip = skip + alphabet[text.get()];
        }
    }
    text.close();
    return counter;
}

void transfer(const char* destination, const char* listPath, const char* textPath) {
    ofstream out(destination, ios::binary);
    ifstream list(listPath);
    int* alphabet = new int[256];
    char* pattern = new char[WordNumber::N]{ 0 };
    int sizeBuff = sizeof(WordNumber);
    WordNumber* bufferObject;
    while (!list.eof()){
        list.getline(pattern, sizeBuff);
        preprocess(pattern, alphabet);
        int counter = search(pattern, textPath, alphabet);
        bufferObject = setObject(pattern, counter);
        out.write((char*)bufferObject, sizeBuff);
        delete bufferObject;
    }
    list.close();
    out.close();
    delete [] alphabet;
    delete [] pattern;
}

int findLength(ifstream &in){
    int pointer = in.tellg();
    in.seekg(0, ios::end);
    int n = in.tellg();
    in.seekg(pointer);
    return n-1;
}

void read(const char* source) {
    ifstream in(source, ios::binary);
    int sizeBuff = sizeof(WordNumber);
    WordNumber* bufferObject = new WordNumber();
    while (in.read((char*)bufferObject, sizeBuff)) {
        cout << bufferObject->getWord() << '\t' << bufferObject->getNumber() << endl;
    }
    in.close();
}

WordNumber* setObject(char* word, int counter) {
    WordNumber* obj = new WordNumber();
    obj->setWord(word);
    obj->setNumber(counter);
    return obj;
}