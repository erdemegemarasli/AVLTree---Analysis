/*
 *  Title : Heaps and AVL Trees
 *  Author : Erdem Ege Marasli
 *  ID : 21602156
 *  Section : 2
 *  Assignment : 3
 *  Description : AVLTree implementation
 *
 */

#include "AVLTree.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "PbBSTNode.h"
using namespace std;

AVLTree :: AVLTree() : PbBST(){}
AVLTree :: AVLTree(const int& rootItem) : PbBST(rootItem){}
AVLTree :: AVLTree(const int& rootItem, const PbBST* leftTreePtr, const PbBST* rightTreePtr) : PbBST(rootItem, leftTreePtr, rightTreePtr){}
AVLTree :: AVLTree(const PbBST& tree) : PbBST(tree){}

void AVLTree::insert(int val){
    insertHelper(rootPtr, val);
}
void AVLTree::insertHelper(PbBSTNode *&nodePtr, int key){
    // Position of insertion found; insert after leaf
    if (nodePtr == NULL) {
        nodePtr = new PbBSTNode(key, NULL, NULL);
        if (nodePtr == NULL)
            cout << "Insert Failed" << endl;
    }
    // Else search for the insertion position
    else if (key < nodePtr->getItem())
    {
        insertHelper(nodePtr->leftChildPtr, key);
        int heightDiff = getHeightDiff(nodePtr);
        // left left
        if(heightDiff == 2)
        {
            if(key < nodePtr->leftChildPtr->item)
                rightRotate(nodePtr);
            else
            {
                leftRotate(nodePtr->leftChildPtr);
                rightRotate(nodePtr);
            }
        }
    }
    else if(key > nodePtr->getItem())
    {
        insertHelper(nodePtr->rightChildPtr, key);
        int heightDiff = getHeightDiff(nodePtr);
        // right right
        if(heightDiff == -2)
        {
            if(key > nodePtr->rightChildPtr->item)
                leftRotate(nodePtr);
            else
            {
                rightRotate(nodePtr->rightChildPtr);
                leftRotate(nodePtr);
            }
        }
    }
    
}

int AVLTree::getHeightDiff(PbBSTNode *nodePtr){
    if(nodePtr == NULL)
        return 0;
    return getHeightHelper(nodePtr->leftChildPtr) - getHeightHelper(nodePtr->rightChildPtr);
}
void AVLTree::deleteKey(int val){
    deleteKeyHelper(rootPtr, val);
}
void AVLTree::deleteKeyHelper(PbBSTNode *&nodePtr, int key){

    if(nodePtr == NULL)
        return;
    else if (key < nodePtr->getItem())
    {
        deleteKeyHelper(nodePtr->leftChildPtr, key);
    }
    else if(key > nodePtr->getItem())
    {
        deleteKeyHelper(nodePtr->rightChildPtr, key);
    }
    else
    {
        // (1)  Test for a leaf
        if ( (nodePtr->leftChildPtr == NULL) && (nodePtr->rightChildPtr == NULL) )
        {
            delete nodePtr;
            nodePtr = NULL;
        }
        
        
        // (2)  Test for no left child
        else if (nodePtr->leftChildPtr == NULL)
        {
            PbBSTNode *delPtr;
            delPtr = nodePtr;
            nodePtr = nodePtr->rightChildPtr;
            delPtr->rightChildPtr = NULL;
            delete delPtr;
        }
        // (3)  Test for no right child
        else if (nodePtr->rightChildPtr == NULL)
        {
            PbBSTNode *delPtr;
            delPtr = nodePtr;
            nodePtr = nodePtr->leftChildPtr;
            delPtr->leftChildPtr = NULL;
            delete delPtr;
        }
        
        // (4)  There are two children:
        //      Retrieve and delete the inorder successor
        else
        {
            processLeftmost(nodePtr->rightChildPtr, key);
            nodePtr->setItem(key);
            deleteKeyHelper(nodePtr->rightChildPtr,key);
        }
    }
    
    if(nodePtr == NULL)
        return;
    int heightDiff = getHeightDiff(nodePtr);
    // left left
    if(heightDiff == 2)
    {
        if(key < nodePtr->leftChildPtr->item)
            rightRotate(nodePtr);
        else
        {
            leftRotate(nodePtr->leftChildPtr);
            rightRotate(nodePtr);
        }
    }
    else if(heightDiff == -2)
    {
        if(key > nodePtr->rightChildPtr->item)
            leftRotate(nodePtr);
        else
        {
            rightRotate(nodePtr->rightChildPtr);
            leftRotate(nodePtr);
        }
    }

    
}

void AVLTree::leftRotate(PbBSTNode *&nodePtr){
    if(nodePtr->rightChildPtr != NULL){
        PbBSTNode *temp = nodePtr->rightChildPtr;
        nodePtr->rightChildPtr = temp->leftChildPtr;
        temp->leftChildPtr = nodePtr;
        nodePtr = temp;
    }
    
}
void AVLTree::rightRotate(PbBSTNode *&nodePtr){
    if(nodePtr->leftChildPtr != NULL){
        PbBSTNode *temp = nodePtr->leftChildPtr;
        nodePtr->leftChildPtr = temp->rightChildPtr;
        temp->rightChildPtr = nodePtr;
        nodePtr = temp;
    }
    
}
