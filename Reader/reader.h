#ifndef READER_H
#define READER_H
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Iteam
{
    string name;
    string type;
    string price;
};

class  Reader
{
public:
     virtual vector<Iteam> read() = 0;
};

class CSVReader : public Reader {
private:
    string linestr;

public:
    CSVReader(const string& m_file_path);

    virtual vector<Iteam> read();

};

#endif // READER_H
