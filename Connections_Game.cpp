#include "Connections_Game.h"
#include <vector>
#include <random>
#include <iomanip>
#include <algorithm>

using namespace std;

std::vector<connect> groups = {
        {"Urdu", category::languages},
        {"Zulu", category::languages},
        {"Uzbek", category::languages},
        {"Farsi", category::languages},
        {"Valletta", category::small_capital},
        {"Vaduz", category::small_capital},
        {"San Marino", category::small_capital},
        {"Funafuti", category::small_capital},
        {"Zamrock", category::music_genres},
        {"Klezmer", category::music_genres},
        {"New Wave", category::music_genres},
        {"Ethio-jazz", category::music_genres},
        {"Fishbowl", category::uvm_locations},
        {"Central", category::uvm_locations},
        {"Ira Allen", category::uvm_locations},
        {"Discovery", category::uvm_locations}
};
std::random_device rand_num;
std::mt19937 gener(rand_num());

Connections_Game::Connections_Game() {
    choose_categories();
}

bool Connections_Game::choose_categories() {
    if (chosen.size() == MAX_NUM) {
        return false;
    }
    shuffle(groups.begin(), groups.end(), gener);
    while (true) {
        for (int i = 0; i < groups.size(); i++) {
            switch (groups[i].group) {
                case languages:
                    language.push_back(groups[i].item);
                    break;
                case small_capital:
                    capital.push_back(groups[i].item);
                    break;
                case music_genres:
                    genre.push_back(groups[i].item);
                    break;
                case uvm_locations:
                    uvm.push_back(groups[i].item);
                    break;
            }
            if (language.size() == NUM_IN_CAT && capital.size() == NUM_IN_CAT // check if categories are full
                && genre.size() == NUM_IN_CAT && uvm.size() == NUM_IN_CAT) {
                return true;
            }
        }
    }
}


void Connections_Game::merge_categories(vector<string>& merge, vector<string>& vec1, vector<string>& vec2,
                                        vector<string>& vec3, vector<string>& vec4) {
    merge.clear();
    merge = vec1;
    merge.insert(merge.end(), vec2.begin(), vec2.end());
    merge.insert(merge.end(), vec3.begin(), vec3.end());
    merge.insert(merge.end(), vec4.begin(), vec4.end());
}

int Connections_Game::find_max_length(vector<string> vec1) {
    int max_length = 0;
    for (string s : vec1) {
        if (s.length() > max_length) {
            max_length = s.length();
        }
    }
    return max_length;
}


bool operator== (const connect& l, const connect& r) {
    return (l.group == r.group);
}


void Connections_Game::print_rules(ostream &outs) {
    outs << "*Adapted from NYT Connections*" << endl;
    outs << "Rules of Connections:" << endl;
    outs << "You will be given a 4x4 grid of words." << endl;
    outs << "There are four groups, so your goal is to find "
            "each group of four words that fit together" << endl;
    outs << "You are allowed to have 3 wrong guesses. On your fourth wrong"
            " guess, you lose." << endl << endl;
}

vector<string> Connections_Game::print_grid(ostream &outs, vector<string> &cat1, vector<string> &cat2,
                       vector<string> &cat3, vector<string> &cat4) {
    const string separator = " ";
    vector<string> merge;
    int count = 0;


    merge_categories(merge, cat1, cat2, cat3, cat4);

    int max_length = find_max_length(merge);

    shuffle(merge.begin(), merge.end(), gener);

    for (int i = 0; i < ((max_length + 2) * 4); i++) {
        outs << "_";
    }
    outs << endl;
    for (string s: merge) {
        outs << left << "|" << setw(max_length + 2) << s; // +2 to add a little whitespace between
        count++;
        if (count % 4 == 0) {
            outs << "|" << endl;
        }
    }

    for (int i = 0; i < ((max_length + 2) * 4); i++) {
        outs << "_";
    }
    outs << endl;
    return merge;
}

vector<string> Connections_Game::get_category_1() {
    return language;
}

vector<string> Connections_Game::get_category_2() {
    return genre;
}

vector<string> Connections_Game::get_category_3() {
    return capital;
}

vector<string> Connections_Game::get_category_4() {
    return uvm;
}

// adapted from "Errors", written by Lisa Dion for CS 2300
char Connections_Game::get_player_choice(ostream &outs, istream &ins) {
    char choice;
    outs << "Press (d) to play 'daily' game, (p) to play custom game, (c) to create custom game, or (e) to exit: ";
    ins >> choice;
    while (choice != 'd' && choice != 'p' && choice != 'c' && choice != 'e' ) {
        outs << "Invalid option. " << endl;
        outs << "Press (d) to play 'daily' game, (p) to play custom game, (c) to create custom game, or (e) to exit: ";
        ins.ignore(numeric_limits<streamsize>::max(), '\n');
        ins >> choice;
    }
    ins.ignore();
    return choice;
}

vector<string> Connections_Game::get_guess(ostream &outs, istream &ins, vector<string> &merge) {
    string guess1, guess2, guess3, guess4;
    vector<string> guesses;
    outs << "Enter your first guess: ";
    getline(ins, guess1);
    while (find(merge.begin(), merge.end(), guess1) == merge.end()) {
        outs << "Invalid guess. " << endl;
        outs << "Enter a word in the grid: ";
        getline(ins, guess1);
    }
    outs << "Enter your second guess: ";
    getline(ins, guess2);
    while (find(merge.begin(), merge.end(), guess2) == merge.end()) {
        outs << "Invalid guess. " << endl;
        outs << "Enter a word in the grid: ";
        getline(ins, guess2);
    }
    outs << "Enter your third guess: ";
    getline(ins, guess3);
    while (find(merge.begin(), merge.end(), guess3) == merge.end()) {
        outs << "Invalid guess. " << endl;
        outs << "Enter a word in the grid: ";
        getline(ins, guess3);
    }
    outs << "Enter your fourth guess: ";
    getline(ins, guess4);
    while (find(merge.begin(), merge.end(), guess4) == merge.end()) {
        outs << "Invalid guess. " << endl;
        outs << "Enter a word in the grid: ";
        getline(ins, guess4);
    }
    guesses.push_back(guess1);
    guesses.push_back(guess2);
    guesses.push_back(guess3);
    guesses.push_back(guess4);
    return guesses;
}

bool Connections_Game::check(const vector<string> &guesses) {
    category cat_to_check = uvm_locations; // initialize with a category
    int count = 0;

    for (const connect &c : groups) {
        if (c == guesses[0]) {
            cat_to_check = c.group;
            break;
        }
    }

    for (const string &s : guesses) {
        for (const connect &c : groups) {
            if (c == s && c.group != cat_to_check) {
                // if any item is not in the category of the first item, return false
                return false;
            } else if (guesses[0] == guesses[1] || guesses[1] == guesses[2] || guesses[2] ==
                                                                               guesses[3] || guesses[3] == guesses[0] || guesses[2] == guesses[0] || guesses[1] ==
                                                                                                                                                     guesses[3]) {
                return false;
            }
        }
    }

    return true;
}

bool Connections_Game::check_win(const std::vector<string>& vec1, const std::vector<string>& vec2) {
    if (vec1.size() != vec2.size()) {
        return false;
    }

    vector<string> sorted_vec1 = vec1;
    vector<string> sorted_vec2 = vec2;

    sort(sorted_vec1.begin(), sorted_vec1.end());
    sort(sorted_vec2.begin(), sorted_vec2.end());

    return sorted_vec1 == sorted_vec2;
}