#include <iostream>
#include "doubly_linked_list.h"

int main() {
    DoublyLinkedList<int> testList1;
    testList1.insert(0, 6);
    std::cout << testList1.size() << std::endl;
    testList1.insert(1, 3);
    testList1.insert(2, 4);
    testList1.remove(1);
    testList1.insert(2, 4);
    testList1.insert(0, 4);
    testList1.insert(3, 20);
    std::cout << testList1[testList1.size() - 1] << std::endl;

    DoublyLinkedList<int> testList2(testList1);

    DoublyLinkedList<int> testList3 = testList1;    

    std::cout << testList2[testList2.size() - 1] << std::endl;

    std::cout << testList1.size() << std::endl; 

    std::cout << testList1.getTail() << std::endl;

    testList1.remove(testList1.size() - 1);
    testList1.remove(0);
    testList1.remove(1);

    while(testList1.size() != 0){
        std::cout << testList1[0] << std::endl;
        testList1.remove(0);
    }

    try{
        testList1.remove(20);
    }catch(std::out_of_range& exception){
        std::cout << "Correct Behavior" << std::endl;
    }

    testList2.insert(0, 1);
    testList1.insert(0, 3);
    testList1 = testList2;
    
}