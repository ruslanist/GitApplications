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
     virtual Iteam readerNext() = 0;
};

class CSVReader : public Reader {
public:
    virtual Iteam readerNext();


#endif // READER_H
