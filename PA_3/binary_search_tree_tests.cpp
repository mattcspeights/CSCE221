#include <iostream>
#include "binary_search_tree.h"

using std::cout, std::endl;

int main() {
    BinarySearchTree<int> test1;
    test1.insert(5);
    test1.insert(2);
    test1.insert(6);
    test1.print_tree();
    BinarySearchTree test2 = test1;
    BinarySearchTree test3(test1);
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

    BinarySearchTree<int> test4;
    test4.insert(5);
    test4.insert(2);
    test4.insert(8);
    // test4.insert(1);
    // test4.insert(3);
    test4.insert(7);
    test4.insert(9);
    test4.insert(12);
    test4.insert(6);
    // test4.insert(4);
    test4.insert(90);
    // test4.insert(0);
    test4.insert(22);
    test4.insert(18);
    // BinarySearchTree<int> test5(test4);
    test4.remove(8);
    // test4.remove(5);
    // test5.remove(9);
    // test5.remove(5);
    // test5 = test4;
    // test4.remove(1);
    // test4.remove(3);
    // test5.remove(7);
    // test5.remove(2);
    // test5 = test5;
    // test5.remove(18);
    // test5.remove(90);
    // test5.makeEmpty();
    // test5.insert(5);
    // test5.insert(2);
    // test5.insert(8);
    // test5.insert(1);
    // test5.makeEmpty();
}
