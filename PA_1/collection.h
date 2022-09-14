#pragma once

#include <cstddef>
#include <iostream>

template <typename Object>
class Collection {
    Object* list;
    size_t list_size;
    size_t capacity;

    public:
        // default constructor
        Collection(): list{nullptr}, list_size(0), capacity(1){
            list = new Object[1];
        }

        ~Collection(){
            delete[] list;
            this->list_size = 0;
            this->capacity = 0;
        }

        //copy constructor
        Collection(const Collection& other): list{nullptr}, list_size(other.list_size), capacity(0) {
            if(other.capacity != 0){
                list = new Object[other.capacity];

                for(size_t i = 0; i < list_size; ++i){
                    list[i] = other.list[i];
                }

                this->capacity = other.capacity;
            }
        }

        // copy assignment operator
        Collection& operator=(const Collection& other){
            if(this != &other){
                return *this;
            }

            delete[] list;
            list = nullptr;
            list_size= other.list_size;
            capacity = other.capacity;

            if(other.capacity != 0){

                list = new Object[other.capacity];

                for(size_t i = 0; i < list_size; ++i){
                    list[i] = other.list[i];
                }
            }

            return *this;
        }

        size_t size() const{
            return this->list_size;
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

        void make_empty(){
            if (this->list != nullptr){
                delete[] this->list;
                this->list = nullptr;

                this->list_size = 0;
            }
            
        }

        void insert(const Object& obj){

            if (this->is_empty()){
                this->resize();
            }


            if (this->list_size + 1 > capacity){
                this->resize();
            }

            if (this->list_size != 0){
                for (size_t i = this->list_size; i > 0; --i){
                    Object temp = this->list[i - 1];
                    this->list[i] = temp;
                }
            }

            this->list[0] = obj;
            this->list_size++;            
        }

        void resize(){

            Object* newList = nullptr;

            if (this->is_empty()){
                newList = new Object[5];
                this->capacity = 5;
            }
            else{
                newList = new Object[this->capacity * 2];
                this->capacity = 2 * this->capacity;
            }
            
            for (size_t i = 0; i < this->list_size; ++i){
                newList[i] = this->list[i];
            }

            delete[] this->list;

            this->list = newList;
        }

        Object& returnIndex(size_t index){
            return this->list[index];
        }

        void remove(const Object& obj){
            std::cout << this->capacity << " " << this->list_size << std::endl;
            for(size_t i = 0; i < this->list_size; ++i){
                if (this->list[i] == obj){
                    for(size_t j = i; j < this->list_size - 1; ++j){
                        this->list[j] = this->list[j + 1];
                    }
                    this->list_size--;
                    break;
                }
            }
            std::cout << this->capacity << " " << this->list_size << std::endl;
        }

        bool contains(const Object& obj) const{
            for (size_t i = 0; i < this->list_size; ++i){
                if (this->list[i] == obj){
                    return true;
                }
            }

            return false;
        }


};
