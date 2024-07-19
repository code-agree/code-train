#include "PostfixCalculator.h"
#include <sstream>
#include <stdexcept>
#include <cmath>

void PostfixCalculator::registerOperator(const std::string& op, std::function<double(double, double)> func) {
    operators[op] = func;
}

bool PostfixCalculator::isOperator(const std::string& token) {
    return operators.find(token) != operators.end();
}

bool PostfixCalculator::isNumber(const std::string& token) {
    try {
        std::stod(token);
        return true;
    } catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        return false;
    }
}

void PostfixCalculator::processOperator(const std::string& op) {
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

PostfixCalculator::PostfixCalculator() {
    registerOperator("+", std::plus<double>());
    registerOperator("-", std::minus<double>());
    registerOperator("*", std::multiplies<double>());
    registerOperator("/", std::divides<double>());
    registerOperator("pow", [](double a, double b) { return std::pow(a, b); });
    registerOperator("sqrt", [](double a, double) { return std::sqrt(a); });
}

double PostfixCalculator::evaluate(const std::string& expression) {
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