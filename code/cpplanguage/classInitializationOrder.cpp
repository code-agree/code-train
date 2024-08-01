#include <iostream>


class A {
public:
    A() { std::cout << "A constructor" << std::endl; }
};

class B : virtual public A {
public:
    B() { std::cout << "B constructor" << std::endl; }
};

class C : virtual public A {
public:
    C() { std::cout << "C constructor" << std::endl; }
};

class D : public B, public C {
private:
    int x;
    int y;
public:
    D() : y(10), x(5) {
        std::cout << "D constructor" << std::endl;
    }
};

int main() {
    D d;
    return 0;
}