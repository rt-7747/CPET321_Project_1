/* Derived class that gets the |Energy Capacity|Efficiency|Capacity| from the file and sets them  
   Uses vehicle specifications defined in the Base class */

// New change

#ifndef __ELECTRICCAR_H__
#define __ELECTRICCAR_H__
#include "Vehicle.h"

class ElectricCar : public Vehicle {
private:

    string Capacity;
    string Efficiency;


public:
    // Constructor needed only if you have local variables of intrinsic types
    ElectricCar();
    
    // Method to set Energy Capacity & Efficiency
    void SetEnergyCapacity(float Capacity);
    void SetEfficiency(float Efficiency);
    
    // Method to get Energy Capacity, Efficiency & Capacity
    float GetEnergyCapacity();
    float GetEfficiency();
    float GetCapacity();
    
    //From Base class
    void PrintVehicleSpec();
};

#endif