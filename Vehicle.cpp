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

bool Vehicle::HasReservation() const {
    return !ReservationDays.empty();
}

void Vehicle::PrintReservations() const {
    if (ReservationDays.empty()) {
        cout << "No reservations.\n";
        return;
    }

    cout << "Reserved days: ";
    for (size_t i = 0; i < ReservationDays.size(); i++) {
        cout << ReservationDays[i] << " ";
    }
    cout << '\n';
}

//Deconstructor
Vehicle :: ~Vehicle(){
    
}

