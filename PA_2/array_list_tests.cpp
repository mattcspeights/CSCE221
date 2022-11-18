#include <iostream>
#include "array_list.h"

int main() {
    ArrayList<int> test1;
    ArrayList<int> test3;

    if (test1.is_empty()){
        std::cout << "Correct Behavior for empty" << std::endl;
    }

    test1.insert(0, 1);
    test1.insert(1, 10);
    test1.insert(2, 20);
    test1.insert(3, 60);
    test1.insert(4, 55);

    ArrayList<int> test2(test1);
    ArrayList<int> test6(10);
    test3 = test1;

    try{
        test1.insert(20, 5);
    }catch(std::invalid_argument& exception){
        std::cout << "Correct Behavior" << std::endl;
    }

    try{
        test1.remove(20);
    }catch(std::invalid_argument& exception){
        std::cout << "Correct Behavior" << std::endl;
    }

    try{
        test1.remove(20);
    }catch(std::invalid_argument& exception){
        std::cout << "Correct Behavior" << std::endl;
    }

    test1.remove(0);


    for(size_t i = 0; i < test1.size(); ++i){
        std::cout << test1[i] << " ";
    }
    
    std::cout << std::endl;


    for(size_t i = 0; i < test3.size(); ++i){
        std::cout << test3[i] << " ";
    }
    std::cout << std::endl;

    test2 = test2;

    ArrayList<int> test4 = test2;
}
