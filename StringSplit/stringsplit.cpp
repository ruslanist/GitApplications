#include <string>
#include <vector>
#include "stringsplit.h"

using std::vector;
using std::string;
using SpliT::get_word;
using SpliT::split;

string get_word(string &str, char delim) {

    size_t pos =0;

    pos = str.find(delim);

    string strFirst = str.substr(0, pos);

    str.erase(0, (pos == string::npos) ? pos : pos + 1);

    return strFirst;
}

vector<string> split(const string& str, char delim) {


    string tmp_str = str;


    vector<string> vec;

    while(!tmp_str.empty()) {


        vec.push_back(get_word(tmp_str, delim));
    }

    return vec;
}
