/* Base class that gets the |Make|Model|Year|Engine Type| from the file and sets them  
   Uses capacity, efficiency and vehicle specifications to be used in the derived classes */

#ifndef __VEHICLE_H__
#define __VEHICLE_H__
#include <string>
#include "Database.h"
using namespace std;

class Vehicle : public Database {
private:

    string Color, Make, Model, Year, EngineType; // Normal String
    int Vcount = 0; // Vehicle count
    int RScount = 0; // Reserved Vehicle count
    int Acount = 0; // Available Vehicle count
    int Reserved[3]; //Reserved Vehicle Array
    int Available[30]; // Available Vehicle Array

public:
    // Constructor needed only if you have local variables of intrinsic types
    Vehicle();
    
    // Method to get Make, Model, Year, & Engine Type
    void SetColor(string Color);
    void SetMake(string Make);
    void SetModel(string Model);
    void SetYear(string Year);
    void SetEngineType(string EngineType);
    
    //Get the Make, Model, Year, & Engine Type
    string GetColor();
    string GetMake();
    string GetModel();
    string GetYear();
    string GetEngineType();
    
    //To be used in derived class (Children class)
    virtual float GetCapacity() = 0;
    virtual float GetEfficiency() = 0;
    virtual void PrintVehicleSpec() = 0;
    
    //Enlist vehicle to reservation
    void AddVehicleToReserve();
    
    //From base class (GrandFather class)
    void PrintReservedVehicles() const;
    void PrintAvailableVehicles() const;
    void PrintAllVehicles() const;
    
    //Deconstructor (gas & electric car objects)
    virtual ~Vehicle();
};

#endif
