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
        Header(const std::string &key, const std::string &value);
        void Set(const std::string &key, const std::string &value);
        std::string Key();
        std::string Value();
        std::string Serialize();
        void Deserialize(const std::string &header);

    private:
        std::string key, value;
    };
}
