#include "wordnumber.h"
#include <cstring>

wordnumber::wordnumber(char* word, int number){
    setword(word);
    setnumber(number);
}
void wordnumber::setword(char* word){
    strcpy(this->word, word);
}
void wordnumber::setnumber(int number){
    this->number = number;
}
char* wordnumber::getword(){
    return word;
}
int wordnumber::getnumber()const{
    return this->number;
}