#include <iostream>
#include <string>
#include <vector>
#include "stringsplit.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string str = "Hello my friend";

    vector<string> vec2;

    vec2 = SpliT::split(str, ' ');

    for(int i =0; i<vec2.size(); i++) {

        cout << vec2[i] << endl;
    }

    return 0;
}

