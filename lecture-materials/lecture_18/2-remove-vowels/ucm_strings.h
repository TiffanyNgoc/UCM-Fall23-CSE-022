#ifndef UCM_STRINGS_H
#define UCM_STRINGS_H

#include<string>

/*
    Create a function that removes all the vowels from a string.
*/


bool isVowel(char letter){
    letter = toupper(letter);
    if (letter == 'A' || letter == 'I' || letter == 'O' || letter == 'E' || letter == 'U'){
        return true;
    }
    else{
        return false;
    }
}

//                         COMPUTER -> CMPTR
std::string removeVowels(std::string sen){
    std::string result = "";

    for (int i = 0; i < sen.length(); i++){
        if (!isVowel(sen[i])){
            result = result + sen[i];
        }
    }

    return result;
}


#endif