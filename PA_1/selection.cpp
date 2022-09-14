#include <stdexcept>
#include <iostream>
#include "selection.h"

const int __INT32_MIN__ = -__INT32_MAX__ - 1;

// slow but easy to make sorting alogirthm lol
int* sortList(int* list, size_t N){
    int* newList = new int[N];
    int highestNum = __INT32_MIN__;
    size_t highestIndex = 0;
    for(size_t i = 0; i < N; ++i){
        highestNum = __INT32_MIN__;
        highestIndex = 0;
        for(size_t j = 0; j < N; ++j){
            if (list[j] > highestNum){
                highestNum = list[j];
                highestIndex = j;
            }
        }
        newList[i] = highestNum;
        list[highestIndex] = __INT32_MIN__;
    }

    delete[] list;
    
    return newList;
}

int select(size_t k, const int* list, size_t N) {
    if(k > N || k == 0){
        throw std::invalid_argument("k exceeds the number of entries in the array");
    }
    if(N == 0){
        throw std::invalid_argument("Array is empty");
    }
    if(list == nullptr){
        throw std::invalid_argument("Array is empty");
    }

    int* copyList = new int[N];

    for(size_t i = 0; i < N; ++i){
        copyList[i] = list[i];
    }

    copyList = sortList(copyList, N);

    int selectedNum = copyList[k-1];

    delete[] copyList;

    return selectedNum;
}
