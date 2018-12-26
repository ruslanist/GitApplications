#ifndef INVENTORY_H
#define INVENTORY_H
#include "reader.h"
#include <vector>

using std::vector;

class Inventory {

    Reader* reader;
    vector<Iteam> items;

public:
    Inventory(const string& input_path);

    double getVolume();

    void printStat();

};

#endif // INVENTORY_H
