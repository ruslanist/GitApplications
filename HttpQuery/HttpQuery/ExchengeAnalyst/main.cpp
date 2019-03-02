#include <iostream>
#include <cstdlib>
#include "mongo/client/dbclient.h"
#include <vector>
#include "analyst.h"

using namespace std;
using namespace mongo;

int main() {
  try {

    std::cout << "connected ok" << std::endl;

    mongo::DBClientConnection c;
    c.connect("localhost");
    mongo::client::initialize();

    vector<double> adjusted_close;

    auto allCollectDB = c.getCollectionNames("stocks");

    auto_ptr<DBClientCursor> cursor = c.query("stocks." + allCollectDB, BSONObj());

    while (cursor->more()) {

       cout << cursor->next().toString() << endl;
    }


    //for(auto item : allCollectDB) {  cout << "count:" << c.count("stocks." + item) << endl; }


    cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;

    cout << "count:" << c.count("us_stocks.ZYME.US") << endl;
    auto_ptr<mongo::DBClientCursor> cursor = c.query("us_stocks.ZYME.US", mongo::BSONObj());
    while (cursor->more()) {
       auto p = cursor->next();
       cout << p.toString() << endl;
       mongo::BSONElement name =  p.getField("adjusted_close");
       cout << name << endl;
       adjusted_close.push_back(name.Double());
    }

    cout << adjusted_close.size() << endl;

    for(int i=0; i<adjusted_close.size(); i++) {

        cout << "Вектор =" << adjusted_close[i] << endl;
    }

    size_t range_Len = 10; // Len of first part
    size_t breakout_Len = 20; // Len of second part

    exchangeAnalyst(adjusted_close.data(), range_Len, breakout_Len);

  } catch( const mongo::DBException &e ) {
    std::cout << "caught " << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}




