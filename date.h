#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int d, int m, int y);

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    int getDay();
    int getMonth();
    int getYear();

    void display();

    friend istream &operator>>(istream &is, Date &date);
};

#endif // DATE_H
