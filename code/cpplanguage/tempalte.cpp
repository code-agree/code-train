#include<iostream>
template <typename T, typename U>

T add(T a, U b){
    return a + b;
}


int main(){
    int const a = 10;
    const int *p = &a;
    int *q = const_cast<int*>(p);
    *q = 20;
    // a = 20;
    std::cout << a << std::ends;
    return 0;
}