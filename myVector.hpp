//Rio Simpson
//Project 2, myVector class

#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

//libraries
#include <vector>

//vectorMedian signature
void vectorMedian(const std::vector<int>* instructions);

class myVector{
    public:
        //constructor
        myVector();

        //methods
        //popMedian method takes no parameters, returns the integer value it removed from vector
        int popMedian();
        
        //insert function takes an integer refence to insert into vector
        void insert(const int& median);

        //basic getter to return vector for printing
        std::vector<int>& getMediansToPrint();

    private:
        std::vector<int> mediansToPrint_;
        std::vector<int> sortedMedians_;
};

#endif