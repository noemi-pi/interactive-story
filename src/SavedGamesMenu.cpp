/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/Menu.hpp"
#include "../include/SavedGamesMenu.hpp"
#include "../include/CommandCodes.hpp"
#include "../include/MenuOption.hpp"
#include<vector>
#include<string>
#include <iostream>
#include <limits>

/*SavedGamesMenu
  concrete class derived from abstract class Menu
  provides a menu for choosing from a list of saved games
  prompt answers from user
  sets command codes depending on the user's input
 */

SavedGamesMenu::SavedGamesMenu(): Menu() {

}

SavedGamesMenu::SavedGamesMenu(std::vector<MenuOption> options): Menu(), m_options(options) {

}

SavedGamesMenu::~SavedGamesMenu(){

}

/*Set the command code corresponding to the input stored in m_input
  parameters: none
  return: void
  */
void SavedGamesMenu::setCommandCodeFromInput(){
  m_command_code = m_options[m_input].commandCode();
}

/*Check wether the input is valid, i.e. if it corresponds to an existing menu option
  parameters: int input
  return: true if valid, false if not
  */
bool SavedGamesMenu::isValidOption(int input) const{
  if (input >= 0 && input < m_options.size()) return true;
  return false;
}

bool SavedGamesMenu::isQuitTrue() const{
  return m_quit;
}

/*quit the menu
  parameters: none
  return: void
  */
void SavedGamesMenu::quit(){
  m_quit = true;
}

/*display the menu, i.e display the description and the input corresponding to each option
  parameters: none
  return: void
  */
void SavedGamesMenu::display() const {
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
void SavedGamesMenu::promptAnswer(){
  int answer;
  std::cin >> answer;
  while(!isValidOption(answer)){
      std::cout << "invalid answer. try again" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin>>answer; //get the player's choice
  }
  m_input = answer;
}

//setters
void SavedGamesMenu::setQuit(bool quit){
  m_quit = quit;
}

void SavedGamesMenu::setCommandCode(CommandCode command_code){
  m_command_code = command_code;
}

void SavedGamesMenu::setOptions(std::vector<MenuOption> options){
  m_options = options;
}

//getters

std::vector<MenuOption> SavedGamesMenu::options() const{
  return m_options;
}

CommandCode SavedGamesMenu::commandCode() const{
  return m_command_code;
}

int SavedGamesMenu::input() const{
  return m_input;
}
