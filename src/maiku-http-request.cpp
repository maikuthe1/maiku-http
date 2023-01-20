#include "headers/maiku-http-request.hpp"
#include "headers/util.hpp"

using namespace MaikuHTTPLib;

Request::Request(const std::string &request)
{
    std::vector<std::string> lines = util::split(request, "\r\n");

    if(lines.size() == 0)
    {
        throw std::runtime_error("Empty request.");
    }

    std::vector<std::string> segments = util::split(lines[0], " ");

    if (segments.size() != 3)
    {
        throw std::runtime_error("First line of HTTP request ('" + std::string(request) + "') consisted of " + std::to_string(segments.size()) + " space separated segments, should be 3.");
    }

    method = method_from_string(segments[0]);
    resource = segments[1];
    version = version_from_string(segments[2]);

    lines.erase(lines.begin());

    for(const std::string &line : lines)
    {
        if(line.size() == 0)
            break;

        headers.push_back(line);
    }
}
