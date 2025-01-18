#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Employee.h"
#include <vector>
#include <string>
using namespace std;

class Department {
private:
    string name;
    int employeeCount;
    int yearsActive;
    vector<Employee*> employees; 

public:
    Department();
    Department(const string& name, int yearsActive);

    string getName() const;
    int getEmployeeCount() const;
    int getYearsActive() const;
    vector<Employee*> getEmployees() const;

    void setName(const string& name);
    void setYearsActive(int yearsActive);
    void addEmployee(Employee* employee); 

    friend ostream& operator<<(ostream& os, const Department& dept);
    friend istream& operator>>(istream& is, Department& dept);

};

#endif
