#include "sorts.h"

int main() {
    std::vector<unsigned> testInsert1;
    std::vector<std::string> testInsert2;
    testInsert1.push_back(81);
    testInsert1.push_back(94);
    testInsert1.push_back(11);
    testInsert1.push_back(96);
    testInsert1.push_back(12);
    testInsert1.push_back(35);
    testInsert1.push_back(17);
    testInsert1.push_back(95);
    testInsert1.push_back(28);
    testInsert1.push_back(58);
    testInsert1.push_back(41);
    testInsert1.push_back(75);
    testInsert1.push_back(15);
    std::vector<unsigned> testInsert3 = testInsert1;
    std::vector<unsigned> test1 = testInsert1;
    std::vector<unsigned> test2 = testInsert1;
    std::vector<unsigned> test3;
    for (int i = 30; i > 0; i--){
        test3.push_back(i);
    }

    // insertion_sort(testInsert1);
    // shell_sort(testInsert3);
    // heap_sort(testInsert1);
    // merge_sort(testInsert1);
    // bucket_sort(testInsert1);
    // radix_sort(testInsert1);
    // radix_sort(testInsert2);
    
    // merge_sort(test1);
    // quick_sort(test2);
    quick_sort(test3);

    return 0;
}
