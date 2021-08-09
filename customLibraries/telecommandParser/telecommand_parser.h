#ifndef TELECOMMAND_PARSER_H
#define TELECOMMAND_PARSER_H
#include <sstream>
#include <vector>
#include <cstdlib>
std::vector<std::string> splitToStrings(const std::string str, char delim);
void extractAndConvertStr(std::vector<std::string> recievedStrings);
extern double receivedLat;
extern double receivedLon;
extern const char* speedLevel;
#endif