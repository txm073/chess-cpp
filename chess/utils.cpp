#include "utils.h"

std::vector<std::string> splitString(std::string str, std::string delim = " ")
{
    std::vector<std::string> splits = {};
    size_t pos_start = 0, pos_end, delim_len = delim.length();
    std::string token;
    while((pos_end = str.find(delim, pos_start)) != std::string::npos){
        token = str.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        splits.push_back(token);
    }
    splits.push_back(str.substr(pos_start));
    return splits;
}

std::string joinStrings(std::vector<std::string> strings, std::string joinString)
{
    std::string joined;
    for(unsigned int i = 0; i < strings.size(); ++i){
       joined = joined + strings[i] + ((i != strings.size()) ? joinString : "");
    }
    return joined;
}

std::string removeSubString(std::string & mainStr, const std::string & toErase)
{
    size_t pos = std::string::npos;
    while ((pos  = mainStr.find(toErase) )!= std::string::npos)
    {
        mainStr.erase(pos, toErase.length());
    }
    return mainStr;
}

std::vector<std::vector<std::string>> stringToArray(std::string str)
{
    std::vector<std::vector<std::string>> arr;
    arr.assign(8, std::vector<std::string>(8, "O"));
    int i = 0;
    for(char c : str){
        int x = i / 8, y = i % 8;
        std::string s{c};
        arr[x][y] = s;
        ++i;
    }
    return arr;
}

std::string arrayToString(std::vector<std::vector<std::string>> arr)
{
    std::string output;
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            output += arr[i][j];
        }
    }
    return output;
}
