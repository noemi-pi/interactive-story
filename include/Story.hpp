/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#pragma once
#include "Node.hpp"
#include "Graph.hpp"

class Story{
private:
  int m_current_node_index;
  Graph m_graph;

public:
  Story();
  Story(int current_node_index, Graph graph);
  bool end() const;
  std::string getCurrentNarration() const;
  std::vector<std::string> getCurrentChoices() const;
  void updateCurrent(int index);
  bool isCurrentSuccessor(int successor_index);
  //getters
  int getCurrentNodeIndex() const;
  Graph graph() const;
  //setters
  void setCurrentNodeIndex(const int &current_node_index);

};
