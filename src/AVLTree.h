/*
 *  Title : Heaps and AVL Trees
 *  Author : Erdem Ege Marasli
 *  ID : 21602156
 *  Section : 2
 *  Assignment : 3
 *  Description : AVLTree header
 *
 */

#ifndef AVLTree_h
#define AVLTree_h
#include "PbBST.h"
class AVLTree : public PbBST
{
private:
    void leftRotate(PbBSTNode*& nodePtr);
    void rightRotate(PbBSTNode*& nodePtr);
    int getHeightDiff(PbBSTNode* nodePtr);
    void insertHelper(PbBSTNode*& nodePtr, int key);
    void deleteKeyHelper(PbBSTNode*& nodePtr, int key);
public:
    AVLTree();
    AVLTree(const int& rootItem);
    AVLTree(const int& rootItem, const PbBST* leftTreePtr, const PbBST* rightTreePtr);
    AVLTree(const PbBST& tree);
    void insert(int val);
    void deleteKey(int val);
    
};
#endif /* AVLTree_h */
