#ifndef UTIL_H
#define UTIL_H

#include <map>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <vector>
#include <sstream>

namespace util{
std::vector<std::string> split(const std::string& str, const std::string& delim) noexcept;


std::string concat(const std::vector<std::string>& strings, const std::string& delim = "") noexcept;

std::string str_tolower(std::string s);

}

#endif
