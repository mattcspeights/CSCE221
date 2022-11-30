#pragma once
#include <functional>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>

using std::vector, std::cout, std::endl;

template <class Key, class Hash=std::hash<Key>>
class HashTable {
    vector<Key> table;
    size_t numValues;
    float loadFactor;
    float maxLoadFactor;

    public:
        HashTable(): table(vector<Key>(11)), numValues(0), loadFactor(0), maxLoadFactor(.5){}
        explicit HashTable(size_t size): table(vector<Key>(size)), numValues(0), loadFactor(0), maxLoadFactor(.5){}

        HashTable(const HashTable& other): table(other.table), numValues(0), loadFactor(other.loadFactor), maxLoadFactor(other.maxLoadFactor){}

        HashTable& operator=(const HashTable& other){
            if (this == &other){
                return *this;
            }
            table = other.table;
            loadFactor = other.loadFactor;
            maxLoadFactor = other.maxLoadFactor;
            numValues = other.numValues;

            return *this;
        }

        bool is_empty() const {
            return table.empty();
        }

        size_t size() const {
            return numValues;
        }

        void make_empty(){
            table.clear();
            loadFactor = 0;
            numValues = 0;
        }

        void insert(const Key& value){
            if (!this->contains(value)){
                size_t hash_value = Hash{}(value)  % table.size();
                // if (table.at(hash_value) == 0){
                table.at(hash_value) = value;
                // }
                // else{
                //     hash_value++;
                //     while (table.at(hash_value) == 0){
                //         hash_value++;
                //     }
                //     table.at(hash_value) = value;
                // }
                numValues++;
                loadFactor = (float)this->numValues / (float)table.size();
                if (loadFactor >= maxLoadFactor){
                    this->rehash();
                }
            }
        }

        size_t remove(const Key& value){
            for (size_t i = 0; i < table.size(); ++i){
                if (table.at(i) == value){
                    table.erase(table.begin() + i);
                    numValues--;
                    loadFactor = (float)this->numValues / (float)table.size();
                    return 1;
                }
            }
            return 0;
        }

        void rehash(size_t numBuckets){
            if (numBuckets != table.size()){
                vector<Key> values;
                for (size_t i = 0; i < table.size(); ++i){
                    values.push_back(table.at(i));
                }
                HashTable newTable(numBuckets);
                newTable.maxLoadFactor = this->maxLoadFactor;
                for (Key i : values){
                    newTable.insert(i);
                }
                this->table = newTable.table;
                loadFactor = (float)this->numValues / (float)table.size();
            }
        }

        void rehash(){
            if (loadFactor >= maxLoadFactor){
                vector<Key> values;
                for (size_t i = 0; i < table.size(); ++i){
                    values.push_back(table.at(i));
                }
                size_t newSize = table.size() * 2;
                while(!isPrime(newSize)){
                    newSize++;
                }
                HashTable newTable(newSize);
                newTable.maxLoadFactor = this->maxLoadFactor;
                for (Key i : values){
                    newTable.insert(i);
                }
                this->table = newTable.table;
                this->numValues = newTable.numValues;
                loadFactor = (float)this->numValues / (float)table.size();
            }
        }

        bool contains(const Key& value) const {
            for (size_t i = 0; i < table.size(); ++i){
                if (table.at(i) == value){
                    return true;
                }
            }
            return false;
        }

        size_t position(const Key& value) const {
            return Hash{}(value) % table.size();
        }

        size_t table_size() const {
            return table.size();
        }

        float load_factor() const {
            return loadFactor;
        }

        float max_load_factor() const {
            return maxLoadFactor;
        }

        void max_load_factor(float newLoadFactor){
            maxLoadFactor = newLoadFactor;
            this->rehash();
        }

        void print_table(std::ostream& os=std::cout) const {
            if (this->is_empty()){
                os << "<empty>\n";
            }
            else{
                for (size_t i = 0; i < table.size(); ++i){
                    os << "[" << table.at(i) << "]" << endl;
                }
            }
        }
        // from wikipedia on primality tests :0
        bool isPrime(int n){
            if (n == 2 || n == 3)
                return true;

            if (n <= 1 || n % 2 == 0 || n % 3 == 0)
                return false;

            for (int i = 5; i * i <= n; i += 6)
            {
                if (n % i == 0 || n % (i + 2) == 0)
                    return false;
            }

            return true;
        }

        
};
