#include <iostream>
#include <cstdlib>
#include <gperftools/heap-checker.h>

void leakyFunction() {
    int* ptr = new int[100];  // 分配内存但不释放
}

int main() {
    HeapLeakChecker heap_checker("global");  // 启动堆检查

    std::cout << "Starting program..." << std::endl;
    
    for (int i = 0; i < 10; ++i) {
        leakyFunction();  // 调用10次,每次都会泄漏内存
    }

    std::cout << "Program finished." << std::endl;

    // 检查是否有泄漏
    if (!heap_checker.NoLeaks()) std::cout << "Memory leaks detected!" << std::endl;
    
    return 0;
}