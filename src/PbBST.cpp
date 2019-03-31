/*
 *  Title : Heaps and AVL Trees
 *  Author : Erdem Ege Marasli
 *  ID : 21602156
 *  Section : 2
 *  Assignment : 3
 *  Description : PbBST implementation
 *
 */

#include "PbBST.h"
#include "PbBSTNode.h"
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
PbBST::PbBST() : rootPtr(NULL) {
} // end default constructor
PbBST::PbBST(const int& rootItem)
{
    rootPtr = new PbBSTNode(rootItem, NULL, NULL);
} // end constructor
PbBST::PbBST(const int& rootItem, const PbBST* leftTreePtr, const PbBST* rightTreePtr)
{
    rootPtr = new PbBSTNode(rootItem,copyTree(leftTreePtr->rootPtr),
                            copyTree(rightTreePtr->rootPtr));
}
    // end constructors

PbBST::PbBST(const PbBST& treePtr)
{
    rootPtr = copyTree(treePtr.rootPtr);
} // end copy constructor

PbBST::~PbBST()
{
    destroyTree(rootPtr);
}


PbBSTNode* PbBST::copyTree(const PbBSTNode* treePtr)
{
    PbBSTNode* newTreePtr = NULL;
    // Copy tree nodes during a preorder traversal
    if (treePtr != NULL)
    {
        // Copy node
        newTreePtr = new PbBSTNode(treePtr->getItem(), NULL, NULL);
        newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
        
    } // end if
    // Else tree is empty (newTreePtr is nullptr)
    return newTreePtr;
    
} // end copyTree

void PbBST::copyTreeOverload(PbBSTNode*& newTreePtr,PbBSTNode* treePtr)
{
    newTreePtr = NULL;
    // Copy tree nodes during a preorder traversal
    if (treePtr != NULL)
    {
        // Copy node
        newTreePtr = new PbBSTNode(treePtr->getItem(), NULL, NULL);
        copyTreeOverload(newTreePtr->leftChildPtr, treePtr->leftChildPtr);
        copyTreeOverload(newTreePtr->rightChildPtr, treePtr->rightChildPtr);
        
    } // end if
}


void PbBST::destroyTree(PbBSTNode*& subTreePtr)
{
    if (subTreePtr != NULL)
    {
        destroyTree(subTreePtr->leftChildPtr);
        destroyTree(subTreePtr->rightChildPtr);
        delete subTreePtr;
        subTreePtr = NULL;
    } // end if
} // end destroyTree

void PbBST::clear()
{
    destroyTree(rootPtr);
}

int PbBST::getHeightHelper(PbBSTNode* subTreePtr) const
{
    if (subTreePtr == NULL)
        return 0;
    else
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                       getHeightHelper(subTreePtr->getRightChildPtr()));
    
} // end getHeightHelper

int PbBST::getHeight()
{
    return getHeightHelper(rootPtr);
}

void PbBST::getNodeCountHelper(PbBSTNode*& subTreePtr, int &count)
{
    if(subTreePtr->leftChildPtr != NULL)
    {
        getNodeCountHelper(subTreePtr->leftChildPtr, count);
        count++;
    }
    if(subTreePtr->rightChildPtr !=NULL)
    {
        getNodeCountHelper(subTreePtr->rightChildPtr,count);
        count++;
    }
}

int PbBST::getNodeCount()
{
    if(rootPtr == NULL)
        return 0;
    int count = 1;
    getNodeCountHelper(rootPtr,count);
    return count;
}
int PbBST::findNodesRequired()
{
    return pow(2.0, double(getHeight())) - 1 - getNodeCount();
}
void PbBST::insertItem(PbBSTNode *& treePtr, int& newItem)
{
    
    // Position of insertion found; insert after leaf
    if (treePtr == NULL) {
        treePtr = new PbBSTNode(newItem, NULL, NULL);
        if (treePtr == NULL)
            cout << "Insert Failed" << endl;
    }
    // Else search for the insertion position
    else if (newItem < treePtr->getItem())
        insertItem(treePtr->leftChildPtr, newItem);
    else
        insertItem(treePtr->rightChildPtr, newItem);
}

void PbBST::insertKey(int key)
{
    insertItem(rootPtr,key);
}

void PbBST::deleteKey(int key)
{
    deleteItem(rootPtr, key);
}

void PbBST::deleteItem(PbBSTNode* &treePtr, int searchKey)
{
    if (treePtr == NULL) // Empty tree
        cout << "Delete Failed" << endl;
    
    // Position of deletion found
    else if (searchKey == treePtr->getItem())
        deleteNodeItem(treePtr);
    
    // Else search for the deletion position
    else if (searchKey < treePtr->getItem())
        deleteItem(treePtr->leftChildPtr, searchKey);
    else
        deleteItem(treePtr->rightChildPtr, searchKey);
}

void PbBST::deleteNodeItem(PbBSTNode * &nodePtr)
{
    PbBSTNode *delPtr;
    int replacementItem;
    
    
    // (1)  Test for a leaf
    if ( (nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL) )
    {
        delete nodePtr;
        nodePtr = NULL;
    }
    
    
    // (2)  Test for no left child
    else if (nodePtr->leftChildPtr == NULL)
    {
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
    // (3)  Test for no right child
    else if (nodePtr->rightChildPtr == NULL)
    {
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }
    
    // (4)  There are two children:
    //      Retrieve and delete the inorder successor
    else
    {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->setItem(replacementItem);
    }
    
}

void PbBST::processLeftmost(PbBSTNode *&nodePtr, int& treeItem)
{
    
    if (nodePtr->leftChildPtr == NULL) {
        treeItem = nodePtr->getItem();
        PbBSTNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL; // defense
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->leftChildPtr, treeItem);
}

void PbBST::operator=(const PbBST &rightHandSide)
{
    if ( &rightHandSide != this)
    {
        if(rootPtr != NULL)
            destroyTree(rootPtr);
        copyTreeOverload(rootPtr, rightHandSide.rootPtr);
    }
}

// Note: This method taken from our lecture which teacher explained for exam.
bool PbBST::isLevelFull(int x)
{
    int nodesInLevel = 0;
    this->isLevelFull(this->rootPtr, x, nodesInLevel);
    return nodesInLevel == pow(2,x-1);
}

// Note: This method taken from our lecture which teacher explained for exam.
void PbBST::isLevelFull(PbBSTNode *&nodePtr, int x, int &nodesInLevel)
{
    if(nodePtr == NULL)
        return;
    if(x == 1)
        nodesInLevel++;
    else
    {
        this->isLevelFull(nodePtr->leftChildPtr, x - 1, nodesInLevel);
        this->isLevelFull(nodePtr->rightChildPtr, x - 1, nodesInLevel);
    }
}

// Note: This method taken from our lecture which teacher explained for exam.
int PbBST::findFullBTLevel()
{
    int noOfLevels = this->getHeight();
    if(noOfLevels == 0)
        return 0;
    for(int i = 1; i <= noOfLevels; i++)
    {
        if(!this->isLevelFull(i))
            return i - 1;
    }
    return noOfLevels;
}

void PbBST::mirrorTree()
{
    if(rootPtr != NULL)
        mirrorTreeHelper(rootPtr);
}

void PbBST::mirrorTreeHelper(PbBSTNode*& nodePtr)
{
    if(nodePtr != NULL)
    {
        mirrorTreeHelper(nodePtr->leftChildPtr);
        mirrorTreeHelper(nodePtr->rightChildPtr);
        PbBSTNode *temp = nodePtr->rightChildPtr;
        nodePtr->rightChildPtr = nodePtr->leftChildPtr;
        nodePtr->leftChildPtr = temp;
    }
}

void PbBST::printLevel(PbBSTNode *&nodePtr, int level, int space)
{
    if(nodePtr == NULL || level < 1)
    {
        for(int i = 0; i < space * 5; i++)
            cout << " ";

        return;
    }

    if(level == 1)
    {
        for(int i = 0; i < space; i++)
            cout << " ";
        for(int i = 0; i < space; i++)
            cout << "-";
        cout << nodePtr->item;
        for(int i = 0; i < space; i++)
            cout << "-";
        for(int i = 0; i < space + space / 2 ; i++)
            cout << " ";
    }
    else
    {
        printLevel(nodePtr->leftChildPtr, level - 1, space);
        printLevel(nodePtr->rightChildPtr, level - 1, space);
    }
}


void PbBST::printTree()
{
    PbBSTNode* temp = rootPtr;
    int noOfLevels = getHeight();
    int space = getHeight() * 4;
    for(int i = 1; i <= noOfLevels; i++)
    {
        printLevel(temp, i, space);
        cout << endl;
        cout << endl;
        space = space / 2;
    }
}


