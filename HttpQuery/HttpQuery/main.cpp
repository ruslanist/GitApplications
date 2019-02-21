#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include<stdexcept>
#include "httpquery.h"

#include <curl/curl.h>
#include <jsoncpp/json/json.h>

int main()
{

    try {

        string url("https://eodhistoricaldata.com/api/exchanges/US?api_token=" API_KEY "&fmt=json");
        HttpQuery urlobj(url);

        urlobj.downloadHttp();

         std::cout << "\nGot successful response from " << url << std::endl;

         // Response looks good - done using Curl now.  Try to parse the results
         // and print them out.
         Json::Value jsonData;
         Json::Reader jsonReader;

         string httpStr = urlobj.getContent();

         std::cout << httpStr << std::endl;

         if (jsonReader.parse(httpStr, jsonData))
         {
            std::cout << "Successfully parsed JSON data" << std::endl;
            std::cout << "\nJSON data received:" << std::endl;
            std::cout << jsonData.toStyledString() << std::endl;
         }
         else
         {
             std::cout << "Could not parse HTTP data as JSON" << std::endl;
             std::cout << "HTTP data was:\n" << httpStr << std::endl;
             return 1;
         }
    }
    catch(exception const& erEx) {

        cout << "Exception of downliad URL"<< erEx.what() << endl;
    }



    return 0;
}
