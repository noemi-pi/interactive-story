/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
*/
#include <iostream>
#include <string>
#include "../include/Application.hpp"
#include <stdexcept>

int main(){
  Application app;
  app.load("files/StoryGraph01.txt", "files/SavedGames.txt");
  app.run();

  return 0;
}
