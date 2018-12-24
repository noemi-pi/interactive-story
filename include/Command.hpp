/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
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
