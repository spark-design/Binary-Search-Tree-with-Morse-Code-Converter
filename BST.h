#pragma once
#include "Morse.h"
#include "Node.h"
#include <math.h>
#include <vector>
#include <string>
using namespace::std;


class BST
{
private:

    // Class variables
	Node* root;
    bool pinsert(Node *&node, int data, char morseChar);
    bool premove(Node *&node, int data, char morseChar);
    bool find(Node* node, int data);
    void pinOrder(Node* node);
    void ppreOrder(Node* node);
    void ppostOrder(Node* node);
    void destroy(Node*& node);
    void pconstructTree(Node*& node, int data, vector<char> mChar);
    void pclear(Node* node);


public:
    BST():
        root(nullptr) {}
        
    bool insert(char mChar, int data);
    bool remove(char mChar, int data);
    bool find(int data);
    void inOrder();
    void preOrder();
    void postOrder();
    void constructTree(int data);
    void convertString(string data);
    void clear();
};


