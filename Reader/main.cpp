#include <iostream>
#include "reader.h"
#include <vector>
#include <iostream>


using std::cout;
using std::endl;
using std::vector;
using std::ifstream;

int main()
{
    CSVReader objTxt("/home/ruslan/test.txt");

    vector<Iteam> finalVec;

    finalVec = objTxt.read();

    for(int i=0; i<finalVec.size(); i++) {

        cout << finalVec[i].name << endl;
    }

    return 0;
}
