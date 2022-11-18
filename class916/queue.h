#include <list>
#include <stdexcept>

template<typename Object>
class queue{
    std::list<Object> list;

    public:
        
        queue(): list{}{}

        void enqueue(const Object& newObject){
            list.push_back(Object);
            size++;
        }

        Object dequeue(){
            if (size == 0){
                throw std::invalid_argument("Queue is empty");
            }
            Object front = list.front();
            list.pop_front();
            size--;
            return front;
        }

        const Object& front() const{
            if (size == 0){
                throw std::invalid_argument("Queue is empty");
            }
            return list.front();
        }

        Object& front(){
            if (size == 0){
                throw std::invalid_argument("Queue is empty");
            }
            return list.front();
        }

        size_t getSize() const{
            return list.size();
        }

};