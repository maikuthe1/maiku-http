#pragma once
#include "maiku-http-header.hpp"
#include <vector>

namespace MaikuHTTPLib
{
    class Request
    {
    public:
        Request(const std::string &request);
        std::vector<Header> headers;
        std::string body;
    };
}
