#pragma once
#include "doubly_linked_list.h"

template <typename T>
class Stack {
    DoublyLinkedList<T> list;

    public:
        Stack(): list(DoublyLinkedList<T>()){}

        Stack(const Stack& other): list(DoublyLinkedList<T>()){
            this->list = DoublyLinkedList<T>(other.list);
        }

        Stack<T>& operator=(const Stack<T>& other){
            this->list = other.list;
            return *this;
        }

        void push(T object){
            list.insert(0, object);
        }

        void pop(){
            list.remove(0);
        }

        T& top(){
            return list[0];
        }

        size_t size() const {
            return list.size();
        }
};