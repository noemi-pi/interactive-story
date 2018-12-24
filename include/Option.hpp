/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#pragma once
#include <string>

class Option{
private:
  std::string m_description;
  CommandCode m_command_code;
public:
  Option();
  ~Option();
}
