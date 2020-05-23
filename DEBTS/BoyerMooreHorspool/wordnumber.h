#ifndef WORDCOUNTER_WORDNUMBER_H
#define WORDCOUNTER_WORDNUMBER_H

class WordNumber {
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

#endif //WORDCOUNTER_WORDNUMBER_H
