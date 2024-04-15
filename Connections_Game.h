#ifndef M2OEP_BAKEANE_MRUBENS_CONNECTIONS_H
#define M2OEP_BAKEANE_MRUBENS_CONNECTIONS_H

#include <iostream>
#include <random>
#include <vector>

enum category { // defining possible categories
    small_capital,
    music_genres,
    languages,
    uvm_locations
};
struct connect {
    std::string item;
    category group;

    bool operator==(const std::string& s) const {
        return item == s;
    }

    bool operator==(category check_cat) const {
        return group == check_cat;
    }
};

extern std::vector<connect> groups;
extern std::random_device rand_num;

class Connections_Game {
private:

    const int MAX_NUM = 16;
    const int NUM_IN_CAT = 4;

    std::vector<std::string> chosen, merged, language, capital, genre, uvm;
public:
    /*
     * Default Constructor
     * Requires: nothing
     * Modifies: category vectors
     * Effects: Sets category vectors to randomly chosen items
     */
    Connections_Game();

    /*
     * Set up categories
     * Requires: nothing
     * Modifies: category vectors
     * Effects: Sets category vectors to randomly chosen items
     */
    bool choose_categories();

    /*
     * Merge vectors
     * Requires: four category vectors and vector to be combined into
     * Modifies: category vectors and merged vector
     * Effects: puts all category vectors into one vector
     */
    void merge_categories(std::vector<std::string>& merged, std::vector<std::string>& vec1, std::vector<std::string>& vec2,
                          std::vector<std::string>& vec3, std::vector<std::string>& vec4);

    /*
     * Find max length
     * Requires: vector of strings
     * Modifies: nothing
     * Effects: finds longest word in vector and returns it
     */
    virtual int find_max_length(std::vector<std::string> vec1);

    /*
     * Overloaded equals
     * Requires: two connect structs
     * Modifies: nothing
     * Effects: checks if two items are in the same group
     */
    friend bool operator== (const connect& l, const connect& r);

    /*
     * Print rules
     * Requires: ostream
     * Modifies: outs
     * Effects: Prints the game's rules to outs
     */
    virtual void print_rules(std::ostream &outs);

    /*
     * Print grid
     * Requires: ostream, four categories
     * Modifies: outs
     * Effects: Prints the game grid to outs
     */
    virtual std::vector<std::string> print_grid(std::ostream &outs, std::vector<std::string> &cat1, std::vector<std::string> &cat2,
                                      std::vector<std::string> &cat3, std::vector<std::string> &cat4);

    /*
     * Get category
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns vector of category
     */
    std::vector<std::string> get_category_1();

    /*
     * Get category
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns vector of category
     */
    std::vector<std::string> get_category_2();

    /*
     * Get category
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns vector of category
     */
    std::vector<std::string> get_category_3();

    /*
     * Get category
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns vector of category
     */
    std::vector<std::string> get_category_4();

    /*
     * Get player choice
     * Requires: ostream, istream
     * Modifies: outs and ins
     * Effects: Prints the options to outs and gets user input. Checks for validity.
     */
    virtual char get_player_choice(std::ostream &outs, std::istream &ins);

    /*
     * Get guess
     * Requires: ostream, istream
     * Modifies: outs, ins
     * Effects: returns vector of guess
     */
    virtual std::vector<std::string> get_guess(std::ostream &outs, std::istream &ins, std::vector<std::string> &merge);

    /*
    * Check connection
    * Requires: guess vector
    * Modifies: nothing
    * Effects: checks if user guess is a correct connection
    */
    virtual bool check(const std::vector<std::string> &guesses);

    /*
    * Check win
    * Requires: guesses vector and vector with all connections
    * Modifies: nothing
    * Effects: checks if user has completed all connections
    */
    virtual bool check_win(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2);

};



#endif //M2OEP_BAKEANE_MRUBENS_CONNECTIONS_GAME_H