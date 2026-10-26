#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Database.h"
#include "Vehicle.h"
#include "ElectricCar.h"
#include "GasCar.h"

using namespace std;

int main() {
    Database db;

    ifstream InFile;
    string Line;

    InFile.open("Inventory.txt");

    if (!InFile.is_open()) {
        cout << "Error! Inventory file could not be opened." << endl;
        return -1;
    }

    while (getline(InFile, Line)) {
        istringstream Record(Line);
        string Field;
        vector<string> Fields;

        while (Record >> Field) {
            Fields.push_back(Field);
        }

        // Ignore blank lines.
        if (Fields.empty()) {
            continue;
        }

        // Make + Model + Year + EngineType + Capacity
        // + Efficiency + Color = at least 7 fields.
        if (Fields.size() < 7) {
            cout << "Error! Inventory file is malformed." << endl;
            cout << Line << endl;
            InFile.close();
            return -2;
        }

        string Make = Fields[0];
        string Model = "";

        // The final five fields are Year, EngineType,
        // Capacity, Efficiency, and Color.
        int YearIndex = static_cast<int>(Fields.size()) - 5;

        for (int i = 1; i < YearIndex; i++) {
            if (Model != "") {
                Model += " ";
            }

            Model += Fields[i];
        }

        string Year = Fields[YearIndex];
        string EngineType = Fields[YearIndex + 1];
        string Capacity = Fields[YearIndex + 2];
        string Efficiency = Fields[YearIndex + 3];
        string Color = Fields[YearIndex + 4];

        float CapacityValue;
        float EfficiencyValue;

        istringstream CapacityStream(Capacity);
        istringstream EfficiencyStream(Efficiency);

        if (!(CapacityStream >> CapacityValue) ||
            !(EfficiencyStream >> EfficiencyValue)) {
            cout << "Error! Invalid capacity or efficiency." << endl;
            cout << Line << endl;
            InFile.close();
            return -2;
        }

        if (EngineType == "ICE") {
            GasCar* Gas_ptr = new GasCar;

            Gas_ptr->SetMake(Make);
            Gas_ptr->SetModel(Model);
            Gas_ptr->SetYear(Year);
            Gas_ptr->SetEngineType(EngineType);
            Gas_ptr->SetColor(Color);
            Gas_ptr->SetFuelCapacity(CapacityValue);
            Gas_ptr->SetEfficiency(EfficiencyValue);

            if (!db.AddVehicle(Gas_ptr)) {
                delete Gas_ptr;
            }
        }
        else if (EngineType == "EV") {
            ElectricCar* EV_ptr = new ElectricCar;

            EV_ptr->SetMake(Make);
            EV_ptr->SetModel(Model);
            EV_ptr->SetYear(Year);
            EV_ptr->SetEngineType(EngineType);
            EV_ptr->SetColor(Color);
            EV_ptr->SetEnergyCapacity(CapacityValue);
            EV_ptr->SetEfficiency(EfficiencyValue);

            if (!db.AddVehicle(EV_ptr)) {
                delete EV_ptr;
            }
        }
        else {
            cout << "Error! Unrecognized propulsion type." << endl;
            InFile.close();
            return -3;
        }
    }

    InFile.close();

    bool ExitRequested = false;

    do {
        char Command;

        cout << "\n============================================" << endl;
        cout << "          VEHICLE RESERVATION SYSTEM" << endl;
        cout << "============================================" << endl;
        cout << "Hello, today is Day " << db.GetCurrentDate() << endl;
        cout << "Enter Command (? for help) > ";

        cin >> Command;

        switch (Command) {
        case '?': {
            cout << "\nDAY " << db.GetCurrentDate() << endl;
            cout << " ? = Display Help" << endl;
            cout << " M = Search by Make" << endl;
            cout << " O = Search by Model" << endl;
            cout << " Y = Search by Year" << endl;
            cout << " C = Search by Color" << endl;
            cout << " R = Set a Reservation" << endl;
            cout << " A = Print Available Vehicle List" << endl;
            cout << " P = Print Reserved Vehicle List" << endl;
            cout << " I = Print Inventory" << endl;
            cout << " D = Advance the Date" << endl;
            cout << " Q = Quit" << endl;
            break;
        }

        case 'm':
        case 'M': {
            string DesiredMake;

            cout << "Enter Make > ";
            cin >> DesiredMake;

            db.SearchVehicles(DesiredMake);
            break;
        }

        case 'o':
        case 'O': {
            string DesiredModel;

            cout << "Enter Model (use underscores for spaces) > ";
            cin >> DesiredModel;

            for (int i = 0; i < static_cast<int>(DesiredModel.length()); i++) {
                if (DesiredModel[i] == '_') {
                    DesiredModel[i] = ' ';
                }
            }

            db.SearchVehicles(DesiredModel);
            break;
        }

        case 'y':
        case 'Y': {
            string DesiredYear;

            cout << "Enter Year > ";
            cin >> DesiredYear;

            db.SearchVehicles(DesiredYear);
            break;
        }

        case 'c':
        case 'C': {
            string DesiredColor;

            cout << "Enter Color > ";
            cin >> DesiredColor;

            db.SearchVehicles(DesiredColor);
            break;
        }

        case 'r':
        case 'R': {
            int VehicleIndex;
            int ReservationDate;

            db.PrintAllVehicles();

            cout << "Enter inventory number > ";
            cin >> VehicleIndex;

            cout << "Enter reservation day (1-30) > ";
            cin >> ReservationDate;

            // Convert the displayed inventory number to a zero-based index.
            VehicleIndex--;

            db.ReserveVehicles(VehicleIndex, ReservationDate);
            break;
        }

        case 'a':
        case 'A': {
            db.PrintAvailableVehicles();
            break;
        }

        case 'p':
        case 'P': {
            db.PrintReservedVehicles();
            break;
        }

        case 'i':
        case 'I': {
            db.PrintAllVehicles();
            break;
        }

        case 'd':
        case 'D': {
            db.AdvanceDate();
            cout << "Current date: Day "
                 << db.GetCurrentDate() << endl;
            break;
        }

        case 'q':
        case 'Q': {
            ExitRequested = true;
            break;
        }

        default: {
            cout << "Unknown command. Enter ? for help." << endl;
            break;
        }
        }

    } while (!ExitRequested);

    return 0;
}
