#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include<stdexcept>
#include "httpquery.h"

#include <curl/curl.h>

int main()
{
    try {

        string urlobj("https://www.google.com/");

        HttpQuery url(&url);

        cout << url.getContent() << endl;

    }
    catch(exception const& erEx) {

        cout << "Exception of downliad URL"<< erEx.what() << endl;
    }

    return 0;
}
