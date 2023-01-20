#pragma once
#include <string>

namespace MaikuHTTPLib
{
    enum class Method
    {
        GET,
        HEAD,
        POST,
        PUT,
        DELETE,
        TRACE,
        OPTIONS,
        CONNECT,
        PATCH,
        UNKNOWN
    };

    std::string to_string(Method method);

    Method method_from_string (const std::string& method) noexcept;
}
