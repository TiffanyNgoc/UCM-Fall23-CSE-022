#include <iostream>
using namespace std;

int main() {

    //Handicap Index X (Slope rating/113) + (Course Rating-Par)
    //10.6994 X (134/113) + 73.5-72

    float line1, line2, line3, line4;
    cin >> line1 >> line2 >> line3 >> line4;

    cout << line1 * (line3/113) + (line2 - line4); 
    
    return 0;
}