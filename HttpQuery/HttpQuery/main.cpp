#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include "httpquery.h"

#include <curl/curl.h>

int main()
{
    string url("https://www.google.com/");

    HttpQuery urlHttp(url);

    ~HttpQuery();

    return 0;
}
