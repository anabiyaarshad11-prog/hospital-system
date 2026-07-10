#include "patient.h"

Patient::Patient() {}

Patient::Patient(int id, string name, int age,
                 string phone, string disease,
                 string bg)
    : Person(id, name, age, phone),
      disease(disease),
      bloodGroup(bg) {

    if(age < 0)
        throw invalid_argument("Age cannot be negative");
}

void Patient::display() const {

    cout << left << setw(6) << id
         << setw(18) << name
         << setw(6) << age
         << setw(14) << phone
         << setw(15) << disease
         << setw(6) << bloodGroup << endl;
}

string Patient::getType() const {
    return "Patient";
}

string Patient::getDisease() const {
    return disease;
}

void showPatientSecret(const Patient& p) {
    cout << "Disease: " << p.disease << endl;
}
