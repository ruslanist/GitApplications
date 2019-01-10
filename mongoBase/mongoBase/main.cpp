#include <iostream>
#include <cstdlib>
#include "mongo/client/dbclient.h"
#include <vector>

using namespace std;
using namespace bson;

int main() {
  try {

    std::cout << "connected ok" << std::endl;

    mongo::DBClientConnection c;
    c.connect("localhost");

    vector<double> adjusted_close;

    cout << "count:" << c.count("us_stocks.ZYME.US") << endl;
    auto_ptr<mongo::DBClientCursor> cursor = c.query("us_stocks.ZYME.US", mongo::BSONObj());
    while (cursor->more()) {
       cout << cursor->next().toString() << endl;
       mongo::BSONElement name =  cursor->next().getField("adjusted_close");
       cout << name << endl;
       adjusted_close.push_back(name.Double());
    }

    for(int i=0; i<adjusted_close.size(); i++) {

        cout << "Вектор =" << adjusted_close[i] << endl;
    }

  } catch( const mongo::DBException &e ) {
    std::cout << "caught " << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}




