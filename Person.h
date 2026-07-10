#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
    int age;
    string phone;

public:
    Person() : id(0), age(0) {}

    Person(int id, string name, int age, string phone)
        : id(id), name(name), age(age), phone(phone) {}

    virtual void display() const = 0;
    virtual string getType() const = 0;

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    virtual ~Person() {}
};

#endif
