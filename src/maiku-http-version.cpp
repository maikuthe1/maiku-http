#include "headers/maiku-http-version.hpp"

using namespace MaikuHTTPLib;


std::string MaikuHTTPLib::to_string(Version version)
{
    switch(version)
    {
        case Version::HTTP_1_0:
            return "HTTP/1.0";

        case Version::HTTP_1_1:
            return "HTTP/1.1";

        case Version::HTTP_2_0:
            return "HTTP/2.0";
    }

    return "UNKNOWN";
}


Version MaikuHTTPLib::version_from_string (const std::string& version) noexcept
{
    if (version == MaikuHTTPLib::to_string(Version::HTTP_1_0))
    {
        return Version::HTTP_1_0;
    }
    else if (version == MaikuHTTPLib::to_string(Version::HTTP_1_1))
    {
        return Version::HTTP_1_1;
    }
    else if (version == MaikuHTTPLib::to_string(Version::HTTP_2_0))
    {
        return Version::HTTP_2_0;
    }

    return Version::UNKNOWN;
}
