/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
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
