#include <list>
// template <typename T>
// struct node{
//     node* next;
//     T value;
// };

// template <typename T>
// class linkedlist{
//     node* head;
//     node* tail;
//     size_t size;

//     public:
//         size_t getSize(){
//             return this->size;
//         }

//         node getHead(){
//             return this->head;
//         }
// };

template <typename T>
class stack{
    std::list<T> list;
    
    public:
        T pop(){
            T top = this->list.front;
            this->list.pop_front();
            return top;
        }

};