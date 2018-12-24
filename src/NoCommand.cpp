/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/NoCommand.hpp"
#include "../include/AppCommand.hpp"
#include "../include/Game.hpp"

/*NoCommand class : concrete class derived from class AppCommand
  Used with the Command Design Pattern (implements execute())
  Does nothing : acts as the default command
 */

NoCommand::NoCommand(){

}

NoCommand::~NoCommand(){

}

void NoCommand::execute(){

}
void NoCommand::execute(Game *game){

}
