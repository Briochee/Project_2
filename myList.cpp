//Rio Simpson
//Project 2, myList class method definitions

//libraries
#include <list>
#include <algorithm>
#include <iostream>
#include <chrono>

#include "myList.hpp"

void listMedian(const std::vector<int>* instructions){
    //initalizing data structure
    myList aList;
    
    //starting timer
    // auto start = std::chrono::high_resolution_clock::now();

    for (const int value : *instructions){
        if (value == -1) {
            aList.getMediansToPrint().push_back(aList.popMedian());
        } else {
            aList.insert(value);
        }
    }

    //ending timer
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration = end - start;
    // std::cout << "\nList Completed in: " << duration.count() * 1000 << " milliseconds\n";

    //printing medians out after algorithm is finished sorting
    for (const int median : aList.getMediansToPrint()){
        std::cout << median << " ";
    }
}

myList::myList(){
    //constructor calls list constructor to make empty list
    mediansToPrint_ = std::vector<int>();
    sortedMedians_ = std::list<int>();
}

std::vector<int>& myList::getMediansToPrint(){
    return mediansToPrint_;
}

int myList::popMedian(){
    //calculating median index
    int medianIndex = sortedMedians_.size() / 2;
    int median;

    //if list has even number of instructions
    if (sortedMedians_.size() % 2 == 0) {
        std::list<int>::iterator it = sortedMedians_.begin();
        for (int i = 0; i < medianIndex - 1; ++i){
            ++it;
        }
        median = *it;
        //removing median from list
        sortedMedians_.erase(it);
    } else {
        std::list<int>::iterator it = sortedMedians_.begin();
        for (int i = 0; i < medianIndex; ++i){
            ++it;
        }
        median = *it;
        //removing median from list
        sortedMedians_.erase(it);
    }
    return median;
}

void myList::insert(const int& median){
    //declaring iterator
    std::list<int>::iterator myIt;
    //iterator begins at list start, ends at list end
    myIt = std::lower_bound(sortedMedians_.begin(), sortedMedians_.end(), median);
    sortedMedians_.insert(myIt, median);
}