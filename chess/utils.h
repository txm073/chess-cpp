#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <utility>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<std::string> splitString(std::string str, std::string delim);
std::string joinStrings(std::vector<std::string> strings, std::string joinString);
std::string removeSubString(std::string & mainStr, const std::string & toErase);
std::string arrayToString(std::vector<std::vector<std::string>> arr);
std::vector<std::vector<std::string>> stringToArray(std::string str);

#endif // UTILS_H
