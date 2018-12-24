/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#pragma once
#include "File.hpp"
#include "GameSave.hpp"
#include <vector>
#include <string>

class LoadFiles{
public:
  static std::vector<File> loadGraphNodesFiles(File graph_file);
  static File loadFile(std::string path);
};
