#include "WordNumber.h"
#include <cstring>

WordNumber::WordNumber(char* word, int number){
    setWord(word);
    setNumber(number);
}
void WordNumber::setWord(char * word){
    strcpy(this->word, word);
}
void WordNumber::setNumber(int number){
    this->number = number;
}
char* WordNumber::getWord(){
    return word;
}
int WordNumber::getNumber()const{
    return this->number;
}