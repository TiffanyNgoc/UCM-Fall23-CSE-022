#ifndef UCM_UTILS_H
#define UCM_UTILS_H
#include <iostream>
#include <string>

void widthControlledHeader(std::string text, int width) {
    std::cout << "=";
    for (int i = 1; i < width - 1; i++) {
        std::cout << "=";
    }
    std::cout << "=" << std::endl;

    if (text.length() > width - 4) {
        std::cout << "| ";
        for (int i = 0; i < width - 7; i++) {
            std::cout << text[i];
        }
        std::cout << "..." << " |" << std::endl;
    }
    else {
        std::cout << "| " << text;
        for (int i = 0; i < width - text.length() - 3; i++) {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }

    std:: cout << "=";
    for (int i = 1; i < width - 1; i++) {
        std::cout << "=";
    }
    std::cout << "=" << std::endl;
}

#endif