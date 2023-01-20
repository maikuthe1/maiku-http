#include "headers/maiku-http-method.hpp"

using namespace MaikuHTTPLib;

std::string to_string(Method method)
{
    switch(method)
    {
        case Method::GET:
            return "GET";
        case Method::HEAD:
            return "HEAD";
        case Method::POST:
            return "POST";
        case Method::PUT:
            return "PUT";
        case Method::DELETE:
            return "DELETE";
        case Method::TRACE:
            return "TRACE";
        case Method::OPTIONS:
            return "OPTIONS";
        case Method::CONNECT:
            return "CONNECT";
        case Method::PATCH:
            return "PATCH";
    }

    return "UNKNOWN";
}

Method method_from_string (const std::string& method) noexcept
{
    if (method == MaikuHTTPLib::to_string(Method::GET))
    {
        return Method::GET;
    }
    else if (method == MaikuHTTPLib::to_string(Method::HEAD))
    {
        return Method::HEAD;
    }
    else if (method == MaikuHTTPLib::to_string(Method::POST))
    {
        return Method::POST;
    }
    else if (method == MaikuHTTPLib::to_string(Method::PUT))
    {
        return Method::PUT;
    }
    else if (method == MaikuHTTPLib::to_string(Method::DELETE))
    {
        return Method::DELETE;
    }
    else if (method == MaikuHTTPLib::to_string(Method::TRACE))
    {
        return Method::TRACE;
    }
    else if (method == MaikuHTTPLib::to_string(Method::OPTIONS))
    {
        return Method::OPTIONS;
    }
    else if (method == MaikuHTTPLib::to_string(Method::CONNECT))
    {
        return Method::CONNECT;
    }
    else if (method == MaikuHTTPLib::to_string(Method::PATCH))
    {
        return Method::PATCH;
    }

    return Method::UNKNOWN;
}
