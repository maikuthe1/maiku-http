#pragma once
#include "util.hpp"
#include "maiku-http-header.hpp"
#include "maiku-http-version.hpp"
#include "maiku-http-method.hpp"
#include <vector>

namespace MaikuHTTPLib
{
    class Request
    {
    public:
        Request(const std::string &request);
        Version version;
        Method method;
        std::string resource;
        std::vector<Header> headers;
        std::string body;
    };
}
