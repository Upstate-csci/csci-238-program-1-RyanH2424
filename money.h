//
// Created by rheme on 1/30/2020.
//

#ifndef UNTITLED_MONEY_H
#define UNTITLED_MONEY_H
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <locale>

using namespace std;
class Money
{
private:
    double change;
    double payment;
    double total;
    int hundreds, tens, fives, ones, quarters, dimes, nickels, cents;
public:
    string toString();
    string toCurrency(double amount);
    string processChange();
    string processFloat();
    string processCheck();
    string processChangeFloat();
    string processChangeChange();
};
#endif
