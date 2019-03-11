/*
#include <iostream>
#include <string>

#include <Poco/Data/MySQL/MySQLException.h>
#include <Poco/Data/MySQL/Connector.h>
#include <Poco/Data/SessionFactory.h>

using namespace std;

int main()
{
Poco::Data::MySQL::Connector::registerConnector();
try
{
string str = "host=localhost;user=vasa;password=123;compress=true;auto-reconnect=true";
Poco::Data::Session test(Poco::Data::SessionFactory::instance().create(Poco::Data::MySQL::Connector::KEY, str ));
}
catch (Poco::Data::MySQL::ConnectionException& e)
{
cout << e.what() << endl;
return -1;
}
catch(Poco::Data::MySQL::StatementException& e)
{
cout << e.what() << endl;
return -1;
}

return 0;
}
*/

#include "Poco/Data/Session.h"
#include "Poco/Data/SQLite/Connector.h"
#include <vector>
#include <iostream>
#include <string>

#include <Poco/Data/MySQL/MySQLException.h>
#include <Poco/Data/MySQL/Connector.h>
#include <Poco/Data/SessionFactory.h>

using std::cout;
using std::endl;
using std::string;

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

// struct
struct Person
{
    std::string name;
    std::string address;
    int         age;
};

int main(int argc, char** argv)
{
    cout << "1111111111111111" << endl;
    // register SQLite connector
    Poco::Data::MySQL::Connector::registerConnector();

    cout << "22222222222222" << endl;

    //string str = "host=localhost;user=vasa;password=123;compress=true;auto-reconnect=true";
    //Poco::Data::Session test(Poco::Data::SessionFactory::instance().create(Poco::Data::MySQL::Connector::KEY, str ));
    string str = "host=localhost;port=3306;db=trafficUser;user=vasa;password=123;compress=true;auto-reconnect=true";


    // create a session
    Session session(Poco::Data::SessionFactory::instance().create(Poco::Data::MySQL::Connector::KEY, str ));

    cout << "3333333333333333" << endl;

    // drop sample table, if it exists c
    session << "DROP TABLE IF EXISTS Person", now;

    cout << "4444444444444" << endl;

    // (re)create table
    session << "CREATE TABLE Person (Name VARCHAR(30), Address VARCHAR, Age INTEGER(3))", now;

    cout << "555555555555555555555" << endl;

    // insert some rows
    Person person =
    {
        "Bart Simpson",
        "Springfield",
        12
    };
    cout << "6666666666666666666666666666666" << endl;

    Statement insert(session);
    cout << "777777777777777777777777777777777777777777777" << endl;
    insert << "INSERT INTO Person VALUES(?, ?, ?)",
        use(person.name),
        use(person.address),
        use(person.age);
cout << "888888888888888888888888888888888" << endl;
    insert.execute();
cout << "999999999999999999999999999999999999999999999" << endl;
    person.name    = "Lisa Simpson";
    cout << "10101010101010101010101010" << endl;
    person.address = "Springfield";
    cout << "1111-----1111111------1111111------111111" << endl;
    person.age     = 10;
    cout << "12121211212121212121212121212121212" << endl;

    insert.execute();

    cout << "1313131313131313131313131313131313131313" << endl;

    // a simple query
    Statement select(session);
    cout << "141414141414141414141414141414" << endl;
    select << "SELECT Name, Address, Age FROM Person",
        into(person.name),
        into(person.address),
        into(person.age),
        range(0, 1); //  iterate over result set one row at a time
        cout << "1515151515151515151515151151515151515" << endl;
    while (!select.done())
    {
        cout << "1616161616161616161616161616161616" << endl;
        select.execute();
        cout << "171717171717171717171717171717171717" << endl;
        std::cout << person.name << " " << person.address << " " << person.age << std::endl;

        cout << "202020202020202020202020202020202020" << endl;
    }

    return 0;
}

