// file2.cpp
#include <iostream>

// 声明外部变量，这里我们可以访问file1.cpp中定义的globalVar
extern int globalVar;

// 静态全局变量，具有内部链接
static int staticVar = 30;

extern const int i = 1; 

void exampleFunction(int param) {
    // param 是函数参数
    int localVar = 40;  // 局部变量
    
    std::cout << "\nIn exampleFunction() of file2.cpp:" << std::endl;
    std::cout << "globalVar: " << globalVar << std::endl;
    std::cout << "staticVar: " << staticVar << std::endl;
    std::cout << "param: " << param << std::endl;
    std::cout << "localVar: " << localVar << std::endl;
    
    // 修改全局变量
    globalVar += 5;
    
    // 局部变量和参数在函数结束后就不再可访问
}