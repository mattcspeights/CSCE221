#include <iostream>
#include "avl_tree.h"

using std::cout, std::endl;

int main() {
    AVLTree<int> test1;
    test1.insert(5);
    test1.insert(2);
    test1.insert(6);
    test1.print_tree();
    AVLTree test2 = test1;
    AVLTree test3(test1);
    test1.remove(6);
    test1.remove(5);
    test1.remove(2);
    test2.print_tree();
    cout << test3.find_max() << endl;
    cout << test3.find_min() << endl;
    if (test3.contains(2)){
        cout << "working" << endl;
    }
    test3.insert(10);
    test3.insert(1);
    test3.insert(7);
    test3.insert(8);
    test3.insert(3);
    test3.insert(9);
    test3.print_tree();

    test3.remove(5);
    test3.remove(8);
    test3.remove(2);
    test3.remove(1);
    test3.remove(3);
    test3.remove(6);
}
