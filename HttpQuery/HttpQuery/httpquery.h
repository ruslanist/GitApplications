#ifndef HTTPQUERY_H
#define HTTPQUERY_H

#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include <curl/curl.h>

using namespace  std;

class HttpQuery {

public:

    HttpQuery(const string url);
    ~HttpQuery();

    CURL* curl;
    unique_ptr<string> httpData;

    static size_t callback(const char* in, size_t size, size_t num, string* out);

    void downloadHttp();
    void saveHttp();


}

#endif // HTTPQUERY_H
