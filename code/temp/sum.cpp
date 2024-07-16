#include <iostream>

int main(){
    int sum = 0, val = 1;
    while (val <= 100){
        sum += val;
        ++val;
    }
    std::cout << sum << std::endl;
    std::cout << "Hello, Worggggld!" << std::endl;
    return 0;
}