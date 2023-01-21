#include "headers/maiku-http-response.hpp"

using namespace MaikuHTTPLib;

Response::Response(Version version, int status, std::string description) : version(version), status(status), description(description)
{

}


std::string Response::Serialize()
{
    std::stringstream response_string("");
    response_string << MaikuHTTPLib::to_string(this->version) << " " << std::to_string(this->status) << " " << this->description << "\r\n";

    for(Header &header : headers)
    {
        response_string << header.Key() << ": " << header.Value() << "\r\n";
    }
    response_string << "Server: " << this->server << "\r\n";
    if(this->body.size() > 0)
        response_string << "content-length: " << std::to_string(static_cast<int>(this->body.size())) << "\r\n";

    response_string << "\r\n";

    if(body.size() > 0)
        response_string << this->body;

    return response_string.str();
}
