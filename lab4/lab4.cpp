#include <iostream>

int main() {
    int* val = new int[4]; 
    int* same_mem = val; 
    std::cout << "val: " << val << " same_mem: " << same_mem << std::endl;

    
    delete[] val; 
    //call func
    int* ptr = getIntPtr();
    std::cout << ptr << " " << *ptr << std::endl;

    return 0;
}

int* getIntPtr() {
    int number = 5;
    return &number;
}