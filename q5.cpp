#include <iostream>
using namespace std;

// Abstract Base Class
class Animal {
public:
    // Pure virtual functions
    virtual void sound() = 0;
    virtual void move() = 0;
    
    // Virtual destructor
    virtual ~Animal() {}
};

// ------------------ Dog Class ------------------
class Dog : public Animal {
public:
    void sound() override {
        cout<<"Dog barks: Woof! Woof!"<<endl;
    }

    void move() override {
        cout<<"Dog runs on four legs."<<endl;
    }
};

// ------------------ Bird Class ------------------
class Bird : public Animal {
public:
    void sound() override {
        cout<<"Bird chirps: Tweet! Tweet!"<<endl;
    }

    void move() override {
        cout<<"Bird flies in the sky."<<endl;
    }
};

int main() {

    // Create objects
    Dog d;
    Bird b;

    // Array of base-class pointers
    Animal* animals[2];
    animals[0] = &d;
    animals[1] = &b;

    // Demonstrate polymorphism
    cout << "\n--- Demonstrating Polymorphism ---\n";
    for (int i = 0; i < 2; i++) {
        animals[i]->sound();
        animals[i]->move();
        cout << endl;
    }

    return 0;
}

