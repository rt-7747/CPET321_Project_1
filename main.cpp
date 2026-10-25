#include <iostream>
#include "Database.h"
#include "Vehicle.h"
#include "ElectricCar.h"
#include "GasCar.h"

using namespace std;

/*
void PrintVehicle(Vehicle* V)
{
    string blank;
    cout << "Make: " << V->GetMake() << "  Model: " << V->GetModel()
        << "  Year: " << V->GetYear() << endl;
    V->GetStats(blank, blank, blank);
    if (isReserved = false)
    {
        cout << " AVALIABLE" << endl;
    }
    else
    {
        cout << "This vehicle is reserved on: ";
        for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 50; j++)
			{
				if (Days[i]Reservations[j] == V)
				{
					cout << "Day " << i + 1 << endl;
				}
			}
        }

    }
}
*/

int main() {
    /*
	When a car is reserved for example a Tesla Model S 2020 is reserved for day 3 and the Tesla Model S is in Inventory[4] Day[6]Reseravation[0] = Inventory[4]
    */

	ifstream InFile;
	string line;
	
	InFile.open("Inventory.txt");
	if (!InFile.is_open()) {
		cout << "Error! Inventory file could not be opened." << endl;
		return -1;
	}
    while (getline(InFile, Line))
    {
        // String stream for parsing words from the line
        istringstream Record(Line);
        // String to hold the parsed field
        string Field;
        // Strings to hold the individual fields
        string Make, Model, Year, EngineType, Capacity, Efficiency, Color;

        // Get the strings from the line
        int FieldCount = 0;
        while (Record >> Field)
        {
            FieldCount++;
            switch (FieldCount)
            {
            case 1: { Make = Field; break; }
            case 2: { Model = Field; break; }
            case 3: { Year = Field; break; }
            case 4: { EngineType = Field; break; }
            case 5: { Capacity = Field; break; }
            case 6: { Efficiency = Field; break; }
			case 7: { Color = Field; break; }

            } // switch()
        } // while()
		if (FieldCount != 7)
		{
			cout << "Error! Inventory file is malformed." << endl;
			cout << Line << endl;
			return -2;
		} // if()
        if (EngineType == "ICE")
        {
            //Vehicle* Gas_ptr;
            GasVehicle* Gas_ptr = new GasVehicle;

            Gas_ptr->SetMake(Make);
            Gas_ptr->SetModel(Model);
            Gas_ptr->SetYear(Year);
            Gas_ptr->SetEngineType(EngineType);
            Gas_ptr->GetFuelCap(Capacity);
            Gas_ptr->GetGas_Efficiency(Efficiency);

            db.AddVehicle(Gas_ptr);
        } // if()
        else if (EngineType == "EV")
        {
            //Vehicle* EV_ptr;
            ElectricVehicle* EV_ptr = new ElectricVehicle;

            // Set the fields
            EV_ptr->SetMake(Make);
            EV_ptr->SetModel(Model);
            EV_ptr->SetYear(Year);
            EV_ptr->SetEngineType(EngineType);
            EV_ptr->GetEnergyCap(Capacity);
            EV_ptr->GetEV_Efficiency(Efficiency);

            // Insert the Electric car into the database

            db.AddVehicle(EV_ptr);
        } // if...if...else()
        else
        {
            cout << "Error! Unrecognized propulsion type." << endl;
            return -3;
        } // if...else()
    } // while()

    bool ExitRequested = false;
    do {
        char Command;
        // Prompt the user for the program option (search by Make, Model, Year, or
        //   or exit the program)
		cout << "                                 _        _ " << endl;
        cout << "                                | |      | |" << endl;
        cout << "  ___ __ _ _ __   _ __ ___ _ __ | |_ __ _| |" << endl;
		cout << " / __/ _` | '__| | '__/ _ \ '_ \| __/ _` | |" << endl;
		cout << "| (_| (_| | |    | | |  __/ | | | || (_| | |" << endl;
		cout << " \___\__,_|_|    |_|  \___|_| |_|\__\__,_|_|" << endl;
		cout << "================================================" << endl
        cout << "Enter Command (? for help) > ";
        cin >> Command;

        // Process the command
        switch (Command)
        {
        case '?': // Help screen
        {
            cout << " ? = Display Help" << endl;
            cout << " M = Search by Make" << endl;
            cout << " O = Search by model" << endl;
            cout << " Y = Search by Year" << endl;
			cout << " C = Search by Color" << endl;
			cout << " R = Set a Reservation" << endl;
            cout << " Q = Quit / Exit the program" << endl;
            break;
        } // Case '?'
        case 'm': case 'M': // Search by Make
        {
            // Prompt the user for the search criteria
            string DesiredMake;
            cout << "Enter Make > ";
            cin >> DesiredMake;

            // Search the database
            SearchVehicles(DesiredMake);
            break;
            // Print out matching entries
        } // case 'a' or 'A'
        case 'o': case 'O': // Search by Model
        {
            // Prompt the user for the search criteria
            string DesiredModel;
            cout << "Enter Model > ";
            cin >> DesiredModel;

            SearchVehicles(DesiredModel);
            break;
        } // case 'o' or 'O'
        case 'y': case 'Y': // Search by Year
        {
            // Prompt the user for the search criteria
            int DesiredYear;
            cout << "Enter Year > ";
            cin >> DesiredYear;

            int Matches = 0;
            for (int i = 0; i < NumVehicles; i++)
            {
                if (Inventory[i]->GetYear() == DesiredYear)
                {
                    // Print out matching entries
                    PrintVehicle(Inventory[i]);
                    Matches++;
                }
            }
            if (Matches == 0)
                cout << " No vehicles found with Year " << DesiredYear << endl;
            break;
            // Print out matching entries
        } // case 'y' or 'Y'
		case 'c': case 'C': // Search by Color
		{
			// Prompt the user for the search criteria
			string DesiredColor;
			cout << "Enter Color > ";
			cin >> DesiredColor;
            SearchVehicles(DesiredColor);
			break;
		} // case 'c' or 'C'
		case 'r': case 'R': // Set a Reservation
		{
			// Prompt the user for the search criteria
			string DesiredMake;
			string DesiredModel;
            string DesiredYear;
            int DesiredDay;

            cout << "Enter Make, Model, and Year of desired vehicle > " << endl;
			cin >> DesiredMake;
			cin >> DesiredModel;
			cin >> DesiredYear;
			cin >> DesiredDay;

			DesiredDay = DesiredDay - 1; // Adjusting for array
          
            int InventoryIndex = -1;

            //Need getter for Inventory based on given make model and year

            /*
            
            if (inventory[i] != nullptr &&
                Inventory[i]->GetMake() == desiredMake &&
                Inventory[i]->GetModel() == desiredModel &&
                Inventory[i]->GetYear() == desiredYear)
            {
				InventoryIndex = i;
            }
            */

			ReserveVehicle(InventoryIndex,DesiredDay); // Looks up the vehicle in the database that match the make, model, and year and sets the reservation for the specified day

			break;
		} // case 'r' or 'R'
        case 'q': case 'Q': // Exit the program
        {
            ExitRequested = true;
            break;
        } // case 'q' or 'Q'
       // "otherwise" is not needed, any other command is ignored
        } // switch()

    } while (!ExitRequested);

    // No error possible
	return 0;
}