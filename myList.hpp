//Rio Simpson
//Project 2, myList class

#ifndef MYLIST_HPP
#define MYLIST_HPP

//libraries
#include <vector>
#include <list>

//listMedian signature
void listMedian(const std::vector<int>& instructions);

class myList{
    public:
        //constructor
        myList();

        //methods
        int popMedian();

        void insert(const int& median);

        std::vector<int>& getMediansToPrint();

    private:
        std::vector<int> mediansToPrint_;
        std::list<int> sortedMedians_;
};

#endif