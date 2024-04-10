//Rio Simpson
//project 2 main.cpp

//libraries
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

//class information
#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLtree.hpp"

int main(){
    std::ifstream input_data("testinput.txt");
    std::vector<int> read_data;

    if (input_data.is_open()) {
        std::string line;
        while (std::getline(input_data, line)) {
            std::istringstream iss(line);
            std::string operation;

            if (!(iss >> operation)) {
                continue;
            }

            if (operation == "insert") {
                int value;
                iss >> value;
                read_data.push_back(value);
            } else if (operation == "pop") {
                read_data.push_back(-1);
            }
        }

        input_data.close();
    }

    vectorMedian(&read_data);
    std::cout << "\nEND OF VECTOR\n";

    listMedian(&read_data);
    std::cout << "\nEND OF LIST\n";

    heapMedian(&read_data);
    std::cout << "\nEND OF HEAP\n";

    treeMedian(&read_data);
    std::cout << "\nEND OF TREE\n";
}