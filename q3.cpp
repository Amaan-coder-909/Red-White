#include <iostream>
using namespace std;

// Base class
class Shape {
private:
    string color;
    double area;

protected:
    // Protected function so derived classes can set area
    void setArea(double a) {
        area = a;
    }

public:
    // Setter for color
    void setColor(string c) {
        color = c;
    }

    // Getter for color
    string getColor() {
        return color;
    }

    // Getter for area
    double getArea() {
        return area;
    }

    // Virtual method for abstraction
    virtual void calculateArea() = 0;  // Pure virtual function
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    void setRadius(double r) {
        radius = r;
    }

    // Implement abstract function
    void calculateArea() override {
        double a = 3.1416 * radius * radius;
        setArea(a);
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    void setDimensions(double l, double w) {
        length = l;
        width  = w;
    }

    // Implement abstract function
    void calculateArea() override {
        double a = length * width;
        setArea(a);
    }
};

int main() {
    // Circle object
    Circle c;
    c.setColor("Red");
    c.setRadius(5);
    c.calculateArea();

    cout<<"Circle Color: "<<c.getColor()<<endl;
    cout<<"Circle Area: "<<c.getArea()<<endl;

    cout<<endl;

    // Rectangle object
    Rectangle r;
    r.setColor("Blue");
    r.setDimensions(4, 6);
    r.calculateArea();

    cout<<"Rectangle Color: "<<r.getColor()<<endl;
    cout<<"Rectangle Area: "<<r.getArea()<<endl;

    return 0;
}

