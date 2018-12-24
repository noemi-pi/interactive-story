/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#pragma once
#include "Game.hpp"
#include "Command.hpp"

class AppCommand : public Command {
private:
public:
  AppCommand();
  ~AppCommand();
  virtual void execute();
  virtual void execute(Game *game);
};
