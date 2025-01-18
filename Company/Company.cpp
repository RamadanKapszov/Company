#include "Firm.h"
#include <iostream>
using namespace std;

void displayMenu() {
    cout << "1. Add Firm\n";
    cout << "2. Add Department\n";
    cout << "3. Add Employee\n";
    cout << "4. Display Firm\n";
    cout << "5. Save to File\n";
    cout << "6. Exit\n";
}

int main() {
    Firm firm;
    int choice;
    bool firmCreated = false;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, type;
            bool isVATRegistered;
            cout << "Enter firm name: ";
            cin >> name;
            cout << "Enter firm type (e.g., OOD, AD, EOOD): ";
            cin >> type;
            cout << "Is the firm VAT registered? (1 for Yes, 0 for No): ";
            cin >> isVATRegistered;
            firm = Firm(name, type, isVATRegistered, {});
            firmCreated = true;
            cout << "Firm added successfully.\n";
            break;
        }
        case 2: {
            if (!firmCreated) {
                cout << "Please create a firm first.\n";
                break;
            }
            string deptName;
            int yearsActive;
            cout << "Enter department name: ";
            cin >> deptName;
            cout << "Enter years active: ";
            cin >> yearsActive;
            firm.getDepartments().emplace_back(deptName, yearsActive);
            cout << "Department added successfully.\n";
            break;
        }
        case 3: {
            if (!firmCreated) {
                cout << "Please create a firm first.\n";
                break;
            }

            if (firm.getDepartments().empty()) {
                cout << "No departments available. Add a department first.\n";
                break;
            }

            string name, egn;
            int experience, workHours, projectCount;
            vector<string> projects;

            cout << "Enter employee name: ";
            cin >> name;
            cout << "Enter employee EGN: ";
            cin >> egn;
            cout << "Enter experience (years): ";
            cin >> experience;
            cout << "Enter work hours: ";
            cin >> workHours;

            cout << "Enter number of projects: ";
            cin >> projectCount;
            projects.resize(projectCount);
            for (int i = 0; i < projectCount; ++i) {
                cout << "Enter project " << i + 1 << ": ";
                cin >> projects[i];
            }

            cout << "Select department by index:\n";
            auto& departments = firm.getDepartments();
            for (size_t i = 0; i < departments.size(); ++i) {
                cout << i + 1 << ". " << departments[i].getName() << "\n";
            }
            int deptIndex;
            cin >> deptIndex;
            if (deptIndex < 1 || deptIndex > departments.size()) {
                cout << "Invalid department index.\n";
                break;
            }

            Department& selectedDept = departments[deptIndex - 1];
            Employee* emp = new Employee(name, egn, experience, workHours, projects, &selectedDept);
            selectedDept.addEmployee(emp);

            cout << "Employee added to department successfully.\n";
            break;
        }
        case 4:{
            cout << firm;
            break;
        }
        case 5:
            try {
                firm.saveToFile("firm_data.txt");
                cout << "Data saved to file successfully.\n";
            }
            catch (const exception& e) {
                cerr << e.what() << "\n";
            }
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
