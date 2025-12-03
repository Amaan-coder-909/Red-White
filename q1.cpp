#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Setter for length
    void setLength(double l) {
        if (l > 0)
            length = l;
        else
            cout << "Length must be positive!" << endl;
    }

    // Setter for width
    void setWidth(double w) {
        if (w > 0)
            width = w;
        else
            cout << "Width must be positive!" << endl;
    }

    // Getter for length
    double getLength() {
        return length;
    }

    // Getter for width
    double getWidth() {
        return width;
    }

    // Method to calculate area
    double area() {
        return length * width;
    }
};

int main() {
    Rectangle rect;

    // Set values
    rect.setLength(10.5);
    rect.setWidth(4.2);

    // Get and display values
    cout<<"Length: "<<rect.getLength()<<endl;
    cout<<"Width: "<<rect.getWidth()<<endl;

    // Display area
    cout<<"Area of Rectangle: "<<rect.area()<<endl;

    return 0;
}

