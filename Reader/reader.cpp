#include "reader.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stringsplit.h>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::fstream;
using std::stringstream;

CSVReader::CSVReader(const string& m_file_path) : linestr(m_file_path) {}

vector <Iteam> CSVReader::read() {

    ifstream t(linestr);
    stringstream buffer;
    buffer << t.rdbuf();
    string data = buffer.str();

   /*
    string data = "Рубашка,Одежда,30\n"
                  "Штаны,Одежда,40\n"
                  "Кружка,Посуда,50\n"
                  "Тарелка,Посуда,60\n";
  */
    Iteam obj;

    // string data2 = SpliT::get_word(data, '\n');


    vector<Iteam> vecitem;

    vector<string> vecData;

    vecData = SpliT::split(data, '\n');

    for(int i = 0; i<vecData.size(); i++) {

        cout << vecData[i] << endl;

        vector<string> vecData2 = SpliT::split(vecData[i], ',');

        obj.name = vecData2[0];
        obj.type = vecData2[1];
        obj.price = vecData2[2];

        vecitem.push_back(obj);

        return vecitem;

    }

}
