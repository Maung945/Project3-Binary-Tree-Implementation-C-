#include <string>
#include <iostream>
#include "Node.h"
#include "BST.h"

using namespace std;

BST::BST() :root(NULL) {}

void BST::initialize() {
    root = new Node("a mammal?");
    Node* mammal = new Node("Are you bigger than a cat?");
    root->right = mammal;
    Node* cow = new Node("Cow");
    mammal->right = cow;
    Node* rabbit = new Node("Rabbit");
    mammal->left = rabbit;
    Node* bird = new Node("Are you bigger than sparrow?");
    root->left = bird;
    Node* crow = new Node("Crow");
    bird->right = crow;
    Node* hummingBird = new Node("Humming bird");
    bird->left = hummingBird;
}

Node* BST::getRoot() {
    return root;
}

void BST::insert(Node* treeNode, string data) {
    if (treeNode == NULL) {
        treeNode = new Node(data);
        root = treeNode;
    }
}

string BST::getData(Node* treeNode) {
    if (treeNode != NULL) {
        return treeNode->data;
    }
    return NULL;
}
void BST::inOrder(Node* treeNode) {

    if (treeNode == NULL) {
        cout << "---" << endl;
        return;
    }
    inOrder(treeNode->left);
    cout << treeNode->data << " ";
    inOrder(treeNode->right);

}

bool BST::isExternal(Node* treeNode) {
    if (treeNode != NULL) {
        if ((treeNode->right == NULL) && (treeNode->left == NULL)) {
            return true;
        }
    }
    return false;
}
