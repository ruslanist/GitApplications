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
    const string str2 = "100.00";
    const string str4 = "/home/ruslan/GitHub/GitApplications/File_of_Prodject/Reder/test.txt";

    vector<string> vec2;

    vec2 = SpliT::split(str, ' ');

    for(int i =0; i<vec2.size(); i++) {

        cout << vec2[i] << endl;
    }

    double str3 = SpliT::toNumber(str2);
    cout << str3 << endl;

    string strgetFile = SpliT::getFileExt(str4);
    cout << "Возвращаемое значение функции getFileExt()" << endl;
    cout << strgetFile << endl;

    return 0;
}


