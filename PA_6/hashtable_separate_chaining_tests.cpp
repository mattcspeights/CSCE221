#include "hashtable_separate_chaining.h"

int main() {
    HashTable<int> test1;
    test1.insert(20);
    test1.insert(21);
    test1.insert(31);
    test1.insert(2);
    test1.insert(12);
    test1.insert(26);
    test1.insert(23);
    test1.insert(35);
    test1.insert(6);
    test1.insert(15);
    test1.insert(29);
    test1.insert(14);
    test1.insert(38);
    test1.insert(3);
    test1.insert(17);
    test1.insert(22);
    test1.insert(9);
    test1.insert(18);
    test1.insert(4);
    test1.insert(40);
    test1.insert(50);
    test1.insert(45);
    test1.insert(52);
    test1.insert(89);
    test1.insert(99);
    test1.remove(99);
    test1.print_table();

    HashTable<int> test3(test1);

    HashTable<int> test4 = test1;

    HashTable<size_t> test2;

    test2.insert(6);
    test2.insert(1);
    test2.insert(10);

    //****using test example from prompt****
    std::cout << "make an empty hash table with 11 buckets for strings" << std::endl;
    HashTable<std::string> table(11);

    std::cout << "initial size is " << table.size() << std::endl;
    std::cout << "initial bucket count is " << table.bucket_count() << std::endl;
    std::cout << "initial load factor is " << table.load_factor() << std::endl;
    std::cout << "initial max load factor is " << table.max_load_factor() << std::endl;

    std::cout << "insert several strings" << std::endl;   
    table.insert("And them who hold High Places");
    table.insert("Must be the ones to start");
    table.insert("To mold a new Reality");
    table.insert("Closer to the Heart");
    table.insert("The Blacksmith and the Artist");
    table.insert("Reflect it in their Art");
    table.insert("Forge their Creativity");
    table.insert("Closer to the Heart");
    table.insert("Philosophers and Plowmen");
    table.insert("Each must know their Part");
    table.insert("To sow a new Mentality");
    table.insert("Closer to the Heart");
    table.insert("You can be the Captain");
    table.insert("I will draw the Chart");
    table.insert("Sailing into Destiny");
    table.insert("Closer to the Heart");

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "bucket count is " << table.bucket_count() << std::endl;
    std::cout << "load factor is " << table.load_factor() << std::endl;
    std::cout << "max load factor is " << table.max_load_factor() << std::endl;

    {
        std::cout << "print the table" << std::endl;
        std::stringstream ss;
        table.print_table(ss);
        std::cout << ss.str() << std::endl;
    }

    std::cout << "remove \"Philosophers and Plowmen\"" << std::endl;
    table.remove("Philosophers and Plowmen");
    std::cout << "remove \"Each must know their Part\"" << std::endl;
    table.remove("Each must know their Part");

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "bucket count is " << table.bucket_count() << std::endl;
    std::cout << "load factor is " << table.load_factor() << std::endl;
    std::cout << "max load factor is " << table.max_load_factor() << std::endl;

    {
        std::cout << "print the table" << std::endl;
        std::stringstream ss;
        table.print_table(ss);
        std::cout << ss.str() << std::endl;
    }

    std::cout << "set max load factor to 2" << std::endl;
    table.max_load_factor(2);
    std::cout << "rehash the table to size 7" << std::endl;
    table.rehash(7);

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "bucket count is " << table.bucket_count() << std::endl;
    std::cout << "load factor is " << table.load_factor() << std::endl;
    std::cout << "max load factor is " << table.max_load_factor() << std::endl;

    {
        std::cout << "print the table" << std::endl;
        std::stringstream ss;
        table.print_table(ss);
        std::cout << ss.str() << std::endl;
    }

    std::cout << "find \"The Blacksmith and the Artist\"" << std::endl;
    size_t index = table.bucket("The Blacksmith and the Artist");
    std::cout << " ==> bucket " << index << std::endl;
    std::cout << "     which has " << table.bucket_size(index) << " elements" << std::endl;

    std::cout << "make the table empty" << std::endl;
    table.make_empty();

    std::cout << "size is " << table.size() << std::endl;
    std::cout << "bucket count is " << table.bucket_count() << std::endl;
    std::cout << "load factor is " << table.load_factor() << std::endl;
    std::cout << "max load factor is " << table.max_load_factor() << std::endl;

    {
        std::cout << "print the table" << std::endl;
        std::stringstream ss;
        table.print_table(ss);
        std::cout << ss.str() << std::endl;
    }

    return 0;
}
