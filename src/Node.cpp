/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/Node.hpp"
#include <vector>
#include <string>

/*Node class
contains and access information about a Node corresponding to a given part of the story :
decision that leads to this node, narration, indices of its successors, and whether the Node is an ending of the story
*/

Node::Node(std::string decision, std::string narration, std::vector<int> &successors, bool end): m_decision(decision), m_narration(narration), m_successors(successors), m_end(end){

}

Node::Node(const Node &node): m_decision(node.m_decision), m_narration(node.m_narration), m_successors(node.m_successors), m_end(node.m_end){

}

Node::Node(){
  m_decision = " ";
  m_narration = " ";
  m_end = false;
}

Node &Node::operator=(const Node &node){
  if(this != &node){
    m_decision = node.m_decision;
    m_narration = node.m_narration;
    m_successors = node.m_successors;
    m_end = m_end;
  }
  return *this;
}

Node::~Node(){

}


//getters
std::string Node::getDecision()  const{
  return m_decision;
}
std::string Node::getNarration()  const{
  return m_narration;
}
std::vector<int> Node::getSuccessors()  const{
  return m_successors;
}

/*get successor from the node's successors' list at a given index
parameters: int index, the index of the wanted node
return: int
*/
int Node::selectSuccessor(int index)  const{
  return m_successors[index];
}

bool Node::end()  const{
  return m_end;
}

/*get the number of choices available from a given node
return: int
*/
int Node::nbChoices() const{
  return m_successors.size();
}

/*check if there is a successor in the node's successors' list at a given index
parameters: const int index, the index to check
return: bool, true if successor exists at index, false if not
*/
bool Node::successorExists(const int index) const{
  if(index < 0 || index >= m_successors.size()) return false;
  return true;
}

//setters
void Node::setDecision(std::string &decision){
  m_decision = decision;
}

void Node::setNarration(std::string &narration){
  m_narration = narration;
}
void Node::setSuccessors(std::vector<int> &successors){
  m_successors = successors;
}

void Node::setEnd(bool end){
  m_end = end;
}
