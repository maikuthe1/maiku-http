#pragma once
#include <string>
#include <vector>
#include <map>

namespace MaikuHTTPLib
{
    class Header
    {
    public:
        Header();
        Header(const std::string &header);
        std::string Get(const std::string &key);
        void Set(const std::string &key, const std::string &value);
        std::string Serialize();
        void Deserialize(const std::string &header);

    private:
        std::map<std::string, std::string> data;
    };
}
