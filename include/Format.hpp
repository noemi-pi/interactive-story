/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#pragma once
#include <vector>
#include <string>

class Format{
public:
  static std::string formatToString(std::vector<std::string> string_vector, std::string delimiter);
  static std::vector<std::string> getSubstrings(std::string string, char delimiter);
  static bool containsSubstring(std::string string, std::string substring);
};
