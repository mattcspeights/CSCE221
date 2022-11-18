#include "collection.h"
#include <iostream>

int main(){
    //testCollection 1
    Collection<int> testCollection;

    Collection<int> testCollection2;
    
    testCollection.insert(8);
    testCollection.insert(20);
    testCollection.insert(40);
    testCollection.insert(30);
    testCollection.insert(50);
    testCollection.insert(24);
    testCollection.insert(28);
    testCollection.insert(29);
    if (testCollection.contains(8)){
        testCollection.remove(8);
    }

    testCollection2 = testCollection;

    testCollection.remove(20);
    testCollection.remove(40);
    testCollection.remove(30);
    testCollection.remove(50);
    testCollection.remove(24);
    testCollection.remove(28);
    testCollection.remove(29);
    for(size_t i = 0; i < testCollection.size(); ++i){
        std::cout << testCollection2.returnIndex(i) << " ";
    }

    std::cout << std::endl << "Done Testing" << std::endl;

    
    
}