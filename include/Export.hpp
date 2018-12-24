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

class Export{
private:

public:
  static std::string gameSaveToString(GameSave saved_game);
  static File gameSavesToFile(std::string path, std::vector<GameSave> saved_games);
};
