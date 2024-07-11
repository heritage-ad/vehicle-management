#Vehicle Management System

#Description: The Vehicle Management System is a C++ application designed to manage a fleet of vehicles. The system allows users to add, display, update, search, save, load, and remove vehicles from a collection. Supported vehicle types include cars, trucks, and motorcycles.
#Features: **Add new vehicles (Car, Truck, Motorcycle) **Display all vehicles **Update vehicle details **Search for vehicle by make or model **Save vehicle data to a file **Load vehicle data from a file **Remove a vehicle by ID

#Menu Options: **Add a vehicle: Prompts for vehicle type and details, then adds the vehicle to the collection. **Display all vehicles: Displays the details of all vehicles in the collection. **Update a vehicle: Prompts for the vehicle ID and new details to update an existing vehicle. **Search for a vehicle: Searches for vehicles by make or model and displays matching results. **Save vehicles to file: Saves the current collection of vehicles to a specified file. **Load vehicles from file: Loads vehicles from a specified file into the collection. **Remove a vehicle: Removes a vehicle from the collection by its ID. **Exit: Exits the application.

#Files **main.cpp: Main program file with the user interface. **Vehicle.h: Base class for vehicles. **Car.h: Car class derived from Vehicle. **Truck.h: Truck class derived from Vehicle. **Motorcycle.h: Motorcycle class derived from Vehicle. **VehicleManager.h: Class to manage the collection of vehicles

