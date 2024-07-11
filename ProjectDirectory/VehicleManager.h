#ifndef VEHICLEMANAGER_H
#define VEHICLEMANAGER_H

#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"

class VehicleManager {
private:
    std::vector<Vehicle*> vehicles;

public:
    ~VehicleManager() {
        for (auto vehicle : vehicles) {
            delete vehicle;
        }
    }

    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void removeVehicle(int vehicleID) {
        auto it = std::remove_if(vehicles.begin(), vehicles.end(), [vehicleID](Vehicle* vehicle) {
            return vehicle->getVehicleID() == vehicleID;
        });
        if (it != vehicles.end()) {
            delete *it;
            vehicles.erase(it, vehicles.end());
        } else {
            throw std::runtime_error("Vehicle not found");
        }
    }

    void updateVehicle(int vehicleID, const std::string &newMake, const std::string &newModel, int newYear, double newPrice) {
        for (auto vehicle : vehicles) {
            if (vehicle->getVehicleID() == vehicleID) {
                vehicle->setMake(newMake);
                vehicle->setModel(newModel);
                vehicle->setYear(newYear);
                vehicle->setPrice(newPrice);
                return;
            }
        }
        throw std::runtime_error("Vehicle not found");
    }

    std::vector<Vehicle*> searchVehicle(const std::string &criteria) {
        std::vector<Vehicle*> results;
        for (auto vehicle : vehicles) {
            if (vehicle->getMake() == criteria || vehicle->getModel() == criteria) {
                results.push_back(vehicle);
            }
        }
        return results;
    }

    void displayAllVehicles() const {
        for (const auto vehicle : vehicles) {
            vehicle->displayDetails();
            std::cout << std::endl;
        }
    }

    void saveToFile(const std::string &filename) {
        std::ofstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file");
        }
        for (const auto vehicle : vehicles) {
            file << vehicle->getVehicleID() << "," << vehicle->getMake() << "," << vehicle->getModel() << ","
                 << vehicle->getYear() << "," << vehicle->getPrice() << std::endl;
        }
        file.close();
    }

    void loadFromFile(const std::string &filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file");
        }
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string token;
            int vehicleID, year;
            double price;
            std::string make, model;

            std::getline(ss, token, ',');
            vehicleID = std::stoi(token);

            std::getline(ss, token, ',');
            make = token;

            std::getline(ss, token, ',');
            model = token;

            std::getline(ss, token, ',');
            year = std::stoi(token);

            std::getline(ss, token, ',');
            price = std::stod(token);

            // Assume that the vehicle type is determined by some logic, here it's simplified
            Vehicle* vehicle = new Vehicle(make, model, year, price, vehicleID);
            vehicles.push_back(vehicle);
        }
        file.close();
    }
};

#endif // VEHICLEMANAGER_H
