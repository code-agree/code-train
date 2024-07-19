#include <iostream>
#include <string>
#include "PostfixCalculator.h"

int main() {
    PostfixCalculator calculator;
    std::string input;

    while (true) {
        std::cout << "Enter a postfix expression (or 'exit' to quit): ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        try {
            double result = calculator.evaluate(input);
            std::cout << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}