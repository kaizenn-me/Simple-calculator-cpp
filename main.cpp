#include <iostream>
#include <curl/curl.h>
#include <cmath>  // Untuk fungsi pow() dan log10()

using namespace std;

// Function prototypes
size_t writeCallback(void* contents, size_t size, size_t nmemb, string* s);
void getCurrencyExchange();
void molecularWeight();
void stoichiometry();
void molarity();
void reactionRate();
void gibbsFreeEnergy();
void nernstEquation();
void bodyMassIndex();
void compoundInterest();
void decimalToBinary();
void asciiToChar();
void charToAscii();
void kineticEnergy();
void menu();

size_t writeCallback(void* contents, size_t size, size_t nmemb, string* s) {
    size_t newLength = size * nmemb;
    try {
        s->append((char*)contents, newLength);
    } catch (std::bad_alloc& e) {
        return 0;
    }
    return newLength;
}

// API for currency exchange
void getCurrencyExchange() {
    CURL* curl;
    CURLcode res;
    string responseString;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        string apiUrl = "https://api.exchangerate-api.com/v4/latest/USD";
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseString);
        
        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        else
            cout << "API Response: " << responseString << endl;

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

// Chemistry calculators
void molecularWeight() {
    double weight;
    cout << "Enter the molecular weight (in g/mol): ";
    cin >> weight;
    cout << "Molecular weight is: " << weight << " g/mol" << endl;
}

void stoichiometry() {
    double reactant, product;
    cout << "Enter the mass of the reactant (in grams): ";
    cin >> reactant;
    cout << "Enter the molar mass of the product (in g/mol): ";
    cin >> product;
    double moles = reactant / product;
    cout << "The number of moles is: " << moles << endl;
}

void molarity() {
    double solute, volume;
    cout << "Enter the amount of solute (in moles): ";
    cin >> solute;
    cout << "Enter the volume of solution (in liters): ";
    cin >> volume;
    double concentration = solute / volume;
    cout << "The molarity of the solution is: " << concentration << " M" << endl;
}

void reactionRate() {
    double concentration, time;
    cout << "Enter the change in concentration (in mol/L): ";
    cin >> concentration;
    cout << "Enter the change in time (in seconds): ";
    cin >> time;
    double rate = concentration / time;
    cout << "The rate of the reaction is: " << rate << " mol/L/s" << endl;
}

void gibbsFreeEnergy() {
    double deltaH, deltaS, temp;
    cout << "Enter the change in enthalpy (delta H, in kJ/mol): ";
    cin >> deltaH;
    cout << "Enter the change in entropy (delta S, in J/mol*K): ";
    cin >> deltaS;
    cout << "Enter the temperature (in Kelvin): ";
    cin >> temp;
    double deltaG = deltaH - (temp * deltaS / 1000);
    cout << "The Gibbs Free Energy is: " << deltaG << " kJ/mol" << endl;
}

void nernstEquation() {
    double E0, concentrationOx, concentrationRed;
    cout << "Enter the standard electrode potential (E0, in volts): ";
    cin >> E0;
    cout << "Enter the concentration of the oxidant (in mol/L): ";
    cin >> concentrationOx;
    cout << "Enter the concentration of the reductant (in mol/L): ";
    cin >> concentrationRed;
    double E = E0 + (0.059 / 1) * log10(concentrationOx / concentrationRed);
    cout << "The cell potential (E) is: " << E << " volts" << endl;
}

// Programming calculators
void decimalToBinary() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;
    cout << "Binary representation: ";
    for (int i = 31; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

void asciiToChar() {
    int ascii;
    cout << "Enter an ASCII value: ";
    cin >> ascii;
    cout << "Character: " << char(ascii) << endl;
}

void charToAscii() {
    char c;
    cout << "Enter a character: ";
    cin >> c;
    cout << "ASCII value: " << int(c) << endl;
}

// Bio laboratory calculators
void bodyMassIndex() {
    double weight, height;
    cout << "Enter your weight (in kg): ";
    cin >> weight;
    cout << "Enter your height (in meters): ";
    cin >> height;
    double bmi = weight / (height * height);
    cout << "Your BMI is: " << bmi << endl;
}

// Finance calculators
void compoundInterest() {
    double principal, rate, time, timesCompounded;
    cout << "Enter the principal amount: ";
    cin >> principal;
    cout << "Enter the annual interest rate (in %): ";
    cin >> rate;
    cout << "Enter the time in years: ";
    cin >> time;
    cout << "Enter the number of times interest is compounded per year: ";
    cin >> timesCompounded;
    double amount = principal * pow((1 + rate / (100 * timesCompounded)), timesCompounded * time);
    cout << "The total amount after interest is: " << amount << endl;
}

// Physics calculators
void kineticEnergy() {
    double mass, velocity;
    cout << "Enter the mass (in kg): ";
    cin >> mass;
    cout << "Enter the velocity (in m/s): ";
    cin >> velocity;
    double energy = 0.5 * mass * velocity * velocity;
    cout << "The kinetic energy is: " << energy << " J" << endl;
}

// Main menu
void menu() {
    int choice;
    do {
        cout << "\n--- Comprehensive Calculator ---\n";
        cout << "1. Molecular Weight (Chemistry)\n";
        cout << "2. Stoichiometry (Chemistry)\n";
        cout << "3. Molarity (Chemistry)\n";
        cout << "4. Reaction Rate (Chemistry)\n";
        cout << "5. Gibbs Free Energy (Thermodynamics)\n";
        cout << "6. Nernst Equation (Electrochemistry)\n";
        cout << "7. Body Mass Index (Bio Lab)\n";
        cout << "8. Compound Interest (Finance)\n";
        cout << "9. Kinetic Energy (Physics)\n";
        cout << "10. Decimal to Binary (Programming)\n";
        cout << "11. ASCII to Char (Programming)\n";
        cout << "12. Char to ASCII (Programming)\n";
        cout << "13. Currency Exchange Rate (API)\n";
        cout << "14. Copyright Information\n";
        cout << "15. Exit\n";
        cout << "Select an option (1-15): ";
        cin >> choice;

        switch (choice) {
            case 1: molecularWeight(); break;
            case 2: stoichiometry(); break;
            case 3: molarity(); break;
            case 4: reactionRate(); break;
            case 5: gibbsFreeEnergy(); break;
            case 6: nernstEquation(); break;
            case 7: bodyMassIndex(); break;
            case 8: compoundInterest(); break;
            case 9: kineticEnergy(); break;
            case 10: decimalToBinary(); break;
            case 11: asciiToChar(); break;
            case 12: charToAscii(); break;
            case 13: getCurrencyExchange(); break;
            case 14: 
                cout << "\n--- Copyright Information ---\n";
                cout << "This calculator was developed by Kaizenn-me.\n";
                cout << "All rights reserved © 2024.\n";
                break;
            case 15: cout << "Exiting...\n"; break;
            default: cout << "Invalid option. Please try again.\n"; break;
        }
    } while (choice != 15);  
}
