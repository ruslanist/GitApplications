#include <iostream>
#include "reader.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    CSVReader objTxt("/home/ruslan/test.txt");

    vector<Iteam> finalVec;

    finalVec = objTxt.read();

    for(int i=0; i<finalVec.size(); i++) {

        cout << finalVec[i] << endl;
    }

    return 0;
}
