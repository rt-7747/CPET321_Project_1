/* 

Possible Edits - 1st option : 2D array of a data type - Days[30](Reservations[50]) 

Take Inventory goes into Availibity list once its reserved it moves from Availbity to reserved at Example index day 3 
It can reserved up to 30 index 


*/

// Availibity will need to check the day and print all cars available for that day. If a car is reserved it will not be available for that day.



#ifndef __DATABASE_H__
#define __DATABASE_H__

class Database : {
private:

    //Data members
    bool IsReserved;
    int DaysReserved;

public:
    // Constructor needed only if you have local variables of intrinsic types
    Database();

    // Set Reservation & Days Reserved
    
    //void SetReservation(bool IsReserved);
    void SetDaysReserved(int DaysReserved);

    // Get Reservation & Days Reserved
    
    //float GetReservation();
    float GetDaysReserved();

    // To be used in base / derived class
    virtual void PrintReservation() = 0;
    virtual void PrintAvailability() = 0;
    virtual void PrintInventory() = 0;
    

    // Deconstructor
    ~Database();


};

#endif

