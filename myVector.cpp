//Rio Simpson
//Project 2, myVector class method definitions

//libraries
#include <vector>
#include <algorithm>
#include <iostream>

#include "myVector.hpp"

myVector::myVector(){
    //constructor calls vector constructor to make empty vector
    mediansToPrint_ = std::vector<int>();
    sortedMedians_ = std::vector<int>();
}

void myVector::vectorMedian(const std::vector<int>& instructions){
    
    for (const int value : instructions){
        if (value == -1){
            mediansToPrint_.push_back(popMedian());
        } else {
            insert(value);
        }
    }

    //printing medians out after algorithm is finished sorting
    for (const int median : mediansToPrint_){
        std::cout << median << " ";
    }
}

int myVector::popMedian(){
    //sorting vector
    std::sort(sortedMedians_.begin(), sortedMedians_.end());

    int medianIndex = sortedMedians_.size() / 2;
    int median;

    //if vector has even number of instructions, 
    if (sortedMedians_.size() % 2 == 0){
        median = sortedMedians_[medianIndex - 1];
        //removing median from vector
        sortedMedians_.erase(sortedMedians_.begin() + (medianIndex - 1));
    } else {
        median = sortedMedians_[medianIndex];
        //removing median from vector
        sortedMedians_.erase(sortedMedians_.begin() + medianIndex);
    }
    return median;
}

void myVector::insert(const int& median){
    sortedMedians_.push_back(median);
}