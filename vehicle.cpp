#include <iostream>
#include <string>
using namespace std;

// ------------------------------------------------------------
// BASE CLASS: VEHICLE
// ------------------------------------------------------------
class Vehicle {
protected:
    string vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle() {
        vehicleID = "N/A";
        manufacturer = "N/A";
        model = "N/A";
        year = 0;
        totalVehicles++;
    }

    Vehicle(string id, string man, string mod, int yr)
        : vehicleID(id), manufacturer(man), model(mod), year(yr) {
        totalVehicles++;
    }

    virtual ~Vehicle() {
        // destructor
    }

    // Setters
    void setVehicleID(string id) { vehicleID = id; }
    void setManufacturer(string man) { manufacturer = man; }
    void setModel(string mod) { model = mod; }
    void setYear(int yr) { year = yr; }

    // Getters
    string getVehicleID() { return vehicleID; }
    string getManufacturer() { return manufacturer; }
    string getModel() { return model; }
    int getYear() { return year; }

    virtual void display() {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;


// ------------------------------------------------------------
// SINGLE INHERITANCE — CLASS CAR
// ------------------------------------------------------------
class Car : public Vehicle {
protected:
    string fuelType;

public:
    Car() : Vehicle() {
        fuelType = "N/A";
    }
    Car(string id, string man, string mod, int yr, string fuel)
        : Vehicle(id, man, mod, yr), fuelType(fuel) {}

    void setFuelType(string f) { fuelType = f; }
    string getFuelType() { return fuelType; }

    void display() override {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};


// ------------------------------------------------------------
// MULTILEVEL INHERITANCE — ELECTRIC CAR (Vehicle -> Car -> ElectricCar)
// ------------------------------------------------------------
class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    ElectricCar() : Car() {
        batteryCapacity = 0;
    }
    ElectricCar(string id, string man, string mod, int yr, string fuel, int cap)
        : Car(id, man, mod, yr, fuel), batteryCapacity(cap) {}

    void display() override {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};


// ------------------------------------------------------------
// MULTIPLE INHERITANCE — AIRCRAFT + CAR → FLYING CAR
// ------------------------------------------------------------
class Aircraft {
protected:
    int flightRange;

public:
    Aircraft() { flightRange = 0; }
    Aircraft(int fr) { flightRange = fr; }

    void setFlightRange(int fr) { flightRange = fr; }
    int getFlightRange() { return flightRange; }

    void showAircraft() {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar() : Car(), Aircraft() {}
    FlyingCar(string id, string man, string mod, int yr, string fuel, int fr)
        : Car(id, man, mod, yr, fuel), Aircraft(fr) {}

    void display() {
        Car::display();
        showAircraft();
    }
};


// ------------------------------------------------------------
// MULTILEVEL AGAIN — SPORTSCAR (ElectricCar → SportsCar)
// ------------------------------------------------------------
class SportsCar : public ElectricCar {
protected:
    int topSpeed;

public:
    SportsCar() : ElectricCar() {
        topSpeed = 0;
    }
    SportsCar(string id, string man, string mod, int yr, string fuel, int cap, int ts)
        : ElectricCar(id, man, mod, yr, fuel, cap), topSpeed(ts) {}

    void display() override {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};


// ------------------------------------------------------------
// HIERARCHICAL INHERITANCE (Car → Sedan, Car → SUV)
// ------------------------------------------------------------
class Sedan : public Car {
public:
    Sedan() : Car() {}
    Sedan(string id, string man, string mod, int yr, string fuel)
        : Car(id, man, mod, yr, fuel) {}

    void display() override {
        cout << "Sedan Vehicle:" << endl;
        Car::display();
    }
};

class SUV : public Car {
public:
    SUV() : Car() {}
    SUV(string id, string man, string mod, int yr, string fuel)
        : Car(id, man, mod, yr, fuel) {}

    void display() override {
        cout << "SUV Vehicle:" << endl;
        Car::display();
    }
};


// ------------------------------------------------------------
// VEHICLE REGISTRY — ARRAY OF POINTERS
// ------------------------------------------------------------
class VehicleRegistry {
private:
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry() {
        count = 0;
    }

    void addVehicle(Vehicle* v) {
        vehicles[count++] = v;
        cout << "Vehicle added successfully!\n";
    }

    void displayAll() {
        if (count == 0) {
            cout << "No vehicles registered.\n";
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "\n--- Vehicle " << i + 1 << " ---\n";
            vehicles[i]->display();
        }
    }

    void searchByID(string id) {
        for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                cout << "\nVehicle Found:\n";
                vehicles[i]->display();
                return;
            }
        }
        cout << "Vehicle with ID " << id << " not found.\n";
    }
};


// ------------------------------------------------------------
// MAIN MENU
// ------------------------------------------------------------
int main() {
    VehicleRegistry registry;
    int choice;

    while (true) {
        cout << "\n========== VEHICLE REGISTRY SYSTEM ==========\n";
        cout << "1. Add Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search by Vehicle ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) break;

        string id, man, mod, fuel;
        int yr, cap, ts, fr, type;

        switch (choice) {
        case 1:
            cout << "\nSelect Vehicle Type:\n";
            cout << "1. Car\n2. Electric Car\n3. Flying Car\n4. Sports Car\n5. Sedan\n6. SUV\n";
            cin >> type;

            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> man;
            cout << "Enter Model: ";
            cin >> mod;
            cout << "Enter Year: ";
            cin >> yr;

            if (type == 1) {
                cout << "Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new Car(id, man, mod, yr, fuel));
            }
            else if (type == 2) {
                cout << "Fuel Type: ";
                cin >> fuel;
                cout << "Battery Capacity: ";
                cin >> cap;
                registry.addVehicle(new ElectricCar(id, man, mod, yr, fuel, cap));
            }
            else if (type == 3) {
                cout << "Fuel Type: ";
                cin >> fuel;
                cout << "Flight Range: ";
                cin >> fr;
                registry.addVehicle(new FlyingCar(id, man, mod, yr, fuel, fr));
            }
            else if (type == 4) {
                cout << "Fuel Type: ";
                cin >> fuel;
                cout << "Battery Capacity: ";
                cin >> cap;
                cout << "Top Speed: ";
                cin >> ts;
                registry.addVehicle(new SportsCar(id, man, mod, yr, fuel, cap, ts));
            }
            else if (type == 5) {
                cout << "Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new Sedan(id, man, mod, yr, fuel));
            }
            else if (type == 6) {
                cout << "Fuel Type: ";
                cin >> fuel;
                registry.addVehicle(new SUV(id, man, mod, yr, fuel));
            }
            break;

        case 2:
            registry.displayAll();
            break;

        case 3:
            cout << "Enter ID to search: ";
            cin >> id;
            registry.searchByID(id);
            break;
        }
    }

    return 0;
}
