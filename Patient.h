#ifndef PATIENT_H
#define PATIENT_H

#include "person.h"
#include <iomanip>

class Patient : public Person {
private:
    string disease;
    string bloodGroup;

public:
    Patient();

    Patient(int id, string name, int age,
            string phone, string disease,
            string bg);

    void display() const;

    string getType() const;

    string getDisease() const;

    friend void showPatientSecret(const Patient& p);
};

#endif
