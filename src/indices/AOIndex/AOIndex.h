//
// Created by pandey on 30/05/24.
//

#ifndef CAINDEX_AOINDEX_H
#define CAINDEX_AOINDEX_H


#include "../../structures/Vertex.h"

class Node
{
public:
    string key;
    Node *left;
    Node *right;
    int height;

};

class AOIndex : Node{
public:
    AOIndex(Vertex* root);
    void computeLabel(Vertex * v);

    int height(Node *v);
    Node* newNode(string key);
    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);
    int getBalance(Node *N);
    Node* insert(Node* node, string key);

};






#endif //CAINDEX_AOINDEX_H
