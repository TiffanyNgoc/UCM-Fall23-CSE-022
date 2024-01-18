#include <iostream>
#include "ucm_display.h"
#include "ucm_display.h"

using namespace std;

int main() {

    string heading;

    while(getline(cin, heading)) {
        displayBanner(heading);
    }

    return 0;
}