/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/AppCommand.hpp"
#include "../include/NewGameCommand.hpp"
#include "../include/Application.hpp"
#include "../include/Story.hpp"
#include "../include/Game.hpp"
#include "../include/Export.hpp"
#include "../include/CommandCodes.hpp"
#include  <iostream>

/*NewGameCommand class : concrete class derived from class AppCommand
  Used with the Command Design Pattern (implements execute())
  Initialize a new game and play it
 */

NewGameCommand::NewGameCommand(): AppCommand() {

}

NewGameCommand::~NewGameCommand(){

}

void NewGameCommand::execute(){

}

/*Initialize a new game and play it
parameters : a pointer to the Game to play
return: void
*/
void NewGameCommand::execute(Game *game){
Story story = Story(0, game->story().graph()); //initialize the game's story at 0 (corresponding to the first node in the graph)
  game->setStory(story);
  game->play();
  if (game->saved()){
    game->save();
  }
}
