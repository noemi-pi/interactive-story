/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#pragma once
#include <string>
#include <vector>

class Node{
private:
  std::string m_decision;
  std::string m_narration;
  std::vector<int> m_successors;
  bool m_end;

public:
  Node();
  Node(std::string m_decision, std::string narration, std::vector<int> &successors, bool end);
  Node(const Node &node);
  ~Node();
  Node &operator=(const Node &node);
  //getters
  std::string getDecision()  const;
  std::string getNarration()  const;
  std::vector<int> getSuccessors()  const;
  int selectSuccessor(int index) const;
  bool end()  const;
  
  int nbChoices() const;
  bool successorExists(const int index) const;

  //setters
  void setDecision(std::string &decision);
  void setNarration(std::string &narration);
  void setSuccessors(std::vector<int> &successors);
  void setEnd(bool end);
};
