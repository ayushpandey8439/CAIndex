//
// Created by pandey on 11/05/24.
//

#include <fstream>
#include <algorithm>
#include "DRAG.h"
#include "deque"
#include "set"

DRAG::DRAG() {
    string graphInputPath = config["variables"]["graphInputPath"].value_or("");
    if (graphInputPath.empty()) {
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
    for (int i = 0; i < numTasks + 1; i++) {
        getline(graph, line);
        // split the string at every 11th character
        string vertex = line.substr(0, 11);
        vertex.erase(remove_if(vertex.begin(), vertex.end(), ::isspace), vertex.end());
        cout << "Vertex " << vertex << endl;
        // insert into vertices map
        Vertex *v = new Vertex(vertex);
        Vertices[stoi(vertex)] = v;
        if (i == 0) {
            root = v;
        }

        for (int j = 33; j < line.size(); j += 11) {
            string p = line.substr(j, 11);
            p.erase(remove_if(p.begin(), p.end(), ::isspace), p.end());
            // Add vertex to the list of its predecessors
            auto predecessor = Vertices.find(stoi(p))->second;
            predecessor->children.push_back(v);
            // Add predecessor to the list of its successors
            v->parents.push_back(predecessor);
        }
    }
}


void DRAG::print() {
    {
        string graphPath = config["variables"]["graphOutputPath"].value_or("");
        if (graphPath.empty()) {
            throw invalid_argument("Graph path not found in config file");
        }
        std::ofstream graph;
        graph.open(graphPath, ios::out);
        if (!graph.is_open()) {
            throw runtime_error("Error opening graph output file");
        }
        graph << "digraph G {" << endl;
        // Print the set of vertices and set their labels
        for (auto const &[key, vertex]: Vertices) {
            graph << vertex->data << " [label=\"" << vertex->data << "(" << vertex->labelString() << ")\"];" << endl;
        }

        // perform a breadth first traversal over the graph from the root and print the graph
        // by only printing unique edges.

        set<pair<string, string>> edges;
        deque<Vertex *> q;
        q.push_back(root);

        while (!q.empty()) {
            Vertex *v = q.front();
            q.pop_front();
            for (Vertex *child: v->children) {
                if (edges.find(make_pair(v->data, child->data)) == edges.end()) {
                    graph << v->data << "->" << child->data << ";" << endl;
                    edges.insert(make_pair(v->data, child->data));
                }
                q.push_back(child);

            }
        }
        graph << "}" << endl;
        graph.close();
    }
}