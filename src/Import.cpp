/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include <stdexcept>
#include "../include/Import.hpp"
#include "../include/File.hpp"
#include "../include/Node.hpp"
#include "../include/GameSave.hpp"
#include "../include/Format.hpp"
#include <vector>
#include <string>
#include <algorithm>

/*Import class :
Import or "translate" information from Files and strings to game objects such as Node and GameSave */

/*
Import a vector of Nodes from a vector of Files
parameters: std::vector<File> node_files, the source vector of Files
return: a std::vector of Nodes
*/
std::vector<Node> Import::nodesFromFiles(std::vector<File> node_files){
  std::vector<Node> nodes;
  for(int i = 0; i < node_files.size(); i++){
    Node node = nodeFromFile(node_files[i]);
    nodes.push_back(node);
  }
  return nodes;
}

/*
Import a Node from a File
parameters: File node_file, the source File
return: a Node
*/
Node Import::nodeFromFile(File node_file){
  std::vector<int> successors;
  std::vector<std::string> substrings = Format::getSubstrings(node_file.getData()[2], ' ');
  bool end;

  if(stoi(node_file.getData()[3]) == 0) end = false;
  else end = true;

  for(int j = 0; j < substrings.size(); j++){
    successors.push_back(stoi(substrings[j]));
  }
  Node node = Node(node_file.getData()[0], node_file.getData()[1], successors, end);
  return node;
}

/*
Import a vector of GameSave from a File
parameters: File games_file, the source File
return: a GameSave
*/
std::vector<GameSave> Import::savedGamesFromFile(File games_file){
  std::vector<GameSave> saved_games;
  for(int i = 0; i < games_file.getData().size(); i++){
    std::string game_data = games_file.getData()[i];
    GameSave game_save = savedGameFromString(game_data);
    saved_games.push_back(game_save);
  }
  return saved_games;
}

/*
Import a single GameSave from a std::string
parameters: std::string game_data, the source string
return: a GameSave
*/
GameSave Import::savedGameFromString(std::string game_data){
    std::vector<std::string> fields = Format::getSubstrings(game_data, '/');
    std::string name = fields[0];
    std::string time_saved = fields[1];
    int saved_node = std::stoi(fields[2]);
    GameSave game_save = GameSave(saved_node, time_saved, name);
    return game_save;
}
