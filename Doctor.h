#ifndef DOCTOR_H
#define DOCTOR_H

#include "person.h"
#include <iomanip>

class Doctor : public Person {
private:
    string specialization;
    string availableTime;
    double consultationFee;

public:
    Doctor();

    Doctor(int id, string name, int age,
           string phone, string spec,
           string time, double fee);

    void display() const;

    string getType() const;

    string getSpecialization() const;

    double getFee() const;
};

#endif
