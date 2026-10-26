#include "DataBase.h"
#include <isostream>

//constructor the updates
DataBase::DataBase()::currentDate(1) {}

//deconstructor 
void DataBase::~DataBase{

	clearInvetory;

}
//clears the cars in the inventory for 
void DataBase::ClearInventory{
	for (Vehicle* v : Inventory) {
		delete v;
	}
	invetory.clear();

}
//add vehicle to invetory if max cap of 50 has not yet been met. 
bool DataBase::AddVehicle(Vehicle* vehicle) {
	if (invetory.size >= Max) {
		std::cout << "Inventory is full.\n";
		return false;
	}
	inventory.push_back(vehicle);
	return true;

}

//presents the current date 
int DataBase::GetCurrentDate() const {
	return currentDate;
}

//advances the current date  by 1 day and clears 
void DataBase::AdvanceDate() {
	currentDate++;
	std::cout << "\nDate advanced to Day" << currentDate << ".\n";
	for (Vehicle* v : inventory) {
		v - > clearExpiredReservations(currentDate);
	}

}
//searchs by the make model color and year 
void DataBase::SearchVehicles() {
	const std::string& query) const{
		std::cout << "Search results for " << query << "\n";
		bool found = false;
		for (size_t i = 0; i < inventory.size(); i++) {
			if (inventory[i]->matchesQuery(query)) { // matches against vehicles 
				std::cout << i + 1;
				inventory[i]->printDetails();
				found = true;
			}
		}
		if (!found) {
			std::cout << "No matches found.\n";

		}
}

    
bool Database::ReserveVehicle(int vehicleIndex, int reservationDate) {
	if (vehicleIndex < 0 || vehicleIndex >= static_cast<int>(inventory.size())) {
		std::cout << "invalid vehicle chioce";
		return false;
	}
	//reservation date must be greater than current date
	if (reservationDate <= currentDate) {
		std::cout << "reservation must be a future date";
		return false;
	}
	Vehicle* vehicle = inventory[vehicleIndex];

	
	// max of 3 future reservations 
	if (vehicle->addreservation(reservationDate)) {
		std:::cout << "reservation successful";
		return true
	}
	else {
		std::cout << "reservation failed. limit reached or vehicle already reserved";
		return false;
	}
}

//lists the cars that are available. 
void DataBase::PrintAvailableVehicles()const {
	std::cout::"These are the cars avaliable for reservation"
		bool found = false;
	for (size_t i = 0; i < inventory.size(); ++i) {
		if (!inventory[i]->  hasReservations()) {
			std::cout << i + 1;
			inventory[i]->printDetails();
			found = true;
			
		}
	}
	if (!found) {
		std::cout << "No Vehicles Avalible;"
	}
}



//Prints the cars in inventory
void DataBase::PrintAllVehicles()const {
	std::cout << "all vehicles in inventory(current Date : Day" << currentDate << ").\n";
	if (inventory.empty()) {
		std::cout << "No vehicles in inventory.\n";
		return;

	}
	for (size_t i = 0; i < inventory.size(); ++i) {
		std::cout << i + 1;
		inventory[i]->printDetails();

	}

}
//Print resservation 
void DataBase::PrintReservedVehicles()const {
	std::cout << "Vehicles with future reservations";
	bool found = false;
	for size_t i = 0; i < inventory.size(); i++){
		if (inventory[i]->hasReservations()) {
			std::cout<< i + 1;
			inventory[i]->printsDetails();
			inventory[i]->printReservation();
			found = true;
		}
	}
	if (!found) {
		std::cout << "no vehcles currently have reservtations";

	}
}


}

