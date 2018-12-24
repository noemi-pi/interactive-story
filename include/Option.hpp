/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
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
