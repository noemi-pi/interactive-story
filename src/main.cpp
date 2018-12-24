/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
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
