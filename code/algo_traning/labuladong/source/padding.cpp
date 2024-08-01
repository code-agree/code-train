#include<iostream>



struct MyStruct {
    int a;
    double b;
    char c;
};


int main(){
    std::cout << sizeof(MyStruct) << std::endl;
    int arr[10];
    std::cout << sizeof(arr) << std::endl;
}