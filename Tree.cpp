//
// Created by pandey on 11/05/24.
//

#include "structures/Tree.h"

void Tree::printTree(const std::string& prefix, TreeNode *node, bool isLast) {
    if (node == nullptr)
        return;

    cout << prefix;

    cout << (isLast ? "└──" : "├──" ) << node->data << endl;

    int i=0;
    for (TreeNode* child : node->children) {
        i++;
        if(i == node->children.size())
            printTree(prefix + (isLast ? "   " : "│  " ) , child, true);
        else
            printTree(prefix + (isLast ? "   " : "│  " )  , child, false);

    }
}

Tree::Tree(int degree, int depth) {
    this->degree = degree;
    this->depth = depth;
    root = TreeNode::createRandomTree(degree, depth);
}
