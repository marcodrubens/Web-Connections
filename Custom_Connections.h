#ifndef M2OEP_BAKEANE_MRUBENS_CUSTOM_CONNECTIONS_H
#define M2OEP_BAKEANE_MRUBENS_CUSTOM_CONNECTIONS_H

#include "Connections_Game.h"
#include "Categories.h"

class Custom_Connections : public Connections_Game {
private:
    vector<string> all, yellow_category, green_category, blue_category, purple_category;
    string yellow, yellow_items, green, green_items, blue, blue_items, purple, purple_items, title, yellow_title, green_title, blue_title, purple_title;

public:
    /*
     * Default Constructor
     * Requires: filename
     * Modifies: class variables
     * Effects: Initializes all variables to be empty
     */
    Custom_Connections(string filename);

    /*
     * Choose game
     * Requires: filename, i/o streams
     * Modifies: nothing
     * Effects: Returns title of chosen game
     */
    string choose_game(string filename, ostream &outs, istream &ins);

    /*
     * Read file
     * Requires: filename
     * Modifies: category vectors
     * Effects: Reads file line-by-line
     */
    void read_categories_from_file(string filename);

    /*
     * Play game
     * Requires: nothing
     * Modifies: nothing
     * Effects: Plays connections game of chosen title
     */
    void play_custom_game();

    /*
     * Check if connection
     * Requires: vector of guesses
     * Modifies: category vectors
     * Effects: Sorts categories and returns if guesses are a connection
     */
    bool check(vector<string> &guesses);

    /*
     * clear file
     * Requires: filename
     * Modifies: txt file
     * Effects: clears the file
     */
    void clear_file(const string& filename);

    /*
     * Set title
     * Requires: title string
     * Modifies: title
     * Effects: changes title to input
     */
    void set_title(string &title);

    /*
     * Get title
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns title
     */
    string get_title() const;

    /*
     * Get yellow title
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns title of yellow connection
     */
    string get_yellow_title() const;

    /*
     * Get green title
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns title of green connection
     */
    string get_green_title() const;

    /*
     * Get blue title
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns title of blue connection
     */
    string get_blue_title() const;

    /*
     * Get purple title
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns title of purple connection
     */
    string get_purple_title() const;

    /*
     * Set title of yellow connection
     * Requires: yellow title string
     * Modifies: yellow title
     * Effects: changes yellow title to input
     */
    void set_yellow_title(string& yellow_title);

    /*
     * Set title of green connection
     * Requires: green title string
     * Modifies: green title
     * Effects: changes green title to input
     */
    void set_green_title(string& green_title);

    /*
     * Set title of blue connection
     * Requires: blue title string
     * Modifies: blue title
     * Effects: changes blue title to input
     */
    void set_blue_title(string& blue_title);

    /*
     * Set title of purple connection
     * Requires: purple title string
     * Modifies: purple title
     * Effects: changes purple title to input
     */
    void set_purple_title(string& purple_title);

    /*
     * Get all items
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns vector of all items
     */
    vector<string> get_all() const;

    /*
     * Get yellow category
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns vector of yellow items
     */
    vector<string> get_yellow_category() const;

    /*
     * Get green category
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns vector of green items
     */
    vector<string> get_green_category() const;

    /*
     * Get blue category
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns vector of blue items
     */
    vector<string> get_blue_category() const;

    /*
     * Get yellow category
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns vector of blue items
     */
    vector<string> get_purple_category() const;

    /*
     * Set yellow category
     * Requires: yellow category vector
     * Modifies: yellow category vector
     * Effects: changes yellow category vector to input
     */
    void set_yellow_category(vector<string> yellow_items);

    /*
     * Set green category
     * Requires: green category vector
     * Modifies: green category vector
     * Effects: changes green category vector to input
     */
    void set_green_category(vector<string> green_items);

    /*
     * Set blue category
     * Requires: blue category vector
     * Modifies: blue category vector
     * Effects: changes blue category vector to input
     */
    void set_blue_category(vector<string> blue_items);

    /*
     * Set purple category
     * Requires: purple category vector
     * Modifies: purple category vector
     * Effects: changes purple category vector to input
     */
    void set_purple_category(vector<string> purple_items);

};


#endif //M2OEP_BAKEANE_MRUBENS_CUSTOM_CONNECTIONS_H
