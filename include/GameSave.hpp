/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#pragma once
#include <ctime>
#include <string>

class GameSave{
private:
  int m_saved_node;
  std::string m_time_saved;
  std::string m_name;
public:
  GameSave();
  GameSave(int saved_node, std::string time_saved, std::string name);

  //getters
  int savedNode() const;
  std::string timeSaved() const;
  std::string name() const;

  //getters
  void setSavedNode(int saved_node);
  void setTimeSaved(std::string time_saved);
  void setName(std::string name);
};
