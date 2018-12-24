/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/Menu.hpp"
#include "../include/AppMenu.hpp"
#include "../include/CommandCodes.hpp"
#include<vector>
#include<string>
#include <limits>
#include <iostream>

/*AppMenu
  concrete class derived from abstract class Menu
  provides a menu for the Application
  prompt answers from user
  sets command codes depending on the user's input
 */

AppMenu::AppMenu(): m_command_code(NO_COMMAND), m_quit(false) {
  std::vector<MenuOption> options;
  options.push_back(MenuOption("QUIT", QUIT));
  options.push_back(MenuOption("NEW GAME", NEW_GAME));
  options.push_back(MenuOption("LOAD GAME", LOAD_GAME));
  m_options = options;
}

AppMenu::AppMenu(std::vector<MenuOption> options): m_options(options), m_command_code(NO_COMMAND), m_quit(false) {

}

AppMenu::~AppMenu(){

}

/*Set the command code corresponding to the input stored in m_input
  parameters: none
  return: void
  */
void AppMenu::setCommandCodeFromInput(){
  m_command_code = m_options[m_input].commandCode();
}

/*Check wether the input is valid, i.e. if it corresponds to an existing menu option
  parameters: int input
  return: true if valid, false if not
  */
bool AppMenu::isValidOption(int input) const {
  if (input >= 0 && input < m_options.size()) return true;
  return false;
}

bool AppMenu::isQuitTrue() const{
  return m_quit;
}

/*quit the menu
  parameters: none
  return: void
  */
void AppMenu::quit(){
  m_quit = true;
}

/*display the menu, i.e display the description and the input corresponding to each option
  parameters: none
  return: void
  */
void AppMenu::display() const {
  std::cout << "Choose one of the following options\n" << std::endl;
  for(int i= 0; i < m_options.size(); i++){
    std::cout << i << ". " << m_options[i].description() << std::endl;
  }
}

/*get the user's input and prompt them to re-enter it if the answer is not valid
  set m_input to the correct answer
  parameters: none
  return: void
  */
void AppMenu::promptAnswer(){
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

void AppMenu::setQuit(bool quit){
  m_quit = quit;
}

void AppMenu::setCommandCode(CommandCode command_code){
  m_command_code = command_code;
}

void AppMenu::setOptions(std::vector<MenuOption> options){
  m_options = options;
}

//getters

std::vector<MenuOption> AppMenu::options() const{
  return m_options;
}

CommandCode AppMenu::commandCode() const{
  return m_command_code;
}

int AppMenu::input() const{
  return m_input;
}
