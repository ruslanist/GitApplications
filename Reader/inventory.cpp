#include "inventory.h"
#include "reader.h"
#include "stringsplit.h"
#include <string>
#include <exception>
#include <map>
#include <iostream>


using std::string;
using std::runtime_error;
using std::map;
using std::cout;
using std::endl;


Inventory::Inventory(const string& input_path) {

    string ext = SpliT::getFileExt(input_path);

    if(ext == ".tag") {

        items = TagReader(input_path).read();

    } else if (ext == ".cvs") {

        items = CSVReader(input_path).read();

    } else {

        throw runtime_error("Error in name of File extension, file.txt. Validation is failed " + ext);
    }
}

double Inventory::getVolume() {

    double sum =0;

    for(int i =0; items.size(); i++) {

        sum += items[i].price * items[i].qty;
    }

    return sum;
}

void Inventory::printStat() {

    map<string, int> strToCount;

    for(int i=0; i<items.size(); i++) {

        strToCount[items[i].type] +=1;

    }

    for(auto iter = strToCount.begin(); iter != strToCount.end(); iter++) {

        cout << "Вывод Количества одежды на складе" << endl;
        cout << iter->first << " -> " << iter->second << endl;
    }

}


