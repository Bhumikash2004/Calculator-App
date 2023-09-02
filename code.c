#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
using namespace std;
class Calculator {
public:
    void run() {
        std::cout << "Welcome to Beautiful Console Calculator!" << std::endl;
        
        while (true) {
            displayCalculator();
            
            std::cout << "Enter an operator (+, -, *, /) or 'q' to quit: ";
            char op;
            std::cin >> op;
            
            if (op == 'q') {
                break;
            }
            
            if (isValidOperator(op)) {
                double operand1, operand2;
                std::cout << "Enter a: ";
                std::cin >> operand1;
                
                std::cout << "Enter b: ";
                std::cin >> operand2;
                
                try {
                    double result = calculate(operand1, operand2, op);
                    displayAnswer(result);
                } catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
            } else {
                std::cout << "Invalid operator. Please enter +, -, *, or /." << std::endl;
            }
        }
        
        std::cout << "Thank you for using Beautiful Console Calculator!" << std::endl;
    }

private:
    bool isValidOperator(char op) {
        return op == '+' || op == '-' || op == '*' || op == '/';
    }

    double calculate(double operand1, double operand2, char op) {
        switch (op) {
            case '+':
                return operand1 + operand2;
            case '-':
                return operand1 - operand2;
            case '*':
                return operand1 * operand2;
            case '/':
                if (operand2 == 0) {
                    throw std::runtime_error("Division by zero");
                }
                return operand1 / operand2;
            default:
                throw std::invalid_argument("Invalid operator");
        }
    }

    void displayCalculator() {
        std::cout << "             ┌──────────────────┐" << std::endl;
        std::cout << "             │──────────────────│" << std::endl;
        std::cout << "             │     7  8  9  /   │" << std::endl;
        std::cout << "             │     4  5  6  x   │" << std::endl;
        std::cout << "             │     1  2  3  -   │" << std::endl;
        std::cout << "             │     C  0  =  +   │" << std::endl;
        std::cout << "             └──────────────────┘" << std::endl;
    }

    void displayAnswer(double ans) {
        cout<<endl<<endl;
        std::cout << "┌────────────────────────────────┐" << std::endl;
        std::cout << "│ Answer: " << std::setw(22) << ans << " │" << std::endl;
        std::cout << "└────────────────────────────────┘" << std::endl;
        std::cout << "Press enter to continue...";
        std::cin.ignore();
        std::cin.get();
    }
};

int main() {
    Calculator calculator;
    calculator.run();
    return 0;
}

