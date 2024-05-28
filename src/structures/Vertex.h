//
// Created by pandey on 11/05/24.
//

#ifndef CAINDEX_VERTEX_H
#define CAINDEX_VERTEX_H

#include <vector>
#include "algorithm"

using namespace std;

class Vertex {
public:
    Vertex(int data){
        this->data = data;
    }

    int data;
    vector <Vertex*> children;
    vector <Vertex*> parents;
    vector <int> label;

    static Vertex* createRandomDRAG(int degree, int depth, int verticalSpread);

    string labelString(){
        string labelString = "";
        for(auto i: label){
            labelString += to_string(i) + " ";
        }
        return labelString;
    }

    void computeLabel(){
        vector<int> tempLabel;
        for(auto parent: parents){
            if(tempLabel.empty()){
                tempLabel.insert(tempLabel.begin(), parent->label.begin(), parent->label.end());
            }
            else {
                // remove all elements from tempLabel that are not in parent->label
                tempLabel.erase(remove_if(tempLabel.begin(), tempLabel.end(), [parent](int i){
                    return find(parent->label.begin(), parent->label.end(), i) == parent->label.end();
                }), tempLabel.end());
            }
        }
        tempLabel.push_back(data);
        label = tempLabel;
    }
};


#endif //CAINDEX_VERTEX_H
