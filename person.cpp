#include "person.h"

int Person::Id = 1;

Person::Person()
{
    id = Id++;
    father = nullptr;
    mother = nullptr;
}

Person::Person(string fN, string lN, string CNIC, Address add, Date dOB, Person *father, Person *mother)
{
    id = Id++;
    firstName = fN;
    lastName = lN;
    cnic = CNIC;
    address = add;
    this->dOB = dOB;
    this->father = father;
    this->mother = mother;
}

Person::Person(Person &other)
{
    id = id++;
    firstName = other.firstName;
    lastName = other.lastName;
    cnic = other.cnic;
    address = other.address;
    dOB = other.dOB;
    father = other.father;
    mother = other.mother;
}

int Person::getId() {
    return id;
}

string Person::getFirstName() {
    return firstName;
}

string Person::getLastName() {
    return lastName;
}

string Person::getCnic() {
    return cnic;
}

Address Person::getAddress() {
    return address;
}

Date Person::getDateOfBirth() {
    return dOB;
}

Person *Person::getFather() {
    return father;
}

Person *Person::getMother() {
    return mother;
}

void Person::setFirstName(string fN) {
    firstName = fN;
}

void Person::setLastName(string lN) {
    lastName = lN;
}

void Person::setCnic(string CNIC) {
    cnic = CNIC;
}

void Person::setAddress(Address add) {
    address = add;
}

void Person::setDateOfBirth(Date dateOfBirth) {
    dOB = dateOfBirth;
}

void Person::setFather(Person *father) {
    this->father = father;
}

void Person::setMother(Person *mother) {
    this->mother = mother;
}

void Person::display() {
    cout << "ID: " << id << "\n"
         << "Name: " << firstName << " " << lastName << "\n"
         << "CNIC: " << cnic << "\n"
         << "Address: ";
    address.display();
    cout << "Date of Birth: ";
    dOB.display();
    if (father) {
        cout << "Father: " << father->getFirstName() << " " << father->getLastName() << "\n";
    }
    if (mother) {
        cout << "Mother: " << mother->getFirstName() << " " << mother->getLastName() << "\n";
    }
}

istream &operator>>(istream &is, Person &person)
{
    cout << "Enter first name: ";
    is >> person.firstName;
    cout << "Enter last name: ";
    is >> person.lastName;
    cout << "Enter CNIC: ";
    is >> person.cnic;
    cout << "Enter address details:\n";
    is >> person.address;
    cout << "Enter date of birth details:\n";
    is >> person.dOB;
    return is;
}
