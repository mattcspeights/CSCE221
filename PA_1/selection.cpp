#include <stdexcept>
#include <iostream>
#include "selection.h"

const int __INT32_MIN__ = -__INT32_MAX__ - 1;

// slow but easy to make sorting alogirthm lol
void sortList(int* &list, size_t N){
    int* newList = new int[N];
    int highestNum = __INT32_MIN__;
    size_t highestIndex = 0;
    for(int i = 0; i < N; ++i){
        highestNum = __INT32_MIN__;
        highestIndex = 0;
        for(int j = 0; j < N; ++j){
            if (list[j] > highestNum){
                highestNum = list[j];
                highestIndex = j;
            }
        }
        newList[i] = highestNum;
        list[highestIndex] = __INT32_MIN__;
    }

    delete[] list;
    list = newList;
}

int select(size_t k, const int* list, size_t N) {
    // TODO(student): solve the selection problem
    return N;
}
