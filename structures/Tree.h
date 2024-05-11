//
// Created by pandey on 11/05/24.
//

#ifndef CAINDEX_TREE_H
#define CAINDEX_TREE_H


#include "TreeNode.h"
#include <iostream>

class Tree {
protected:
    TreeNode* root;
    int degree;
    int depth;
    void printTree(const std::string& prefix, TreeNode* root, bool isLast);
public:
    void print() {
        printTree("", root, true);
    }


    Tree(int degree, int depth);
};


#endif //CAINDEX_TREE_H
