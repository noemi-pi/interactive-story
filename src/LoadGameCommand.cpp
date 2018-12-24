/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/Command.hpp"
#include "../include/LoadGameCommand.hpp"
#include "../include/Application.hpp"
#include "../include/Story.hpp"
#include "../include/Game.hpp"
#include "../include/GameSave.hpp"
#include "../include/Export.hpp"
#include "../include/CommandCodes.hpp"
#include "../include/Menu.hpp"
#include "../include/SavedGamesMenu.hpp"
#include "../include/MenuOption.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <limits>

/*LoadGameCommand class : concrete class derived from class AppCommand
  Used with the Command Design Pattern (implements execute())
  Provide a menu  and let the player quit or load an existing saved game and play it
  To be improved by delegating quit() and initAndRunGame() to  additionnal commands, using a similar design to Application
 */

LoadGameCommand::LoadGameCommand() : AppCommand() {

}

LoadGameCommand::~LoadGameCommand(){

}

void LoadGameCommand::execute(){
}

/*execute(Game * game)
display the menu and let the player answer
update the menu's command code accordingly
execute the action corresponding to the menu's command code
parameters: Game * game, the game to play
return: void
 */
void LoadGameCommand::execute(Game *game){
  loadMenu(game->savedGames());
  while(!m_menu.isQuitTrue()){
    m_menu.display();
    m_menu.promptAnswer();
    m_menu.setCommandCodeFromInput();
    m_menu.quit();
  }
  try{
    executeActionCode(game);
  }
  catch(std::exception e){
    std::cout<<e.what() <<std::endl;
  }
}

/*Load the menu, using the info from saved games as options description
parameters: std::vector<GameSave> saved_games, the saved games used to create the menu's options
return: void
 */
void LoadGameCommand::loadMenu(std::vector<GameSave> saved_games){
  std::vector<MenuOption> options;
  options.push_back(MenuOption("quit menu", QUIT)); //quit is the first option
  for(int i=0; i < saved_games.size(); i++){
    std::string saved_game_desc = Export::gameSaveToString(saved_games[i]); //convert the info from each saved game to a string
    MenuOption option = MenuOption(saved_game_desc, LOAD_GAME_START); //use the saved game description to initialize each option
    options.push_back(option);
  }
  m_menu.setOptions(options);
}

/*execute the action corresponding to the menu's current command code
parameters: Game * game, the game on which to execute the action
return: void
 */
void LoadGameCommand::executeActionCode(Game *game){
  switch(m_menu.commandCode()){
    case QUIT : m_menu.quit();
    break;
    case LOAD_GAME_START: initAndRunGame(game);
    m_menu.quit();
    break;
    default : throw(std::runtime_error("command code not valid"));
    m_menu.quit();
  }
}

/*initialize the game using the selected saved game
parameters: Game * game, the game to play
return: void
 */
void LoadGameCommand::initAndRunGame(Game * game){
  GameSave saved_game = game->savedGames()[m_menu.input()-1]; //get the GameSave corresponding to the player's input
  int first_node = saved_game.savedNode(); //get the node index saved in saved_game
  Story story = Story(first_node, game->story().graph()); //use it to initialize the game's story
  game->setStory(story);
  game->play(); //play the game
  if (game->saved()){
    game->save();
  }
}

//setters
void LoadGameCommand::setMenu(const SavedGamesMenu &menu){
  m_menu = menu;
}

void LoadGameCommand::setInput(const int input){
  m_input = input;
}

//getters
SavedGamesMenu LoadGameCommand::menu() const{
  return m_menu;
}

int LoadGameCommand::input() const{
  return m_input;
}
