#ifndef POSTFIX_CALCULATOR_H
#define POSTFIX_CALCULATOR_H

#include <string>
#include <vector>
#include <functional>
#include <unordered_map>

class PostfixCalculator {
private:
    std::vector<double> stack;
    std::unordered_map<std::string, std::function<double(double, double)>> operators;

    void registerOperator(const std::string& op, std::function<double(double, double)> func);
    bool isOperator(const std::string& token);
    bool isNumber(const std::string& token);
    void processOperator(const std::string& op);

public:
    PostfixCalculator();
    double evaluate(const std::string& expression);
};

#endif // POSTFIX_CALCULATOR_H