#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private: 
    double payloadCapacity;
    int numberOfAxles;

public:
    Truck(const std::string &make, const std::string &model, int year, double price, int vehicleID, 
    double payloadCapacity, int numberOfAxles)
    : Vehicle(make, model, year, price, vehicleID), payloadCapacity(payloadCapacity), numberOfAxles(numberOfAxles) {}

    double getPayloadCapacity() const { return payloadCapacity; }
    int getNumberOfAxles() const { return numberOfAxles; }

    void setPayloadCapacity(double capacity) { payloadCapacity = capacity; }
    void setNumberOfAxles(int axles) { numberOfAxles = axles; }

    void displayDetails() const override{
        Vehicle::displayDetails();
        std::cout << "Payload Capacity: " <<payloadCapacity << "\nNumber of Axles: " << numberOfAxles << std::endl;
    }
};
#endif // TRUCK_H