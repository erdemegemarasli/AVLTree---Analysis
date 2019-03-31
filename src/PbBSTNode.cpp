/*
 *  Title : Heaps and AVL Trees
 *  Author : Erdem Ege Marasli
 *  ID : 21602156
 *  Section : 2
 *  Assignment : 3
 *  Description : PbBSTNode header
 *
 */
#include "PbBSTNode.h"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

PbBSTNode::PbBSTNode(){}

PbBSTNode::PbBSTNode(const int& nodeItem,PbBSTNode *left, PbBSTNode *right)
{
    setItem(nodeItem);
    setLeftChildPtr(left);
    setRightChildPtr(right);
}
void PbBSTNode::setItem(const int& nodeItem)
{
    item = nodeItem;
}

int PbBSTNode::getItem() const
{
    return item;
}

PbBSTNode* PbBSTNode::getLeftChildPtr() const
{
    return leftChildPtr;
}

PbBSTNode* PbBSTNode::getRightChildPtr() const
{
    return rightChildPtr;
}

void PbBSTNode::setLeftChildPtr(PbBSTNode *leftPtr)
{
    leftChildPtr = leftPtr;
}

void PbBSTNode::setRightChildPtr(PbBSTNode *rightPtr)
{
    rightChildPtr = rightPtr;
}


