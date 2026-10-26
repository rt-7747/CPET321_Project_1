#include "Database.h"
#include "Vehicle.h"
#include <iostream>
#include <string>

//constructor
Database::Database() : currentDate(1) {
    for (int i = 0; i < MaxDays; i++) {
        for (int j = 0; j < Max; j++) {
            reservations[i][j] = false;
        }
    }
    
}

//deconstructor 
Database::~Database() {

	ClearInventory();

}
//clears the cars in the invetory for 
void Database::ClearInventory() {
    for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
        delete inventory[i];
    }

    inventory.clear();

    for (int i = 0; i < MaxDays; i++) {
        for (int j = 0; j < Max; j++) {
            reservations[i][j] = false;
        }
    }
}
//add vehicle to invetory if max cap of 50 is not met
bool Database::AddVehicle(Vehicle* vehicle) {
	if (static_cast<int>(inventory.size()) >= Max) {
		cout << "Inventory is full.\n";
		return false;
	}
	
	if (vehicle == nullptr) {
        return false;
    }
    
	inventory.push_back(vehicle);
	return true;

}

//presents the current date 
int Database::GetCurrentDate() const {
	return currentDate;
}

//advances the current date  by 1 day
void Database::AdvanceDate() {
	if (currentDate < MaxDays) {
        currentDate++;
        cout << "Date advanced to Day " << currentDate << "." << endl;
    }
    else {
        cout << "Maximum day reached." << endl;
    }
}
//searchs bby the make model color and year 
bool Database::SearchVehicles(const string& query) const{
		bool found = false;

    cout << "Search results for: " << query << endl;

    for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
        if (inventory[i]->GetMake() == query || inventory[i]->GetModel() == query || inventory[i]->GetYear() == query || inventory[i]->GetColor() == query || inventory[i]->GetEngineType() == query) {

            cout << "Inventory number: " << i + 1 << endl;
            inventory[i]->PrintVehicleSpec();
            found = true;
        }
    }
    if (!found) {
        cout << "No matching vehicles found." << endl;
    }

    return found;
}
    
bool Database::ReserveVehicles(int VehicleIndex, int ReservationDate) {
	if (VehicleIndex < 0 || VehicleIndex >= static_cast<int>(inventory.size())) {
		cout << "invalid vehicle chioce";
		return false;
	}
	 if (ReservationDate <= currentDate || ReservationDate > MaxDays) {
        cout << "Reservation must be between Day " << currentDate + 1 << " and Day " << MaxDays << "." << endl;
        return false;
    }

    if (reservations[ReservationDate - 1][VehicleIndex]) {
        cout << "This vehicle is already reserved for that day." << endl;
        return false;
    }

    reservations[ReservationDate - 1][VehicleIndex] = true;

    cout << "Reservation successful for Day " << ReservationDate << "." << endl;

    return true;
}


//lists the cars that are avilable
void Database::PrintAvailableVehicles()const {
	cout << "These are the cars avaliable for reservation" << endl;
		bool found = false;
	for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
        bool vehicleReserved = false;

        for (int j = currentDate; j < MaxDays; j++) {
            if (reservations[j][i]) {
                if (!vehicleReserved) {
                    cout << "Inventory number: " << i + 1 << endl;
                    inventory[i]->PrintVehicleSpec();
                    vehicleReserved = true;
                    found = true;
                }

                cout << "Reserved for Day " << j + 1 << endl;
            }
        }
    }

    if (!found) {
        cout << "No vehicles currently have future reservations." << endl;
    }
}



//Prints the cars in inventory
void Database::PrintAllVehicles()const {
	cout << "all vehicles in inventory(current Date : Day" << currentDate << ").\n";
	if (inventory.empty()) {
		cout << "No vehicles in inventory.\n";
		return;

	}
	for (size_t i = 0; i < static_cast<int>(inventory.size()); ++i) {
		cout << i + 1;
		inventory[i]->PrintVehicleSpec();

	}

}
//Print resservation 
void Database::PrintReservedVehicles()const {
	cout << "Vehicles with future reservations";
	bool found = false;
	for (size_t i = 0; i < inventory.size(); i++){
		if (inventory[i]->HasReservation()) {
			cout<< i + 1;
			inventory[i]->PrintVehicleSpec();
			inventory[i]->PrintReservations();
			found = true;
		}
	}
	if (!found) {
		cout << "no vehcles currently have reservtations";

	}
}

