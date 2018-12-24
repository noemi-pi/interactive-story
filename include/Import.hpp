/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#pragma once
#include "File.hpp"
#include "GameSave.hpp"
#include "Node.hpp"
#include <vector>
#include <string>

class Import{
private:
  static Node nodeFromFile(File node_file);
  static GameSave savedGameFromString(std::string game_data);
public:
  static std::vector<Node> nodesFromFiles(std::vector<File> node_files);
  static std::vector<GameSave> savedGamesFromFile(File game_file);
};
