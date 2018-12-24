/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/GameSave.hpp"
#include <ctime>
#include <string>

/*GameSave class :
contains information about a saved game: the index of the story's current node, the time at which it was saved, the name of GameSave
*/

GameSave::GameSave(): m_saved_node(0), m_time_saved(" "), m_name("Game_0"){

}

GameSave::GameSave(int saved_node, std::string time_saved, std::string name): m_saved_node(saved_node), m_time_saved(time_saved), m_name(name){

}

//getters
int GameSave::savedNode() const{
  return m_saved_node;
}
std::string GameSave::timeSaved() const{
  return m_time_saved;
}
std::string GameSave::name() const{
  return m_name;
}

//setters
void GameSave::setSavedNode(int saved_node){
  m_saved_node = saved_node;
}
void GameSave::setTimeSaved(std::string time_saved){
  m_time_saved = time_saved;
}
void GameSave::setName(std::string name){
  m_name = name;
}
