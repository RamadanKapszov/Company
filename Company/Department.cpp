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

ostream& operator<<(ostream& os, const Department& dept) {
    os << "Department Name: " << dept.name << "\n"
        << "Years Active: " << dept.yearsActive << " years\n"
        << "Number of Employees: " << dept.employeeCount << "\n";
    for (const auto& emp : dept.employees) {
        os << *emp << "\n";
    }
    return os;
}
