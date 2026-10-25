#include <iostream>
#include "Vehicle.h"

//Constructor
Vehicle::Vehicle(){
    Color = "";
    Make = "";
    Model = "";
    Year = "";
    EngineType = "";
}

void Vehicle::SetColor(string Color) {
    this->Color = Color;
}//SetColor

void Vehicle::SetMake(string Make) {
    this->Make = Make;
}//SetMake

void Vehicle::SetModel(string Model) {
    this->Model = Model;
}//SetModel

void Vehicle::SetYear(string Year) {
    this->Year = Year;
}//SetYear

void Vehicle::SetEngineType(string EngineType) {
    this->EngineType = EngineType;
}//SetEngineType()

string Vehicle::GetColor() {
    return Color;
}//GetColor()

string Vehicle::GetMake() {
    return Make;
}//GetMake()

string Vehicle::GetModel() {
    return Model;
}//GetModel()

string Vehicle::GetYear() {
    return Year;
}//GetYear()

string Vehicle::GetEngineType() {
    return EngineType;
}//GetEngineType()


// Add a vehicle to the reservation list
void Vehicle::AddVehicleToReserve() {
    string Make, Model, Year, Color;

    PrintAvailability(); // Show Availability

    cout << "Enter Make: ";
    cin >> Make;

    cout << "Enter Model: ";
    cin >> Model;

    cout << "Enter Year: ";
    cin >> Year;

    cout << "Enter Color: ";
    cin >> Color;
    
    //2D array indexing [Inventory Vehicle = i & Reserved Vehicle = j] 
    for (int i = 0; i < Vcount; i++) {
        if (Vehicle[i].GetMake() == Make && Vehicle[i].GetModel() == Model && Vehicle[i].GetYear() == Year && Vehicle[i].GetColor() == Color) {
            for (int j = 0; j < RScount; j++) {
                if (Reserved[j].GetMake() == Make && Reserved[j].GetModel() == Model && Reserved[j].GetYear() == Year && Reserved[j].GetColor() == Color) {
                    cout << "Already reserved.\n";
                    return;
                }
            }

            cout << "Vehicle added to reservation list.\n";
            return;
        }
    }

    cout << "Vehicle not found in inventory.\n";
}

// Print reservation list
void Vehicle::PrintReservation() {
    cout << "\n Reservation List:\n";

    for (int i = 0; i < Vcount; i++) {
        cout << Vehicle[i].GetYear() << " " << Vehicle[i].GetColor() << " " << Vehicle[i].GetMake() << " " << Vehicle[i].GetModel() << " " << Vehicle[i].GetEngineType() << endl;
    }
    
    if (!IsReserved) {
        cout << "No reservations.\n";
    }
}

// Print available vehicles
void Vehicle::PrintAvailability() {
    cout << "\n Available Vehicles:\n";

    for (int i = 0; i < Vcount; i++) {
        bool IsReserved = false;

        for (int j = 0; j < Acount; j++) {
            if (Available[j].GetMake() == Vehicle.GetMake() && Available[j].GetModel() == Vehicle.GetModel() && Available[j].GetYear() == Vehicle.GetYear() && Available[j].GetColor() == Vehicle.GetColor()) {
                IsReserved = true;
                break;
            }
        }

        if (!IsReserved) {
            cout << Vehicle.GetYear() << " " << Vehicle.GetColor() << " " << Vehicle.GetMake() << " " << Vehicle.GetModel() << " " << Vehicle.GetEngineType() << endl;
        }
    }
}

// Print complete inventory
void Vehicle::PrintInventory() {
    cout << "\nVehicle Inventory:\n";

    for () {
        cout << GetYear() << " " << GetMake() << " " << GetModel() << " " << endl;
    }
}

//Deconstructor
Vehicle :: ~Vehicle(){
    
}

