#include <iostream>
#include <string>
#include <cstring>
#include "Node.h"
#include "BST.h"

using namespace std;

bool userWantsToContinue() {
    string userInput;
    cout << "Shall we play again? [Yes or No]" << endl;
    getline(cin, userInput);
    if (strcmp(userInput.c_str(), "Yes") == 0) {
        return true;
    }
    return false;
}
int main() {
    string userInput;
    BST* bst = new BST();
    bst->initialize();
    Node* current = bst->getRoot();
    Node* prev = NULL;
    string prevDirection;
    bst->inOrder(current);
    cout << endl;
    bool isContinue = true;
    while (isContinue) {
        if (current == NULL) {
            isContinue = false;

        }
        else {
            if (bst->isExternal(current) == true) {
                cout << "My guess is " << current->data << ". Aam I right? [Yes or No]" << endl;
                getline(cin, userInput);
                if (strcmp(userInput.c_str(), "Yes") == 0) {
                    if (userWantsToContinue() == true) {
                        current = bst->getRoot();
                        isContinue = true;
                        continue;
                    }
                    else {
                        cout << "Thank you for teaching me a thing or two.";
                        break;
                    }
                }
                else {
                    cout << "I giveup. What are you?" << endl;
                    getline(cin, userInput);
                    string newEntry = userInput;
                    cout << "Please type an yes or no question that distinguish " << newEntry << " from a "
                        << current->data << "." << endl;
                    cout << "Your question:" << endl;
                    getline(cin, userInput);
                    string newQuestion = userInput;
                    Node* questionNode = new Node(newQuestion);
                    Node* newEntryNode = new Node(newEntry);
                    cout << "As a " << newEntry << ", " << newQuestion << " Please answer [Yes or No]" << endl;
                    getline(cin, userInput);
                    if (strcmp(prevDirection.c_str(), "l") == 0) {
                        prev->left = questionNode;
                        questionNode->left = current;
                        questionNode->right = newEntryNode;
                    }
                    else {
                        prev->right = questionNode;
                        questionNode->left = current;
                        questionNode->right = newEntryNode;
                    }
                    if (userWantsToContinue() == true) {
                        current = bst->getRoot();
                        isContinue = true;
                        continue;
                    }
                    else {
                        cout << "Thank you for teaching me a thing or two.";
                        break;
                    }

                }
            }
            else {
                cout << "Are you " << current->data << " Please Answer [Yes or No]:";
                getline(cin, userInput);
                if (strcmp(userInput.c_str(), "Yes") == 0) {
                    cout << "Yes" << endl;
                    prev = current;
                    prevDirection = "right";
                    current = current->right;
                }
                else {
                    cout << "No" << endl;
                    prev = current;
                    prevDirection = "left";
                    current = current->left;
                }
            }
        }
    }
    return 0;
}