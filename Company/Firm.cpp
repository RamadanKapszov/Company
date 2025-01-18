#include "Firm.h"
#include "Department.h"
#include "Employee.h"
#include <fstream>
#include <sstream>
#include <nlohmann/json.hpp>


Firm::Firm() : name(""), type(""), isVATRegistered(false) {}

Firm::Firm(const string& name, const string& type, bool isVATRegistered, const vector<Department>& departments)
    : name(name), type(type), isVATRegistered(isVATRegistered), departments(departments) {}

string Firm::getName() const { return name; }
string Firm::getType() const { return type; }
bool Firm::getIsVATRegistered() const { return isVATRegistered; }
vector<Department>& Firm::getDepartments() { return departments; }

void Firm::setName(const string& name) { this->name = name; }
void Firm::setType(const string& type) { this->type = type; }
void Firm::setIsVATRegistered(bool isVATRegistered) { this->isVATRegistered = isVATRegistered; }
void Firm::setDepartments(const vector<Department>& departments) { this->departments = departments; }


void Firm::saveToFile(const string& filename) const {
    nlohmann::json j;
    j["name"] = name;
    j["type"] = type;
    j["isVATRegistered"] = isVATRegistered;

    // Saving departments and employees
    for (const auto& dept : departments) {
        nlohmann::json deptJson;
        deptJson["name"] = dept.getName();
        deptJson["yearsActive"] = dept.getYearsActive();

        for (const auto& emp : dept.getEmployees()) {
            nlohmann::json empJson;
            empJson["name"] = emp->getName();
            empJson["egn"] = emp->getEgn();
            empJson["experience"] = emp->getExperience();
            empJson["workHours"] = emp->getWorkHours();
            empJson["projects"] = emp->getProjects();

            deptJson["employees"].push_back(empJson);
        }

        j["departments"].push_back(deptJson);
    }

    // Write JSON to file
    std::ofstream file(filename);
    if (file.is_open()) {
        file << j.dump(4);  // Pretty print JSON with 4 spaces indentation
    }
    else {
        throw std::runtime_error("Could not open file for writing.");
    }
}

void Firm::loadFromFile(const string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for reading.");
    }

    nlohmann::json j;
    file >> j;  // Parse the file into a JSON object

    // Validate and load firm details
    if (j.contains("name")) name = j["name"];
    if (j.contains("type")) type = j["type"];
    if (j.contains("isVATRegistered")) isVATRegistered = j["isVATRegistered"];

    // Validate and load departments
    if (j.contains("departments")) {
        for (const auto& deptJson : j["departments"]) {
            string deptName = deptJson.value("name", "");
            int yearsActive = deptJson.value("yearsActive", 0);
            Department dept(deptName, yearsActive);

            // Validate and load employees for the department
            if (deptJson.contains("employees")) {
                for (const auto& empJson : deptJson["employees"]) {
                    string empName = empJson.value("name", "");
                    string egn = empJson.value("egn", "");
                    int experience = empJson.value("experience", 0);
                    int workHours = empJson.value("workHours", 0);
                    vector<string> projects = empJson.value("projects", vector<string>{});

                    Employee* emp = new Employee(empName, egn, experience, workHours, projects, &dept);
                    dept.addEmployee(emp);
                }
            }

            departments.push_back(dept);
        }
    }
}



ostream& operator<<(ostream& os, const Firm& firm) {
    os << "Firm Name: " << firm.name << "\n"
        << "Type: " << firm.type << "\n"
        << "VAT Registered: " << (firm.isVATRegistered ? "Yes" : "No") << "\n";
    for (const auto& dept : firm.departments) {
        os << dept << "\n"; 
    }
    return os;
}
