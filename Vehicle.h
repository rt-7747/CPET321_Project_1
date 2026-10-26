/* Base class that gets the |Make|Model|Year|Engine Type| from the file and sets them  
   Uses capacity, efficiency and vehicle specifications to be used in the derived classes */

#ifndef __VEHICLE_H__
#define __VEHICLE_H__
#include <string>
#include <vector>

using namespace std;

class Vehicle {
private:

    string Color, Make, Model, Year, EngineType; // Normal String
    vector<int> ReservationDays;
public:
    // Constructor
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
    
    //Reservation methods need in Vehicle
    bool HasReservation() const;
    void PrintReservations() const;
    
    //Deconstructor (gas & electric car objects)
    ~Vehicle();
};

#endif
