//Rio Simpson
//myAVLtree method implementations
//NOTE: AVLtree class taken from Data Structures and Algorithm Analysis, 4th Edition, Mark Allen Weiss, adapted by Rio Simpson for this project

//libraries
#include "vector"
#include "iostream"
#include "algorithm"

//header file
#include "myAVLtree.hpp"

//my methods
void treeMedian(const std::vector<int>& instructions){
    //envoking avlTree class constructor
    //modified the avltree class to have two roots, one for a min tree, and one for a max tree
    //working with one object as opposed to two
    //distinction between trees is handled by insert and pop median
    AvlTree aTree;

    for (const int value : instructions) {
        if (value == -1) {
            aTree.getMediansToPrint().push_back(aTree.popMedian());
        } else {
            aTree.insert(value);
        }
    }

    //printing medians out after algorithm is finished
    for (const int median : aTree.getMediansToPrint()) {
        std::cout << median << " ";
    }
}

int AvlTree::popMedian(){

}

void AvlTree::insert(const int& median){

}

std::vector<int>& AvlTree::getMediansToPrint(){
    return mediansToPrint_;
}

//textbook methods
AvlTree::AvlTree( ) : minRoot{ nullptr }, maxRoot{nullptr}
{ }

// AvlTree::AvlTree( const AvlTree & rhs ) : root{ nullptr }
// {
//     root = clone( rhs.root );
// }

// AvlTree::AvlTree( AvlTree && rhs ) : root{ rhs.root }
// {
//     rhs.root = nullptr;
// }

AvlTree::~AvlTree( )
{
    makeEmpty( );
}

/**
 * Deep copy.
 */
AvlTree & AvlTree::operator=( const AvlTree & rhs )
{
    AvlTree copy = rhs;
    std::swap( *this, copy );
    return *this;
}
    
/**
 * Move.
 */
// AvlTree & AvlTree::operator=( AvlTree && rhs )
// {
//     std::swap( root, rhs.root );
    
//     return *this;
// }

/**
 * Find the smallest item in the tree.
 * Throw UnderflowException if empty.
 */
const int& AvlTree::findMin(std::string minMax) const
{
    // if( isEmpty( ) )
    //     throw std::UnderflowException{ };
    if (minMax == "min"){
        return findMin(minRoot)->median;
    } else if (minMax == "max"){
        return findMin(maxRoot)->median;
    }
    
}

/**
 * Find the largest item in the tree.
 * Throw UnderflowException if empty.
 */
const int & AvlTree::findMax(std::string minMax) const
{
    // if( isEmpty( ) )
    //     throw std::UnderflowException{ };
    if (minMax == "min"){
        return findMax( minRoot )->median;
    } else if (minMax == "max"){
        return findMax( maxRoot )->median;
    }
    
}

/**
 * Returns true if x is found in the tree.
 */
bool AvlTree::contains( const int & x, std::string minMax) const
{
    if (minMax == "min"){
        return contains( x, minRoot );
    } else if (minMax == "max"){
        return contains( x, maxRoot );
    }
}

/**
 * Test if the tree is logically empty.
 * Return true if empty, false otherwise.
 */
bool AvlTree::isEmpty(std::string minMax) const
{
    if (minMax == "min"){
        return minRoot == nullptr;
    } else if (minMax == "max"){
        return maxRoot == nullptr;
    }
    
}

/**
 * Print the tree contents in sorted order.
 */
// void AvlTree::printTree( ) const
// {
//     if( isEmpty( ) )
//         std::cout << "Empty tree" << std::endl;
//     else
//         printTree( root );
// }

/**
 * Make the tree logically empty.
 */
// void AvlTree::makeEmpty( )
// {
//     makeEmpty( root );
// }

/**
 * Insert x into the tree; duplicates are ignored.
 */
void AvlTree::insert( const int & x, std::string minMax)
{
    if (minMax == "min"){
        insert(x, minRoot);
    } else if (minMax == "max"){
        insert(x, maxRoot);
    }
    
}

/**
 * Insert x into the tree; duplicates are ignored.
 */
// void AvlTree::insert( int && x )
// {
//     insert( std::move( x ), root );
// }

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
void AvlTree::remove( const int & x, std::string minMax)
{
    if (minMax == "min"){
        remove(x, minRoot);
    } else if (minMax == "max"){
        remove(x, maxRoot);
    }
    
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void AvlTree::insert( const int & x, AvlNode * & t )
{
    if( t == nullptr )
        t = new AvlNode{ x, nullptr, nullptr };
    else if( x < t->median )
        insert( x, t->left );
    else if( t->median < x )
        insert( x, t->right );
    
    balance( t );
}

/**
 * Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void AvlTree::insert( int && x, AvlNode * & t )
{
    if( t == nullptr )
        t = new AvlNode{ std::move( x ), nullptr, nullptr };
    else if( x < t->median )
        insert( std::move( x ), t->left );
    else if( t->median < x )
        insert( std::move( x ), t->right );
    
    balance( t );
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the subtree.
 * Set the new root of the subtree.
 */
void AvlTree::remove( const int & x, AvlNode * & t )
{
    if( t == nullptr )
        return;   // Item not found; do nothing
    
    if( x < t->median )
        remove( x, t->left );
    else if( t->median < x )
        remove( x, t->right );
    else if( t->left != nullptr && t->right != nullptr ) // Two children
    {
        t->median = findMin( t->right )->median;
        remove( t->median, t->right );
    }
    else
    {
        AvlNode *oldNode = t;
        t = ( t->left != nullptr ) ? t->left : t->right;
        delete oldNode;
    }
    
    balance( t );
}

// Assume t is balanced or within one of being balanced
void AvlTree::balance( AvlNode * & t )
{
    if( t == nullptr )
        return;
    
    if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
        if( height( t->left->left ) >= height( t->left->right ) )
            rotateWithLeftChild( t );
        else
            doubleWithLeftChild( t );
    else
    if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
        if( height( t->right->right ) >= height( t->right->left ) )
            rotateWithRightChild( t );
        else
            doubleWithRightChild( t );
            
    t->height = max( height( t->left ), height( t->right ) ) + 1;
}

/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
AvlTree::AvlNode * AvlTree::findMin( AvlNode *t ) const
{
    if( t == nullptr )
        return nullptr;
    if( t->left == nullptr )
        return t;
    return findMin( t->left );
}

/**
 * Internal method to find the largest item in a subtree t.
 * Return node containing the largest item.
 */
AvlTree::AvlNode * AvlTree::findMax( AvlNode *t ) const
{
    if( t != nullptr )
        while( t->right != nullptr )
            t = t->right;
    return t;
}


/**
 * Internal method to test if an item is in a subtree.
 * x is item to search for.
 * t is the node that roots the tree.
 */
bool AvlTree::contains( const int & x, AvlNode *t ) const
{
    if( t == nullptr )
        return false;
    else if( x < t->median )
        return contains( x, t->left );
    else if( t->median < x )
        return contains( x, t->right );
    else
        return true;    // Match
}

/**
 * Internal method to make subtree empty.
 */
void AvlTree::makeEmpty( AvlNode * & t )
{
    if( t != nullptr )
    {
        makeEmpty( t->left );
        makeEmpty( t->right );
        delete t;
    }
    t = nullptr;
}

/**
 * Internal method to print a subtree rooted at t in sorted order.
 */
void AvlTree::printTree( AvlNode *t ) const
{
    if( t != nullptr )
    {
        printTree( t->left );
        std::cout << t->median << std::endl;
        printTree( t->right );
    }
}

/**
 * Internal method to clone subtree.
 */
AvlTree::AvlNode * AvlTree::clone( AvlNode *t ) const
{
    if( t == nullptr )
        return nullptr;
    else
        return new AvlNode{ t->median, clone( t->left ), clone( t->right ), t->height };
}
    // Avl manipulations
/**
 * Return the height of node t or -1 if nullptr.
 */
int AvlTree::height( AvlNode *t ) const
{
    return t == nullptr ? -1 : t->height;
}

int AvlTree::max( int lhs, int rhs ) const
{
    return lhs > rhs ? lhs : rhs;
}

/**
 * Rotate binary tree node with left child.
 * For AVL trees, this is a single rotation for case 1.
 * Update heights, then set new root.
 */
void AvlTree::rotateWithLeftChild( AvlNode * & k2 )
{
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    k2 = k1;
}

/**
 * Rotate binary tree node with right child.
 * For AVL trees, this is a single rotation for case 4.
 * Update heights, then set new root.
 */
void AvlTree::rotateWithRightChild( AvlNode * & k1 )
{
    AvlNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
    k2->height = max( height( k2->right ), k1->height ) + 1;
    k1 = k2;
}

/**
 * Double rotate binary tree node: first left child.
 * with its right child; then node k3 with new left child.
 * For AVL trees, this is a double rotation for case 2.
 * Update heights, then set new root.
 */
void AvlTree::doubleWithLeftChild( AvlNode * & k3 )
{
    rotateWithRightChild( k3->left );
    rotateWithLeftChild( k3 );
}

/**
 * Double rotate binary tree node: first right child.
 * with its left child; then node k1 with new right child.
 * For AVL trees, this is a double rotation for case 3.
 * Update heights, then set new root.
 */
void AvlTree::doubleWithRightChild( AvlNode * & k1 )
{
    rotateWithLeftChild( k1->right );
    rotateWithRightChild( k1 );
}