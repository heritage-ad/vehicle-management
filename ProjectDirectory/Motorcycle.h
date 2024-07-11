#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(const std::string &make, const std::string &model, int year, double price, int vehicleID, bool hasSidecar)
    : Vehicle(make, model, year, price, vehicleID), hasSidecar(hasSidecar) {}

    bool getHasSidecar() const { return hasSidecar; }
    void setHasSidecar(bool sidecar) { hasSidecar = sidecar; }

    void displayDetails() const override {
        Vehicle::displayDetails();
        std::cout << "Has Sidecar: " << std::boolalpha << hasSidecar << std::endl;
    }
};

#endif // MOTORCYCLE_H