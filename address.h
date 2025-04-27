#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string street;
    string city;
    string state;
    string postalCode;

public:
    Address();
    Address(string str, string cty, string st, string pC);
    
    void setStreet(string str);
    void setCity(string cty);
    void setState(string st);
    void setPostalCode(string pC);

    string getStreet();
    string getCity();
    string getState();
    string getPostalCode();

    void display();

    friend istream &operator>>(istream &is, Address &address);
};

#endif // ADDRESS_H
