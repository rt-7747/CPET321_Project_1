#include <iostream>
#include "Database.h"
#include "Vehicle.h"
#include "ElectricCar.h"
#include "GasCar.h"

using namespace std;

int main() {
    /*
	Database db;
	// Create some vehicles
	ElectricCar tesla("Tesla", "Model S", 2020, 100);
	GasCar ford("Ford", "Mustang", 2019, 15);
	// Add vehicles to the database
	db.addVehicle(&tesla);
	db.addVehicle(&ford);
	// Display all vehicles in the database
	db.displayVehicles();
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

            Database[NumVehicles] = Gas_ptr;
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

            Database[NumVehicles] = EV_ptr;
        } // if...if...else()
        else
        {
            cout << "Error! Unrecognized propulsion type." << endl;
            return -3;
        } // if...else()

       // Increment the running counter of the cars in the inventory
        NumVehicles++;
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
			cout << " E = Search by Efficiency" << endl;
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
            int Matches = 0;
            for (int i = 0; i < NumVehicles; i++)
            {
                if (Database[i]->GetMake() == DesiredMake)
                {
                    // Print out matching entries
                    PrintVehicle(Database[i]);
                    Matches++;
                }
            }
            if (Matches == 0)
                cout << " No vehicles found with Make " << DesiredMake << endl;
            break;
            // Print out matching entries
        } // case 'a' or 'A'
        case 'o': case 'O': // Search by Model
        {
            // Prompt the user for the search criteria
            string DesiredModel;
            cout << "Enter Model > ";
            cin >> DesiredModel;

            int Matches = 0;
            for (int i = 0; i < NumVehicles; i++)
            {
                if (Database[i]->GetModel() == DesiredModel)
                {
                    // Print out matching entries
                    PrintVehicle(Database[i]);
                    Matches++;
                }
            }
            if (Matches == 0)
                cout << " No vehicles found with Model " << DesiredModel << endl;
            break;
            // Print out matching entries
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
                if (Database[i]->GetYear() == DesiredYear)
                {
                    // Print out matching entries
                    PrintVehicle(Database[i]);
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
			int Matches = 0;
			for (int i = 0; i < NumVehicles; i++)
			{
				if (Database[i]->GetColor() == DesiredColor)
				{
					// Print out matching entries
					PrintVehicle(Database[i]);
					Matches++;
				}
			}
			if (Matches == 0)
				cout << " No vehicles found with Color " << DesiredColor << endl;
			break;
		} // case 'c' or 'C'
        case 'e': case 'E': // Search by Efficiency
        {
            // Prompt the user for the search criteria
            float ;
            cout << "Enter Efficiency > ";
            cin >> DesiredEfficiency;
            int Matches = 0;
            for (int i = 0; i < NumVehicles; i++)
            {
                if (Database[i]->GetEfficiency() == DesiredEfficiency)
                {
                    // Print out matching entries
                    PrintVehicle(Database[i]);
                    Matches++;
                }
            }
            if (Matches == 0)
                cout << " No vehicles found with Efficiency " << DesiredEfficiency << endl;
            break;
		} // case 'e' or 'E'
		case 'r': case 'R': // Set a Reservation
		{
			// Prompt the user for the search criteria
			string DesiredMake;
			string DesiredModel;
            string DesiredYear;

            cout << "Enter Make, Model, and Year of desired vehicle > " << endl;
			cin >> DesiredMake;
			cin >> DesiredModel;
			cin >> DesiredYear;

			cout << "Enter number of days reserved 

            /*
			search database for matching vehicle
            
            			int Matches = 0;
			for (int i = 0; i < NumVehicles; i++)
			{
				if (Database[i]->GetReservation() == DesiredReservation)
				{
					// Print out matching entries
					PrintVehicle(Database[i]);
					Matches++;
				}
			}
			if (Matches == 0)
				cout << " No vehicles found with Reservation " << DesiredReservation << endl;

            */

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