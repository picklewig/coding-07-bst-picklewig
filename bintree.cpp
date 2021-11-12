/*
 * Your comment header here
 */

#include "bintree.h"

BinTree::BinTree(){
    root = NULL;
    count = 0;
}

BinTree::~BinTree(){
    clear();
}

bool BinTree::isEmpty(){
    bool empty = false;
    if(root == NULL){
        empty = true;
    }
    return empty;
}

int BinTree::getCount(){
    return count;
}

bool BinTree::getRootData(Data* dataStruct){
    bool gotRootData = false;
    if(root){
        dataStruct->information = root->data.information;
        dataStruct->id = root->data.id;
        gotRootData = true;
    }
    else{
        dataStruct->information = "";
        dataStruct->id = -1;
    }
    return gotRootData;
}

void BinTree::displayTree(){
    if(isEmpty()){
        cout << "Tree is Empty" << endl;
    }
    else{
        cout << "Tree is NOT empty" << endl;
    }
    cout << "Height: " << getHeight() << endl;
    cout << endl << "Pre-Order Traversal" << endl;
    displayPreOrder();
    cout << endl << "In-Order Traversal" << endl;
    displayInOrder();
    cout << endl << "Post-Order Traversal" << endl;
    displayPostOrder();
}

//public overloaded methods

void BinTree::clear(){
    clear(root);
}

bool BinTree::addNode(int id, const string *info){
    //validate info, make DataNode, pass to private addNode
    bool added = false;
    if(id > 0 and *info != ""){
        DataNode* newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = *info;
        if(addNode(newNode, &root)){
            added = true;
            count++;
        }
        else{
            delete newNode;
        }
    }
    return added;
}

bool BinTree::removeNode(int id){
    int tempCount = count;
    bool removed = false;
    removeNode(id, root);
    if(count < tempCount){
        removed = true;
    }
    return removed;
}

bool BinTree::getNode(Data* dataStruct, int id){
    bool gotten = false;
    if(id > 0){
        if(getNode(dataStruct, id, root)){
            gotten = true;
        }
    }
    return gotten;
}

bool BinTree::contains(int id){
    bool isContained = false;
    if(id > 0){
        if(contains(id, root)){
            isContained = true;
        }
    }
    return isContained;
}

int BinTree::getHeight(){
    return getHeight(root);
}

void BinTree::displayPreOrder(){
    displayPreOrder(root);
}

void BinTree::displayPostOrder(){
    displayPostOrder(root);
}

void BinTree::displayInOrder(){
    displayInOrder(root);
}

//private overloaded methods

void BinTree::clear(DataNode*){

}

bool BinTree::addNode(DataNode* newNode, DataNode** tempRoot){
    bool added = false;
    if(tempRoot){
        if(newNode->data.id < tempRoot->data.id){
            addNode(newNode, &tempRoot->left);
        }
    }
    return added;
}

DataNode* BinTree::removeNode(int, DataNode*){

}

bool BinTree::getNode(Data*, int, DataNode*){

}

bool BinTree::contains(int, DataNode*){

}

int BinTree::getHeight(DataNode*){

}

void BinTree::displayPreOrder(DataNode* temproot){
    if(temproot){
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if(temproot->left){ //validation argument it doesn't need to open a new recursion
            displayInOrder(temproot->left);
        }
        if(temproot->right){
            displayInOrder(temproot->right);
        }
    }
    return;
}

void BinTree::displayPostOrder(DataNode* temproot){
    if(temproot){
        if(temproot->left){ //validation argument it doesn't need to open a new recursion
            displayInOrder(temproot->left);
        }
        if(temproot->right){
            displayInOrder(temproot->right);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
    }
    return;
}

void BinTree::displayInOrder(DataNode* temproot){
    if(temproot){
        if(temproot->left){ //validation argument it doesn't need to open a new recursion
            displayInOrder(temproot->left);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if(temproot->right){
            displayInOrder(temproot->right);
        }
    }
    return;
}

//method for finding the minimum value node

DataNode* BinTree::minValueNode(DataNode* node){
    DataNode* current = node;
    while(current and current->left != NULL){
        current = current->left;
    }
    return current;
}