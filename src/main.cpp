#include <iostream>
#include "structures/DRAG.h"
#include "toml++/toml.h"

using namespace std;

toml::table config = toml::parse_file("config/config.toml");

int main() {
    try {
        DRAG tree;
        tree.label();
        tree.print();
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}
