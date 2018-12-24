/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include "../include/Game.hpp"
#include "../include/Story.hpp"
#include "../include/GameSave.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <limits>

/*Game class
  mathods to play a Game and update its information as the game advances
  To improve later, by representing choices as a Menu and using Commands*/

Game::Game(){
  Story story;
  m_story = story;
  m_saved = true;
  m_quit = -1;
}

Game::Game(Story story, std::vector<GameSave> saved_games, bool saved): m_story(story), m_saved_games(saved_games), m_saved(saved), m_quit(-1){

}

Game::Game(Story story, std::vector<GameSave> saved_games): m_story(story), m_saved_games(saved_games), m_saved(true), m_quit(-1){

}

/*Play the Game : progress from one stage of the story to another
display the narration, the possible choices and let the player choose one choice,
update the story accordingly then repeat until the end of the story has been reached OR until the player choose to quit
let the player quit by typing a specific code
When the game ends, give the player the choice to save the game or not
parameters : none
return: void
*/
void Game::play(){
  bool quit = false;
  std::cout << "to quit, type " << m_quit << std::endl;
  while(!m_story.end() && !quit){
    displayNarration();
    displayChoices();
    int answer = promptAnswer();
    if(quitRequest(answer)) quit = true;
    else m_story.updateCurrent(answer);
  }
  if (m_story.end()) displayNarration();
  std::cout << "save game ? (y/n)" << std::endl;
  bool save = saveRequest(promptSaveRequest());
  setSaved(save);
}

/* get the player's decision to save the game and check if it is valid
if not, prompt the player to enter it again
parameters : none
return: char
*/
char Game::promptSaveRequest(){
  char input;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin>> input;
  while(input != 'y' && input != 'n'){
    std::cout << "invalid answer. try again" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin>> input;
  }
  return input;
}

/* get the player's decision to save the game and check if it is valid
if not, prompt the player to enter it again
parameters : none
return: char
*/
bool Game::saveRequest(char input){
  char save = 'y';
  if(input == save) return true;
  else return false;
}

/*get the user's input and prompt them to re-enter it if the answer is not valid
  return the correct answer
  parameters: none
  return: int
  */
int Game::promptAnswer(){
  int answer;
  std::cin >> answer;
  while(!m_story.isCurrentSuccessor(answer) && !quitRequest(answer)){
      std::cout << "invalid answer. try again" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin>>answer;
  }
  return answer;
}

/*check if the input corresponds to the code for quitting
  return: a bool, true if it does, false if not*/
bool Game::quitRequest(int input){
  if (input == m_quit) return true;
  return false;
}

/*display the narration of the current story part
parameters: none
return: void*/
void Game::displayNarration() const{
  std::cout << m_story.getCurrentNarration() <<std::endl;
}

/*display the possible choices for the current story part*
parameters: none
return: void*/
void Game::displayChoices() const{
  std::vector<std::string> choices = m_story.getCurrentChoices();
  for(int i = 0; i < choices.size(); i++){
    std::cout<< i << ". " << choices[i] << std::endl;
  }
}

/*save the current advancement of the story: current node, time and name of the game
parameters: none
return: void*/
void Game::save(){
  time_t rawtime;
  time(&rawtime); //get the current time
  std::string time_string(ctime(&rawtime)); //set it to a string
  GameSave saved_game = GameSave(m_story.getCurrentNodeIndex(), time_string, "Game_"+ std::to_string(m_saved_games.size()));//create a GameSave using data about the current game's progress
  m_saved_games.push_back(saved_game); //add the GameSave to the game's saved games
}

//getters
Story Game::story() const{
  return m_story;
}

std::vector<GameSave> Game::savedGames() const{
  return m_saved_games;
}

bool Game::saved() const {
  return m_saved;
}
//setters
void Game::setStory(Story story){
  m_story = story;
}
void Game::setSavedGames(std::vector<GameSave> saved_games){
  m_saved_games = saved_games;
}

void Game::setSaved(bool saved){
  m_saved = saved;
}
