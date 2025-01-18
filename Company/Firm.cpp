#include "Firm.h"

Firm::Firm() : name(""), type(""), isVATRegistered(false) {}

Firm::Firm(const string& name, const string& type, bool isVATRegistered, const vector<Department>& departments)
    : name(name), type(type), isVATRegistered(isVATRegistered), departments(departments) {}

string Firm::getName() const { return name; }
string Firm::getType() const { return type; }
bool Firm::getIsVATRegistered() const { return isVATRegistered; }
vector<Department>& Firm::getDepartments() {
    return departments;
}


void Firm::setName(const string& name) { this->name = name; }
void Firm::setType(const string& type) { this->type = type; }
void Firm::setIsVATRegistered(bool isVATRegistered) { this->isVATRegistered = isVATRegistered; }
void Firm::setDepartments(const vector<Department>& departments) { this->departments = departments; }

void Firm::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open file for writing.");
    }
    file << *this;
    file.close();
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
