/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#pragma once
#include "Menu.hpp"
#include "CommandCodes.hpp"
#include "MenuOption.hpp"
#include<vector>
#include<string>

class SavedGamesMenu : public Menu {
private:
  std::vector<MenuOption> m_options;
  CommandCode m_command_code;
  bool m_quit;
  int m_input;

public:
  SavedGamesMenu();
  SavedGamesMenu(std::vector<MenuOption> options);
  ~SavedGamesMenu() override;
  bool isQuitTrue() const;
  void quit();
  bool isValidOption(int input) const override;
  void display() const;
  void promptAnswer();
  //setters
  void setCommandCodeFromInput() override;
  void setCommandCode(CommandCode command_code);
  void setQuit(bool quit);
  void setOptions(std::vector<MenuOption> options);

  //getters
  std::vector<MenuOption> options() const;
  CommandCode commandCode() const;
  int input() const;
};
