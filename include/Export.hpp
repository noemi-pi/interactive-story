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

class Export{
private:

public:
  static std::string gameSaveToString(GameSave saved_game);
  static File gameSavesToFile(std::string path, std::vector<GameSave> saved_games);
};
