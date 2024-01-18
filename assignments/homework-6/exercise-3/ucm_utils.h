#ifndef UCM_UTILS_H
#define UCM_UTILS_H

#include <cctype>
#include <iostream>

bool WordE(char letter) {
    if (letter == ' ' || letter == ',' || letter == '.' || letter == '!' || letter == '?') {
        return true;
    }
    else {
        return false;
    }
}

std::string funkyString(std::string text) {
    for (int i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }
    for (int i = 0; i < text.length(); i++) {
        if (WordE(text[i])) {
            text [i - 1] = toupper(text[i - 1]);

            text[i + 1] = toupper(text[i + 1]);
        }
        text[0] = toupper(text[0]);
        text[text.length() - 1] = toupper(text[text.length() - 1]);
    }
    return text;
}
#endif