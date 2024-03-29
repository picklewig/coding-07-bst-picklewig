/**********
  * author: Isaac Shepherd
 * file: bintree.cpp
 * defines methods, contructor, and destructor of class prototype in bintree.h
 ************/

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
    cout << "Node count: " << getCount() << endl;
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
    root = NULL;
}

bool BinTree::addNode(int id, const string *info){
    //validate info, make DataNode, pass to private addNode
    bool added = false;
    if(id > 0 and *info != ""){
        DataNode* newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = *info;
        newNode->left = NULL;
        newNode->right = NULL;
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
    root = removeNode(id, root);
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

void BinTree::clear(DataNode* tempRoot){
    if(tempRoot){
        clear(tempRoot->left);
        clear(tempRoot->right);
        tempRoot->left = NULL;
        tempRoot->right = NULL;
        delete tempRoot;
        count--;
    }
    return;
}

bool BinTree::addNode(DataNode* newNode, DataNode** tempRoot){
    bool added = false;
    if(*tempRoot){
        if(newNode->data.id < (*tempRoot)->data.id){
            added = addNode(newNode, &((*tempRoot)->left));
        }
        if(newNode->data.id > (*tempRoot)->data.id){
            added = addNode(newNode, &((*tempRoot)->right));
        }
    }
    else{
        *tempRoot = newNode;
        added = true;
    }
   return added;
}

DataNode* BinTree::removeNode(int id, DataNode* tempRoot){
    if(tempRoot){
        if(id < tempRoot->data.id){
            tempRoot->left = removeNode(id, tempRoot->left);
        }
        else if(id > tempRoot->data.id){
            tempRoot->right = removeNode(id, tempRoot->right);
        }
        else{
            DataNode* nodeHolder;
            if(tempRoot->left == NULL and tempRoot->right == NULL){ //no child case
                delete tempRoot;
                tempRoot = NULL;
                count--;
            }
            else if(tempRoot->left == NULL){ //one child cases
                nodeHolder = tempRoot;
                tempRoot = tempRoot->right;
                delete nodeHolder;
                count--;
            }
            else if(tempRoot->right == NULL){
                nodeHolder = tempRoot;
                tempRoot = tempRoot->left;
                delete nodeHolder;
                count--;
            }
            else{ //two child case
                nodeHolder = minValueNode(tempRoot->right);
                tempRoot->data.id = nodeHolder->data.id;
                tempRoot->data.information = nodeHolder->data.information;
                tempRoot->right = removeNode(nodeHolder->data.id, tempRoot->right);
            }
        }
    }
    return tempRoot;
}

bool BinTree::getNode(Data* dataStruct, int id, DataNode* tempRoot){
    bool gotten;
    if(tempRoot){
        if(id == tempRoot->data.id){
            gotten = true;
        }
        else{
            if(id < tempRoot->data.id){
                gotten = getNode(dataStruct, id, tempRoot->left);
            }
            if(id > tempRoot->data.id){
                gotten = getNode(dataStruct, id, tempRoot->right);
            }
        }
    }
    if(gotten){
        dataStruct->id = tempRoot->data.id;
        dataStruct->information = tempRoot->data.information;
    }
    return gotten;
}

bool BinTree::contains(int id, DataNode* tempRoot){
    bool isContained = false;
    if(tempRoot){
        if(id == tempRoot->data.id) {
            isContained = true;
        }
        else{
            if(id < tempRoot->data.id){
                isContained = contains(id, tempRoot->left);
            }
            if(id > tempRoot->data.id){
                isContained = contains(id, tempRoot->right);
            }
        }
    }
    return isContained;
}

int BinTree::getHeight(DataNode* tempRoot){
    int leftHeight = 0;
    int rightHeight = 0;
    int height = 0;
    if(tempRoot){
        if(tempRoot->left){
            leftHeight = getHeight(tempRoot->left);
        }
        if(tempRoot->right){
            rightHeight = getHeight(tempRoot->right);
        }
        height = max(leftHeight, rightHeight) + 1;
    }
    return height;
}

void BinTree::displayPreOrder(DataNode* temproot){
    if(temproot){
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if(temproot->left){
            displayPreOrder(temproot->left);
        }
        if(temproot->right){
            displayPreOrder(temproot->right);
        }
    }
    return;
}

void BinTree::displayPostOrder(DataNode* temproot){
    if(temproot){
        if(temproot->left){
            displayPostOrder(temproot->left);
        }
        if(temproot->right){
            displayPostOrder(temproot->right);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
    }
    return;
}

void BinTree::displayInOrder(DataNode* temproot){
    if(temproot){
        if(temproot->left){
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