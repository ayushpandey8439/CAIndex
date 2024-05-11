//
// Created by pandey on 11/05/24.
//

#include "TreeNode.h"
#include <cstdlib>;

TreeNode* TreeNode::createRandomTree(int degree, int depth) {
    if (depth == 0) {
        return nullptr;
    }
    auto* root = new TreeNode();
    root->data = rand() % 100;
    int childrenCount = rand() % degree;
    for (int i = 0; i <= childrenCount; i++) {
        root->children.push_back(createRandomTree(degree, depth - 1));
    }
    return root;
}