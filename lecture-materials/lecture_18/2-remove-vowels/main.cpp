#include <iostream>
#include "ucm_strings.h"
using namespace std;

int main() {

    string text = "The quick brown fox jumps over the lazy dog.";
    string result = removeVowels(text);

    cout << text << endl;
    cout << result << endl;

    // RSLT

    return 0;
}
