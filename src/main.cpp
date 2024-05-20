#include <iostream>
#include "structures/DRAG.h"
#include "toml++/toml.h"

using namespace std;

toml::table config = toml::parse_file("config/config.toml");

int main() {
//
//    int treeDepth = config["variables"]["treeDepth"].value_or(0);
//    int maxDegree = config["variables"]["maxVertexDegree"].value_or(0);
//    int verticalSpread = config["variables"]["maxVerticalSpread"].value_or(0);

//    DRAG tree(maxDegree, treeDepth, verticalSpread);
    DRAG tree;
    tree.print();
}
