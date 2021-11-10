/*
 * Your comment header here
 */

#include "bintree.h"

BinTree::BinTree(){
    *root = NULL;
    count = 0;
}

BinTree::~BinTree(){
    clear();
}

bool BinTree::isEmpty(){

}

int BinTree::getCount(){

}

bool BinTree::getRootData(Data *){

}

void BinTree::DisplayTree(){

}

//public overloaded methods

void BinTree::clear(){

}

bool BinTree::addNode(int id, const string *info){
    //validate info, make DataNode, pass to private addNode
    bool added = false;
    if(id > 0 and *info != ""){
        DataNode* newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = info;
        if(addNode(newNode, root)){
            added = true;
            count++;
        }
    }
    return added;
}

bool BinTree::removeNode(int){

}

bool BinTree::getNode(Data*, int){

}

bool BinTree::contains(int){

}

int BinTree::getHeight(){

}

void BinTree::displayPreOrder(){

}

void BinTree::displayPostOrder(){

}

void BinTree::displayInOrder(){

}

//private overloaded methods

void BinTree::clear(DataNode*){

}

bool BinTree::AddNode(DataNode*, DataNode**){

}

DataNode* BinTree::removeNode(int, DataNode*){

}

bool BinTree::getNode(Data*, int, DataNode*){

}

bool BinTree::contains(int, DataNode*){

}

int BinTree::getHeight(DataNode*){

}

void BinTree::displayPreOrder(DataNode*){

}

void BinTree::displayPostOrder(DataNode*){

}

void BinTree::displayInOrder(DataNode*){

}