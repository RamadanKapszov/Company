#include "Employee.h"
#include <algorithm> // За std::all_of
#include "Department.h"

Employee::Employee() : name(""), egn(""), experience(0), workHours(0), department(nullptr) {}

Employee::Employee(const string& name, const string& egn, int experience, int workHours, const vector<string>& projects, Department* department)
    : name(name), egn(egn), experience(experience), workHours(workHours), projects(projects), department(department) {
    validateData();
}

string Employee::getName() const { return name; }
string Employee::getEgn() const { return egn; }
int Employee::getExperience() const { return experience; }
int Employee::getWorkHours() const { return workHours; }
vector<string> Employee::getProjects() const { return projects; }
Department* Employee::getDepartment() const { return department; }

void Employee::setName(const string& name) { this->name = name; }
void Employee::setEgn(const string& egn) { this->egn = egn; validateData(); }
void Employee::setExperience(int experience) { this->experience = experience; }
void Employee::setWorkHours(int workHours) { this->workHours = workHours; }
void Employee::setProjects(const vector<string>& projects) { this->projects = projects; }
void Employee::setDepartment(Department* department) { this->department = department; }

void Employee::validateData() {
    if (egn.length() != 10 || !all_of(egn.begin(), egn.end(), ::isdigit)) {
        throw invalid_argument("Invalid EGN. It must be 10 digits.");
    }
}

ostream& operator<<(ostream& os, const Employee& emp) {
    os << "Employee Name: " << emp.name << "\n"
        << "EGN: " << emp.egn << "\n"
        << "Experience: " << emp.experience << " years\n"
        << "Work Hours: " << emp.workHours << " hours\n"
        << "Projects: ";
    for (const auto& project : emp.projects) {
        os << project << ", ";
    }
    os << "\n";
    if (emp.department) {
        os << "Department: " << emp.department->getName() << "\n";
    }
    return os;
}