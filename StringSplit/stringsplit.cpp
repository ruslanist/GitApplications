#include <string>
#include <vector>
#include "stringsplit.h"
#include <fstream>
#include <sstream>
#include <exception>

using std::vector;
using std::string;
using std::stringstream;
using std::exception;
using std::runtime_error;

string SpliT::get_word(string &str, char delim) {

    size_t pos =0;

    pos = str.find(delim);

    string strFirst = str.substr(0, pos);

    str.erase(0, (pos == string::npos) ? pos : pos + 1);

    return strFirst;
}

vector<string> SpliT::split(const string& str, char delim) {


    string tmp_str = str;


    vector<string> vec;

    while(!tmp_str.empty()) {


        vec.push_back(get_word(tmp_str, delim));
    }

    return vec;
}

double SpliT::toNumber(const string &strVal) {

    stringstream stream(strVal);
    double dVal;

    stream >> dVal;

    return dVal;
}

string SpliT::getFileExt(const string &input_path) {

    string patch = input_path;

    size_t pos = 0;

    pos = patch.rfind(".");

    string ext = patch.substr(0, pos);

    if(pos == string::npos) {

        throw runtime_error("Fail to get extenstion for file: " + input_path);
    }

    return ext;
}




















