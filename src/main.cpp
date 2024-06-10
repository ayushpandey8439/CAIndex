#include <iostream>
#include "structures/DRAG.h"
#include "toml++/toml.h"
#include "indices/CAIndex/CAIndex.h"
#include "indices/AOIndex/AOIndex.h"

using namespace std;

toml::table config = toml::parse_file("config/config.toml");

int main() {
    try {
        DRAG tree;
        string indexing = config["variables"]["index"].value_or("");
        if(indexing == "CAIndex"){
            CAIndex(tree.root);
        }
        if(indexing == "AOIndex"){
             AOIndex(tree.root);
        }
        tree.print();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}
