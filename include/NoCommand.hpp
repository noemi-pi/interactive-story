/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#pragma once
#include "AppCommand.hpp"
#include "Game.hpp"

class NoCommand : public AppCommand {
private:
public:
  NoCommand();
  ~NoCommand();
  void execute();
  void execute(Game *game);
};
