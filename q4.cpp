#include <iostream>
using namespace std;

// Base class
class Shape {
private:
    string color;
    double area;

protected:
    // Allow derived classes to set area
    void setArea(double a) {
        area = a;
    }

public:
    // Set and get color
    void setColor(string c) {
        color = c;
    }

    string getColor() {
        return color;
    }

    double getArea() {
        return area;
    }

    // Pure virtual functions
    virtual void calculateArea() = 0;
    virtual void display() = 0;  // New virtual function
};

// ------------------- CIRCLE CLASS -----------------------
class Circle : public Shape {
private:
    double radius;

public:
    void setRadius(double r) {
        radius = r;
    }

    void calculateArea() override {
        double a = 3.1416 * radius * radius;
        setArea(a);
    }

    void display() override {
        cout << "=== Circle Information ===\n";
        cout << "Color: " << getColor() << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << getArea() << endl;
    }
};

// ------------------- RECTANGLE CLASS -----------------------
class Rectangle : public Shape {
private:
    double length, width;

public:
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }

    void calculateArea() override {
        double a = length * width;
        setArea(a);
    }

    void display() override {
        cout << "=== Rectangle Information ===\n";
        cout << "Color: " << getColor() << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << getArea() << endl;
    }
};

int main() {

    // Create objects
    Circle c;
    c.setColor("Red");
    c.setRadius(5);
    c.calculateArea();

    Rectangle r;
    r.setColor("Blue");
    r.setDimensions(4, 6);
    r.calculateArea();

    // Array of base-class pointers
    Shape* shapes[2];
    shapes[0] = &c;
    shapes[1] = &r;

    // Demonstrate polymorphism
    cout << "\n--- Polymorphic Display Calls ---\n";
    for (int i = 0; i < 2; i++) {
        shapes[i]->display();   // Calls the correct derived class version
        cout << endl;
    }

    return 0;
}

