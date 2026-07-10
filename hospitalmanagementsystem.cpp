#include "hospitalmanagementsystem.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>

using namespace std;

HospitalManagementSystem::HospitalManagementSystem() {

    nextPatientId = 1;
    nextDoctorId = 1;
    nextAppointmentId = 1;

    doctors.push_back(
        Doctor(nextDoctorId++,
               "Dr. Samya",
               45,
               "03362266737",
               "Cardiology",
               "9AM-1PM",
               4000)
    );

    doctors.push_back(
        Doctor(nextDoctorId++,
               "Dr. Rabiya",
               38,
               "03353193406",
               "Dermatology",
               "2PM-6PM",
               3000)
    );
}

void HospitalManagementSystem::addPatient() {

    string name;
    string phone;
    string disease;
    string bg;

    int age;

    cout << "\n--- Register Patient ---\n";

    cin.ignore();

    cout << "Name: ";
    getline(cin, name);

    cout << "Age: ";
    cin >> age;

    if(age < 0) {
        cout<<"invalid Age !"<<endl;
    }

    cin.ignore();

    cout << "Phone: ";
    getline(cin, phone);

    cout << "Disease: ";
    getline(cin, disease);

    cout << "Blood Group: ";
    getline(cin, bg);

    patients.push_back(
        Patient(nextPatientId,
                name,
                age,
                phone,
                disease,
                bg)
    );

    ofstream file("patients.txt", ios::app);

    file << nextPatientId << endl;
    file << name << endl;
    file << age << endl;
    file << phone << endl;
    file << disease << endl;
    file << bg << endl;

    file.close();

    cout << "Patient Added Successfully!\n";

    nextPatientId++;
}

void HospitalManagementSystem::viewPatients() {

    cout << "\n--- Patients List ---\n";

    cout << left
         << setw(6) << "ID"
         << setw(18) << "Name"
         << setw(6) << "Age"
         << setw(14) << "Phone"
         << setw(15) << "Disease"
         << setw(6) << "BG"
         << endl;

    for(const auto& p : patients) {
        p.display();
    }
}

void HospitalManagementSystem::viewDoctors() {

    cout << "\n--- Doctors List ---\n";

    cout << left
         << setw(6) << "ID"
         << setw(18) << "Name"
         << setw(18) << "Specialization"
         << setw(14) << "Time"
         << "Fee"
         << endl;

    for(const auto& d : doctors) {
        d.display();
    }
}

void HospitalManagementSystem::bookAppointment() {

    int pid;
    int did;

    string date;
    string time;

    viewPatients();

    cout << "\nEnter Patient ID: ";
    cin >> pid;

    viewDoctors();

    cout << "Enter Doctor ID: ";
    cin >> did;

    cin.ignore();

    cout << "Enter Date: ";
    getline(cin, date);

    cout << "Enter Time: ";
    getline(cin, time);

    double fee = 0;

    for(const auto& d : doctors) {
        if(d.getId() == did) {
            fee = d.getFee();
        }
    }

    appointments.push_back(
        Appointment(nextAppointmentId,
                    pid,
                    did,
                    date,
                    time,
                    fee)
    );

    ofstream file("appointments.txt", ios::app);

    file << nextAppointmentId << endl;
    file << pid << endl;
    file << did << endl;
    file << date << endl;
    file << time << endl;
    file << "Booked" << endl;
    file << fee << endl;

    file.close();

    cout << "Appointment Booked!\n";

    nextAppointmentId++;
}

void HospitalManagementSystem::viewAppointments() {

    cout << "\n--- Appointments ---\n";

    cout << left
         << setw(6) << "ID"
         << setw(18) << "Patient"
         << setw(18) << "Doctor"
         << setw(12) << "Date"
         << setw(8) << "Time"
         << setw(12) << "Status"
         << "Bill"
         << endl;

    for(const auto& a : appointments) {
        a.display(patients, doctors);
    }
}

void HospitalManagementSystem::updateAppointmentStatus() {

    int id;

    cout << "Enter Appointment ID: ";
    cin >> id;

    for(auto& a : appointments) {

        if(a.getId() == id) {

            int choice;

            cout << "1. Completed\n";
            cout << "2. Cancelled\n";
            cout << "Choice: ";

            cin >> choice;

            if(choice == 1)
                a.setStatus("Completed");

            else
                a.setStatus("Cancelled");

            cout << "Status Updated!\n";
        }
    }
}

void HospitalManagementSystem::run() {

    int choice;

    do {

        cout << "\n===== Health Care Appointment System =====\n";

        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. View Doctors\n";
        cout << "4. Book Appointment\n";
        cout << "5. View Appointments\n";
        cout << "6. Update Appointment\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";

        cin >> choice;

        try {

            switch(choice) {

                case 1:
                    addPatient();
                    break;

                case 2:
                    viewPatients();
                    break;

                case 3:
                    viewDoctors();
                    break;

                case 4:
                    bookAppointment();
                    break;

                case 5:
                    viewAppointments();
                    break;

                case 6:
                    updateAppointmentStatus();
                    break;

                case 7:
                    cout << "Goodbye!\n";
                    break;

                default:
                    cout << "Invalid Choice!\n";
            }
        }

        catch(exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while(choice != 7);
}
