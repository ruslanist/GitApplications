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

        urlobj.downloadHttp();

         //cout << "\nGot successful response from " << url << std::endl;

         // Response looks good - done using Curl now.  Try to parse the results
         // and print them out.
         Json::Value jsonData;
         Json::Reader jsonReader;

         string httpStr(urlobj.getContent());

         if (jsonReader.parse(httpStr, jsonData))
         {
           cout << "Successfully parsed JSON data" << endl;
           cout << "\nJSON data received:" << endl;
           //cout << jsonData.toStyledString() << endl;

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
                        cout << next_jsonData.toStyledString() << endl;

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
