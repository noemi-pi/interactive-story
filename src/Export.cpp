/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/Export.hpp"
#include "../include/File.hpp"
#include "../include/GameSave.hpp"
#include <vector>
#include <string>
#include <algorithm>

/*Export class :
Export or "translate" information from game objects, such as GameSaves, so that they can be written to Files and std::string */

/*gameSaveToString
Export a single GameSave to a std::string
parameters: saved_game, the GameSave to export
return: std::string*/
std::string Export::gameSaveToString(GameSave saved_game){
  std::string game_data = saved_game.name() + '/' + saved_game.timeSaved() + '/' + std::to_string(saved_game.savedNode());
  game_data.erase(std::remove(game_data.begin(), game_data.end(), '\n'), game_data.end());
  return game_data;
}

/*gameSavesToFile
Export a vector of GameSaves to a single File object
parameters: std::string path, the path to the resulting File written
            std::vector<GameSave> saved_gamessaved_game, the vector of GameSaves to export
return: std::string*/
File Export::gameSavesToFile(std::string path, std::vector<GameSave> saved_games){
  std::vector<std::string> saved_games_data;
  for(int i = 0; i <saved_games.size(); i++){
    std::string game_data = gameSaveToString(saved_games[i]);
    saved_games_data.push_back(game_data);
  }
  File saved_games_file = File(path, saved_games_data);
  return saved_games_file;
}
