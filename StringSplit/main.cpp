#include <iostream>
#include <string>
#include <vector>
#include "stringsplit.h"

using std::cout;
using std::end;
using std::string;
using std::vector;
//using SpliT::get_word;
using SpliT::split;

int main()
{
    string str = "Hello my friend";

    vector<string> vec2;

    vec2 = split(str, ' ');

    for(int i =0; i<vec.size(); i++) {

        cout << vec2[i] << endl;
    }

    return 0;
}


