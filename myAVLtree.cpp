//Rio Simpson
//myAVLtree method implementations
//NOTE: AVLtree class taken from Data Structures and Algorithm Analysis, 4th Edition, Mark Allen Weiss, adapted by Rio Simpson for this project
//NOTE: Appropriate modifications taken from https://www.programiz.com

//libraries
#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>

//header file
#include "myAVLtree.hpp"

void treeMedian(const std::vector<int> *instructions) {
    //envoking constructor to make tree
    AvlTree tree;
    //vector to store medians for printing after
    std::vector<int> mediansToPrint_;

    //starting timer
    //auto start = std::chrono::high_resolution_clock::now();

    for (const int& value : *instructions){
        if (value == -1){
            //pop median
            mediansToPrint_.push_back(tree.popMedian());
        } else {
            //insert
            tree.insert(value);
        }
    }

    //ending timer
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> duration = end - start;
    // std::cout << "\nTree Completed in: " << duration.count() * 1000 << " milliseconds\n";

    for (const int& medians : mediansToPrint_){
        std::cout << medians << " ";
    }
}

void AvlTree::insert(const int& median) {
    if (small.isEmpty() || median <= small.getMax()){
        //inserts into small avl tree if median is less than max value of small tree
        small.push(median);
    } else {
        //if median is larger than median in small tree, move to large tree
        large.push(median);
    }

    balance();
}

int AvlTree::popMedian() {
    if (small.isEmpty() && large.isEmpty()){
        return -1;
    }
    //removes value from top of small avl tree
    int mid = small.popMax();

    balance();

    return mid;
}

void AvlTree::balance() {
    if (small.getSize() > large.getSize() + 1){
        //if the size of the small tree is greater than the large tree by more than 1 (the median)
        //the max value (median) of the small tree is moved to the large tree (as its minimum most value)
        //popMax is called and reconfigures the root node
        large.push(small.popMax());
    } else if (large.getSize() > small.getSize()){
        //if the size of the large tree is greater than the small tree
        //the min value (new median) of the large tree is moved to the small tree (as its root value and becomes the median)
        //popMin is called and reconfigures the root node
        small.push(large.popMin());
    }
}
