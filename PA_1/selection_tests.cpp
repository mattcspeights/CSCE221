#include "selection.cpp"

void printArray(const int* list, size_t size){
    for (int i = 0; i < size; ++i){
        std::cout << list[i] << ", ";
    }
    std::cout << std::endl;
}

int main(){
    //testSort 1
    int* sortTest1 = new int[6]{10, 30, 20, 60, 100, 5};

    sortList(sortTest1, 6);
    printArray(sortTest1, 6);

    delete[] sortTest1;
}