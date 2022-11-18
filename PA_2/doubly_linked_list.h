#pragma once
#include <cstddef>
#include <stdexcept>
template<typename T>
struct Node{
    Node* next;
    Node* prev;
    T value;

    Node(const Node& other): next(0), prev(0), value(other.value){}
    Node(T value): next(0), prev(0), value(value){}
};

template <typename T>
class DoublyLinkedList {
    Node<T>* head;
    Node<T>* tail;
    size_t list_size;

    public:
        DoublyLinkedList(): head(nullptr), tail(nullptr), list_size(0){}

        ~DoublyLinkedList(){
            Node<T>* helper = head;
            while(helper != nullptr){
                head = head->next;
                delete helper;
                helper = head;
            }
        }

        size_t size() const{
            return this->list_size;
        }

        DoublyLinkedList(const DoublyLinkedList<T>& other): head(nullptr), tail(nullptr), list_size(other.list_size){
            Node<T>* n1 = 0;
            Node<T>* n2 = 0;
            Node<T>* newNode;
            if (other.head == 0){
                head = 0;
            }
            else{
                newNode = new Node<T>(*other.head);
                head = newNode;
                n1 = newNode;
                n2 = other.head->next;
            }
            while(n2 != nullptr){
                newNode = new Node<T>(*n2);
                n1->next = newNode;
                newNode->prev = n1;
                n1 = n1->next;
                n2 = n2->next;
                if (n2 == nullptr){
                    tail = newNode;
                    newNode->next = nullptr;
                }
            }

        }

        DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other){
            if (this == &other){
                return *this;
            }
            if (this->head != 0){
                Node<T>* helper = head;
                while(helper != nullptr){
                    head = head->next;
                    delete helper;
                    helper = head;
                }
            }

            // Node<T>* n1 = other.head;
            // while(n1 != 0){
            //     this->insert(list_size, n1->value);
            //     n1 = n1->next;
            // }
            Node<T>* n1 = 0;
            Node<T>* n2 = 0;
            Node<T>* newNode;
            if (other.head == 0){
                head = 0;
            }
            else{
                newNode = new Node<T>(*other.head);
                head = newNode;
                tail = newNode;
                n1 = newNode;
                n2 = other.head->next;
            }
            while(n2 != nullptr){
                newNode = new Node<T>(*n2);
                n1->next = newNode;
                newNode->prev = n1;
                n1 = n1->next;
                n2 = n2->next;
            }

            list_size = other.list_size;

            return *this;
        }

        void insert(size_t index, const T& object){
            if (index > this->list_size){
                throw std::out_of_range("Index out of range");
            }

            Node<T>* newNode = new Node(object);
            Node<T>* n1 = 0;

            if (index == 0){
                if (head != 0){
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                }
                else{
                    head = newNode;
                    tail = newNode;
                }
            }
            else if (index == list_size){
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else{
                n1 = head;
                for (size_t i = 0; i < index - 1; ++i){
                    n1 = n1->next;
                }
                newNode->prev = n1;
                newNode->next = n1->next;
                n1->next->prev = newNode;
                n1->next = newNode;
            }

            this->list_size++;
        }

        void remove(size_t index){
            if (index >= this->list_size || this->list_size == 0){
                throw std::out_of_range("Index out of range");
            }
            
            Node<T>* n1 = this->head;

            if (index == 0){
                n1 = this->head;
                this->head = head->next;
                delete n1;
                n1 = 0;
            }
            else if (index == this->list_size - 1){
                n1 = 0;
                Node<T>* n2 = head;
                while(n2->next != 0){
                    n1 = n2;
                    n2 = n2->next;
                }
                delete n2;
                n1->next = 0;
                tail = n1;
            }
            else{
                for (size_t i = 0; i < index; ++i){
                    n1 = n1->next;
                }
                n1->prev->next = n1->next;
                n1->next->prev = n1->prev;
                delete n1;
                n1 = 0;
            }

            this->list_size--;
        }

        T& operator[](size_t index){
            if (index >= this->list_size){
                throw std::out_of_range("Index out of range");
            }
            Node<T>* n1 = this->head;
            for (size_t i = 0; i < index; ++i){
                n1 = n1->next;
            }
            return n1->value;
        }

        T& getTail(){
            return tail->value;
        }


};
