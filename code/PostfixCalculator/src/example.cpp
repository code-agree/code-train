#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <stdexcept>
#include <cmath>
#include <iomanip>

class PostfixCalculator {
private:
    std::vector<double> stack;
    std::unordered_map<std::string, std::function<double(double, double)>> operators;

    void registerOperator(const std::string& op, std::function<double(double, double)> func) {
        operators[op] = func;
    }

    bool isOperator(const std::string& token) {
        if (operators.find(token) != operators.end()){
            return true;
        }
        return false;
    }

    bool isNumber(const std::string& token) {
        try {
            std::stod(token);
            return true;
        } catch (const std::invalid_argument&) {
            return false;
        } catch (const std::out_of_range&) {
            return false;
        }
    }

    void processOperator(const std::string& op) {
        if (stack.size() < 2) {
            throw std::runtime_error("Not enough operands");
        }
        double b = stack.back(); stack.pop_back();
        double a = stack.back(); stack.pop_back();
        auto it = operators.find(op);
        if (it == operators.end()) {
            throw std::runtime_error("Invalid operator");
        }
        
        stack.push_back(it->second(a, b));
    }

public:
    PostfixCalculator() {
        registerOperator("+", std::plus<double>());
        registerOperator("-", std::minus<double>());
        registerOperator("*", std::multiplies<double>());
        registerOperator("/", std::divides<double>());
        registerOperator("pow", [](double a, double b) { return std::pow(a, b); });
        registerOperator("sqrt", [](double a, double) { return std::sqrt(a); });
    }

    double evaluate(const std::string& expression) {
        std::istringstream iss(expression);
        std::string token;
        stack.clear();

        while (iss >> token) {
            if (isNumber(token)) {
                stack.push_back(std::stod(token));
            } else if (isOperator(token)) {
                processOperator(token);
            } else {
                throw std::runtime_error("Invalid operand");
            }
        }

        if (stack.size() > 1) {
            throw std::runtime_error("Too many operands");
        } else if (stack.empty()) {
            throw std::runtime_error("Not enough operands");
        }

        return stack.back();
    }
};

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