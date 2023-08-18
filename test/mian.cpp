#include <iostream>

// 函数接受一个数组和数组的大小作为参数，并返回数组中元素的个数
template <typename T, size_t N>
size_t countElements(const T (&arr)[N]) {
    if(N == 0)
    return *arr;
    else{

    }
}

int main() {
    int myArray[] = {1};
    size_t elementCount = countElements(myArray);
    
    std::cout << "数组中元素的个数: " << elementCount << std::endl;

    return 0;
}
