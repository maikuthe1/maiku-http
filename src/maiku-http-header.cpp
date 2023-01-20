#include "headers/maiku-http-header.hpp"
#include "headers/util.hpp"

using namespace MaikuHTTPLib;

Header::Header()
{

}

MaikuHTTPLib::Header::Header ( const std::string& header )
{
    Deserialize(header);
}


void Header::Deserialize ( const std::string& header )
{

}

std::string Header::Serialize()
{
    return "";
}

std::string Header::Get ( const std::string& key )
{
    return "";
}

void Header::Set ( const std::string& key, const std::string& value )
{
}
