#ifndef STRINGSPLIT_H
#define STRINGSPLIT_H
#include <string>
#include <vector>

using std::vector;
using std::string;

namespace SpliT {

string get_word(string &str, char delim);

vector<string> split(const string& str, char delim);

}

#endif // STRINGSPLIT_H