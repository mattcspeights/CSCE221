#include "collection.h"
#include <iostream>

void printArray(int* list, size_t size){
    for (size_t i = 0; i < size; ++i){
        std::cout << list[i] << ", ";
    }
    std::cout << std::endl;
}

int main(){
    //testCollection 1
    Collection<int> testCollection;
    
    
}