#ifndef FIRM_H
#define FIRM_H

#include "Department.h"
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

class Firm {
private:
    string name;
    string type;
    bool isVATRegistered;
    vector<Department> departments;

public:
    Firm();
    Firm(const string& name, const string& type, bool isVATRegistered, const vector<Department>& departments);

    string getName() const;
    string getType() const;
    bool getIsVATRegistered() const;
    vector<Department>& getDepartments();

    void setName(const string& name);
    void setType(const string& type);
    void setIsVATRegistered(bool isVATRegistered);
    void setDepartments(const vector<Department>& departments);

    void saveToFile(const string& filename) const;

    friend ostream& operator<<(ostream& os, const Firm& firm);
};

#endif

