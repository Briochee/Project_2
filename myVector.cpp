//Rio Simpson
//Project 2, myVector class method definitions

//libraries
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

#include "myVector.hpp"

void vectorMedian(const std::vector<int>* instructions){
    myVector aVector;

    //starting timer
    // auto start = std::chrono::high_resolution_clock::now();

    for (const int value : *instructions){
        if (value == -1){
            aVector.getMediansToPrint().push_back(aVector.popMedian());
        } else {
            aVector.insert(value);
        }
    }

    //ending timer
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration = end - start;
    // std::cout << "\nVector Completed in: " << duration.count() * 1000 << " milliseconds\n";

    //printing medians out after algorithm is finished sorting
    for (const int median : aVector.getMediansToPrint()){
        std::cout << median << " ";
    }
}

myVector::myVector(){
    //constructor calls vector constructor to make empty vector
    mediansToPrint_ = std::vector<int>();
    sortedMedians_ = std::vector<int>();
}

std::vector<int>& myVector::getMediansToPrint(){
    return mediansToPrint_;
}

int myVector::popMedian(){
    //calculating median index
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
    //declaring iterator
    std::vector<int>::iterator myIt;
    //iterator begins at vector start, ends at vector end
    myIt = std::lower_bound(sortedMedians_.begin(), sortedMedians_.end(), median);
    sortedMedians_.insert(myIt, median);
}