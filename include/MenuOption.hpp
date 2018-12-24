/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#pragma once
#include <string>
#include "CommandCodes.hpp"

class MenuOption{
private:
  std::string m_description;
  CommandCode m_command_code;
public:
  MenuOption();
  MenuOption(std::string description, CommandCode command_code);
  ~MenuOption();
  //getters
  std::string description() const;
  CommandCode commandCode() const;
  //setters
  void setDescription(std::string description);
  void setCommandCode(CommandCode command_code);
};
