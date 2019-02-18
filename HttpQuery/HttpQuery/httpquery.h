#ifndef HTTPQUERY_H
#define HTTPQUERY_H

#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include <curl/curl.h>

using namespace  std;

class HttpQuery {

private:

    CURL* curl;
    unique_ptr<string> httpData;

public:

    HttpQuery(const string &url);
    ~HttpQuery();

    static size_t callback(const char* in, size_t size, size_t num, string* out);

    void downloadHttp();
    string getContent();


}

#endif // HTTPQUERY_H
