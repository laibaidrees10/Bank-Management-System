#include "address.h"

Address::Address() {}

Address::Address(string str, string cty, string st, string pC)
{
    street = str;
    city = cty;
    state = st;
    postalCode = pC;
}

void Address::setStreet(string str)
{
    street = str;
}

void Address::setCity(string cty)
{
    city = cty;
}

void Address::setState(string st)
{
    state = st;
}

void Address::setPostalCode(string pC)
{
    postalCode = pC;
}

string Address::getStreet()
{
    return street;
}

string Address::getCity()
{
    return city;
}

string Address::getState()
{
    return state;
}

string Address::getPostalCode()
{
    return postalCode;
}

void Address::display()
{
    cout << street << ", " << city << ", " << state << ", " << postalCode << endl;
}

istream &operator>>(istream &is, Address &address)
{
    cout << "Enter street: ";
    getline(is, address.street);
    cout << "Enter city: ";
    getline(is, address.city);
    cout << "Enter state: ";
    getline(is, address.state);
    cout << "Enter postal code: ";
    getline(is, address.postalCode);
    return is;
}
