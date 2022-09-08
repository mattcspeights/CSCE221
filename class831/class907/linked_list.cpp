#include <iostream>
#include <string>
#include <stdexcept>
using std::cout, std::endl, std::string, std::ostream;

struct node{
    string myString;
    node* next;
};

class linkedList{
    size_t size;
    node* head;
    node* tail;

    public:

        void remove(size_t index){
        }

        void insert(size_t index){
            if (index >= this->size){
                throw std::out_of_range("Index out of bounds");
            }
            size_t count = 1;
            node* current = this->head;
            while(count < index){
                current = current->next;
                count++;
            }
        }

        size_t getSize(){
            return this->size;
        }


}