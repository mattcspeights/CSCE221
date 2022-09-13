#pragma once

#include <cstddef>

template <typename Object>
class Collection {
    Object* list;
    size_t size;

    public:
        Collection(): list{}, size(0){}

        ~Collection(){
            delete[] list;
        }

        Collection(const Collection& other): list{}, size(other.size) {
            if(other.size != 0){
                list = new Object[size];

                for(size_t i = 0; i < size; ++i){
                    list[i] = other.list[i];
                }
            }
        }

        Collection& operator=(const Collection& other){
            if(this != &other){
                return *this;
            }

            delete[] list;
            list = nullptr;
            size = other.size;

            if(other.size != 0){

                list = new Object[size];

                for(size_t i = 0; i < size; ++i){
                    list[i] = other.list[i];
                }
            }

            return *this;
        }
};
