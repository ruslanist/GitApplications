
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






