/* Derived class that gets the |Fuel Capacity|Efficiency|Capacity| from the file and sets them  
   Uses vehicle specifications defined in the Base class */
#ifndef __GASCAR_H__
#define __GASCAR_H__
#include "Vehicle.h"

class GasCar : public Vehicle {
private:

    float Capacity;
    float Efficiency;
    
public:
    // Constructor needed only if you have local variables of intrinsic types
    GasCar();
    
    // Method to set Fuel Capacity & Efficiency
    void SetFuelCapacity(float Capacity);
    void SetEfficiency(float Efficiency);
    
    // Method to get Fuel Capacity, Efficiency & Capacity
    float GetFuelCapacity();
    float GetEfficiency();
    float GetCapacity();
    
    // From Base class
    void PrintVehicleSpec();

};

#endif
