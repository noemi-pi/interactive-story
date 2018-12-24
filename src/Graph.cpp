/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/Graph.hpp"
#include "../include/Node.hpp"
#include <vector>

/*Graph class
Contains a vector of nodes and provides methods to access the nodes
*/
Graph::Graph(){
  std::vector<Node> nodes;
  m_nodes = nodes;
}

Graph::Graph(std::vector<Node> nodes): m_nodes(nodes) {}

Graph::Graph(const Graph &graph): m_nodes(graph.m_nodes){}

Graph::~Graph(){

}

Graph &Graph::operator=(const Graph &graph) {
  if(this != &graph){
    m_nodes = graph.m_nodes;
  }
  return *this;
}

//getters
std::vector<Node> Graph::getNodes() const{
  return m_nodes;
}

/*
 return a vector of Nodes corresponding to indices specified in a vector of ints
 parameters : indices, a std::vector of int
 return : a std::vector of Nodes
 */
std::vector<Node> Graph::getNodesByIndices(std::vector<int> indices) const{
  std::vector<Node> selected_nodes;
  for(int i=0; i < indices.size(); i++){
    Node node = getNode(indices[i]);
    selected_nodes.push_back(node);
  }
  return selected_nodes;
}

/*
 return a Node corresponding to a specified index
 parameters : index, an int
 return : a Node
 */
Node Graph::getNode(int index) const{
  return m_nodes[index];
}

//setters
void Graph::setNodes(std::vector<Node> &nodes){
  m_nodes = nodes;
}
