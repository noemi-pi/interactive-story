/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#pragma once
#include "AppCommand.hpp"
#include "LoadGameCommand.hpp"
#include "Game.hpp"
class NewGameCommand : public AppCommand {

public:
  NewGameCommand();
  ~NewGameCommand();
  void execute() override;
  void execute(Game *game) override;
  int newGameStart();
};
