#ifndef UCM_UTILS_H
#define UCM_UTILS_H
#include <iostream>
using namespace std;

void alignedHeader(string s, char align){
    if (align == 'm'){
        for( int i = 0; i < s.length() + 8; i++){
            cout << "=";
        }
        cout << endl;
        cout << "    " <<  s << "    " << endl;

        for( int i = 0; i < s.length() + 8; i++){
            cout << "=";
        }
    cout << endl;
    }
    else if (align == 'r'){
        for( int i = 0; i < s.length() + 4; i++){
            cout << "=";
        }
        cout << endl;
        cout << "    " <<  s << "" << endl;

        for( int i = 0; i < s.length() + 4; i++){
            cout << "=";
        }
        cout << endl;
    }
    else{
        for( int i = 0; i < s.length() + 4; i++){
            cout << "=";
        }
        cout << endl;
        cout << "" <<  s << "    " << endl;

        for( int i = 0; i < s.length() + 4; i++){
            cout << "=";
        }
        cout << endl;
    }
}


#endif