#include <iostream>
#include "wordnumber.h"
#include <fstream>
#include <windows.h>
#include <cstring>
//"*.txt"

using namespace std;

void preprocess(char*, int*);
bool cmp(ifstream &, char*, int, int);
int search(char*, char*, int*);
void transfer(char*, char*, char*);
int findlength(ifstream &);
void read(char*);
void namebin(char*);
char* filelist(const char*);
int menu();
void systemfun();
void algorithm();

wordnumber* setobj(char*, int);

int main() {


    algorithm();
/*    char filename[50] = "List.bin";
    enum {init = 1, display, search, exit};
    while (true) {
        int key = menu();
        if (key == exit)
            return 0;
        system("cls");
        switch (key) {
            case init:
                namebin(filename);
                systemfun();
                break;
            case display:
                read(filename);
                systemfun();
                break;
            case search:
                algorithm();
                systemfun();
                break;
            default:
                cout << "\nIncorrect input! Try again!";
                systemfun();
        }

    }*/
    return 0;
}


void algorithm(){
    cout << "PICK WORDS LIST" << endl;
    char* list = filelist("*list.txt");
    cout << "PICK TEXT" << endl;
    char* text = filelist("*text.txt");
    cout << "PICK BIN FILE" << endl;
    char* bin = filelist("*.bin");
    transfer(bin, list, text);
    read(bin);
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

int search(char* pattern, char* textpath, int* alphabet) {
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

void transfer(char* destination, char* listpath, char* textpath) {
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
        cout << counter << endl;
        bufferobj = setobj(pattern, counter);
        out.write((char*)bufferobj, sizebuff);
        delete bufferobj;
    }
    list.close();
    out.close();
    delete [] alphabet;
    delete [] pattern;
}

int findlength(ifstream &in) {
    int pointer = in.tellg();
    in.seekg(0, ios::end);
    int n = in.tellg();
    in.seekg(pointer);
    return n-1;
}

void read(char* source) {
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

char* filelist(const char* marker) {
    WIN32_FIND_DATA FindFileData;
    HANDLE hf;

    char** filenames = new char*[15];
    for (int i = 0; i < 10; ++i)
        filenames[i] = new char[50];
    int counter = 0;

    hf = FindFirstFile(marker, &FindFileData);
    if (hf != INVALID_HANDLE_VALUE) {
        do {
            strcpy(filenames[counter], FindFileData.cFileName);
            cout << ++counter << ") " << filenames[counter-1] << "\n";
        }
        while (FindNextFile(hf, &FindFileData) != 0);
        FindClose(hf);
    }

    int n;
    cin >> n;
    char* buff;

    buff = filenames[n-1];
    for (int i = 0; i < counter-1; ++i)
        delete [] filenames[i];

    return buff;
}

int menu() {
    int k;
    cout << "Enter the number - the mode of operations with file:"
            "\n 1 - INITIALIZATION THE NAME OF FILE"
            "\n 2 - VIEWING OF CONTENTS OF THE FILE"
            "\n 3 - START STRING-SEARCHING ALGORITHM"
            "\n 4 - EXIT\n";
    cin >> k;
    return k;
}

void namebin(char* filename) {
    cout << "Enter the name of file: " << endl;
    cin.ignore();
    cin.getline(filename, 256, '\n');
    system("cls");
}

void systemfun() {
    cout << endl;
    system("pause");
    system("cls");
}