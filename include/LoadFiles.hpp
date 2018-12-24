/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
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
