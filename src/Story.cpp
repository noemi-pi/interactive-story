/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/Story.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "../include/Node.hpp"

/*Story class
contains and access information about a Story: the story's graph and the current node's index in the graph
*/

Story::Story(){

}

Story::Story(int current_node_index, Graph graph): m_current_node_index(current_node_index), m_graph(graph){

}

/*replace the current node's index by a node in its successors list
parameters: int index, the index of the successor
return: void
*/
void Story::updateCurrent(int index){
  Node current_node = m_graph.getNode(m_current_node_index);
  m_current_node_index = current_node.selectSuccessor(index);
}

/*check if an index exist in the current node's successors list
parameters: int index, the index to check
return: bool, true if the index exist, false if not
*/
bool Story::isCurrentSuccessor(int successor_index){
  Node current_node = m_graph.getNode(m_current_node_index);
  if(!current_node.successorExists(successor_index)) return false;
  return true;
}

/*check if the current node is an ending of the story
parameters: none
return: bool, true if the current node is an ending, false if not
*/
bool Story::end() const {
  Node current_node = m_graph.getNode(m_current_node_index);
  if(current_node.end() || current_node.getSuccessors()[0] < 0) return true;
  return false;
}

/*get the narration corresponding to the current node
parameters: none
return: std::string
*/
std::string Story::getCurrentNarration() const {
  Node current_node = m_graph.getNode(m_current_node_index);
  return current_node.getNarration();
}

/*get the decisions corresponding to the current node
parameters: none
return: std::vector<std::string>
*/
std::vector<std::string> Story::getCurrentChoices() const{
  Node current_node = m_graph.getNode(m_current_node_index); //get the current node
  std::vector<Node> current_successors = m_graph.getNodesByIndices(current_node.getSuccessors()); //get the nodes corresponding to the current node's successor
  std::vector<std::string> current_choices;
  for(int i = 0; i < current_successors.size(); i++){
    current_choices.push_back(current_successors[i].getDecision()); //get the choice corresponding to each of the current node's successor and add it to current_choices
  }
  return current_choices;
}

//getters
int Story::getCurrentNodeIndex() const{
  return m_current_node_index;
}

Graph Story::graph() const{
  return m_graph;
}
//setters
void Story::setCurrentNodeIndex(const int &current_node_index){
  m_current_node_index = current_node_index;
}
