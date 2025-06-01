
#include <iostream>  
#include <cmath>    
#include <thread>  
#include <chrono>   
#include <limits> 
#include <cctype>
#include <string> 
#include <iomanip>  

using namespace std;

// Clear screen 
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Wait function
void wait(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

// Loading animation
void loading(string msg = "Loading") {
    cout << "\033[1;33m\n\n  " << msg << flush;
    for (int i = 0; i < 3; i++) {
        wait(300);
        cout << "." << flush;
    }
    cout << "\033[0m" << endl;
    wait(500);
    clearScreen();
}

// Get number input
double getNumber(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\033[1;31mInvalid input! Please enter a number.\033[0m\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Get integer input
int getInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\033[1;31mInvalid choice! Please enter a number.\033[0m\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Section header
void printSectionHeader(const string& title) {
    cout << "\n\033[1;35m" << title << "\033[0m\n";
    cout << "\033[1;30m==========================================\033[0m\n";
}

// Result output
void printResult(double result) {
    cout << "\033[1;32m┌───────────────────────────────┐\033[0m\n";
    cout << "\033[1;32m│          RESULT: \033[1;36m";
    // the fixed-point notation with 2 decimal places
    cout << fixed << setprecision(2) << setw(10) << left << result;
    cout << "\033[1;32m   │\033[0m\n";
    cout << "\033[1;32m└───────────────────────────────┘\033[0m\n\n";
}

// Print creator header
void printCreatorHeader() {
    cout << "\033[1;36m┌───────────────────────────────────────┐\033[0m\n";
    cout << "\033[1;36m│    \033[1;35mCALCULATOR CREATED BY SIM12-MAKER\033[1;36m  │\033[0m\n";
    cout << "\033[1;36m└───────────────────────────────────────┘\033[0m\n\n";
}

// Simple calculator
void simpleCalculator() {
    clearScreen();
    printCreatorHeader();  // Added creator header
    
    cout << "\033[1;32m┌───────────────────────────────────────┐\033[0m\n";
    cout << "\033[1;32m│        \033[1;36mSIMPLE CALCULATOR\033[1;32m              │\033[0m\n";
    cout << "\033[1;32m└───────────────────────────────────────┘\033[0m\n";
    
    printSectionHeader("OPERATION TYPES");
    cout << " \033[33m1. Addition (+)\n";
    cout << " 2. Subtraction (-)\n";
    cout << " 3. Division (/)\n";
    cout << " 4. Multiplication (*)\033[0m\n";
    cout << "\033[1;30m==========================================\033[0m\n";
    
    int op = getInt("\n\033[1;34mChoose operation (1-4) :: \033[0m");
    if (op < 1 || op > 4) {
        cout << "\n\033[1;31mInvalid operation selected!\033[0m\n";
        cout << "\033[1;36mPress Enter to continue...\033[0m";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    
    double num1 = getNumber("\n\033[1;32mEnter first number :: \033[0m");
    double num2 = getNumber("\033[1;32mEnter second number :: \033[0m");
    double result = 0;
    bool valid = true;

    printSectionHeader("CALCULATION AREA");
    cout << " \033[1;33m" << num1 << " ";
    switch (op) {
        case 1:
            cout << "+";
            result = num1 + num2;
            break;
        case 2:
            cout << "-";
            result = num1 - num2;
            break;
        case 3:
            cout << "÷";
            if (num2 == 0) {
                cout << "\n\033[1;31mError: Division by zero!\033[0m\n";
                valid = false;
            } else {
                result = num1 / num2;
            }
            break;
        case 4:
            cout << "×";
            result = num1 * num2;
            break;
    }
    cout << " " << num2 << " = ?\033[0m\n";

    if (valid) {
        printResult(result);
    }
    
    cout << "\033[1;36mPress Enter to continue...\033[0m";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Area calculator
void areaCalculator() {
    const double PI = 3.141592653589793;
    clearScreen();
    printCreatorHeader();  //  creator header
    
    cout << "\033[1;32m┌───────────────────────────────────────┐\033[0m\n";
    cout << "\033[1;32m│       \033[1;36mAREA CALCULATOR\033[1;32m                 │\033[0m\n";  // Fixed title alignment
    cout << "\033[1;32m└───────────────────────────────────────┘\033[0m\n";
    
    printSectionHeader("SHAPE TYPES");
    cout << " \033[33m1. Square\n";
    cout << " 2. Triangle\n";
    cout << " 3. Rectangle\n";
    cout << " 4. Circle\033[0m\n";
    
    int shape = getInt("\n\033[1;34mChoose shape (1-4):: \033[0m");
    if (shape < 1 || shape > 4) {
        cout << "\033[1;31mInvalid shape selection!\033[0m\n";
        cout << "\033[1;36mPress Enter to continue...\033[0m";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    double area = 0;
    printSectionHeader("CALCULATION AREA");
    switch (shape) {
        case 1: {
            double side = getNumber("Enter side length:: ");
            cout << " \033[1;33mFormula: side × side\n";
            cout << " Calculation: " << side << " × " << side << "\033[0m\n";
            area = side * side;
            break;
        }
        case 2: {
            double base = getNumber("Enter base:: ");
            double height = getNumber("Enter height:: ");
            cout << " \033[1;33mFormula: (base × height) ÷ 2\n";
            cout << " Calculation: (" << base << " × " << height << ") ÷ 2\033[0m\n";
            area = 0.5 * base * height;
            break;
        }
        case 3: {
            double length = getNumber("Enter length:: ");
            double width = getNumber("Enter width:: ");
            cout << " \033[1;33mFormula: length × width\n";
            cout << " Calculation: " << length << " × " << width << "\033[0m\n";
            area = length * width;
            break;
        }
        case 4: {
            double radius = getNumber("Enter radius:: ");
            cout << " \033[1;33mFormula: π × radius²\n";
            cout << " Calculation: π × " << radius << "²\033[0m\n";
            area = PI * radius * radius;
            break;
        }
    }

    printResult(area);

    cout << "\033[1;36mPress Enter to continue...\033[0m";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Main menu
int main() {
    bool running = true;
    
    while (running) {
        clearScreen();
        printCreatorHeader();  //  creator header
   
        cout << "\033[1;32m┌─────────────────────────────────────┐\033[0m\n";
        cout << "\033[1;32m│          \033[1;36mCALCULATOR MENU\033[1;32m            │\033[0m\n";
        cout << "\033[1;32m├─────────────────────────────────────┤\033[0m\n";
        cout << "\033[1;34m│ 1. Simple Calculator                │\033[0m\n";
        cout << "\033[1;34m│ 2. Area Calculator                  │\033[0m\n";
        cout << "\033[1;34m│ 3. Exit                             │\033[0m\n";
        cout << "\033[1;32m└─────────────────────────────────────┘\033[0m\n";
        
        int choice = getInt("\n\033[1;36mEnter your choice (1-3):: \033[0m");
        
        switch (choice) {
            case 1:
                loading("Starting Simple Calculator");
                simpleCalculator();
                break;
            case 2:
                loading("Starting Area Calculator");
                areaCalculator();
                break;
            case 3:
                cout << "\n\033[1;32mContinue using calculator!\033[0m\n";
                running = false;
                break;
            default:
                cout << "\033[1;31mInvalid choice! Please try again.\033[0m\n";
                wait(1000);
        }
    }
    
    return 0;
}// end of main()

// This created by sim12-maker
// >>> https://github.com/Sim12-maker