//
// Created by pandey on 11/05/24.
//

#ifndef CAINDEX_VERTEX_H
#define CAINDEX_VERTEX_H

#include <vector>
#include "algorithm"
#include "iostream"


using namespace std;

class Vertex {
public:
    Vertex(string data){
        this->data = data;
    }

    string data;
    vector <Vertex*> children;
    vector <Vertex*> parents;
    vector <string> label;


    string labelString(){
        string labelString = "";
        for(auto i: label){
            labelString += i + ", ";
        }
        return labelString;
    }


};


#endif //CAINDEX_VERTEX_H
