#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

string funk(string const& str, string const& from, string const& to) {


    size_t pos = string::npos;

    while((pos = str.find(from, pos)) != string::npos) {

        str[pos] = to;

        string strchange = str;

        return strchange;

    }
}


int main()

{

    string str1;
    string from1;
    string to1;

    cout << " Введите строку состоящая из слов и символов" << endl;
    cin >> str1;

    cout << "Параметр 2: Введите символ который желаете заменить" << endl;
    cin >> from1;

     cout << "Параметр 3: Введите символ на который нужно изменить" << endl;
    cin >> to1;

    string strchange = funk(str1, from1, to1);


    cout << strchange << endl;

    return 0;
}
