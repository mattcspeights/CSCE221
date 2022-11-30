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
    vector<vector<Key>> table;
    size_t numValues;
    float loadFactor;
    float maxLoadFactor;

    public:
        HashTable(): table(vector<vector<Key>>(11)), numValues(0), loadFactor(0), maxLoadFactor(1){}
        explicit HashTable(size_t size): table(vector<vector<Key>>(size)), numValues(0), loadFactor(0), maxLoadFactor(1){}

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
            for (size_t i = 0; i < table.size(); i++){
                if (!table.at(i).empty()){
                    return false;
                }
            }
            return true;
        }

        size_t size() const {
            return numValues;
        }

        void make_empty(){
            for (size_t i = 0; i < table.size(); i++){
                table.at(i).clear();
            }
            loadFactor = 0;
            numValues = 0;
        }

        void insert(const Key& value){
            if (!this->contains(value)){
                size_t hash_value = Hash{}(value)  % table.size();
                table.at(hash_value).push_back(value);
                numValues++;
                loadFactor = (float)this->numValues / (float)table.size();
                if (loadFactor >= maxLoadFactor){
                    this->rehash();
                }
            }
        }

        size_t remove(const Key& value){
            size_t hash_value = Hash{}(value) % table.size();
            for (size_t i = 0; i < table.at(hash_value).size(); ++i){
                if (table.at(hash_value).at(i) == value){
                    table.at(hash_value).erase(table.at(hash_value).begin() + i);
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
                    for (size_t j = 0; j < table.at(i).size(); ++j){
                        values.push_back(table.at(i).at(j));
                    }
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
                    for (size_t j = 0; j < table.at(i).size(); ++j){
                        values.push_back(table.at(i).at(j));
                    }
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
            size_t hash_value = Hash{}(value)  % table.size();
            for (size_t i = 0; i < table.at(hash_value).size(); ++i){
                if (table.at(hash_value).at(i) == value){
                    return true;
                }
            }
            return false;
        }

        size_t bucket_count() const {
            return table.size();
        }

        size_t bucket_size(size_t index) const {
            return table.at(index).size();
        }

        size_t bucket(const Key& value) const {
            return Hash{}(value) % table.size();
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
                    if (table.at(i).size() == 0){
                        os << "[]\n";
                    }
                    else{
                        os << "[";
                        for (size_t j = 0; j < table.at(i).size(); ++j){
                            os << table.at(i).at(j);
                            if (j != table.at(i).size() - 1){
                                os << ", ";
                            }
                        }
                        os << "]\n";
                    }
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
