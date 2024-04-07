//Rio Simpson
//Project 2, myVector class

#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

//libraries
#include <vector>

class myVector{
    public:
        //constructor
        myVector();

        //methods
        void vectorMedian(const std::vector<int>& instructions);

        int popMedian();

        void insert(const int& median);

    private:
        std::vector<int> mediansToPrint_;
        std::vector<int> sortedMedians_;
};

#endif