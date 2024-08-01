// file1.cpp
#include <iostream>

// 全局变量，具有外部链接
int globalVar = 10;

// 函数声明，具有外部链接
void exampleFunction(int param);

int main() {
    std::cout << "In main() of file1.cpp:" << std::endl;
    std::cout << "globalVar: " << globalVar << std::endl;
    
    exampleFunction(20);
    //fileA.cpp

    //fileB.cpp                    //声明
    extern const int i;
    std::cout << i << std::endl;


    
    return 0;
}

