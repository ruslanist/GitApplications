#ifndef INVENTORY_H
#define INVENTORY_H
#include "reader.h"
#include <vector>

using std::vector;

class Inventory {

    Reader* reader;
    vector<Iteam> items;

};

#endif // INVENTORY_H
