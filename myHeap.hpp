//Rio Simpson
//Project 2, myHeap class

#ifndef MYHEAP_HPP
#define MYHEAP_HPP

//libraries
#include <vector>
#include <queue>

//heapMedian signature
void heapMedian(const std::vector<int>* instructions);

class myHeap {
    public:
        //constructor
        myHeap();

        //methods
        int popMedian();

        void insert(const int& median);

        std::vector<int>& getMediansToPrint();

    private:
        std::vector<int> mediansToPrint_;
        std::priority_queue<int> maxHeap;
        //specifing greater than comparison to make minHeap
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};


#endif