//
// Created by pandey on 30/05/24.
//

#ifndef CAINDEX_CAINDEX_H
#define CAINDEX_CAINDEX_H


#include "../../structures/Vertex.h"

class CAIndex {
    void computeLabel(Vertex * v);

public:
    CAIndex(Vertex * root);
};


#endif //CAINDEX_CAINDEX_H
