#ifndef HOSPITALMANAGEMENTSYSTEM_H
#define HOSPITALMANAGEMENTSYSTEM_H

#include <vector>

#include "patient.h"
#include "doctor.h"
#include "appointment.h"

using namespace std;

class HospitalManagementSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;

    int nextPatientId;
    int nextDoctorId;
    int nextAppointmentId;

public:
    HospitalManagementSystem();

    void addPatient();

    void viewPatients();

    void viewDoctors();

    void bookAppointment();

    void viewAppointments();

    void updateAppointmentStatus();

    void run();
};

#endif
