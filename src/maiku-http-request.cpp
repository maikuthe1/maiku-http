#include "headers/maiku-http-request.hpp"
#include "headers/util.hpp"

using namespace MaikuHTTPLib;

Request::Request(const std::string &request)
{
    std::vector<std::string> lines = util::split(request, "\r\n");
    for(const std::string &line : lines)
    {
        if(line.size() == 0)
            break;

        headers.push_back(line);
    }
}
