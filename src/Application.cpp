/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include <iostream>
#include <string>
#include <vector>
#include "../include/Story.hpp"
#include "../include/Node.hpp"
#include "../include/FileManager.hpp"
#include "../include/File.hpp"
#include "../include/Game.hpp"
#include "../include/Graph.hpp"
#include "../include/Format.hpp"
#include "../include/GameSave.hpp"
#include "../include/LoadFiles.hpp"
#include "../include/Export.hpp"
#include "../include/Import.hpp"
#include "../include/CommandCodes.hpp"
#include "../include/Menu.hpp"
#include "../include/AppMenu.hpp"
#include "../include/AppCommand.hpp"
#include "../include/Command.hpp"
#include "../include/LoadGameCommand.hpp"
#include "../include/NewGameCommand.hpp"
#include "../include/NoCommand.hpp"
#include "../include/QuitCommand.hpp"
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <algorithm>

/*Application
  Manage the application:
  load the information needed by the Application
  Run the application: present a menu to the user with several options (new game, load game and quit) and execute the selected option
  Export saved games to a file
 */

Application::Application(){

}
Application::~Application(){
  delete m_command;
}

/*load the information from the files needed by the Application, and use use it to set the application's m_graph, m_saved_games and m_game fields
  parameters:
  graph_path: std::string representing the path to the file containing the information for m_graph construction
  saved_games_path : std::string representing the path to the file containing the information for importing saved games
  return: void
  */
void Application::load(std::string graph_path, std::string saved_games_path){
  loadGraph(graph_path);
  loadSavedGames(saved_games_path);
  m_game.setStory(Story(0, m_graph));
  m_game.setSavedGames(m_saved_games);
}

/*load the graph information from a file, and use it to set the application's m_graph field
  parameters:
  graph_path: std::string representing the path to the file containing the information for m_graph construction
  return: void
  */
void Application::loadGraph(std::string graph_path){
  FileManager file_manager;
  File graph_file = LoadFiles::loadFile(graph_path);
  std::vector<File> graph_nodes_files = LoadFiles::loadGraphNodesFiles(graph_file);
  std::vector<Node> graph_nodes = Import::nodesFromFiles(graph_nodes_files);
  m_graph = Graph(graph_nodes);
}

/*load the game information from a file, and use it to set the application's m_saved_games field
  parameters:
  saved_games_path: std::string representing the path to the file containing the information for m_saved_games_path construction
  return: void
  */
void Application::loadSavedGames(std::string saved_games_path){
    File saved_games_file = LoadFiles::loadFile(saved_games_path);
    m_saved_games = Import::savedGamesFromFile(saved_games_file);
}

/*let the player choose possible options from a menu and execute the selected options
  export saved games to a file
  parameters: none
  return: void
*/

void Application::run(){
  while(!m_menu.isQuitTrue()){
    m_menu.display();
    m_menu.promptAnswer(); //get the player's answer
    m_menu.setCommandCodeFromInput(); //set the menu's command code from the answer
    setCommandFromCommandCode(m_menu.commandCode()); //use the menu's command code to set the command which will be executed
    try{
      executeCommand(); //execute the command, will execute different actions depending on which command was previously set
    }
    catch (std::exception e){
      std::cout<< "application error" << e.what() <<std::endl;
      exit(EXIT_FAILURE);
    }

  }
  exportSavedGames("files/SavedGames.txt");
}

/*set the Command m_command to be executed by the application from a command code
  parameters: a code from the CommandCode enum
  return: void
  */
void Application::setCommandFromCommandCode(CommandCode command_code){
    AppCommand * quit =  new QuitCommand();
    AppCommand * new_game = new NewGameCommand();
    AppCommand * load_game = new LoadGameCommand();
    AppCommand * no_command = new NoCommand();

    switch (command_code) {
      case QUIT: m_command = quit;
      m_menu.quit();
      break;
      case NEW_GAME: m_command = new_game;
      break;
      case LOAD_GAME: m_command = load_game;
      break;
      case NO_COMMAND: m_command = no_command;
      break;
      default : throw(std::runtime_error("command code not recognized"));
    }
  }


/*execute m_command
  parameters: none
  return: void
*/
void  Application::executeCommand(){
  m_command->execute(&m_game);
}

/*export saved games to a File and write them in a file at the designated path
  parameters: path, a std::string representing the path to the file
  return: void
*/
void Application::exportSavedGames(std::string path){
  FileManager file_manager;
  File saved_games_file = Export::gameSavesToFile(path, m_game.savedGames());
  try{
      file_manager.write(saved_games_file);
  }
  catch(const std::exception &e){
    std::cerr << "error when trying to write file: " << e.what() <<std::endl;
  }
}

//getters
std::vector<GameSave> Application::savedGames() const{
  return m_saved_games;
}

Graph Application::graph() const{
  return m_graph;
}

//setters
void Application::setGame(Game game){
  m_game = game;
}
