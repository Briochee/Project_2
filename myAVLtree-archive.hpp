//Rio Simpson
//Project 2, myList class
//NOTE: AVLtree class taken from Data Structures and Algorithm Analysis, 4th Edition, Mark Allen Weiss

#ifndef MYAVLTREE_HPP
#define MYAVLTREE_HPP

//#include "dsexceptions.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <exception>
#include <string>

// AvlTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

//treeMedian Signature
void treeMedian(const std::vector<int>& instructions);

class AvlTree {
    public:
        //methods
        int popMedian();

        void insert(const int& median);

        std::vector<int>& getMediansToPrint();

        AvlTree( );
        
        AvlTree( const AvlTree & rhs );

        AvlTree( AvlTree && rhs );
        
        ~AvlTree( );

        /**
         * Deep copy.
         */
        AvlTree & operator=( const AvlTree & rhs );
            
        /**
         * Move.
         */
        AvlTree & operator=( AvlTree && rhs );
        
        /**
         * Find the smallest item in the tree.
         * Throw UnderflowException if empty.
         */
        //modified
        const int& findMin(std::string minMax = "min") const;

        /**
         * Find the largest item in the tree.
         * Throw UnderflowException if empty.
         */
        //modified
        const int & findMax(std::string minMax = "min") const;

        /**
         * Returns true if x is found in the tree.
         */
        bool contains( const int & x, std::string minMax = "min") const;

        /**
         * Test if the tree is logically empty.
         * Return true if empty, false otherwise.
         */
        bool isEmpty(std::string minMax = "min") const;

        /**
         * Print the tree contents in sorted order.
         */
        void printTree( ) const;

        /**
         * Make the tree logically empty.
         */
        void makeEmpty( );

        /**
         * Insert x into the tree; duplicates are ignored.
         */
        void insert( const int & x, std::string minMax = "min");
        
        /**
         * Insert x into the tree; duplicates are ignored.
         */
        void insert( int && x );
        
        /**
         * Remove x from the tree. Nothing is done if x is not found.
         */
        void remove( const int & x, std::string minMax = "min");

    private:
        struct AvlNode
        {
            int median;
            AvlNode   *left;
            AvlNode   *right;
            int       height;

            //size counter for number of nodes
            int size;

            AvlNode( const int & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
            : median{ ele }, left{ lt }, right{ rt }, height{ h } { }
            
            AvlNode( int && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
            : median{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
        };

        //root pointer for values greater than the median
        AvlNode *maxRoot;
        //root pinter for values less than the median
        AvlNode *minRoot;


        /**
         * Internal method to insert into a subtree.
         * x is the item to insert.
         * t is the node that roots the subtree.
         * Set the new root of the subtree.
         */
        void insert( const int & x, AvlNode * & t );

        /**
         * Internal method to insert into a subtree.
         * x is the item to insert.
         * t is the node that roots the subtree.
         * Set the new root of the subtree.
         */
        void insert( int && x, AvlNode * & t );
        
        /**
         * Internal method to remove from a subtree.
         * x is the item to remove.
         * t is the node that roots the subtree.
         * Set the new root of the subtree.
         */
        void remove( const int & x, AvlNode * & t );
        
        static const int ALLOWED_IMBALANCE = 1;

        // Assume t is balanced or within one of being balanced
        void balance( AvlNode * & t );
        
        /**
         * Internal method to find the smallest item in a subtree t.
         * Return node containing the smallest item.
         */
        AvlNode * findMin( AvlNode *t ) const;

        /**
         * Internal method to find the largest item in a subtree t.
         * Return node containing the largest item.
         */
        AvlNode * findMax( AvlNode *t ) const;


        /**
         * Internal method to test if an item is in a subtree.
         * x is item to search for.
         * t is the node that roots the tree.
         */
        bool contains( const int & x, AvlNode *t ) const;

        /**
         * Internal method to make subtree empty.
         */
        void makeEmpty( AvlNode * & t );

        /**
         * Internal method to print a subtree rooted at t in sorted order.
         */
        void printTree( AvlNode *t ) const;

        /**
         * Internal method to clone subtree.
         */
        AvlNode * clone( AvlNode *t ) const;
            // Avl manipulations
        /**
         * Return the height of node t or -1 if nullptr.
         */
        int height( AvlNode *t ) const;

        int max( int lhs, int rhs ) const;

        /**
         * Rotate binary tree node with left child.
         * For AVL trees, this is a single rotation for case 1.
         * Update heights, then set new root.
         */
        void rotateWithLeftChild( AvlNode * & k2 );

        /**
         * Rotate binary tree node with right child.
         * For AVL trees, this is a single rotation for case 4.
         * Update heights, then set new root.
         */
        void rotateWithRightChild( AvlNode * & k1 );

        /**
         * Double rotate binary tree node: first left child.
         * with its right child; then node k3 with new left child.
         * For AVL trees, this is a double rotation for case 2.
         * Update heights, then set new root.
         */
        void doubleWithLeftChild( AvlNode * & k3 );

        /**
         * Double rotate binary tree node: first right child.
         * with its left child; then node k1 with new right child.
         * For AVL trees, this is a double rotation for case 3.
         * Update heights, then set new root.
         */
        void doubleWithRightChild( AvlNode * & k1 );

        //my container to store medians for printing
        std::vector<int> mediansToPrint_;
};

#include "myAVLtree.cpp"
#endif