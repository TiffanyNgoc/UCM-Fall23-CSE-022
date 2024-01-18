// This is the complete solution code
#include <cstdio>
#include <iostream>
using namespace std;

int main() {

    string name;
    string address1;
    string address2;

    getline(cin, name);
    getline(cin, address1);
    getline(cin, address2);

    float l, w, h;
    cin >> l >> w >> h;
    cin.ignore();
    string material;
    getline(cin, material);

    bool delivery;
    cin >> delivery;

    cout << "-------------------------" << endl;
    cout << "          QUOTE          " << endl;
    cout << "-------------------------" << endl;
    cout << name << endl;
    cout << address1 << endl;
    cout << address2 << endl;
    cout << endl;
    cout << "DESCRIPTION SUMMARY" << endl;
    cout << "Dimensions: " << l << " x " << w << " x " << h << endl;
    cout << "Material: " << material << endl;

    if (delivery == true){
        cout << "Delivery: Yes" << endl; 
    }
    else{
        cout << "Delivery: No" << endl;
    }
    cout << endl;
    cout << "PRICE SUMMARY" << endl;

    float materialPrice = 0;
    if (material == "Wood"){
        materialPrice = 1.5;
    }
    if (material == "Metal"){
        materialPrice = 2.0;
    }

    float wallTotal = ((l * h * 2) + (w * h * 2)) * materialPrice;

    cout << "Walls:    $" << wallTotal << endl;

    float roofPrice = 3.0;
    float roofTotal = w * l * roofPrice;

    cout << "Roof:     $" << roofTotal << endl;

    float deliveryTotal = 0;
    if (delivery && (wallTotal + roofTotal) < 1500){
        deliveryTotal = 100;
    }
    cout << "Delivery: $" << deliveryTotal << endl;

    float total = wallTotal + roofTotal + deliveryTotal;
    cout << "Total:    $" << total << endl;
    return 0;
}