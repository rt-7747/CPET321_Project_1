/* 

Possible Edits - 1st option : 2D array of a data type - Days[30](Reservations[50]) 

Take Inventory goes into Availibity list once its reserved it moves from Availbity to reserved at Example index day 3 
It can reserved up to 30 index 


*/

// Availibity will need to check the day and print all cars available for that day. If a car is reserved it will not be available for that day.



#ifndef __DATABASE_H__
#define __DATABASE_H__
#include <vector>
#include <string>

class Database : {
private:
    static const in Max = 50; // max number of vehicles in inventory 
    std::vector<Vehicle*> inventory;// inventory pointers 

    int currentDate; //tracks the date
 

public:
    // Constructor needed only if you have local variables of intrinsic types
    Database();
    ~DataBase();
    // Deconstructor

//inentory 
    bool AddVehicle(Vehicle* vehicle);
    int GetCurrentDate() const;
    void AdvanceDate;//
    // advaces the date and clears past reserations 
    // 
    void ClearInventory();
    bool SearchVehicles(const std::string& query)const; // 
    virtual void PrintAllVehicles() const;
    virtual void PrintReservedVehicles() const;
    virtual void PrintAvailableVehicles() const;

    bool ReserveVehicles(int vehicleIndex, int reservationDate);

   


};

#endif
