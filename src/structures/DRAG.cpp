//
// Created by pandey on 11/05/24.
//

#include <fstream>
#include <algorithm>
#include "DRAG.h"
#include "deque"
#include "set"
//DRAG::DRAG(int degree, int depth, int verticalSpread) {
//    this->degree = degree;
//    this->depth = depth;
////    root = Vertex::createRandomDRAG(degree, depth, verticalSpread);
//}

DRAG::DRAG() {
    string graphInputPath = config["variables"]["graphInputPath"].value_or("");
    if(graphInputPath.empty()) {
        throw invalid_argument("Graph path not found in config file");
    }
    ifstream graph;
    graph.open(graphInputPath, ios::in);
    if (!graph.is_open()) {
        throw runtime_error("Error opening graph source file");
    }
    string line;
    getline(graph, line);

    // remove whiespaces from string
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
    // convert to integer
    int numTasks = stoi(line);
    cout << "Number of tasks " << (numTasks) << endl;
    // loop numTasks time and read each line
    for (int i = 0; i < numTasks+1; i++) {
        getline(graph, line);
        // split the string at every 11th character
        string vertex = line.substr(0, 11);
        vertex.erase(remove_if(vertex.begin(), vertex.end(), ::isspace), vertex.end());
        cout << "Vertex " << vertex << endl;
        // insert into vertices map
        Vertex* v = new Vertex(stoi(vertex));
        Vertices[stoi(vertex)] = v;
        if(i==0){
            root = v;
        }

        for (int j = 33; j < line.size(); j += 11) {
            string p = line.substr(j,11);
            p.erase(remove_if(p.begin(), p.end(), ::isspace), p.end());
            // Add vertex to the list of its predecessors
            auto predecessor = Vertices.find(stoi(p))->second;
            predecessor->children.push_back(v);
            // Add predecessor to the list of its successors
            v->parents.push_back(predecessor);
        }
    }


//    while (getline(graph, line)) {
//       cout << line << endl;
//    }
}

void DRAG::print(){
    {
        string graphPath = config["variables"]["graphOutputPath"].value_or("");
        if(graphPath.empty()) {
            throw invalid_argument("Graph path not found in config file");
        }
        std::ofstream graph;
        graph.open(graphPath, ios::out);
        if (!graph.is_open()) {
            throw runtime_error("Error opening graph output file");
        }
        graph << "digraph G {" << endl;
        // perform a breadth first traversal over the graph from the root and print the graph
        // by onlu printing unique edges.
        set<pair<int, int>> edges;
        deque <Vertex*> q;
        q.push_back(root);
        while (!q.empty()) {
            Vertex* v = q.front();
            q.pop_front();
            for (Vertex* child : v->children) {
                if(edges.find(make_pair(v->data, child->data)) == edges.end()){
                    graph << v->data << "->" << child->data << ";"<< endl;
                    edges.insert(make_pair(v->data, child->data));
                }
                q.push_back(child);

            }
        }
        graph << "}" << endl;
        graph.close();
    }
}

//void DRAG::printTree(ofstream * graph, const string& prefix, Vertex *node) {
//    if (node == nullptr)
//        return;
//
//    *graph << prefix << "->" << node->data << ";"<< endl;
//
//    for (Vertex* child : node->children) {
//        printTree(graph, to_string(node->data) , child);
//
//    }
//}