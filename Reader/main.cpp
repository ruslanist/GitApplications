#include <iostream>
#include "reader.h"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::ifstream;

int main() {

    CSVReader objTxt("/home/ruslan/GitHub/GitApplications/File_of_Prodject/Reder/test.txt");
    TagReader objTxt2("/home/ruslan/GitHub/GitApplications/File_of_Prodject/Reder/test2.txt");

    vector<Iteam> finalVec;
    vector<Iteam> finalVec2;

    finalVec = objTxt.read();
    finalVec2 = objTxt2.read();

    for(int i=0; i<finalVec.size(); i++) {

        cout << "Вывод  в main() полей Класса CSVReader" << endl;
        cout << "Название" << " " << finalVec[i].name << endl;
        cout << "Тип" << " " << finalVec[i].type << endl;
        cout << "Цена" << " " << finalVec[i].price << endl;
        cout << " " << endl;
    }

    for(int i=0; i<finalVec2.size(); i++) {

        cout << "Вывод  в main() полей Класса TagReader" << endl;
        cout << "Название" << " " << finalVec2[i].name << endl;
        cout << "Тип" << " " << finalVec2[i].type << endl;
        cout << "Цена" << " " << finalVec2[i].price << endl;
        cout << " " << endl;
    }

    return 0;
}
