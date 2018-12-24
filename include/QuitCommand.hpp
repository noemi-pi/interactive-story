/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#pragma once
#include "AppCommand.hpp"
#include "Game.hpp"

class QuitCommand : public AppCommand {
private:
public:
  QuitCommand();
  ~QuitCommand();
  void execute();
  void execute(Game *game);
};
