/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
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
