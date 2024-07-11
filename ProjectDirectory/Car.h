#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {

private: 
    int numberOfDoors;
    bool isElectric;

public: 
    Car(const std::string &make, const std::string &model, int year, double price, int vehicleID, int numberOfDoors, bool isElectric) 
    : Vehicle(make, model, year, price, vehicleID), numberOfDoors(numberOfDoors), isElectric(isElectric) {}

    int getNumberOfDoors() const { return numberOfDoors; }
    bool getIsElectric() const { return isElectric; }

    void setNumberOfDoors(int doors) { numberOfDoors = doors; }
    void setIsElectric(bool electric) { isElectric = electric; }

    void displayDetails() const override {
        Vehicle::displayDetails();
        std::cout << "Number of Doors: "<< numberOfDoors << "\nIs Electric: " << std::boolalpha << isElectric << std::endl;
    }
};

#endif // CAR_H