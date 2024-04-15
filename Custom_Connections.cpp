#include "Custom_Connections.h"
#include "Categories.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
Custom_Connections::Custom_Connections(string filename) {
    yellow = "";
    yellow_items = "";
    green = "";
    green_items = "";
    blue = "";
    blue_items = "";
    purple = "";
    purple_title = "";
    title = "";
    yellow_title = "";
    green_title = "";
    blue_title = "";
    purple_title = "";
    all = {};
    yellow_category = {};
    green_category = {};
    blue_category = {};
    purple_category = {};
}

string Custom_Connections::choose_game(string filename, ostream &outs, istream &ins) {
    ifstream inFile("../" + filename);
    vector<string> title_list;
    string line;
    int i = 0;
    int num = 0;
    string number;

    // Test if file opens correctly
    if(!inFile.is_open()) {
        cout << "FILE NOT OPENED" << endl;
    }

    while (getline(inFile, line)) {
        if (line.compare(0,5, "Title") == 0) {
            title_list.push_back(line);
        }
        line.clear();
    }

    outs << "List of available games: " << endl;
    for (string s : title_list) {
        i++;
        outs << i << ". " << s << endl;
    }
    cout << "Enter the number of the game you wish to play: ";
    getline(ins, number);
    try {
        num = stoi(number);
    } catch (std::invalid_argument) {
        num = 1; // default to 1
    }
    while (num > i || num <= 0) {
        // ins.ignore();
        // ins.clear();
        cout << "Invalid Input, Please enter an integer in the specified range!" << endl;
        getline(ins, number);
        num = stoi(number);
    }
    line = title_list[num - 1];
    return line;
}

void Custom_Connections::read_categories_from_file(string filename) {
    string game, check, item;
    int number = 0;
    Custom_Connections c(filename);

    yellow_category.clear();
    green_category.clear();
    blue_category.clear();
    purple_category.clear();

    ifstream inFile("../" + filename);
    game = c.choose_game(filename, cout, cin);

    while (getline(inFile, check)) {
        if (check == game) {
            getline(inFile, item);
            set_yellow_title(item);
            for (int i = 0; i < 4; i++) {
                getline(inFile, item);
                yellow_category.push_back(item);
            }
            getline(inFile, item);
            set_green_title(item);
            for (int i = 0; i < 4; i++) {
                getline(inFile, item);
                green_category.push_back(item);
            }
            getline(inFile, item);
            set_blue_title(item);
            for (int i = 0; i < 4; i++) {
                getline(inFile, item);
                blue_category.push_back(item);
            }
            getline(inFile, item);
            set_purple_title(item);
            for (int i = 0; i < 4; i++) {
                getline(inFile, item);
                purple_category.push_back(item);
            }
        }
    }
    inFile.close();
    //cin.ignore();
    //cin.clear();
}

bool Custom_Connections::check(vector<string> &guesses) {
    sort(guesses.begin(), guesses.end());
    sort(yellow_category.begin(), yellow_category.end());
    sort(green_category.begin(), green_category.end());
    sort(blue_category.begin(), blue_category.end());
    sort(purple_category.begin(), purple_category.end());

    if (guesses == yellow_category) {
        cout << "Correct! These four items form the YELLOW connection: " << yellow_title << endl;
        return true;
    } else if (guesses == green_category) {
        cout << "Correct! These four items form the GREEN connection: " << green_title << endl;
        return true;
    } else if (guesses == blue_category) {
        cout << "Correct! These four items form the BLUE connection: " << blue_title << endl;
        return true;
    } else if (guesses == purple_category) {
        cout << "Correct! These four items form the PURPLE connection: " << purple_title << endl;
        return true;
    }
    return false;
}

void Custom_Connections::play_custom_game() {
    vector<string> m, guesses, win;
    int lives = 4;
    m = {"N/A"};
    while (!(check_win(win, m))) {
        m.clear();
        m = Connections_Game::print_grid(cout, yellow_category, green_category, blue_category, purple_category);
        guesses = get_guess(cout, cin, m);
        if (check(guesses)) {
            for (string &s: guesses) {
                win.push_back(s);
            }
        } else {
            lives--;
            cout << "No connection. " << lives << " lives remaining." << endl;
        }
        if (lives == 0) {
            cout << "You lose." << endl;
            break;
        }
    }
    if (lives != 0) {
        cout << "You Win!" << endl;
    }
}

void Custom_Connections::clear_file(const string& filename) {
    ofstream out_file;
    out_file.open(filename);
}

void Custom_Connections::set_title(string &title) {
    this->title = title;
}

string Custom_Connections::get_title() const {
    return title;
}

string Custom_Connections::get_yellow_title() const {
    return yellow_title;
}

string Custom_Connections::get_green_title() const {
    return green_title;
}

string Custom_Connections::get_blue_title() const {
    return blue_title;
}
string Custom_Connections::get_purple_title() const {
    return purple_title;
}

void Custom_Connections::set_yellow_title(string &yellow_title) {
    this->yellow_title = yellow_title;
}

void Custom_Connections::set_green_title(string &green_title) {
    this->green_title = green_title;
}

void Custom_Connections::set_blue_title(string &blue_title) {
    this->blue_title = blue_title;
}

void Custom_Connections::set_purple_title(string &purple_title) {
    this->purple_title = purple_title;
}

vector<string> Custom_Connections::get_all() const {
    return all;
}

vector<string> Custom_Connections::get_yellow_category() const {
    return yellow_category;
}

vector<string> Custom_Connections::get_green_category() const {
    return green_category;
}

vector<string> Custom_Connections::get_blue_category() const {
    return blue_category;
}

vector<string> Custom_Connections::get_purple_category() const {
    return purple_category;
}

void Custom_Connections::set_yellow_category(vector<std::string> yellow_items) {
    this->yellow_category = yellow_items;
}

void Custom_Connections::set_green_category(vector<std::string> green_items) {
    this->green_category = green_items;
}

void Custom_Connections::set_blue_category(vector<std::string> blue_items) {
    this->blue_category = blue_items;
}

void Custom_Connections::set_purple_category(vector<std::string> purple_items) {
    this->purple_category = purple_items;
}