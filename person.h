#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "date.h"
#include "address.h"

using namespace std;

class Person
{
private:
    int id;
    string firstName;
    string lastName;
    string cnic;
    Address address;
    Date dOB;
    Person *father;
    Person *mother;

public:
    friend istream &operator>>(istream &i, Person &other);
    static int Id;

    Person();
    Person(string fN, string lN, string CNIC, Address add, Date dOB, Person *father = nullptr, Person *mother = nullptr);
    Person(Person &other);

    int getId();
    string getFirstName();
    string getLastName();
    string getCnic();
    Address getAddress();
    Date getDateOfBirth();
    Person *getFather();
    Person *getMother();

    void setFirstName(string fN);
    void setLastName(string lN);
    void setCnic(string CNIC);
    void setAddress(Address add);
    void setDateOfBirth(Date dateOfBirth);
    void setFather(Person *father);
    void setMother(Person *mother);

    void display();
};

#endif // PERSON_H
