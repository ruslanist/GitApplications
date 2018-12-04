#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;



string funk(string const &str, char const from, char const to) {

    string strchange = str;

    size_t pos = 0;


    while((pos = strchange.find(from, pos)) != string::npos) {

        strchange[pos] = to;

    }


    return strchange;
}

string trim(const string &str2) {

    size_t word_began = 0;
    size_t tmp = 0;

    tmp = str2.find_first_not_of(" \n\t");

            if(tmp != string::npos) {

                word_began = tmp;
            }

            return str2.substr(word_began);
}

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

    string str11 = funk(str1, from1, to1);

    cout << str1 << endl;

    cout << str11 << endl;

    cout << "Функция уберающая пробеллы и табуляции в начале строк" << endl;

    string str2;

    cout << "Введите слово с пробелами и табуляцией в начале этого слова" << endl;
    cin >> str2;

    string str22 = trim(str2);

    cout << str2 << endl;
    cout << str22 << endl;

    return 0;
}
