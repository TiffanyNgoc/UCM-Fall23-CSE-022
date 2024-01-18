#include <iostream>
#include <ucm_random>

using namespace std;

int main() {

    // Your code here

    int n;
    cin >> n;

    RNG generator;

    for (int i = 0; i < n; i++){
        int x = generator.get(100, 1000);
        cout << x << endl;
    }

    



	return 0;
}