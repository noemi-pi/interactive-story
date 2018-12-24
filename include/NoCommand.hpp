/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
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
