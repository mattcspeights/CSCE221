#include <iostream>
#include "stack.h"

int main() {
    Stack<int> test1;

    test1.push(1);
    test1.push(5);
    test1.push(4);

    Stack<int> test2 = test1;

    Stack<int> test3(test2);

    std::cout << test1.top() << std::endl;

    test1.pop();

    std::cout << test1.size() << std::endl;


}
