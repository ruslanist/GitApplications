#ifndef READER_H
#define READER_H
#include <string>

using std::string;

struct Iteam
{
    Iteam();
    string name;
    string type;
    string price;
};

class  Reader
{
public:
     virtual Iteam read() = 0;
};

class CSVReader : public Reader {
private:
    string linestr;

public:
    CSVReader::CSVReader(const string& file_path);

    virtual Iteam read();


#endif // READER_H
