#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::end;
using std::string;
using std::vector;

vector<string> vec;

vector<string> split(const string& str, char delim) {

    size_t pos =0;
    string tmp_str = str;
    string strWord;

    while(!test_str.empty()) {

        pos = tmp_str.find(delim);

        strWord = tmp_str.substr(0, pos);

        tmp_str.erase(0, (pos == string::npos) ? pos : pos + 1);

        vec.push_back(strWord);
    }

    return vec;
}

int main()
{
    string str = "Hello my friend";

    string<string> vec2 = split(str, ' ');

    for(int i =0; i<vec.size(); i++) {

        cout << vec2[i] << endl;
    }

    return 0;
}


