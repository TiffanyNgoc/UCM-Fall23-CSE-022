#ifndef UCM_HIDDEN_H
#define UCM_HIDDEN_H

#include <termios.h>
#include <unistd.h>
#include <iostream>

struct HIDDEN_INPUT {
    static int count;
    HIDDEN_INPUT(){}
    
    std::string get(){
        termios oldt;
        
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        std::string s;
        std::cin >> s;

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return s;
    }
};

#endif