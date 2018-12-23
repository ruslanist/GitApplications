#include "reader.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stringsplit.h>
#include <sstream>
#include<stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::fstream;
using std::stringstream;
using std::runtime_error;
using std::exception;

CSVReader::CSVReader(const string& m_file_path) : linestr(m_file_path) {}

TagReader::TagReader(const string& m_file_path2) : linestr2(m_file_path2) {}

vector <Iteam> CSVReader::read() {

    ifstream t(linestr);
    stringstream buffer;
    buffer << t.rdbuf();
    string data = buffer.str();

    Iteam obj;

    vector<Iteam> vecitem;

    vector<string> vecData;

    vecData = SpliT::split(data, '\n');

    for(int i = 0; i<vecData.size(); i++) {

        cout << "Вывод 4 строки Класса CSVReader" << " " << vecData[i] << endl;

        vector<string> vecData2 = SpliT::split(vecData[i], ',');

        if(vecData2.size() != 3) {

            throw runtime_error("Syntax error of file.txt. Validation is failed" + vecData2[i]);
        }

        obj.name = vecData2[0];
        obj.type = vecData2[1];
        obj.price = vecData2[2];

        vecitem.push_back(obj);
    }

    return vecitem;
}

vector<Iteam> TagReader::read() {

    ifstream t2(linestr2);
    stringstream buffer2;
    buffer2 << t2.rdbuf();
    string data2 = buffer2.str();

    vector<Iteam> vecitem2;
    vector<string> vecData2;

    vecData2 = SpliT::split(data2, '\n');

    for(int i=0; i<vecData2.size(); i++) {

        string tmp = vecData2[i];
        Iteam obj2;
        string tagWord;

        tagWord = SpliT::get_word(vecData2[i], '>');

        if(tagWord != "<name") {

            throw runtime_error("Syntax error of file.txt. Validation is failed " + tmp);
        }

        string word1 = SpliT::get_word(vecData2[i], '<');
        tagWord = SpliT::get_word(vecData2[i], '>');

        if(tagWord != "type") {

            throw runtime_error("Syntax error of file.txt. Validation is failed " + tmp);
        }

        string word2 = SpliT::get_word(vecData2[i], '<');
        tagWord = SpliT::get_word(vecData2[i], '>');

        if(tagWord != "price") {

            throw runtime_error("Syntax error of file.txt. Validation is failed " + tmp);
        }

        string word3 = vecData2[i];

        obj2.name = word1;
        obj2.type = word2;
        obj2.price = word3;

        vecitem2.push_back(obj2);
    }

    return vecitem2;
}

