/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
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
