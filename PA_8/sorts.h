#pragma once
#include <functional>
#include <iostream>
#include <vector>
#include <utility>

// Pretty printing for vectors of Printable objects (have ostream operator<< defined)
// Be careful: modifications risk failing tests
template <class Printable>
std::ostream& operator<<(std::ostream& os, const std::vector<Printable>& container) {
    os << "[";
    bool first = false;
    for (const Printable& t : container) {
        if (first) {
            os << ", ";
        }
        if (typeid(t) == typeid(std::string)) {
            os << "\"" << t << "\"";
        } else {
            os << t;
        }
        first = true;
    }
    os << "]";
    return os;
}

// Selection sort (example of implementation expectations)
template <class Comparable>
void selection_sort(std::vector<Comparable>& container) {
    // print the initial container
    std::cout << container << std::endl;

    if (container.empty()) {
        return;
    }

    for (size_t index = 0; index < container.size()-1; index++) {
        // do 1 pass of selection sort: find the min and swap it to the front
        size_t index_min = index;
        for (size_t i = index+1; i < container.size(); i++) {
            if (container[i] < container[index_min]) {
                index_min = i;
            }
        }
        Comparable t = container[index];
        container[index] = container[index_min];
        container[index_min] = t;

        // print the container after each pass
        std::cout << container << std::endl;
    }
}

// TODO(student): implement sorts: insertion, shell, heap, merge, quick, bucket, radix
template <class Comparable>
void insertion_sort(std::vector<Comparable>& list){
    size_t counter = 1;
    for (size_t i = 0; i < list.size(); ++i){
        if (counter == i){
            std:: cout << list << std::endl;
            counter++;
        }
        if (i != 0){
            if (list.at(i) < list.at(i - 1)){
                Comparable current = list.at(i);
                list.at(i) = list.at(i - 1);
                list.at(i - 1) = current;
                i -= 2;
            }
        }
    }
    std:: cout << list << std::endl;
}

template <class Comparable>
void insertion_sort(std::vector<Comparable>& list, int left, int right){
    if (right != -1){
        std:: cout << list << std::endl;
    }
    
    int counter = left + 1;
    for (int i = left; i < right + 1; ++i){
        if (i != 0){
            if (list.at(i) < list.at(i - 1)){
                Comparable current = list.at(i);
                list.at(i) = list.at(i - 1);
                list.at(i - 1) = current;
                i -= 2;
            }
        }
        if (counter == i){
            std:: cout << list << std::endl;
            counter++;
        }
    }
}

size_t pow(size_t base, size_t power){
    size_t output = 1;
    for (size_t i = 0; i < power; ++i){
        output *= base;
    }
    return output;
}

template <class Comparable>
void shell_sort(std::vector<Comparable>& list){
    std::cout << list << std::endl;
    std::vector<int> gaps;
    size_t index = 1;
    while(pow(2, index) - 1 < list.size()){
        gaps.push_back(pow(2, index) - 1);
        index++;
    }
    for (int i = gaps.size() - 1; i >=0; i--){
        for (int j = 0; j + gaps.at(i) < (int)list.size(); ++j){
            if (list.at(j) > list.at(j + gaps.at(i))){
                Comparable current = list.at(j + gaps.at(i));
                list.at(j + gaps.at(i)) = list.at(j);
                list.at(j) = current;
                if (j - gaps.at(i) >= 0){
                    j -= gaps.at(i) + 1;
                }
            }
        }
        std::cout << list << std::endl;
    }
    
}

template <class Comparable>
void heap_sort(std::vector<Comparable>& list){
    list = list;
}

template <class Comparable>
void merge(std::vector<Comparable>& list, std::vector<Comparable>& output, int left, int right, int end){
    int outCount = left;
    int leftEnd = right - 1;
    int total = end - left + 1;
    while (left <= leftEnd && right <= end){
        if (list.at(left) < list.at(right)){
            output.at(outCount) = list.at(left);
            left++;
            outCount++;
        }
        else{
            output.at(outCount) = list.at(right);
            right++;
            outCount++;
        }
    }
    while (left <= leftEnd){
        output.at(outCount) = list.at(left);
        left++;
        outCount++;
    }
    while (right <= end){
        output.at(outCount) = list.at(right);
        right++;
        outCount++;
    }
    for (int i = 0; i < total; ++i){
        list.at(end) = output.at(end);
        end--;
    }
    std::cout << list << std::endl;
}

template <class Comparable>
void merge_sort(std::vector<Comparable>& list, std::vector<Comparable>& output, int left, int right){
    if (left < right){
        int middle = (left + right) / 2;
        merge_sort(list, output, left, middle);
        merge_sort(list, output, middle + 1, right);
        merge(list, output, left, middle + 1, right);
    }
}

template <class Comparable>
void merge_sort(std::vector<Comparable>& list){
    std::vector<Comparable> temp(list.size());
    std::cout << list << std::endl;
    merge_sort(list, temp, 0, list.size() - 1);
}

template <class Comparable>
const Comparable& findPivot(std::vector<Comparable>& list, int left, int right){
    int median;
    if ((right + 1) % 2 == 0){
        median = (left + right + 1) / 2;
    }else{
        median = (left + right) / 2;
    }
    if (list.at(median) < list.at(left) )
        std::swap( list.at(left), list.at(median) );
    if (list.at(right) < list.at(left) )
        std::swap( list.at(left), list.at(right) );
    if (list.at(right) < list.at(median))
        std::swap( list.at(median), list.at(right) );

    std::swap(list.at(median), list.at(right));
    return list.at(right);
}

template <class Comparable>
void quick_sort(std::vector<Comparable>& list, int left, int right){
    std:: cout << list << std::endl;
    if (left + 10 <= right){
        const Comparable& median = findPivot(list, left, right);
        int i = left, j = right;

        for ( ; ; ){
            while(list.at(i) <= median){++i;};
            while(list.at(j) >= median){j--;};
            if (i < j){
                std::swap(list.at(i), list.at(j));
            }
            else{
                break;
            }
        }
        std::swap(list.at(i), list.at(right));

        quick_sort(list, left, i - 1);
        quick_sort(list, i + 1, right);
    }
    else{
        insertion_sort(list, left, right);
    }
}

template <class Comparable>
void quick_sort(std::vector<Comparable>& list){
    quick_sort(list, 0, list.size() - 1);
}

void bucket_sort(std::vector<unsigned>& list){
    list = list;
}

template <class Comparable>
void radix_sort(std::vector<Comparable>& list){
    list = list;
}

void radix_sort(std::vector<std::string>& array){
    array = array;
}   






