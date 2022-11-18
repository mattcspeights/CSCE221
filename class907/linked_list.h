#include <iostream>
#include <stdexcept>
using std::cout, std::endl;

template<typename T>
struct node{
    node* next;
    node* prev;
    T value;

    public:
        node<T>(const node<T>& other): next{}, prev{}, value(other.value){}

};

template<typename T>
class linkedlist{
    node<T>* head;
    node<T>* tail;
    size_t size;
    
    public:
        linkedlist<T>(): head{}, tail{}, size(0){}

        ~linkedlist<T>(){
            node<T>* temp = head;
            while(head != nullptr){
                head = head->next;
                delete temp;
                temp = head;
            }

            tail = nullptr;
        }

        linkedlist<T>(const linkedlist<T>& other): head{}, tail{}, size(0){
            node<T>* temp1 = new node<T>(other.head);
            node<T>* temp2 = other.head;
            head = temp1;
            temp1->next = nullptr;
            while(temp2 != nullptr){
                temp2 = temp2->next;
                node<T>* newNode = new node(*temp2);
                temp1->next = newNode;
                newNode->prev = temp1;
            }
            size = other.size;
        }

        linkedlist<T>& operator=(const linkedlist<T>& other){
            if (this != &other){
                this->~linkedlist();
                if (other.head == nullptr){
                    head = nullptr;
                    return *this;
                }
                node<T>* temp1 = new node<T>(*other.head);
                node<T>* temp2 = other.head;
                head = temp1;
                temp1->next = nullptr;
                while(temp2 != nullptr){
                    temp2 = temp2->next;
                    node<T>* newNode = new node(*temp2);
                    temp1->next = newNode;
                    newNode->prev = temp1;
                }
                size = other.size;
            }

            return *this;
        }

        void insert(const T& value){
            
        }

};