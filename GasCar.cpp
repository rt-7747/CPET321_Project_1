#include <iostream>
#include "GasCar.h"
using namespace std;

GasCar::GasCar(){
    Capacity = 0.0f;
    Efficiency = 0.0f;
    SetEngineType("ICE");
}//Constructor

void GasCar::SetFuelCapacity(float Capacity) {
    this->Capacity = Capacity;
}//SetFuelCapacity();

void GasCar::SetEfficiency(float Efficiency) {
    this->Efficiency = Efficiency;
}//SetEfficiency();

float GasCar::GetFuelCapacity()
{
    return Capacity;
}//GetFuelCapacity

float GasCar::GetEfficiency()
{
    return Efficiency;
}//GetEfficiency

float GasCar::GetCapacity()
{
    return Capacity;
}//GetCapacity

void GasCar::PrintVehicleSpec()
{
    cout << "Make: " << GetMake() << endl;
    cout << "Model: " << GetModel() << endl;
    cout << "Year: " << GetYear() << endl;
    cout << "Engine Type: " << GetEngineType() << endl;
    cout << "Capacity: " << Capacity << endl;
    cout << "Efficiency: " << Efficiency << endl;
    cout << "Color: " << GetColor() << endl << endl;
}
