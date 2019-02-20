#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include "httpquery.h"

#include <curl/curl.h>
#include <jsoncpp/json/json.h>

using namespace  std;

HttpQuery::HttpQuery(const string &init_url) : curl(curl_easy_init()), url(init_url), httpData(new string()) {

        //Set remote URL.
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Don't bother trying IPv6, which would increase DNS resolution time.
        curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

        // Don't wait forever, time out after 10 seconds.
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

        // Follow HTTP redirects if necessary.
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Response information.
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

        // Hook up data container (will be passed as the last parameter to the
        // callback handling function).  Can be any pointer type, since it will
        // internally be passed as a void pointer.
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
}

size_t HttpQuery::callback(const char* in, size_t size, size_t num, string* out) {

    const size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}

void HttpQuery::downloadHttp() {

    long httpCode(0);
    // Hook up data handling function.

    // Run our HTTP GET command, capture the HTTP response code, and clean up.
        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

        if (httpCode != 200) {

            throw runtime_error("Couldn't GET from" + url);
        }
}

string  HttpQuery::getContent() {

    return *httpData;
}

HttpQuery::~HttpQuery() {

    curl_easy_cleanup(curl);
}
