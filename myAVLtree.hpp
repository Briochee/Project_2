//Rio Simpson
//Project 2, myList class
//NOTE: AVLtree class taken from Data Structures and Algorithm Analysis, 4th Edition, Mark Allen Weiss, adapted by Rio Simpson for this project
//NOTE: Appropriate modifications taken from https://www.programiz.com

#ifndef MYAVLTREE_HPP
#define MYAVLTREE_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

//treeMedian Signature
void treeMedian(const std::vector<int>* instructions);

//node structure
struct Node {
    int val, height;
    Node *left, *right;

    Node(const int& val) : val{val}, left{nullptr}, right{nullptr}, height{1} {}
};

//structure of avl tree
struct AVL {
    public:
        //Root node
        Node* root;

        //default constructor
        AVL(){
            root = nullptr;
            size = 0;
        }

        //Removes the maximum node in the tree
        int popMax() {
            if (!root) return -1;

            Node* ptr = root;
            while (ptr->right) ptr = ptr->right;

            int max = ptr->val;

            root = deleteNode(root, ptr->val);

            size--;
            return max;
        }

        //Removes the minimum node in the tree
        int popMin() {
            if (!root) return -1;

            Node* ptr = root;
            while (ptr->left) ptr = ptr->left;

            int min = ptr->val;

            root = deleteNode(root, ptr->val);

            size--;
            return min;
        }

        //Returns max number in tree
        int getMax() {
            if (!root) return -1;

            Node* ptr = root;
            while (ptr->right) ptr = ptr->right;

            return ptr->val;
        }

        //Adds node to tree
        void push(int val) {
            root = insertNode(root,val);
            size++;
        }

        //Returns size of tree
        int getSize() {return size;}

        //Checks if tree is empty or not
        bool isEmpty() {return !root;}

    private:
        int size;
        
        //Returns node height
        int getHeight(Node* node) {
            if (!node) return 0;
            return node->height;
        }

        //Updates a nodes height
        void updateHeight(Node* node) {node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;}

        //Gets the balance factor of a node
        int bf (Node* node) {
            if (!node) return 0;
            return getHeight(node->left) - getHeight(node->right);
        }

        //Performs left rotation
        Node* leftRotate(Node* node) {
            Node* new_root = node->right;
            Node* temp = new_root->left;

            new_root->left = node;
            node->right = temp;

            updateHeight(node);
            updateHeight(new_root);

            return new_root;
        }

        //Performs right rotation
        Node* rightRotate(Node* node) {
            Node* new_root = node->left;
            Node* temp = new_root->right;

            new_root->right = node;
            node->left = temp;

            updateHeight(node);
            updateHeight(new_root);

            return new_root;
        }

        //Finds the minimum of current node
        Node* minNode(Node* node) {
            Node *ptr = node;
            while (ptr->left) ptr = ptr->left;
            return ptr;
        }

        //Inserts node into tree
        Node* insertNode(Node* node, int val) {
            if (!node) return new Node(val);

            if (val <= node->val) node->left = insertNode(node->left, val);
            else if (val > node->val) node->right = insertNode(node->right, val);

            updateHeight(node);
            int bal = bf(node);

            //Balance the tree
            if (bal > 1) {
                if (val <= node->left->val) return rightRotate(node);
                else if (val > node->left->val) {
                    node->left = leftRotate(node->left);
                    return rightRotate(node);
                }
            }
            if (bal < -1) {
                if (val > node->right->val) return leftRotate(node);
                else if (val <= node->right->val) {
                    node->right = rightRotate(node->right);
                    return leftRotate(node);
                }
            }

            return node;
        }

        //Removes node from tree
        Node* deleteNode(Node* node, int val) {
            if (!node) return node;

            if (val < node->val) node->left = deleteNode(node->left, val);
            else if (val > node->val) node->right = deleteNode(node->right, val);
            else {
                if ((!node->left) || (!node->right)) {
                    Node* temp;
                    if (node->left) temp = node->left;
                    else temp = node->right;

                    if (!temp) {
                        temp = node;
                        node = nullptr;
                    }
                    else *node = *temp;

                    delete temp;
                }
                else {
                    Node* temp = minNode(node->right);
                    node->val = temp->val;
                    node->right = deleteNode(node->right, temp->val);
                }
            }

            if (!node) return node;

            updateHeight(node);
            int bal = bf(node);

            //Balance the tree
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

//class Definition
class AvlTree {
    public:
        //default Constructor
        AvlTree() {}

        //methods
        void insert(const int& num);
        int popMedian();
        void rebalance();
        
    private:
        AVL small, large;
};

#endif
