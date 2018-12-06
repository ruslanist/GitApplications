#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

string get_word(string &str, char delim) {

    size_t pos =0;

    pos = str.find(delim);

    string strFirst = str.substr(0, pos);

    str.erase(0, (pos == string::npos) ? pos : pos + 1);

    return strFirst;
}

int main()
{
    string str = "How Are You";

    string strChange1 = get_word(str, ' ');
    string strChange2 = get_word(str, ' ');
    string strChange3 = get_word(str, ' ');

    if(strChange1 == "How") {
        cout << "Test 1 OK!" << endl;
    } else {
        cout << "Test 1 FAIL!" << endl;
    }

    if(strChange2 == "Are") {
        cout << "Test 2 OK!" << endl;
    } else {
       cout << "Test 2 FAIL!" << endl;
    }

    if(strChange3 == "You")
        cout << "Test 3 OK!" << endl;
    else
        cout << "Test 3 FAIL!" << endl;

    string str2 = "How Are";
    string strChange4 = get_word(str2, ' ');
    if((strChange4 == "How Are") && str2.empty()) {
        cout << "Test 4 OK!" << endl;
    } else {
        cout << "Test 4 FAIL!" << endl;
    }

    return 0;
}
