#include <iostream>
using namespace std;

int main() {

    string name;
    getline (cin, name);

    string title;
    getline (cin, title);

    string department;
    getline (cin, department);

    string school;
    getline (cin, school);

    string email;
    getline (cin, email);

    string phone;
    getline (cin, phone);

    cout << "" << endl;
    cout << "              | " << name << endl;
    cout << "              | " << endl;
    cout << "              | " << title << endl;
    cout << "  UNIVERSITY  | " << endl;
    cout << "      OF      | " << department << endl;
    cout << "  CALIFORNIA  | " << school << endl;
    cout << "    MERCED    | " << endl;
    cout << "              | 5200 Lake Road | Merced, CA 95343" << endl;
    cout << "              | " << email << endl;
    cout << "              | " << phone << endl;
    cout << "" << endl;
    cout << "BUILDING THE FUTURE IN THE HEART OF CALIFORNIA" << endl;

    return 0;
}