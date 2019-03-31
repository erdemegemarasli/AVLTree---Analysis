/*
 *  Title : Heaps and AVL Trees
 *  Author : Erdem Ege Marasli
 *  ID : 21602156
 *  Section : 2
 *  Assignment : 3
 *  Description : main function
 *
 */

#include <iostream>
#include <string>
#include "PbBST.h"
#include "analysis.h"
#include "AVLTree.h"


using namespace std;

int main()
{
    AVLTree tree;
    analysis a;
    tree.insert(5);
    tree.insert(10);
    tree.insert(15);
    tree.insert(60);
    tree.insert(8);
    tree.insert(40);
    tree.insert(2);
    tree.insert(30);
    tree.insert(17);
    tree.insert(12);
    tree.insert(74);
    cout<<"-----------------After Insertions-----------------"<<endl;
    tree.printTree();
    tree.deleteKey(30);
    tree.deleteKey(10);
    tree.deleteKey(8);
    tree.deleteKey(74);
    tree.deleteKey(5);
    cout<<"-----------------After Deletions-----------------"<<endl;
    tree.printTree();
    a.heightAnalysis();
    //tree.printTree();
    
}
