//Rio Simpson
//project 2 main.cpp

//libraries
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

//class information
#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLtree.hpp"

int main(){
    std::ifstream input_data1("testinput.txt");
    // std::ifstream input_data1("input1.txt");
    // std::ifstream input_data2("input2.txt");
    // std::ifstream input_data3("input3.txt");
    std::vector<int> read_data1;
    // std::vector<int> read_data2;
    // std::vector<int> read_data3;

    if (input_data1.is_open()) {
        std::string line;
        while (std::getline(input_data1, line)) {
            std::istringstream iss(line);
            std::string operation;

            if (!(iss >> operation)) {
                continue;
            }

            if (operation == "insert") {
                int value;
                iss >> value;
                read_data1.push_back(value);
            } else if (operation == "pop") {
                read_data1.push_back(-1);
            }
        }

        input_data1.close();
    }
    
    // if (input_data2.is_open()) {
    //     std::string line;
    //     while (std::getline(input_data2, line)) {
    //         std::istringstream iss(line);
    //         std::string operation;

    //         if (!(iss >> operation)) {
    //             continue;
    //         }

    //         if (operation == "insert") {
    //             int value;
    //             iss >> value;
    //             read_data2.push_back(value);
    //         } else if (operation == "pop") {
    //             read_data2.push_back(-1);
    //         }
    //     }

    //     input_data2.close();
    // }
    
    // if (input_data3.is_open()) {
    //     std::string line;
    //     while (std::getline(input_data3, line)) {
    //         std::istringstream iss(line);
    //         std::string operation;

    //         if (!(iss >> operation)) {
    //             continue;
    //         }

    //         if (operation == "insert") {
    //             int value;
    //             iss >> value;
    //             read_data3.push_back(value);
    //         } else if (operation == "pop") {
    //             read_data3.push_back(-1);
    //         }
    //     }

    //     input_data3.close();
    // }

    vectorMedian(&read_data1);
    // vectorMedian(&read_data2);
    // vectorMedian(&read_data3);
    std::cout << "\nEND OF VECTOR\n";

    listMedian(&read_data1);
    // listMedian(&read_data2);
    // listMedian(&read_data3);
    std::cout << "\nEND OF LIST\n";

    heapMedian(&read_data1);
    // heapMedian(&read_data2);
    // heapMedian(&read_data3);
    std::cout << "\nEND OF HEAP\n";

    treeMedian(&read_data1);
    // treeMedian(&read_data2);
    // treeMedian(&read_data3);
    std::cout << "\nEND OF TREE\n";
}