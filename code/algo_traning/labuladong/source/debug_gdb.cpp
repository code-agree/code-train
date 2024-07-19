#include <vector>
#include <iostream>

void process_vector(std::vector<int>& vec) {
    for (int i = 0; i <= vec.size() + 10; i++) {  // 注意这里的 <= 可能导致越界
        vec[i] *= 2;
        std::cout << "Processing index " << i << " value " << vec[i] << std::endl;
    }
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    process_vector(numbers);
    return 0;
}