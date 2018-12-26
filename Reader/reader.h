#ifndef READER_H
#define READER_H
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include<stdexcept>

using std::string;
using std::vector;
using std::stringstream;
using std::runtime_error;
using std::exception;

template<typename NumType>
NumType toNumber2(const string& strVal) {

    stringstream stream(strVal);
    NumType numVal;

    if(stream >> numVal) {

        return numVal;
    }
    throw runtime_error("fail to convert " + strVal + " to number");
}

struct Iteam {

    string name;
    string type;
    double price;
    int qty;
};

class  Reader {
public:
     virtual vector<Iteam> read() = 0;

    enum {
        name_indx,
        type_indx,
        price_indx,
        qty_indx
    };

};

class CSVReader : public Reader {
private:
    string linestr;

public:
    CSVReader(const string& m_file_path);

    virtual vector<Iteam> read();
};

class TagReader : public Reader {
private:
    string linestr2;

public:
    TagReader(const string& m_file_path2);

    virtual vector<Iteam> read();
};

#endif // READER_H
