/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/AppCommand.hpp"
#include "../include/Command.hpp"
#include "../include/Game.hpp"

/*AppCommand
  Derives abstract class Command so that it can be instantiated
  overloads the execute method so that it can take a pointer to Game as a parameter, but does not define any behaviour
 */

AppCommand::AppCommand(){

}

AppCommand::~AppCommand(){

}

void AppCommand::execute(){

}
void AppCommand::execute(Game *game){

}
