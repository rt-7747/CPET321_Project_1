/* Base class that gets the |Make|Model|Year|Engine Type| from the file and sets them  
   Uses capacity, efficiency and vehicle specifications to be used in the derived classes */\

//testing

#ifndef __VEHICLE_H__
#define __VEHICLE_H__
#include <string>
using namespace std;

class Vehicle : public Database {
private:

    string Make, Model, Year, EngineType;

public:
    // Constructor needed only if you have local variables of intrinsic types
    Vehicle();
    
    // Method to get Make, Model, Year, & Engine Type
    void SetMake(string Make);
    void SetModel(string Model);
    void SetYear(string Year);
    void SetEngineType(string EngineType);
    
    //Get the Make, Model, Year, & Engine Type
    string GetMake();
    string GetModel();
    string GetYear();
    string GetEngineType();
    
    //To be used in derived class
    virtual float GetCapacity() = 0;
    virtual float GetEfficiency() = 0;
    virtual void PrintVehicleSpec() = 0;
    
    //Deconstructor (gas & electric car objects)
    virtual ~Vehicle();
};

#endif