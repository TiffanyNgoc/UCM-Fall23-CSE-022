#include <iostream>
#include <string>
using namespace std;

int main() {

    int month;
    cin >> month;

    int day;
    cin >> day;

    int year;
    cin >> year;

    // Error Messages

    if (month > 12 || month < 1) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    if (day < 1) {
        cerr << "Invalid date" << endl;
        return 1;
    }
    
    // Ordinal Function

    string ordinal;

    if (day % 100 == 11 || day % 100 == 12 || day % 100 == 13) {
        ordinal = "th";
    }
    else {
        if (day % 10 == 1) {
            ordinal = "st";
        }
        else {
            if (day % 10 == 2) {
                ordinal = "nd";
            }
            else {
                if (day % 10 == 3) {
                    ordinal = "rd";
                }
                else {
                    if (day % 10 == 4 || day % 10 == 5 || day % 10 == 6 || day % 10 == 7 || day % 10 == 8 || day % 10 == 9 || day % 10 == 0) {
                        ordinal = "th";
                    }
                }
            }
        }
    }
    
    // Start of printing out calender including error messages

    if ((month == 1) && (day <= 31)) {
        cout << "January" << " " << day << ordinal << ", " << year << endl;   
    }
    else if ((month == 1) && (day >=31)) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    if ((month == 2) && (day <= 28)) {
        cout << "February" << " " << day << ordinal << ", " << year << endl;
    }
    else if ((month == 2) && (day >= 28)) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    if ((month == 3) && (day <= 31)) {
        cout << "March" << " " << day << ordinal << ", " << year << endl;
    }
    else if ((month == 3) && (day > 31)) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    if ((month == 4) && (day <= 30)) {
        cout << "April" << " " << day << ordinal << ", " << year << endl;
    }
    else if ((month == 4) && (day > 30)) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    if ((month == 5) && (day <= 31)) {
        cout << "May" << " " << day << ordinal << ", " << year << endl;
    }
    else if ((month == 5) && (day > 31)) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    if ((month == 6) && (day <= 30)) {
        cout << "June" << " " << day << ordinal << ", " << year << endl;
    }
    else if ((month == 6) && (day > 30)) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    if ((month == 7) && (day <= 31)) {
        cout << "July" << " " << day << ordinal << ", " << year << endl;
    }
    else if ((month == 7) && (day > 31)) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    if ((month == 8) && (day <= 31)) {
        cout << "August" << " " << day << ordinal << ", " << year << endl;
    }
    else if ((month == 8) && (day > 31)) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    if ((month == 9) && (day <= 30)) {
        cout << "September" << " " << day << ordinal << ", " << year << endl;
    }
    else if ((month == 9) && (day > 30)) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    if ((month == 10) && (day <= 31)) {
        cout << "October" << " " << day << ordinal << ", " << year << endl;
    }
    else if ((month == 10) && (day > 31)) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    if ((month == 11) && (day <= 30)) {
        cout << "November" << " " << day << ordinal << ", " << year << endl;
    }
    else if ((month == 11) && (day > 30)) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    if ((month == 12) && (day <= 31)) {
        cout << "December" << " " << day << ordinal << ", " << year << endl;
    }
    else if ((month == 12) && (day > 31)) {
        cerr << "Invalid date" << endl;
        return 1;
    }

    return 0;
}