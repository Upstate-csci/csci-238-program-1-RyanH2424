/********
 Author: Ryan Hemelgarn
 Program: Money class - program assignment #1 (Grade A version)
 Due Date: February 3, 2020
 Purpose: convert format of money
 ********/
#include "money.h"

// Convert currency to a string format.
string Money::toString() {
    stringstream string;
    string << hundreds << " hundreds, " << tens << " tens, " << fives << " fives, " << ones << " ones, " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << cents << " cents";
    return string.str();
}

// Set account to a local currency and return.
string Money::toCurrency(double amount) {
    stringstream ss;

    ss << showbase << put_money(amount*100);
    return ss.str();
}

// Reads the users input and gives it back to them showing what kinds of currency they have and the total.
string Money::processChange() {
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents;
    float total2 = (float) total;
    total = hundreds * 100 + tens * 10 + fives * 5 + ones * 1 + quarters * 0.25 + dimes * 0.10 + nickels * 0.05 + cents * 0.01;
    // No rounding error fix needed.
    //show all parts and then the total.
    cout << toString() << " = $" << total;
    return "";
}

// Take the currency given by the user and break it down into all of its parts.
string Money::processFloat() {
    float total2 = (float) total;
    cin >> total2;
    double amount;
    amount = total2;
    //Put the values into the variables.
    hundreds = amount / 100;
    amount -= hundreds * 100;
    tens = amount / 10;
    amount -= tens * 10;
    fives = amount / 5;
    amount -= fives * 5;
    ones = amount / 1;
    amount -= ones * 1;
    quarters = amount / 0.25;
    amount -= quarters * 0.25;
    dimes = amount / 0.10;
    amount -= dimes * 0.10;
    nickels = amount / 0.05;
    amount -= nickels * 0.05;
    cents = amount / 0.01;
    amount -= cents * 0.01;
    //Fix for rounding error.
    if (amount != 0)
        cents++;
    //Show the total and then all of the parts.
    cout << total2 << " = " << toString();
    return "";
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
    return "";
}

// Take the amount someone paid and the actual cost then subtract them to get their change.
string Money::processChangeFloat() {
    float payment2 = (float) payment;
    float total2 = (float) total;
    cin >> payment;
    cin >> total;
    change = payment - total;
    double amount;
    amount = change;
    //Put values into the variables
    hundreds = amount / 100;
    amount -= hundreds * 100;
    tens = amount / 10;
    amount -= tens * 10;
    fives = amount / 5;
    amount -= fives * 5;
    ones = amount / 1;
    amount -= ones * 1;
    quarters = amount / 0.25;
    amount -= quarters * 0.25;
    dimes = amount / 0.10;
    amount -= dimes * 0.10;
    nickels = amount / 0.05;
    amount -= nickels * 0.05;
    cents = amount / 0.01;
    amount -= cents * 0.01;
    // Fix for rounding error.
    if (amount != 0)
        cents++;
    // Display how much was paid and the actual cost to show the change that is owed, then break it into pieces.
    cout << "Change back on $" << payment << " for purchase of $" << total << " is " << change << " which is " << toString();

    return "";
}

// Take the amount someone paid and the actual cost then subtract them to get their change.
string Money::processChangeChange() {
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents >> total;
    payment = hundreds * 100 + tens * 10 + fives * 5 + ones * 1 + quarters * 0.25 + dimes * 0.10 + nickels * 0.05 + cents * 0.01;
    change = payment - total;
    //Show the amount paid in pieces and the total cost.
    cout << "change back on " <<  toString() << " for purchase of $" << total << " is ";
    double amount;
    amount = change;
    //Add values to the variables.
    hundreds = amount / 100;
    amount -= hundreds * 100;
    tens = amount / 10;
    amount -= tens * 10;
    fives = amount / 5;
    amount -= fives * 5;
    ones = amount / 1;
    amount -= ones * 1;
    quarters = amount / 0.25;
    amount -= quarters * 0.25;
    dimes = amount / 0.10;
    amount -= dimes * 0.10;
    nickels = amount / 0.05;
    amount -= nickels * 0.05;
    cents = amount / 0.01;
    amount -= cents * 0.01;
    //fix for rounding error.
    if (amount != 0)
        cents++;
    // Show the change given from how much was paid and the total cost, then show it in pieces.
    cout << change << " which is " << toString();

    return "";
}