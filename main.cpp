#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class Appliance {
private:
    string name;
    double powerW;   // watts
    double hours;    // hours/day

public:
    Appliance() : name(""), powerW(0), hours(0) {}
    Appliance(const string& n, double p, double h) : name(n), powerW(p), hours(h) {}

    string getName() const { return name; }
    double getPowerW() const { return powerW; }
    double getHours() const { return hours; }

    double dailyEnergyKwh() const {
        // kWh = (W * hours) / 1000
        return (powerW * hours) / 1000.0;
    }
};

// ---- Input Helpers (Validation) ----
void clearBadInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string inputNonEmptyString(const string& prompt) {
    while (true) {
        cout << prompt;
        string s;
        getline(cin, s);

        // trim simple spaces
        while (!s.empty() && s.front() == ' ') s.erase(s.begin());
        while (!s.empty() && s.back() == ' ') s.pop_back();

        if (!s.empty()) return s;
        cout << "Error: name must not be empty.\n";
    }
}

double inputPositiveDouble(const string& prompt) {
    while (true) {
        cout << prompt;
        double x;
        if (cin >> x && x > 0) {
            clearBadInput();
            return x;
        }
        cout << "Error: value must be greater than 0.\n";
        clearBadInput();
    }
}

double inputHours0to24(const string& prompt) {
    while (true) {
        cout << prompt;
        double h;
        if (cin >> h && h >= 0 && h <= 24) {
            clearBadInput();
            return h;
        }
        cout << "Error: hours must be between 0 and 24.\n";
        clearBadInput();
    }
}

// ---- Features ----
void registerAppliance(vector<Appliance>& appliances) {
    cout << "\n--- Register Appliance ---\n";
    string name = inputNonEmptyString("Appliance name: ");
    double power = inputPositiveDouble("Power rating (W): ");
    double hours = inputHours0to24("Daily usage (hours 0-24): ");

    appliances.emplace_back(name, power, hours);
    cout << "Saved: " << name << " (" << power << "W, " << hours << "h/day)\n";
}

void viewAppliances(const vector<Appliance>& appliances) {
    cout << "\n--- All Registered Appliances ---\n";
    if (appliances.empty()) {
        cout << "No appliances registered yet.\n";
        return;
    }

    cout << left
         << setw(5)  << "No."
         << setw(25) << "Name"
         << setw(12) << "Power(W)"
         << setw(12) << "Hours"
         << setw(12) << "kWh/day"
         << "\n";

    cout << string(65, '-') << "\n";

    for (size_t i = 0; i < appliances.size(); i++) {
        const auto& a = appliances[i];
        cout << left
             << setw(5)  << (i + 1)
             << setw(25) << a.getName()
             << setw(12) << fixed << setprecision(2) << a.getPowerW()
             << setw(12) << fixed << setprecision(2) << a.getHours()
             << setw(12) << fixed << setprecision(3) << a.dailyEnergyKwh()
             << "\n";
    }
}

void searchAppliance(const vector<Appliance>& appliances) {
    cout << "\n--- Search Appliance ---\n";
    if (appliances.empty()) {
        cout << "No appliances registered yet.\n";
        return;
    }

    string key = inputNonEmptyString("Enter name to search: ");

    bool found = false;
    for (const auto& a : appliances) {
        // simple case-insensitive search (basic)
        string n = a.getName();
        string k = key;
        for (char& c : n) c = (char)tolower(c);
        for (char& c : k) c = (char)tolower(c);

        if (n.find(k) != string::npos) {
            if (!found) {
                cout << "Found:\n";
                cout << left << setw(25) << "Name"
                     << setw(12) << "Power(W)"
                     << setw(12) << "Hours"
                     << setw(12) << "kWh/day" << "\n";
                cout << string(61, '-') << "\n";
            }
            found = true;
            cout << left << setw(25) << a.getName()
                 << setw(12) << fixed << setprecision(2) << a.getPowerW()
                 << setw(12) << fixed << setprecision(2) << a.getHours()
                 << setw(12) << fixed << setprecision(3) << a.dailyEnergyKwh()
                 << "\n";
        }
    }

    if (!found) cout << "No appliance matched: " << key << "\n";
}

int menu() {
    cout << "\n==============================\n";
    cout << " Electrical Load Monitoring\n";
    cout << "==============================\n";
    cout << "1. Register appliance\n";
    cout << "2. View all appliances\n";
    cout << "3. Search appliance by name\n";
    cout << "0. Exit\n";
    cout << "Choose: ";

    int choice;
    if (!(cin >> choice)) {
        clearBadInput();
        return -1; // invalid
    }
    clearBadInput();
    return choice;
}

int main() {
    vector<Appliance> appliances;

    while (true) {
        int choice = menu();

        switch (choice) {
            case 1:
                registerAppliance(appliances);
                break;
            case 2:
                viewAppliances(appliances);
                break;
            case 3:
                searchAppliance(appliances);
                break;
            case 0:
                cout << "Goodbye.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
