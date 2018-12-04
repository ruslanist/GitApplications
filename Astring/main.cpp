#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;



string funk(string const &str, char const &from, char const &to) {

    string strchange = str;

    size_t pos = 0;


    while((pos = strchange.find(from, pos)) != string::npos) {

        strchange[pos] = to;

    }


    return strchange;
}

string trim(const string &str) {}

int main()

{

    string str1;
    char from1;
    char to1;

    cout << " Введите строку состоящая из слов и символов" << endl;
    cin >> str1;

    cout << "Параметр 2: Введите символ который желаете заменить" << endl;
    cin >> from1;

     cout << "Параметр 3: Введите символ на который нужно изменить" << endl;
    cin >> to1;



    string str2 = funk(str1, from1, to1);

    cout << str1 << endl;

    cout << str2 << endl;

    return 0;
}
