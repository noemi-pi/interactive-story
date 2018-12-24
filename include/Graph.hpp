/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#pragma once
#include "Node.hpp"
#include <vector>

class Graph{
private:
  std::vector<Node> m_nodes;

public:
  Graph();
  Graph(std::vector<Node> nodes);
  Graph(const Graph &graph);
  ~Graph();
  Graph &operator=(const Graph &Graph);

  //getters
  std::vector<Node> getNodes() const;
  std::vector<Node> getNodesByIndices(std::vector<int> indices) const;
  Node getNode(int index) const;

  //setters
  void setNodes(std::vector<Node> &nodes);
};
