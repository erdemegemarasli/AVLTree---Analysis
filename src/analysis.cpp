/*
 *  Title : Heaps and AVL Trees
 *  Author : Erdem Ege Marasli
 *  ID : 21602156
 *  Section : 2
 *  Assignment : 3
 *  Description : Height analysis of AVL tree operations.
 *
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include "analysis.h"
#include "PbBST.h"
#include "AVLTree.h"
#include <algorithm>

using namespace std;
analysis::analysis(){}

void analysis::heightAnalysis()
{
    int *arr = new int[80000];
    int *arrRandom = new int[80000];
    AVLTree randomTree;
    AVLTree ascendingTree;
    AVLTree descendingTree;
    cout << "Part b - Height analysis of AVL  trees " <<endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Array Size        Random        Ascending        Descending" <<endl;
    cout << "---------------------------------------------------------------" << endl;
    for(int i = 4000; i < 80001; i+= 4000){
        for(int j = i - 4000; j < i; j++){
            arr[j] = j;
            arrRandom[j] = j;
            ascendingTree.insert(j);
        }
        random_shuffle(&arrRandom[0], &arrRandom[i - 1]);
        for(int k = i; k > -1; k--){
            descendingTree.insert(arr[k]);
            randomTree.insert(arrRandom[k]);
        }
        cout << i << "              " << randomTree.getHeight()<<"              " << ascendingTree.getHeight() << "              " << descendingTree.getHeight()<<endl;
    }
    delete [] arr;
    delete [] arrRandom;
    



    
}
