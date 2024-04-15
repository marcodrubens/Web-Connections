#include "Categories.h"

using namespace std;

Categories::Categories() {}

void Categories::get_user_input(const std::string& filename, std::istream &ins, std::ostream &outs) {
    ofstream out_file;
    out_file.open ("../" + filename, ios::app);

    if (!out_file.is_open()) {
        outs << "error" << endl;
    }

    // make sure strings are empty
    title.clear();
    connector.clear();
    cat_items.clear();

    outs << "Enter the title of this connections puzzle: ";
    getline(ins, title);
    out_file << "Title: " << title << "\n";

    outs << "There are four different groups of connections with varying difficulty. Yellow is the easiest, green"
            " is the second easiest, then blue, with purple being the hardest." << endl;
    outs << "Enter the name of the yellow connection: ";
    get_category(cin, cout, out_file, connector, cat_items, split_items);
    outs << "Enter the name of the green connection: ";
    get_category(cin, cout, out_file, connector, cat_items, split_items);
    outs << "Enter the name of the blue connection: ";
    get_category(cin, cout, out_file, connector, cat_items, split_items);
    outs << "Enter the name of the purple connection: ";
    get_category(cin, cout, out_file, connector, cat_items, split_items);
    out_file.close();
}

vector<string> Categories::split_string(const string& s) {
    stringstream ss;
    vector<string> items;
    ss << s;
    while (ss.good()) {
        string substring;
        getline(ss, substring, ',');
        items.push_back(substring);
    }
    return items;
}

void Categories::get_category(istream &ins, ostream &outs, ofstream &outs_file, string &connection, string &items, vector<string> &split) {
    int comma_count = 0;
    getline(ins, connection);
    outs_file << connection << "\n";
    outs << "Enter the four items seperated by commas (Ex. 'Red,Blue,Green,Yellow'): ";
    getline(ins, items);
    for (char c: items) {
        if (c == ',') {
            comma_count++;
        }
    }
    while (comma_count != 3) {
        comma_count = 0;
        for (char c: items) {
            if (c == ',') {
                comma_count++;
            }
        }
        outs << "Invalid input. Enter the items again (Ex. 'Red,Blue,Green,Yellow'): ";
        getline(ins,items);
    }
    split = split_string(items);
    for (const string& s : split) {
        outs_file << s << "\n";
    }
    connection.clear();
    items.clear();
    split.clear();
}
