#include <iostream>
#include <ucm_random>

using namespace std;

int main() {

    // Your code here

    int n, a , b;
    cin >> n >> a >> b;

    RNG generator;

    for (int i = 0; i < n; i++){
        int x = generator.get(a, b);
        cout << x << endl;
    }

    



	return 0;
}