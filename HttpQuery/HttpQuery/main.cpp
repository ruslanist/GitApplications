#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include <set>

#include "httpquery.h"

#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "mongo/client/dbclient.h"

using namespace std;
using namespace mongo;

int main()
{

    try {

        mongo::DBClientConnection c;
        c.connect("localhost");

        std::cout << "connected ok" << std::endl;

        string url("https://eodhistoricaldata.com/api/exchanges/US?api_token=" API_KEY "&fmt=json");
        HttpQuery urlobj(url);

        cout << "111" << endl;

        urlobj.downloadHttp();

        cout << "222222222222222222222222" << endl;

         //cout << "\nGot successful response from " << url << std::endl;

         // Response looks good - done using Curl now.  Try to parse the results
         // and print them out.
         Json::Value jsonData;
         Json::Reader jsonReader;

         string httpStr(urlobj.getContent());
            cout << "222" << endl;
         if (jsonReader.parse(httpStr, jsonData))
         {
           cout << "Successfully parsed JSON data" << endl;
           cout << "\nJSON data received:" << endl;
           //cout << jsonData.toStyledString() << endl;
             cout << "333" << endl;
            set<string> exchangeCheck;
            exchangeCheck.insert("AMEX");
            exchangeCheck.insert("ASX");
            exchangeCheck.insert("BATS");
            exchangeCheck.insert("CSE");
            exchangeCheck.insert("IEX");
            exchangeCheck.insert("NASDAQ");
            exchangeCheck.insert("NYSE");
            exchangeCheck.insert("NYSE ARCA");
            exchangeCheck.insert("NYSE MKT");
            exchangeCheck.insert("US");
             cout << "444" << endl;

            for(int index = 0; index < jsonData.size(); ++index) {

                if( exchangeCheck.count(jsonData[index]["Exchange"].asString()) ) {

                    string val_ofCode( jsonData[index]["Code"].asString() );

                    string nextUrl("https://eodhistoricaldata.com/api/eod/" + val_ofCode + ".US?api_token=" API_KEY "&period=d&order=a&from=2017-01-01&fmt=json");

                    HttpQuery nextUrlobj(nextUrl);

                    nextUrlobj.downloadHttp();

                    Json::Value next_jsonData;
                    Json::Reader next_jsonReader;

                    string next_httpStr(nextUrlobj.getContent());

                    if(next_jsonReader.parse(next_httpStr, next_jsonData)) {

                        cout << "Successfully parsed JSON next_data" << endl;
                        cout << "\nJSON next_data received:" << endl;
                        //cout << next_jsonData.toStyledString() << endl;

                        cout << "1" << endl;
                        BSONObjBuilder bil;

                        for(int index2 = 0; index2 < next_jsonData.size(); ++index2) {

                            cout << "2" << endl;
                            bil.append("Close", next_jsonData[index2]["close"].asString());
                            bil.append("High", next_jsonData[index2]["high"].asString());
                            bil.append("Low", next_jsonData[index2]["low"].asString());
                            bil.append("Open", next_jsonData[index2]["open"].asString());

                            cout << "3" << endl;
                            BSONObj p = bil.obj();

                            c.insert("tutorial.exchange", p);

                            cout << "4" << endl;
                            cout << "count:" << c.count("tutorial.exchange") << endl;

                            cout << "5" << endl;
                            auto_ptr<DBClientCursor> cursor =
                            c.query("tutorial.exchange", BSONObj());

                            cout << "6" << endl;
                            while (cursor->more()) {

                                cout << "7" << endl;
                               cout << cursor->next().toString() << endl;
                            }
                        }
                    }
                }

            }

         }
         else
         {
             cout << "Could not parse HTTP data as JSON" << endl;
             cout << "HTTP data was:\n" << httpStr << endl;
             return 1;
         }
    }
    catch(exception const& erEx) {

        cout << "Exception of downliad URL"<< erEx.what() << endl;
    }



    return 0;
}
