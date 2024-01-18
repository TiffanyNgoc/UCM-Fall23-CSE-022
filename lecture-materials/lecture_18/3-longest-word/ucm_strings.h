#ifndef UCM_STRINGS_H
#define UCM_STRINGS_H

#include<iostream>
#include <string>

/*
    Create a function that finds the largest word in a string.
*/

// hello world

// word = "hello"
std::string longestWord(std::string sen){
    std::string word = "";
    std::string longest = "";
    for (int i = 0; i < sen.length(); i++){
        if (sen[i] != ' '){
            word = word + sen[i];
        }
        else{
            if (word.length() > longest.length()){
                longest = word;
            }
            std::cout << "Word is: " << word << std::endl;
            word = "";
        }
    }

    std::cout << "Last word: " << word << std::endl;
    if (word.length() > longest.length()){
        longest = word;
    }

    return longest;
}

#endif