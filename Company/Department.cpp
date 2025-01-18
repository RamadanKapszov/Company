#include "Department.h"

Department::Department() : name(""), employeeCount(0), yearsActive(0) {}

Department::Department(const string& name, int yearsActive)
    : name(name), employeeCount(0), yearsActive(yearsActive) {}

string Department::getName() const { return name; }
int Department::getEmployeeCount() const { return employeeCount; }
int Department::getYearsActive() const { return yearsActive; }
vector<Employee*> Department::getEmployees() const { return employees; }

void Department::setName(const string& name) { this->name = name; }
void Department::setYearsActive(int yearsActive) { this->yearsActive = yearsActive; }

void Department::addEmployee(Employee* employee) {
    employees.push_back(employee);
    employeeCount = employees.size();
}

istream& operator>>(istream& is, Department& dept) {
    getline(is, dept.name);
    is >> dept.yearsActive;
    is >> dept.employeeCount; // Assuming employeeCount is stored
    is.ignore(); // To ignore the newline character after integer

    // Read employees (assuming each employee is on a new line)
    dept.employees.clear(); // Clear any previous employees
    for (int i = 0; i < dept.employeeCount; ++i) {
        Employee* emp = new Employee();
        is >> *emp;  // Assuming Employee has an operator>> implemented
        dept.addEmployee(emp);
    }

    return is;
}



ostream& operator<<(ostream& os, const Department& dept) {
    os << "Department Name: " << dept.getName() << "\n"
        << "Years Active: " << dept.getYearsActive() << " years\n"
        << "Number of Employees: " << dept.getEmployeeCount() << "\n";
    for (const auto& emp : dept.getEmployees()) {
        os << *emp << "\n"; // This will print the employee's details
    }
    return os;
}

