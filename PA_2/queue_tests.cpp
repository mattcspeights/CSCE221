#include <iostream>
#include "queue.h"

int main() {
    Queue<int> test1;

    test1.enqueue(1);
    test1.enqueue(25);
    test1.enqueue(14);
    test1.enqueue(69);

    Queue<int> test2 = test1;

    Queue<int> test3(test1);
    
    std::cout << test1.size() << std::endl;

    std::cout << test1.front() << std::endl;
    
    std::cout << test1.dequeue() << std::endl;
}
