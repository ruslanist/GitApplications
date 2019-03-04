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

    for(auto item : allCollectDB) {

    auto_ptr<DBClientCursor> cursor = c.query("stocks." + item, BSONObj());

        while (cursor->more()) {

            BSONObj p2 = cursor->next();

            //cout << "Open" << p2.getField("Open").number() << endl;
            //cout << "High" << p2.getField("High").number() << endl;
            //cout << "Low" << p2.getField("Low").number() << endl;

            adjusted_close.push_back(p2.getField("Close").number());

            for(int i =0; i < adjusted_close.size(); i++) {

                cout << "The Value Close of Exchange =" << adjusted_close[i] << endl;
            }

            cout << p2.toString() << endl;
        }
    }

    size_t range_Len = 10; // Len of first part
    size_t breakout_Len = 20; // Len of second part

    exchangeAnalyst(adjusted_close.data(), range_Len, breakout_Len);

  } catch( const mongo::DBException &e ) {
    std::cout << "caught " << e.what() << std::endl;
  }
  return EXIT_SUCCESS;

}
