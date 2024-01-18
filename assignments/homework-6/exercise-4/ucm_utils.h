#ifndef UCM_UTILS_H
#define UCM_UTILS_H

#include <cstddef>
#include <iostream>
#include <algorithm>

bool wordExists(std::string text, std::string target) {
    std::transform(text.begin(), text.end(), text.begin(), ::tolower);
    std::transform(target.begin(), target.end(), target.begin(), ::tolower);

    std::string delimiter = ",. ";
    size_t pos = 0;
    std::string word;

    while ((pos = text.find_first_of(delimiter)) != std::string::npos) {
        word = text.substr(0, pos);
        // Check if the current word matches the target word
        // If yes, return true
        if (word == target) {
            return true;
        }
        // Erase the processed word and delimiter from the text
        text.erase(0, pos + 1);
    }
    if (text == target) {
        return true;
    }
    return false;
}

#endif