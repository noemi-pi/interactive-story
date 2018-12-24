/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#pragma once
#include "Game.hpp"

class Command {
private:
public:
  Command();
  virtual ~Command();
  virtual void execute() = 0;
};
