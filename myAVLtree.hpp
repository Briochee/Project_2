//Rio Simpson
//Project 2, myList class
//NOTE: AVLtree class taken from Data Structures and Algorithm Analysis, 4th Edition, Mark Allen Weiss, adapted by Rio Simpson for this project
//NOTE: Appropriate modifications taken from https://www.programiz.com

#ifndef MYAVLTREE_HPP
#define MYAVLTREE_HPP

#include <algorithm>
#include <iostream>
#include <vector>

//treeMedian signature
void treeMedian(const std::vector<int>* instructions);

//node structure
struct AvlNode {
    int median_;
    int height_;
    AvlNode *left;
    AvlNode *right;

    AvlNode(const int& median){
        median_ = median;
        height_ = 1;
        left = nullptr;
        right = nullptr; 
    }
};

//structure of avl tree
struct AVL {
    public:
        //Root node
        AvlNode* root;

        //default constructor
        AVL(){
            root = nullptr;
            size = 0;
        }

        //remove max value of avl tree
        int popMax() {
            if (!root) return -1;

            AvlNode* ptr = root;
            //goes down the right side of tree to get max value
            while (ptr->right != nullptr){
                ptr = ptr->right;
            }

            int max = ptr->median_;
            root = deleteNode(root, ptr->median_);

            size--;
            return max;
        }

        //remove max value of avl tree
        int popMin() {
            if (!root) return -1;

            AvlNode* ptr = root;
            //goes down the left side of tree to get min value
            while (ptr->left != nullptr){
                ptr = ptr->left;
            }

            int min = ptr->median_;
            root = deleteNode(root, ptr->median_);

            size--;
            return min;
        }

        //returns max value
        int getMax() {
            if (!root) return -1;

            AvlNode* ptr = root;
            while (ptr->right != nullptr){
                ptr = ptr->right;
            }

            return ptr->median_;
        }

        //inserts node to tree
        void push(int median_) {
            root = insertNode(root,median_);
            size++;
        }

        //basic getter for size
        int getSize() {return size;}

        //returns true if root != nullptr
        bool isEmpty() {return !root;}

    private:
        int size;
        
        //basic getter for node height
        int getHeight(AvlNode* node) {
            if (!node) return 0;
            return node->height_;
        }

        //updates height
        void changeHeight(AvlNode* node) {
            node->height_ = std::max(getHeight(node->left), getHeight(node->right)) + 1;
        }

        //determines factor of unbalance if node is not equal to nullptr
        int bf (AvlNode* node) {
            if (!node) return 0;
            return getHeight(node->left) - getHeight(node->right);
        }

        //left rotation
        AvlNode* leftRotate(AvlNode* node) {
            AvlNode* new_root = node->right;
            AvlNode* temp = new_root->left;

            new_root->left = node;
            node->right = temp;

            changeHeight(node);
            changeHeight(new_root);

            return new_root;
        }

        //right rotation
        AvlNode* rightRotate(AvlNode* node) {
            AvlNode* new_root = node->left;
            AvlNode* temp = new_root->right;

            new_root->right = node;
            node->left = temp;

            changeHeight(node);
            changeHeight(new_root);

            return new_root;
        }

        //finds lowest node
        AvlNode* minNode(AvlNode* node) {
            AvlNode *ptr = node;
            while (ptr->left != nullptr){
                ptr = ptr->left;
            }
            return ptr;
        }

        //inserts node
        AvlNode* insertNode(AvlNode* node, int median_) {
            if (!node){
                return new AvlNode(median_);
            }

            if (median_ <= node->median_){
                node->left = insertNode(node->left, median_);
            } else if (median_ > node->median_){
                node->right = insertNode(node->right, median_);
            }

            changeHeight(node);
            int bal = bf(node);

            //Balance the tree
            if (bal > 1) {
                if (median_ <= node->left->median_){
                    return rightRotate(node);
                } else if (median_ > node->left->median_) {
                    node->left = leftRotate(node->left);
                    return rightRotate(node);
                }
            }
            if (bal < -1) {
                if (median_ > node->right->median_){
                    return leftRotate(node);
                } else if (median_ <= node->right->median_) {
                    node->right = rightRotate(node->right);
                    return leftRotate(node);
                }
            }

            return node;
        }

        //removes node
        AvlNode* deleteNode(AvlNode* node, int median_) {
            if (!node){
                return node;
            }

            if (median_ < node->median_){
                node->left = deleteNode(node->left, median_);
            } else if (median_ > node->median_){
                node->right = deleteNode(node->right, median_);
            } else {
                if ((!node->left) || (!node->right)) {
                    AvlNode* temp;
                    if (node->left) temp = node->left;
                    else temp = node->right;

                    if (!temp) {
                        temp = node;
                        node = nullptr;
                    }
                    else *node = *temp;

                    delete temp;
                } else {
                    AvlNode* temp = minNode(node->right);
                    node->median_ = temp->median_;
                    node->right = deleteNode(node->right, temp->median_);
                }
            }

            if (!node){
                return node;
            }

            changeHeight(node);
            int bal = bf(node);

            //balance the tree
            if (bal > 1) {
                if (bf(node->left) >= 0) return rightRotate(node);
                else {
                    node->left = leftRotate(node->left);
                    return rightRotate(node);
                }
            }
            if (bal < -1) {
                if (bf(node->right) <= 0) return leftRotate(node);
                else {
                    node->right = rightRotate(node->right);
                    return leftRotate(node);
                }
            }

            return node;
        }
};

//class definition
class AvlTree {
    public:
        //default constructor
        AvlTree() {}

        //methods
        //popMedian method takes no parameters, returns the integer value it removed from AvlTree
        int popMedian();

        //insert function takes an integer refence to insert into vector
        void insert(const int& median);

        //balance method used to simplify re-balancing small and large trees aftere pop and insert methods are applied
        void balance();
        
    private:
        AVL small, large;
};

#endif
