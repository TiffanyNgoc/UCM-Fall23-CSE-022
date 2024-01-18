#include <iostream>
#include <string>

using namespace std;

int main(){

    float width, depth, height, price;
    cin >> width >> depth >> height >> price;

    //only do ignore if statement is followed by a getline
    
    float total_area = (width * height * 2) + (depth * height * 2);

    float total_cost = total_area * price;

    cout << total_cost << endl;

    return 0;
}

//for i in $(ls projects); do ./app < projects/$i; done