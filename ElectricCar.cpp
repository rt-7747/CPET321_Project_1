#include <iostream>
#include <string>
#include "ElectricCar.h"
using namespace std;

ElectricCar::ElectricCar(){
    Capacity = 0.0;
    Efficiency = 0.0;
    SetEngineType("EV");
}//Constructor

void ElectricCar::SetEnergyCapacity(float Capacity) {
    this->Capacity = Capacity;
}//SetFuelCapacity();

void ElectricCar::SetEfficiency(float Efficiency) {
    this->Efficiency = Efficiency;
}//SetEfficiency();

//Needs change from string to float
float ElectricCar::GetEnergyCapacity()
{
    return Capacity;
}//GetEnergyCapacity

//Needs change from string to float
float ElectricCar::GetEfficiency()
{
    return Efficiency;
}//GetEfficiency

//Needs change from string to float
float ElectricCar::GetCapacity()
{
    return Capacity;
}//GetCapacity

void ElectricCar::PrintVehicleSpec()
{
    cout << "Make: " << GetMake() << endl;
    cout << "Model: " << GetModel() << endl;
    cout << "Year: " << GetYear() << endl;
    cout << "Engine Type: " << GetEngineType() << endl;
    cout << "Capacity: " << Capacity << endl;
    cout << "Efficiency: " << Efficiency << endl << endl;
}//Base class