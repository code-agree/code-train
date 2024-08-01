#include<iostream>

class MyClass {
public:
    ~MyClass() {
        throw std::runtime_error("Exception from destructor");
    }
};

int main() {
    try {
        MyClass obj;
        // obj 在这里超出作用域，析构函数被调用
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}