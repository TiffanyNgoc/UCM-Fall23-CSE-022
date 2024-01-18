#include <iostream>
#include <string>
using namespace std;

int main() {

    // Get in information

    string day;
    string time;
    
    getline(cin, day);
    getline(cin, time);

    float holes;
    cin >> holes;

    bool cart, clubs, balls;
    cin >> cart >> clubs >> balls;

    // Error messages

    if (!(time == "Morning" || time == "Afternoon" || time == "Twilight")) {
        cerr << "Invalid information" << endl;
        return 1;
    }

    if (!(holes == 9 || holes == 18)) {
        cerr << "Invalid information" << endl;
        return 1;
    }

    if (!(day == "Monday" || day == "Tuesday" || day == "Wednesday" || day == "Thursday" || day == "Friday" || day == "Saturday" || day == "Sunday")) {
        cerr << "Invalid information" << endl;
        return 1;
    }

    // Start printing out receipt

    cout << "---------------------" << endl;
    cout << "       RECEIPT       " << endl;
    cout << "---------------------" << endl;    
    cout << "Day: " << day << endl;
    cout << "Time: " << time << endl;
    cout << "Holes: " << holes << endl;

    // Boolean values for printing out

    if (cart == true) {
        cout << "Cart: Yes" << endl;
    }
    else {
        cout << "Cart: No" << endl;
    }

    cout << endl;
    cout << "EXTRAS" << endl;

    if (clubs == true) {
        cout << "Rental Clubs: Yes" << endl;
    }
    else {
        cout << "Rental Clubs: No" << endl;
    }

    if (balls == true) {
        cout << "Range Balls: Yes" << endl;
    }
    else {
        cout << "Range Balls: No" << endl;
    }

    // Printing out second part of receipt

    cout << endl;
    cout << "PRICE SUMMARY" << endl;

    // Start assigning to days and times and holes

    float greenFees = 0;

    // Price for holes 18 and on weekends

    if ((day == "Saturday" && time == "Morning" && holes == 18) || (day == "Sunday" && time == "Morning" && holes == 18)) {
        greenFees = 60;
    }
    else if ((day == "Saturday" && time == "Afternoon" && holes == 18) || (day == "Sunday" && time == "Afternoon" && holes == 18)) {
        greenFees = 40;
    }
    else if ((day == "Saturday" && time == "Twilight" && holes == 18) || (day == "Sunday" && time == "Twilight" && holes == 18)) {
        greenFees = 35;
    }
    
    // Price for holes 18 and on weekdays

    else if ((day == "Monday" && time == "Morning" && holes == 18) || (day == "Tuesday" && time == "Morning" && holes == 18) || (day == "Wednesday" && time == "Morning" && holes == 18) || (day == "Thursday" && time == "Morning" && holes == 18) || (day == "Friday" && time == "Morning" && holes == 18)) {
        greenFees = 45;
    }
    else if ((day == "Monday" && time == "Afternoon" && holes == 18) || (day == "Tuesday" && time == "Afternoon" && holes == 18) || (day == "Wednesday" && time == "Afternoon" && holes == 18) || (day == "Thursday" && time == "Afternoon" && holes == 18) || (day == "Friday" && time == "Afternoon" && holes == 18)) {
        greenFees = 30;
    }
    else if ((day == "Monday" && time == "Twilight" && holes == 18) || (day == "Tuesday" && time == "Twilight" && holes == 18) || (day == "Wednesday" && time == "Twilight" && holes == 18) || (day == "Thursday" && time == "Twilight" && holes == 18) || (day == "Friday" && time == "Twilight" && holes == 18)) {
        greenFees = 25;
    }

    // Price for holes 9 and on weekends

    else if ((day == "Saturday" && time == "Morning" && holes == 9) || (day == "Sunday" && time == "Morning" && holes == 9)) {
        greenFees = 30;
    }
    else if ((day == "Saturday" && time == "Afternoon" && holes == 9) || (day == "Sunday" && time == "Afternoon" && holes == 9)) {
        greenFees = 20;
    }
    else if ((day == "Saturday" && time == "Twilight" && holes == 9) || (day == "Sunday" && time == "Twilight" && holes == 9)) {
        greenFees = 17.5;
    }

    // Price for holes 9 and on weekdays

    else if ((day == "Monday" && time == "Morning" && holes == 9) || (day == "Tuesday" && time == "Morning" && holes == 9) || (day == "Wednesday" && time == "Morning" && holes == 9) || (day == "Thursday" && time == "Morning" && holes == 9) || (day == "Friday" && time == "Morning" && holes == 9)) {
        greenFees = 22.5;
    }
    else if ((day == "Monday" && time == "Afternoon" && holes == 9) || (day == "Tuesday" && time == "Afternoon" && holes == 9) || (day == "Wednesday" && time == "Afternoon" && holes == 9) || (day == "Thursday" && time == "Afternoon" && holes == 9) || (day == "Friday" && time == "Afternoon" && holes == 9)) {
        greenFees = 15;
    }
    else if ((day == "Monday" && time == "Twilight" && holes == 9) || (day == "Tuesday" && time == "Twilight" && holes == 9) || (day == "Wednesday" && time == "Twilight" && holes == 9) || (day == "Thursday" && time == "Twilight" && holes == 9) || (day == "Friday" && time == "Twilight" && holes == 9)) {
        greenFees = 12.5;
    }
    else {
        cout << "fuuuuu" << endl;
        cerr << "Invalid information" << endl;

        return 1;
    }

    // Prices for cart

    float cartPrice = 0;

    if (holes == 9 && cart == true) {
        cartPrice = 10;
    }
    else if (holes == 18 && cart == true) {
        cartPrice = 20;
    }

    // Prices for rental clubs

    float clubPrice = 0;

    if (clubs == true) {
        clubPrice = 15;
    }

    // Prices for range balls

    float ballPrice = 0;

    if (balls == true) {
        ballPrice = 7;
    }

    // Cout prices

    cout << "Green Fee:    $" << greenFees << endl;
    cout << "Cart Fee:     $" << cartPrice << endl;

    if (clubs == true) {
        cout << "Rental Clubs: $" << clubPrice << endl;
    }

    if (balls == true) {
        cout << "Range Balls:  $" << ballPrice << endl;
    }

    float total = greenFees + cartPrice + clubPrice + ballPrice;
    cout << "Total:        $" << total << endl;


    return 0;
}