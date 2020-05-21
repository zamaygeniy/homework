#ifndef WORDCOUNTER_WORDNUMBER_H
#define WORDCOUNTER_WORDNUMBER_H

class wordnumber {
public:
    static const int N = 25;
    wordnumber(){}
    wordnumber(char*,int);
    void setword(char*);
    void setnumber(int);
    char* getword();
    int getnumber()const;

private:
    char word[N];
    int number;
};

#endif //WORDCOUNTER_WORDNUMBER_H
