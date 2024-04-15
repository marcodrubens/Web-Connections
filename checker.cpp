#include "Connections_Game.cpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    vector<string> guess;
    Connections_Game g;
    ifstream to_check("check.txt");

    string line;
    while (getline(to_check, line)) {
        if (!line.empty()) {
            guess.push_back(line);
        }
    }
    to_check.close();
    if (g.check(guess)) {
        cout << "Correct" << endl;
    } else {
        cout << "Incorrect" << endl;
    }
    to_check.close();
    return 0;
}
