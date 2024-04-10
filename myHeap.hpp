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
        //popMedian method takes no parameters, returns the integer value it removed from heap
        int popMedian();
        
        //insert function takes an integer refence to insert into heap
        void insert(const int& median);

        //basic getter to return vector for printing
        std::vector<int>& getMediansToPrint();

    private:
        std::vector<int> mediansToPrint_;
        std::priority_queue<int> maxHeap;
        //specifing greater than comparison to make minHeap
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};


#endif