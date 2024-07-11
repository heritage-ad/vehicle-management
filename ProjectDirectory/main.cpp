#include <iostream>
#include "VehicleManager.h"

void addVehicleFromInput(VehicleManager& manager) {
    int vehicleType;
    std::cout << "Enter vehicle type (1 for Car, 2 for Truck, 3 for Motorcycle): ";
    std::cin >> vehicleType;

    std::string make, model;
    int year, vehicleID, numberOfDoors, payloadCapacity, numberOfAxles;
    double price;
    bool isElectric, hasSidecar;

    std::cout << "Enter vehicle ID: ";
    std::cin >> vehicleID;
    std::cin.ignore(); // Ignore newline character left in the buffer

    std::cout << "Enter make: ";
    std::getline(std::cin, make);

    std::cout << "Enter model: ";
    std::getline(std::cin, model);

    std::cout << "Enter year: ";
    std::cin >> year;

    std::cout << "Enter price: ";
    std::cin >> price;

    if (vehicleType == 1) {
        std::cout << "Enter number of doors: ";
        std::cin >> numberOfDoors;

        std::cout << "Is electric (1 for true, 0 for false): ";
        std::cin >> isElectric;

        manager.addVehicle(new Car(make, model, year, price, vehicleID, numberOfDoors, isElectric));
    } else if (vehicleType == 2) {
        std::cout << "Enter payload capacity: ";
        std::cin >> payloadCapacity;

        std::cout << "Enter number of axles: ";
        std::cin >> numberOfAxles;

        manager.addVehicle(new Truck(make, model, year, price, vehicleID, payloadCapacity, numberOfAxles));
    } else if (vehicleType == 3) {
        std::cout << "Has sidecar (1 for true, 0 for false): ";
        std::cin >> hasSidecar;

        manager.addVehicle(new Motorcycle(make, model, year, price, vehicleID, hasSidecar));
    } else {
        std::cout << "Invalid vehicle type." << std::endl;
    }
}

void updateVehicleFromInput(VehicleManager& manager) {
    int vehicleID;
    std::string make, model;
    int year;
    double price;

    std::cout << "Enter vehicle ID to update: ";
    std::cin >> vehicleID;
    std::cin.ignore(); // Ignore newline character left in the buffer

    std::cout << "Enter new make: ";
    std::getline(std::cin, make);

    std::cout << "Enter new model: ";
    std::getline(std::cin, model);

    std::cout << "Enter new year: ";
    std::cin >> year;

    std::cout << "Enter new price: ";
    std::cin >> price;

    manager.updateVehicle(vehicleID, make, model, year, price);
}

int main() {
    VehicleManager manager;
    char choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a vehicle\n";
        std::cout << "2. Display all vehicles\n";
        std::cout << "3. Update a vehicle\n";
        std::cout << "4. Search for a vehicle\n";
        std::cout << "5. Save vehicles to file\n";
        std::cout << "6. Load vehicles from file\n";
        std::cout << "7. Remove a vehicle\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                addVehicleFromInput(manager);
                break;
            case '2':
                manager.displayAllVehicles();
                break;
            case '3':
                updateVehicleFromInput(manager);
                break;
            case '4': {
                std::string searchTerm;
                std::cout << "Enter make or model to search: ";
                std::cin.ignore(); // Ignore newline character left in the buffer
                std::getline(std::cin, searchTerm);
                auto results = manager.searchVehicle(searchTerm);
                for (auto vehicle : results) {
                    vehicle->displayDetails();
                    std::cout << std::endl;
                }
                break;
            }
            case '5': {
                std::string filename;
                std::cout << "Enter filename to save to: ";
                std::cin >> filename;
                manager.saveToFile(filename);
                break;
            }
            case '6': {
                std::string filename;
                std::cout << "Enter filename to load from: ";
                std::cin >> filename;
                manager.loadFromFile(filename);
                break;
            }
            case '7': {
                int vehicleID;
                std::cout << "Enter vehicle ID to remove: ";
                std::cin >> vehicleID;
                manager.removeVehicle(vehicleID);
                break;
            }
            case '8':
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != '8');

    return 0;
}
