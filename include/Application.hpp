/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#pragma once
#include <string>
#include <vector>
#include "Game.hpp"
#include "Graph.hpp"
#include "GameSave.hpp"
#include "Menu.hpp"
#include "AppMenu.hpp"
#include "AppCommand.hpp"
#include "Command.hpp"
#include <stdexcept>

class Application{
private:
  std::vector<GameSave> m_saved_games;
  Graph m_graph;
  Game m_game;
  bool m_quit;
  AppMenu m_menu;
  AppCommand * m_command;

  void loadGraph(std::string graph_path);
  void loadSavedGames(std::string saved_games_path);
  void setCommandFromCommandCode(CommandCode command_code);
  void executeCommand();

public:
  Application();
  ~Application();
  void load(std::string graph_path, std::string saved_games_path);
  void run();
  void exportSavedGames(std::string path);

  //getters
  std::vector<GameSave> savedGames() const;
  Graph graph() const;

  //setters
  void setGame(Game game);
};
