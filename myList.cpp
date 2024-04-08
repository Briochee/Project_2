//Rio Simpson
//Project 2, myList class method definitions

//libraries
#include <list>
#include <algorithm>
#include <iostream>

#include "myList.hpp"

void listMedian(const std::vector<int>& instructions) {
    //initalizing data structure
    myList aList;
    
    for (const int value : instructions) {
        if (value == -1) {
            aList.getMediansToPrint().push_back(aList.popMedian());
        } else {
            aList.insert(value);
        }
    }

    //printing medians out after algorithm is finished sorting
    for (const int median : aList.getMediansToPrint()) {
        std::cout << median << " ";
    }
}

myList::myList() {
    //constructor calls list constructor to make empty list
    mediansToPrint_ = std::vector<int>();
    sortedMedians_ = std::list<int>();
}

std::vector<int>& myList::getMediansToPrint(){
    return mediansToPrint_;
}

int myList::popMedian() {
    //sorting list
    sortedMedians_.sort();

    int medianIndex = sortedMedians_.size() / 2;
    int median;

    //if list has even number of instructions
    if (sortedMedians_.size() % 2 == 0) {
        std::list<int>::iterator it = sortedMedians_.begin();
        for (int i = 0; i < medianIndex - 1; ++i) {
            ++it;
        }
        median = *it;
        //removing median from list
        sortedMedians_.erase(it);
    } else {
        std::list<int>::iterator it = sortedMedians_.begin();
        for (int i = 0; i < medianIndex; ++i) {
            ++it;
        }
        median = *it;
        //removing median from list
        sortedMedians_.erase(it);
    }
    return median;
}

void myList::insert(const int& median) {
    sortedMedians_.push_back(median);
}