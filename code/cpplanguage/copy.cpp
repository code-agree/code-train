#include <iostream>
#include <cstring>

class DeepCopyString {
private:
    char* data;

public:
    // 构造函数
    DeepCopyString(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        std::cout << "Constructor called" << std::endl;
    }

    // 析构函数
    ~DeepCopyString() {
        delete[] data;
        std::cout << "Destructor called" << std::endl;
    }

    // 复制构造函数实现深拷贝
    DeepCopyString(const DeepCopyString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        std::cout << "Copy constructor (deep copy) called" << std::endl;
    }

    // 赋值运算符实现深拷贝
    DeepCopyString& operator=(const DeepCopyString& other) {
        if (this != &other) {
            delete[] data;  // 释放原有资源
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        std::cout << "Assignment operator (deep copy) called" << std::endl;
        return *this;
    }

    void print() const {
        std::cout << data << std::endl;
    }

    // 添加一个修改内容的方法用于测试
    void modify(const char* newStr) {
        delete[] data;
        data = new char[strlen(newStr) + 1];
        strcpy(data, newStr);
    }

    // 添加一个获取内部数据地址的方法用于测试
    const char* getAddress() const {
        return data;
    }
};

int main() {
    // 测试复制构造函数的深拷贝
    {
        DeepCopyString s1("Hello");
        DeepCopyString s2 = s1;  // 使用复制构造函数

        std::cout << "Before modification:" << std::endl;
        std::cout << "s1: "; s1.print();
        std::cout << "s2: "; s2.print();
        std::cout << "s1 address: " << (void*)s1.getAddress() << std::endl;
        std::cout << "s2 address: " << (void*)s2.getAddress() << std::endl;

        s1.modify("Modified Hello");

        std::cout << "After modifying s1:" << std::endl;
        std::cout << "s1: "; s1.print();
        std::cout << "s2: "; s2.print();
    }

    std::cout << "\n------------------------\n" << std::endl;

    // 测试赋值运算符的深拷贝
    {
        DeepCopyString s3("World");
        DeepCopyString s4("Test");
        s4 = s3;  // 使用赋值运算符

        std::cout << "Before modification:" << std::endl;
        std::cout << "s3: "; s3.print();
        std::cout << "s4: "; s4.print();
        std::cout << "s3 address: " << (void*)s3.getAddress() << std::endl;
        std::cout << "s4 address: " << (void*)s4.getAddress() << std::endl;

        s3.modify("Modified World");

        std::cout << "After modifying s3:" << std::endl;
        std::cout << "s3: "; s3.print();
        std::cout << "s4: "; s4.print();
    }

    return 0;
}