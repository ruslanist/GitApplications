#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include "httpquery.h"

#include <curl/curl.h>

using namespace  std;

HttpQuery::HttpQuery(const string url) : curl(curl_easy_init())  {

        downloadHttp();

        // Don't bother trying IPv6, which would increase DNS resolution time.
        curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

        // Don't wait forever, time out after 10 seconds.
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

        // Follow HTTP redirects if necessary.
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        httpData(new string());
}

static size_t callback(const char* in, size_t size, size_t num, string* out) {

    const size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}

void downloadHttp() {

    //Set remote URL.
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
}

void saveHttp() {

    // Hook up data handling function.
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

    // Hook up data container (will be passed as the last parameter to the
    // callback handling function).  Can be any pointer type, since it will
    // internally be passed as a void pointer.
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

    // Response information.
    long httpCode(0);

    // Run our HTTP GET command, capture the HTTP response code, and clean up.
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
}

~HttpQuery() {

    curl_easy_cleanup(curl);
}
