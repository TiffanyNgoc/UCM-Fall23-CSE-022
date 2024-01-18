#ifndef UCM_DISPLAY_H
#define UCM_DISPLAY_H

#include <iostream>

void printBanner(std::string text) {
    for (int i = 0; i < text.length() + 2; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;

    std::cout << " " << text << " " << std::endl;

    for (int i = 0; i < text.length() + 2; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

void displayBanner(std::string heading) {
    system("clear");
    printBanner(heading);
    std::cout << std::endl;
}

#endif