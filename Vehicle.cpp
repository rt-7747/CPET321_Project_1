#include <iostream>
#include "Vehicle.h"

//Constructor
Vehicle::Vehicle(){
    Make = "";
    Model = "";
    Year = "";
    EngineType = "";
}

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

void Vehicle::PrintReservation(){
    cout << "Reservation List: "<< endl;
    
    for (int i = 0; i < Vcount; i++) {
        string Make, Model, Year;
        Vehicle[i].GetYear();
        Vehicle[i].GetMake();
        Vehicle[i].GetModel();

        cout << GetYear() << " " << GetMake() << " " << GetModel() << " " << endl;

    }
    
}//PrintReservation()

void Vehicle::PrintAvailability(){
    cout << "The following is available: "<< endl;
    cout << GetYear() << " " << GetMake() << " " << GetModel() << " " << endl;
}//PrintAvailibility()

void Vehicle::PrintInventory(){
    cout << "In Inventory: "<< endl;
    cout << GetYear() << " " << GetMake() << " " << GetModel() << " " << endl;
}//PrintInventory()

//Deconstructor
Vehicle :: ~Vehicle(){
    
}

