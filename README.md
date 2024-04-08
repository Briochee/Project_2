Project 2 OverviewProject 2 Overview
For project 2, you will implement an ADT that only has 2 operations: insert and pop median.
You will implement this in 4 ways, and compare their performance:
1) Using a vector that's kept sorted
2) Using a linked list that's kept sorted
3) Using a max heap holding all elements <= the median and a min heap holding all elements > the median
4) Using 2 AVL trees, one holding all elements <= the median and the other holding all elements > the median
Note: AVL trees must be able to hold duplicate values.
pop median will both return and remove the median. For a container with an even number of elements, the median will be the lesser of the two middle elements.
Autograder will be up soon. Project is due Wednesday, April 10, by end of day.


Item
Project 2 filesProject 2 files
You must submit the following files:
main.cpp, which reads the input from file, converts it to an integer format, and passes it to each method.
myVector.cpp, containing the function void vectorMedian (const std::vector<int> * instructions)
myVector.hpp, containing the prototypes* of the functions in myVector.cpp
myList.cpp, containing the function void listMedian (const std::vector<int> * instructions)
myList.hpp, containing the prototypes* of the functions in myList.cpp
myHeap.cpp, containing the function void heapMedian (const std::vector<int> * instructions)
myHeap.hpp, containing the prototypes* of the functions in myHeap.cpp
myAVLtree.cpp, containing the function void treeMedian (const std::vector<int> * instructions)
myAVLtree.hpp, containing your implementation of an AVL tree data structure
For each method, "instructions" should be in the format shown in testinput_in_integer_format.txt at the bottom of this page. Each method should print out (to standard output) a list of medians, as shown in testinput_medians.txt.
For the vector, list, and heap-based data structures, you may use the STL fully.
For the AVL tree, the STL does not have one, so you must implement your own. You may use the textbook implementation, modified to specifically handle integers and to handle duplicates.
You may include other supporting functions as needed, but the ones listed must be called from main, and must accomplish the task of following the instructions they receive and printing out the medians in the order they're popped.
* You may implement all the required functionality in the vectorMedian, listMedian, and heapMedian functions, in which case those hpp files don't need to contain anything other than function prototypes. If you prefer a more OOP approach and wish to implement insert and popmedian functions in your hpp files, you may do that, but please comment in your cpp files that those implementations are contained in your hpp files, otherwise the grader may not see them.
Item


Project 2 main.cppProject 2 main.cpp
main.cpp should read the input file and convert it to an integer vector as follows:
For an insert X operation, push X to the back of the vector.
For a pop median operation, push -1 to the back of the vector.
Essentially, main.cpp will be your own testing function that will convert an input file (for example testinput.txt) into the format shown in testinput_in_integer_format.txt. Do not print this format out, instead you only need to store it in a vector, then pass that vector to each of your 4 median-tracking methods.
This format will be used to test your other functions on Gradescope, so you must do this conversion in main.cpp and not simply pass the instructions to your other functions.

Item
Project 2 I/OProject 2 I/O
You will be provided with a sample input file with strings of the two commands "insert X" and "pop median".
For each "pop median" you will remove the median from its container and print it out, followed by a space.
Your output will be just the one line, consisting only of those numbers.
In order to keep expensive I/O operations separate from the time the algorithm itself takes, write the medians to a vector as you find them, then print them out at the end of each function (vectorMedian, listMedian, heapMedian and treeMedian), after you stop recording the time.


Item
Project 2 TimingProject 2 Timing
You will time each method on each input and write them in a table on your report. You should only time your main loop in each method - importantly, as you pop each median, do not write it to standard output. Instead, copy it to an output vector, then print out that vector after you've stopped timing.
This is to ensure that expensive output operations don't overshadow the differences in computational times between the methods.


Item
Approach for Vector and List implementationsApproach for Vector and List implementations
Using a vector or a list, there are 2 options: either keep it sorted the entire time by inserting each new element into its correct sorted position, or sort it to find the median each time. We're doing the first option.
For a vector, use lower_bound or upper_bound to find the correct position for a new number and insert it there. These functions essentially implement binary search on a sorted (or at least partitioned) STL container.
For a linked list, you'll have to iterate through the list to find the correct position to insert the new element.


Item
Approach for heap and tree implementationsApproach for heap and tree implementations
The approach you'll take for using heaps and trees is simple:
You'll keep 2 containers, let's call them "small" and "large", with small holding the median and all values less than the median, and large holding all values greater than the median.
Thus, the median will be the maximum element in small, and small will always be of equal size or 1 element larger than large.
While inserting or popping the median, you may need to rebalance the containers, requiring you to move the largest element in "small" to "large", or the smallest element in "large" to "small", as appropriate.
As a reminder, for a container with an even number of elements, the median will be the lesser of the two middle elements.
For heaps, you may use https://cplusplus.com/reference/queue/priority_queue/. If you look at the template parameters, you'll see 3: T, Container, Compare. If you leave Container and Compare blank, you'll get the default heap - a max heap using a vector. If you want a min heap, you need to specify all the parameters, and use "greater than" as the comparison.


Item
Project 2 GradingProject 2 Grading
Vector implementation: 10 pts
Linked list implementation: 10 pts
Heap implementation: 20 pts
AVL tree implementation: 20 pts
Report: 15 pts
Manual grading (documentation, code quality, following instructions): 15 pts
Penalty for using a completely different implementation than the one specified in a file will be equal to the points awarded by the autograder if deemed unintentional, twice that if deemed intentional. In other words, if you use vectors to find the correct answer, and copy that into the heap and AVL tree files because the output is the same and it passes the autograder tests, you will end up with a negative score on the project after the grader sees that.


Item
Project 2 ReportProject 2 Report
Along with your files, submit a report in PDF format with the following:
1) A clearly labeled table showing the time it took for each implementation on each input.
2) A complexity analysis of each method in O-notation.
3) A paragraph or two on how your results lined up with the O complexity.
4) Any additional observations you had during the project.
The whole thing should be about 2 pages.
