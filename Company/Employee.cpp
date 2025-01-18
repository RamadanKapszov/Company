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

istream& operator>>(istream& is, Employee& emp) {
    getline(is, emp.name);
    getline(is, emp.egn);
    is >> emp.experience;
    is >> emp.workHours;
    is.ignore(); // To ignore the newline character

    // Read the projects (assuming each project is a single line)
    string project;
    while (getline(is, project)) {
        if (project.empty()) break;  // Break if an empty line is encountered (or use another termination condition)
        emp.projects.push_back(project);
    }

    // Optionally set the department pointer if needed
    // Assuming we have a way to set the department (e.g., matching by name)

    return is;
}


ostream& operator<<(ostream& os, const Employee& emp) {
    os << "Employee Name: " << emp.getName() << "\n"
        << "EGN: " << emp.getEgn() << "\n"
        << "Experience: " << emp.getExperience() << " years\n"
        << "Work Hours: " << emp.getWorkHours() << " hours\n"
        << "Projects: ";
    for (const auto& project : emp.getProjects()) {
        os << project << ", ";
    }
    os << "\n";
    if (emp.getDepartment()) {
        os << "Department: " << emp.getDepartment()->getName() << "\n";
    }
    return os;
}