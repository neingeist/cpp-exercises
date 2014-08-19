#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using std::map;
using std::pair;
using std::vector;

int main() {
    // notice how the lists are nested to match the templates' parameters:
    map<std::string, vector<pair<std::string, int>>> name_languages_year {
        {"Dennis Ritchie",    {{"B",      1969}, {"C",        1973}}},
        {"Niklaus Wirth",     {{"Pascal", 1970}, {"Modula-2", 1973},
                               {"Oberon", 1986}}},
        {"Bjarne Stroustrup", {{"C++",    1983}}},
        {"Walter Bright",     {{"D",      1999}}}
    };

    // prints `Pascal':
    std::cout << name_languages_year["Niklaus Wirth"].at(0).first << std::endl;

    // adds a new entry to the map:
    name_languages_year["John McCarthy"] = {
        {"Lisp", 1958}
    };

    // prints 'Lisp':
    std::cout << name_languages_year["John McCarthy"].at(0).first << std::endl;
}
