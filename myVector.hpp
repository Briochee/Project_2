//Rio Simpson
//Project 2, myVector class

#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

//libraries
#include <vector>

//vectorMedian signature
void vectorMedian(const std::vector<int>& instructions);

class myVector{
    public:
        //constructor
        myVector();

        //methods
        int popMedian();

        void insert(const int& median);

        std::vector<int>& getMediansToPrint();

    private:
        std::vector<int> mediansToPrint_;
        std::vector<int> sortedMedians_;
};

#endif