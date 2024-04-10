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
    auto start = std::chrono::high_resolution_clock::now();

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
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "\nTree Completed in: " << duration.count() * 1000 << " milliseconds\n";

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

    rebalance();
}

int AvlTree::popMedian() {
    if (small.isEmpty() && large.isEmpty()){
        return -1;
    }
    //removes value from top of small avl tree
    int mid = small.popMax();

    rebalance();

    return mid;
}

void AvlTree::rebalance() {
    if (small.getSize() > large.getSize() + 1){
        large.push(small.popMax());
    } else if (large.getSize() > small.getSize()){
        small.push(large.popMin());
    }
}
