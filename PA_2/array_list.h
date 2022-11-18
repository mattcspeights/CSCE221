#pragma once
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdexcept>

template <typename T>
class ArrayList {
    T* list;
    size_t list_size;
    size_t list_capacity;

    public:

        size_t size() const{
            return list_size;
        }

        size_t capacity() const{
            return list_capacity;
        }

        ArrayList(size_t capacity = 1): list{}, list_size(0), list_capacity(capacity) {
            list = new T[capacity];
        }

        ~ArrayList(){
            delete[] list;
        }

        ArrayList(const ArrayList& other): list{}, list_size(0), list_capacity(0){
            if (other.list != nullptr && other.list_capacity != 0){
                T* newList = new T[other.list_capacity];

                for (size_t i = 0; i < other.list_size; ++i){
                    newList[i] = other.list[i];
                }

                list_size = other.list_size;
                list_capacity = other.list_capacity;
                list = newList;
            }
        }

        ArrayList& operator=(const ArrayList& other){
            if (this == &other){
                return *this;
            }

            if (other.list != nullptr && other.list_capacity != 0){
                T* newList = new T[other.list_capacity];

                for (size_t i = 0; i < other.list_size; ++i){
                    newList[i] = other.list[i];
                }

                delete[] list;

                list_size = other.list_size;
                list_capacity = other.list_capacity;
                list = newList;
            }

            return *this;
        }

        T& operator[](size_t index){
            if (index >= list_size){
                throw std::invalid_argument("Index out of bounds");
            }

            return list[index];
        }

        void resize(){

            T* newList = nullptr;

            if (this->is_empty()){
                newList = new T[1];
                this->list_capacity = 1;
            }
            else{
                newList = new T[this->list_capacity * 2];
                this->list_capacity = 2 * this->list_capacity;
            }
            
            for (size_t i = 0; i < this->list_size; ++i){
                newList[i] = this->list[i];
            }

            delete[] this->list;

            this->list = newList;
        }

        bool is_empty() const{
            if (this->list == nullptr){
                return true;
            }

            if (this->list_size == 0){
                return true;
            }

            return false;
        }

        void insert(size_t index, const T& obj){
            if (index > list_size){
                throw std::invalid_argument("Index out of bounds");
            }

            if (this->is_empty() && index == 0){
                this->resize();
                this->list[index] = obj;
            }
            else if (this->list_size != 0){
                if (this->list_size + 1 > list_capacity){
                    this->resize();
                }
                for (size_t i = this->list_size; i > index; --i){
                    T temp = this->list[i - 1];
                    this->list[i] = temp;
                }
                this->list[index] = obj;
            }

            this->list_size++;    
        }

        void remove(size_t index){
            if (index >= list_size){
                throw std::invalid_argument("Index out of bounds");
            }

            for(size_t i = 0; i < this->list_size; ++i){
                if (i == index){
                    for(size_t j = i; j < this->list_size - 1; ++j){
                        this->list[j] = this->list[j + 1];
                    }
                    this->list_size--;
                    break;
                }
            }
        }






};

#endif  // ARRAY_LIST_H