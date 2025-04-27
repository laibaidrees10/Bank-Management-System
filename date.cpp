#include "date.h"

Date::Date() {
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

void Date::setDay(int d) {
    day = d;
}

void Date::setMonth(int m) {
    month = m;
}

void Date::setYear(int y) {
    year = y;
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

void Date::display() {
    cout << day << "/" << month << "/" << year << endl;
}

istream &operator>>(istream &is, Date &date) {
    cout << "Enter day: ";
    is >> date.day;
    cout << "Enter month: ";
    is >> date.month;
    cout << "Enter year: ";
    is >> date.year;
    return is;
}
