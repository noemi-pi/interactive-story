/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#pragma once
#include<vector>
#include<string>
#include"CommandCodes.hpp"
#include "MenuOption.hpp"

class Menu{
private:
  std::vector<MenuOption> m_options;
  CommandCode m_command_code;
  bool m_quit;
  int m_input;

public:
  Menu();
  virtual ~Menu() = 0;
  bool isQuitTrue() const;
  void quit();
  virtual bool isValidOption(int input) const = 0;
  void display() const;
  void promptAnswer();
  //setters
  virtual void setCommandCodeFromInput() = 0;
  void setCommandCode(CommandCode command_code);
  void setQuit(bool quit);
  void setOptions(std::vector<MenuOption> options);

  //getters
  std::vector<MenuOption> options() const;
  CommandCode commandCode() const;
  int input() const;
};
