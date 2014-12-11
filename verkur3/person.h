#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Person
{
public:
    Person();
    Person(int id, string fn, string ln, int by, int dy, string s, string n);
    friend ostream& operator <<(ostream& out, const Person& p);
    int getID() const;
    int getBY() const;
    int getDY() const;
    string getFName() const;
    string getLName() const;
    string getSex() const;
    string getNationality() const;
private:
    int pid;
    int birth_year;
    int death_year;
    string first_name;
    string last_name;
    string sex;
    string nationality;
};

#endif // PERSON_H
