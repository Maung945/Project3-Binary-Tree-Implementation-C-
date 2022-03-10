#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;


struct Node {
    string data;
    Node* left;
    Node* right;
    Node(string val) :data(val), left(NULL), right(NULL) {}
};

#endif //NODE_H


