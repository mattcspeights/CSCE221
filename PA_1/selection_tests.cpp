#include "selection.h"
#include <iostream>

void printArray(int* list, size_t size){
    for (size_t i = 0; i < size; ++i){
        std::cout << list[i] << ", ";
    }
    std::cout << std::endl;
}

int main(){
    //testSort 1
    int* sortTest1 = new int[6]{10, 30, 20, 60, 100, 5};
    int* sortTest2 = new int[6]{10, 30, 20, 60, 100, 5};


    int* sortedList = sortList(sortTest1, 6);
    printArray(sortedList, 6);

    std::cout << select(2, sortTest2, 6) << std::endl;

    delete[] sortedList;
    delete[] sortTest2;
}