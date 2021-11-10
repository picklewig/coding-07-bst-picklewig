/*
 * Your comment header here
 */

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include "data.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class BinTree{
    private:
        DataNode *root;
        int count;
        //overloads
        void clear(DataNode*);
        bool AddNode(DataNode*, DataNode**);
        DataNode* removeNode(int, DataNode*);
        bool getNode(Data*, int, DataNode*);
        bool contains(int, DataNode*);
        int getHeight(DataNode*);
        void displayPreOrder(DataNode*);
        void displayPostOrder(DataNode*);
        void displayInOrder(DataNode*);
    public:
        BinTree();
        ~BinTree();
        //non-overloading methods
        bool isEmpty();
        int getCount();
        bool getRootData(Data*);
        void DisplayTree();
        //overloading methods
        void clear();
        bool AddNode(int, const string*);
        bool removeNode(int);
        bool getNode(Data*, int);
        bool contains(int);
        int getHeight();
        void displayPreOrder();
        void displayPostOrder();
        void displayInOrder();
};


#endif /* BINTREE_BINTREE_H */

