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

MaikuHTTPLib::Header::Header ( const std::string& key, const std::string &value )
{
    Set(key, value);
}

void Header::Deserialize ( const std::string& header )
{
    if(header.size() == 0)
        return;
    std::vector<std::string> segments = util::split(header, " ");
    if(segments.size() == 0)
        return;
    const std::string key = segments[0].substr(0, segments[0].size() - 1);
    segments.erase(segments.begin());
    const std::string value = util::concat(segments, " ");

    this->Set(util::str_tolower(key), value);
}

std::string Header::Serialize()
{
    return "";
}

void Header::Set ( const std::string& key, const std::string& value )
{
    this->key = util::str_tolower(key);
    this->value = value;
}

std::string Header::Key()
{
    return key;
}

std::string Header::Value()
{
    return value;
}
