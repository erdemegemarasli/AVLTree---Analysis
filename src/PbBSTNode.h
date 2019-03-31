/*
 *  Title : Heaps and AVL Trees
 *  Author : Erdem Ege Marasli
 *  ID : 21602156
 *  Section : 2
 *  Assignment : 3
 *  Description : PbBSTNode implementation
 *
 */

#ifndef PbBSTNode_h
#define PbBSTNode_h
#include <iostream>
#include <string>
using namespace std;

class PbBSTNode
{     // a node in the tree
private:
    
    
    
    int item;         // a data item in the tree
    PbBSTNode *leftChildPtr;    // pointers to children
    PbBSTNode *rightChildPtr;
public:
    
    PbBSTNode();
    PbBSTNode(const int&, PbBSTNode* = NULL, PbBSTNode* = NULL);
    void setItem(const int& nodeItem);
    int getItem() const;
    bool isLeaf();
    PbBSTNode* getLeftChildPtr() const;
    PbBSTNode* getRightChildPtr() const;
    void setLeftChildPtr(PbBSTNode* leftPtr);
    void setRightChildPtr(PbBSTNode* rightPtr);
    
    // friend class - can access private parts
    friend class PbBST;
    friend class AVLTree;
};

#endif /* PbBSTNode_h */
