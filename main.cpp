#include "Connections_Game.cpp"
#include "Custom_Connections.cpp"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    Connections_Game game;
    vector<string> merged, win, guesses, cat1, cat2, cat3, cat4;

    cat1 = game.get_category_1();
    cat2 = game.get_category_2();
    cat3 = game.get_category_3();
    cat4 = game.get_category_4();

    game.merge_categories(merged, cat1, cat2, cat3, cat4);

    ofstream output;
    output.open("output.txt");

    for (int i = 0; i < merged.size(); i++) {
        if (i != merged.size() - 1) {
            output << merged[i] << endl;
        } else {
            output << merged[i];
        }
    }

    output.close();

    return 0;
}
