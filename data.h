/*********
 * author: Isaac Shepherd
 * file: data.h
 * holds prototypes for structures used in binary tree. DataNode structure make up the binary tree. Data structure
 * holds id and string information used for traversing in specific binary tree methods.
 *********/

#ifndef BINTREE_DATA_H
#define BINTREE_DATA_H

#include <string>
using std::string;

struct Data {
    int id;
    string information;
};

struct DataNode {
    Data data;
    DataNode *left, *right;
};

#endif /* BINTREE_DATA_H */
