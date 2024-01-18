#include <iostream>

using namespace std;

int main(){

    int c = 0;

    for (int i = 0; i < 10; i++){
        int age;
        cin >> age;
        
        if (age >= 18){
            c++;
        }
    }

    cout << "There are " << c << " people who can enter" << endl;

    return 0;
}