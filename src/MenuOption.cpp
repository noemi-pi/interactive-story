/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include <string>
#include "../include/MenuOption.hpp"
#include "../include/CommandCodes.hpp"

/*MenuOption class
  Option used in a Menu : contains a description m_description (string) and a CommandCode m_command_code, to identify an action corresponding the each option
  */
MenuOption::MenuOption(): m_description("NO COMMAND"), m_command_code(NO_COMMAND){}

MenuOption::MenuOption(std::string description, CommandCode command_code): m_description(description), m_command_code(command_code){

}
MenuOption::~MenuOption(){}
//getters
std::string MenuOption::description() const{
  return m_description;
}
CommandCode MenuOption::commandCode() const{
  return m_command_code;
}
//setters
void MenuOption::setDescription(std::string description){
  m_description = description;
}
void MenuOption::setCommandCode(CommandCode command_code){
  m_command_code = command_code;
}
