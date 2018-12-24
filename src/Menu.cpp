/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/Menu.hpp"
#include "../include/CommandCodes.hpp"
#include "../include/MenuOption.hpp"
#include <iostream>
#include<vector>
#include<string>
#include<limits>

/*Menu
  abstract class Menu for providing a generic Menu
  prompt answers from user
  sets command codes depending on the user's input
 */

Menu::Menu(): m_command_code(NO_COMMAND), m_quit(false){

}

Menu::~Menu() {

}

bool Menu::isQuitTrue() const{
  return m_quit;
}

void Menu::quit(){
  m_quit = true;
}

/*display the menu, i.e display the description and the input corresponding to each option
  parameters: none
  return: void
  */
void Menu::display() const {
  std::cout << "Choose one of the following options\n" << std::endl;
  for(int i=0; i < m_options.size(); i++){
    std::cout << i << ". " << m_options[i].description() << std::endl;
  }
}

/*get the user's input and prompt them to re-enter it if the answer is not valid
  set m_input to the correct answer
  parameters: none
  return: void
  */
void Menu::promptAnswer(){
  int answer;
  std::cin >> answer;
  while(!isValidOption(answer)){
      std::cout << "invalid answer. try again" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin>>answer;
  }
  m_input = answer;
}

//setters
void Menu::setQuit(bool quit){
  m_quit = quit;
}

void Menu::setCommandCode(CommandCode command_code){
  m_command_code = command_code;
}

void Menu::setOptions(std::vector<MenuOption>  options){
  m_options = options;
}

//getters
std::vector<MenuOption> Menu::options() const{
  return m_options;
}

CommandCode Menu::commandCode() const{
  return m_command_code;
}
