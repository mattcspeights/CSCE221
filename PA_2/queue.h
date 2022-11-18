#pragma once
#include "doubly_linked_list.h"
template <typename T>
class Queue {
    DoublyLinkedList<T> list;

    public:
        Queue(): list(DoublyLinkedList<T>()){}

        Queue(const Queue& other): list(DoublyLinkedList<T>()){
            this->list = DoublyLinkedList<T>(other.list);
        }

        Queue<T>& operator=(const Queue<T>& other){
            this->list = other.list;
            return *this;
        }

        void enqueue(T object){
            list.insert(0, object);
        }

        T dequeue(){
            T frontVal = list[list.size() - 1];
            list.remove(list.size() - 1);
            return frontVal;
        }

        T& front(){
            return list[list.size() - 1];
        }

        size_t size() const {
            return list.size();
        }
};
