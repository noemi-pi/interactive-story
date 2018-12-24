/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#pragma once
#include "Story.hpp"
#include "GameSave.hpp"
#define NEW_GAME_NODE 0

class Game{
private:
  std::vector<GameSave> m_saved_games;
  Story m_story;
  bool m_saved;
  int m_quit;

  int promptAnswer();
  bool quitRequest(int input);
  char promptSaveRequest();
  bool saveRequest(char input);
  void displayNarration() const;
  void displayChoices() const;

public:
  Game();
  Game(Story story, std::vector<GameSave> saved_games, bool m_saved);
  Game(Story story, std::vector<GameSave> saved_games);
  void save();
  void play();

  //getters
  Story story() const;
  std::vector<GameSave> savedGames() const;
  bool saved() const;
  //setters
  void setStory(Story story);
  void setSavedGames(std::vector<GameSave> saved_games);
  void setSaved(bool save);
};
