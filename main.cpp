#include <iostream>
#include "calculator.h"
using namespace std;

int main() {
    Calculator calc;
    char choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Square Root" << endl;
        cout << "2. Natural Logarithm" << endl;
        cout << "3. Power" << endl;
        cout << "4. Factorial" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                double number;
                cout << "Enter a number: ";
                cin >> number;
                cout << "Square root of " << number << " is: " << calc.squareRoot(number) << endl;
                break;
            }
            case '2': {
                double number;
                cout << "Enter a number: ";
                cin >> number;
                cout << "Natural logarithm of " << number << " is: " << calc.naturalLog(number) << endl;
                break;
            }
            case '3': {
                int base, exponent;
                cout << "Enter base: ";
                cin >> base;
                cout << "Enter exponent: ";
                cin >> exponent;
                cout << base << " raised to the power of " << exponent << " is: " << calc.power(base, exponent) << endl;
                break;
            }
            case '4': {
                int n;
                cout << "Enter a number: ";
                cin >> n;
                cout << "Factorial of " << n << " is: " << calc.factorial(n) << endl;
                break;
            }
            case '5': {
                cout << "Exiting program..." << endl;
                break;
            }
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }

    } while (choice != '5');

    return 0;
}
