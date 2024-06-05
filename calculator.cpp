#include <iostream>
#include <cstring>
using namespace std;

class Calculator {
public:
    void run() {
        char operation[10];
        double num1, num2;

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter operator (+, -, *, /, %, ^): ";
        cin >> operation;
        cout << "Enter second number: ";
        cin >> num2;

        try {
            double result = calculate(num1, num2, operation);
            cout << "Result: " << result << endl;
        }
        catch (const char* msg) {
            cerr << "Error: " << msg << endl;
        }
    }

private:
    double calculate(double num1, double num2, const char* operation) {
        if (strcmp(operation, "+") == 0) {
            return add(num1, num2);
        }
        else if (strcmp(operation, "-") == 0) {
            return subtract(num1, num2);
        }
        else if (strcmp(operation, "*") == 0) {
            return multiply(num1, num2);
        }
        else if (strcmp(operation, "/") == 0) {
            return divide(num1, num2);
        }
        else if (strcmp(operation, "%") == 0) {
            return static_cast<int>(num1) % static_cast<int>(num2);
        }
        else if (strcmp(operation, "^") == 0) {
            return power(num1, static_cast<int>(num2));
        }
        else {
            cout<< "Invalid operator";
        }
    }

    double add(double num1, double num2) {
        return num1 + num2;
    }

    double subtract(double num1, double num2) {
        return num1 - num2;
    }

    double multiply(double num1, double num2) {
        return num1 * num2;
    }

    double divide(double num1, double num2) {
        if (num2 == 0) {
            throw "Division by zero";
        }
        return num1 / num2;
    }

    double power(double base, int exponent) {
        if (exponent == 0) {
            return 1;
        }
        else if (exponent < 0) {
            return 1 / power(base, -exponent);
        }
        else {
            return base * power(base, exponent - 1);
        }
    }
};

int main() {
    Calculator calc;
    char choice;

    do {
        calc.run();
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Goodbye!" << std::endl;
    return 0;
}
