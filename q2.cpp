#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double salary;
    string designation;

public:
    // Setter for name
    void setName(string n) {
        name = n;
    }

    // Setter for salary
    void setSalary(double s) {
        if (s > 0)
            salary = s;
        else
            cout<<"Salary must be positive!"<<endl;
    }

    // Setter for designation
    void setDesignation(string d) {
        designation = d;
    }

    // Getter for name
    string getName() {
        return name;
    }

    // Getter for salary
    double getSalary() {
        return salary;
    }

    // Getter for designation
    string getDesignation() {
        return designation;
    }
};

int main(){
    Employee emp;   // Object creation

    // Setting values using public methods
    emp.setName("Amaan Ranchadiya");
    emp.setSalary(500000);
    emp.setDesignation("Software Engineer");

    // Getting values using public methods
    cout<<"Employee Name: "<<emp.getName()<<endl;
    cout<<"Employee Salary: "<<emp.getSalary()<<endl;
    cout<<"Employee Designation: "<<emp.getDesignation()<<endl;

    return 0;
}

