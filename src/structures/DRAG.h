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
    map<int, Vertex*> Vertices;
public:
    DRAG();
    void print();
    Vertex* root;
};


#endif //CAINDEX_DRAG_H
