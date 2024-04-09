//Rio Simpson
//Project 2, myHeap class method definitions

//libraries
#include <queue>
#include <algorithm>
#include <iostream>

#include "myHeap.hpp"

void heapMedian(const std::vector<int>& instructions){
    //creating heap object for heapMedian
    myHeap aHeap;
    for (const int value : instructions) {
        if (value == -1) {
            aHeap.getMediansToPrint().push_back(aHeap.popMedian());
        } else {
            aHeap.insert(value);
        }
    }

    //printing medians out after algorithm is finished
    for (const int median : aHeap.getMediansToPrint()) {
        std::cout << median << " ";
    }
}

myHeap::myHeap(){
    //initalizing data members
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
}

std::vector<int>& myHeap::getMediansToPrint(){
    return mediansToPrint_;
}

int myHeap::popMedian() {
    int median = maxHeap.top();
    maxHeap.pop();

    //rebalance the heaps
    if (maxHeap.size() < minHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }

    return median;
}

void myHeap::insert(const int& median) {
    //if median is less than or equal to current median, insert into maxHeap
    if (maxHeap.empty() || median <= maxHeap.top()) {
        maxHeap.push(median);
    } else {
        minHeap.push(median);
    }

    //rebalance the heaps
    if (maxHeap.size() > minHeap.size() + 1) {
        //maintaining the minHeap having a greater size than the maxHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    } else if (minHeap.size() > maxHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}