/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#pragma once
#include "Menu.hpp"
#include<vector>
#include<string>

class AppMenu : public Menu {
private:
  std::vector<MenuOption> m_options;
  CommandCode m_command_code;
  bool m_quit;
  int m_input;

public:
  AppMenu();
  AppMenu(std::vector<MenuOption> options);
  ~AppMenu() override;
  
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
