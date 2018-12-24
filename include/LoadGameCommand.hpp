/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#pragma once
#include "AppCommand.hpp"
#include "LoadGameCommand.hpp"
#include "Application.hpp"
#include "GameSave.hpp"
#include "Menu.hpp"
#include "SavedGamesMenu.hpp"
#include <iostream>
#include <vector>
#include <string>

class LoadGameCommand : public AppCommand {
private:
  SavedGamesMenu m_menu;
  int m_input;
  void executeActionCode(Game *game);
  void initAndRunGame(Game *game);

public:
  LoadGameCommand();
  ~LoadGameCommand();
  void execute() override;
  void execute(Game *game) override;
  void loadMenu(std::vector<GameSave> saved_games);

  //setters
  void setMenu(const SavedGamesMenu &menu);
  void setInput(const int input);

  //getters
  SavedGamesMenu menu() const;
  int input() const;
};
