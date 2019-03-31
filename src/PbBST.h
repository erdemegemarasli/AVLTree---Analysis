/*
 *  Title : Heaps and AVL Trees
 *  Author : Erdem Ege Marasli
 *  ID : 21602156
 *  Section : 2
 *  Assignment : 3
 *  Description : PbBST header
 *
 */

#ifndef PbBST_h
#define PbBST_h
#include "PbBSTNode.h"
#include <iostream>
#include <string>
using namespace std;

class PbBST
{
private:
    
    PbBSTNode* rootPtr;
    
protected:
    
    int getHeightHelper(PbBSTNode* subTreePtr) const;
    void destroyTree(PbBSTNode*& subTreePtr);
    void deleteItem(PbBSTNode*&, int key);
    void insertItem(PbBSTNode *& treePtr, int& newItem);
    void deleteNodeItem(PbBSTNode * &nodePtr);
    void processLeftmost(PbBSTNode *&nodePtr, int& treeItem);
    void clear();
    void copyTreeOverload(PbBSTNode*& newTreePtr,PbBSTNode* treePtr);
    void getNodeCountHelper(PbBSTNode*& subTreePtr, int &count);
    bool isLevelFull(int x);
    void isLevelFull(PbBSTNode*& nodePtr, int x, int& nodesInLevel);
    void mirrorTreeHelper(PbBSTNode*& nodePtr);
    void printLevel(PbBSTNode*& nodePtr, int level, int space);
    
public:
    
    PbBST();
    PbBST(const int& rootItem);
    PbBST(const int& rootItem, const PbBST* leftTreePtr, const PbBST* rightTreePtr);
    PbBST(const PbBST& tree);
    ~PbBST();
    
    void insertKey(int key);
    void deleteKey(int key);
    
    int getHeight();
    int getNodeCount();
    int findNodesRequired();
    
    int findFullBTLevel();
    
    void mirrorTree();
    void printTree();
    
    bool isEmpty();
    
    
    PbBSTNode* copyTree(const PbBSTNode* treePtr);
    
    void operator=(const PbBST& rightHandSide);
    friend class AVLTree;
};

#endif /* PbBST_h */
