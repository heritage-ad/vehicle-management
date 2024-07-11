#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

class Vehicle {
protected:
    std::string make;
    std::string model;
    int year;
    double price;
    int vehicleID;

public:
    Vehicle(const std::string& make, const std::string& model, int year, double price, int vehicleID)
        : make(make), model(model), year(year), price(price), vehicleID(vehicleID) {}

    virtual ~Vehicle() {}

    int getVehicleID() const {
        return vehicleID;
    }

    std::string getMake() const {
        return make;
    }

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    double getPrice() const {
        return price;
    }

    void setMake(const std::string& newMake) {
        make = newMake;
    }

    void setModel(const std::string& newModel) {
        model = newModel;
    }

    void setYear(int newYear) {
        year = newYear;
    }

    void setPrice(double newPrice) {
        price = newPrice;
    }

    virtual void displayDetails() const {
        std::cout << "Vehicle ID: " << vehicleID << std::endl;
        std::cout << "Make: " << make << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Price: " << price << std::endl;
    }
};

#endif // VEHICLE_H
