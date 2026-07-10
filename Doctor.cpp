#include "doctor.h"
#include <string.h>
Doctor::Doctor() {}

Doctor::Doctor(int id, string name, int age,
               string phone, string spec,
               string time, double fee)
    : Person(id, name, age, phone),
      specialization(spec),
      availableTime(time),
      consultationFee(fee) {}

void Doctor::display() const {

    cout << left << setw(6) << id
         << setw(18) << name
         << setw(18) << specialization
         << setw(14) << availableTime
         << "Rs. " << consultationFee << endl;
}

string Doctor::getType() const {
    return "Doctor";
}

string Doctor::getSpecialization() const {
    return specialization;
}

double Doctor::getFee() const {
    return consultationFee;
}
