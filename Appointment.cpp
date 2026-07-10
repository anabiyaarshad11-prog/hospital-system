#include "appointment.h"

Appointment::Appointment()
    : appointmentId(0),
      patientId(0),
      doctorId(0),
      bill(0),
      status("Booked") {}

Appointment::Appointment(int aid, int pid,
                         int did, string date,
                         string time, double fee)
    : appointmentId(aid),
      patientId(pid),
      doctorId(did),
      date(date),
      time(time),
      status("Booked"),
      bill(fee) {}

int Appointment::getId() const {
    return appointmentId;
}

int Appointment::getPatientId() const {
    return patientId;
}

int Appointment::getDoctorId() const {
    return doctorId;
}

string Appointment::getStatus() const {
    return status;
}

void Appointment::setStatus(const string& newStatus) {
    status = newStatus;
}
 void Appointment::display(const vector<Patient>& patients,
                          const vector<Doctor>& doctors) const {
    string patientName = "Unknown";
    for (const auto& p : patients) {
        if (p.getId() == patientId) {
            patientName = p.getName();
            break;
        }
    }

    string doctorName = "Unknown";
    for (const auto& d : doctors) {
        if (d.getId() == doctorId) {
            doctorName = d.getName();
            break;
        }
    }

    cout << "Appointment ID : " << appointmentId << endl;
    cout << "Patient : " << patientName << endl;
    cout << "Doctor : " << doctorName << endl;
    cout << "Date : " << date << endl;
    cout << "Time : " << time << endl;
    cout << "Status : " << status << endl;
    cout << "Bill : Rs. " << bill << endl;
}
