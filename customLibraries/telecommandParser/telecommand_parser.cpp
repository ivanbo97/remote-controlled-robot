#include "telecommand_parser.h"

std::vector<std::string> splitToStrings(const std::string str, char delim)
{
    std::vector<std::string> result;
    std::istringstream ss{ str };
    std::string token;
    while (std::getline(ss, token, delim)) {
        if (!token.empty()) {
            result.push_back(token);
        }
    }
    return result;
}
void extractAndConvertStr(std::vector<std::string> recievedStrings)
{
    receivedLat = ::atof(recievedStrings[0].c_str());
    receivedLon = ::atof(recievedStrings[1].c_str());
    speedLevel = recievedStrings[2].c_str();
}
