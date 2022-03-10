#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
#include "Node.h"


class BST {
private:
    Node* root;
public:
    BST();
    ~BST();
    void insert(Node* treeNode, string data);
    void inOrder(Node* treeNode);
    void initialize();
    string getData(Node* treeNode);
    bool isExternal(Node* treeNode);
    Node* getRoot();
};

#endif //BST_H

