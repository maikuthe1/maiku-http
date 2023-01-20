#pragma once
#include <string>

namespace MaikuHTTPLib
{

    enum class Version
    {
        HTTP_1_0,
        HTTP_1_1,
        HTTP_2_0,
        UNKNOWN
    };

    std::string to_string(Version version);

    Version version_from_string (const std::string& version) noexcept;

}
