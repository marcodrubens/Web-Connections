#ifndef M2OEP_BAKEANE_MRUBENS_CATEGORIES_H
#define M2OEP_BAKEANE_MRUBENS_CATEGORIES_H

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using std::string;
using std::istream;
using std::ostream;
using std::ofstream;
using std::vector;

class Categories {
private:
    std::vector<std::string> split_items;
    std::string connector, cat_items, title;

public:
    /*
     * Default Constructor
     * Requires: nothing
     * Modifies: nothing
     * Effects: default constructor
     */
    Categories();

    /*
     * Get user input
     * Requires: filename, i/o streams
     * Modifies: text file
     * Effects: writes categories and titles to text file
     */
    void get_user_input(const std::string& filename, std::istream &ins, std::ostream &outs);

    /*
     * Split string
     * Requires: string
     * Modifies: strings
     * Effects: splits string into four strings
     */
    static std::vector<std::string> split_string(const std::string& s);

    /*
     * Get category
     * Requires: i/o streams, connector, items, split strings vector
     * Modifies: variable that write to file
     * Effects: gets custom connections game
     */
    static void get_category(istream &ins, ostream &outs, ofstream &outs_file, string &connection, string &items, vector<string> &split);
};
#endif //M2OEP_BAKEANE_MRUBENS_CATEGORIES_H
