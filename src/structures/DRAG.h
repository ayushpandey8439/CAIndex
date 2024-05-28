//
// Created by pandey on 11/05/24.
//

#ifndef CAINDEX_DRAG_H
#define CAINDEX_DRAG_H


#include "Vertex.h"
#include <iostream>
#include <fstream>
#include "toml++/toml.h"

extern toml::table config;

using namespace std;
class DRAG {
protected:
    Vertex* root;
    map<int, Vertex*> Vertices;
    void printTree(ofstream* graph, const string& prefix, Vertex* root);
public:
//    DRAG(int degree, int depth, int verticalSpread);
    DRAG();

    void print();
};


#endif //CAINDEX_DRAG_H
