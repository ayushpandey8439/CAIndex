//
// Created by pandey on 11/05/24.
//

#ifndef CAINDEX_VERTEX_H
#define CAINDEX_VERTEX_H

#include <vector>

using namespace std;

class Vertex {
public:
    Vertex(int data){
        this->data = data;
    }

    int data;
    vector <Vertex*> children;

    static Vertex* createRandomDRAG(int degree, int depth, int verticalSpread);
};


#endif //CAINDEX_VERTEX_H
