/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
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
