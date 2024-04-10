//Rio Simpson
//Project 2, myList class

#ifndef MYLIST_HPP
#define MYLIST_HPP

//libraries
#include <vector>
#include <list>

//listMedian signature
void listMedian(const std::vector<int>* instructions);

class myList{
    public:
        //constructor
        myList();

        //methods
        //popMedian method takes no parameters, returns the integer value it removed from list
        int popMedian();

        //insert function takes an integer refence to insert into list
        void insert(const int& median);

        //basic getter to return vector for printing
        std::vector<int>& getMediansToPrint();

    private:
        std::vector<int> mediansToPrint_;
        std::list<int> sortedMedians_;
};

#endif