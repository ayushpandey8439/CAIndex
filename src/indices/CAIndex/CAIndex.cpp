//
// Created by pandey on 30/05/24.
//

#include "CAIndex.h"
#include "deque"
#include "algorithm"


CAIndex::CAIndex(Vertex *root) {
    deque<Vertex *> q;
    q.push_back(root);
    while (!q.empty()) {
        Vertex *v = q.front();
        q.pop_front();
        computeLabel(v);
        for (Vertex *child: v->children) {
            q.push_back(child);
        }
    }
}

void CAIndex::computeLabel(Vertex *v) {
    vector<string> tempLabel;
    for (auto parent: v->parents) {
        if (tempLabel.empty()) {
            tempLabel.insert(tempLabel.begin(), parent->label.begin(), parent->label.end());
        } else {
            // remove all elements from tempLabel that are not in parent->label
            tempLabel.erase(remove_if(tempLabel.begin(), tempLabel.end(), [parent](string i) {
                return find(parent->label.begin(), parent->label.end(), i) == parent->label.end();
            }), tempLabel.end());
        }
    }
    tempLabel.push_back(v->data);
    v->label = tempLabel;
}