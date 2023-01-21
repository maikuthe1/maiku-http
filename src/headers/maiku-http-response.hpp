#pragma once
#include <string>
#include "maiku-http-version.hpp"
#include "maiku-http-header.hpp"
#include <sstream>
#include <vector>

namespace MaikuHTTPLib
{
    class Response
    {
    public:
        Response();
        Response(Version version, int status, std::string description);

        Version version;
        int status;
        std::string description;
        const std::string server = "Maiku-HTTP/0.1 (*nix)";
        std::vector<Header> headers;
        std::string body;

        std::string Serialize();
    };
}
