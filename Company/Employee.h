// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Department; // Forward declaration

class Employee {
private:
    string name;
    string egn;
    int experience;
    int workHours;
    vector<string> projects;
    Department* department; // Reference to the department

public:
    Employee();
    Employee(const string& name, const string& egn, int experience, int workHours, const vector<string>& projects, Department* department = nullptr);

    string getName() const;
    string getEgn() const;
    int getExperience() const;
    int getWorkHours() const;
    vector<string> getProjects() const;
    Department* getDepartment() const;

    void setName(const string& name);
    void setEgn(const string& egn);
    void setExperience(int experience);
    void setWorkHours(int workHours);
    void setProjects(const vector<string>& projects);
    void setDepartment(Department* department);

    void validateData();

    friend ostream& operator<<(ostream& os, const Employee& emp);
    friend istream& operator>>(istream& is, Employee& emp);

};

#endif