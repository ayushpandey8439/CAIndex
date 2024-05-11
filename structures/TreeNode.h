//
// Created by pandey on 11/05/24.
//

#ifndef CAINDEX_TREENODE_H
#define CAINDEX_TREENODE_H

#include <vector>

using namespace std;

class TreeNode {
public:
    int data;
    vector <TreeNode*> children;

    static TreeNode* createRandomTree(int degree, int depth);
};


#endif //CAINDEX_TREENODE_H
