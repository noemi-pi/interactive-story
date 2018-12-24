# $@ : nom de la cible
# $< : première dépendance de la liste de dépendances
# $?: les dépendances les plus récentes de la cible
# $^: toute les dépendances
# $* : correspond au "*" dans le shell = représente n'importe quel nom

CXX = g++
CXXFLAGS = -Wall -ansi

APP_BIN = story

SRC = main.cpp game.cpp player.cpp
SRC_PATH = src
BIN_PATH = build
GRAPH_OBJ = $(BIN_PATH)/node.o  $(BIN_PATH)/graph.o
GAME_OBJ = $(BIN_PATH)/story.o $(BIN_PATH)/game.o $(BIN_PATH)/gamesave.o
FILE_OBJ = $(BIN_PATH)/filemanager.o $(BIN_PATH)/file.o $(BIN_PATH)/loadfiles.o
FORMAT_OBJ = $(BIN_PATH)/format.o
EXPORT_OBJ = $(BIN_PATH)/export.o
IMPORT_OBJ = $(BIN_PATH)/import.o
COMMAND_OBJ = $(BIN_PATH)/command.o $(BIN_PATH)/loadgamecommand.o $(BIN_PATH)/newgamecommand.o $(BIN_PATH)/nocommand.o $(BIN_PATH)/quitcommand.o $(BIN_PATH)/appcommand.o
MENU_OBJ = $(BIN_PATH)/menu.o $(BIN_PATH)/appmenu.o $(BIN_PATH)/savedgamesmenu.o $(BIN_PATH)/menuoption.o
APP_OBJ = $(BIN_PATH)/application.o
OBJECTS = $(BIN_PATH)/main.o $(GRAPH_OBJ) $(GAME_OBJ) $(FILE_OBJ) $(FORMAT_OBJ) $(EXPORT_OBJ) $(IMPORT_OBJ) $(MENU_OBJ) $(COMMAND_OBJ) $(APP_OBJ)
INC_PATH = include
LIB_PATH = lib

default: $(BIN_PATH)/$(APP_BIN)

all: $(OBJECTS)

$(BIN_PATH)/$(APP_BIN): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXFLAGS) -o $(BIN_PATH)/$(APP_BIN)

$(BIN_PATH)/main.o: $(SRC_PATH)/main.cpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/node.o: $(SRC_PATH)/Node.cpp $(INC_PATH)/Node.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/story.o: $(SRC_PATH)/Story.cpp $(INC_PATH)/Story.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/filemanager.o: $(SRC_PATH)/FileManager.cpp $(INC_PATH)/FileManager.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/file.o: $(SRC_PATH)/File.cpp $(INC_PATH)/File.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/graph.o: $(SRC_PATH)/Graph.cpp $(INC_PATH)/Graph.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/game.o: $(SRC_PATH)/Game.cpp $(INC_PATH)/Game.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/format.o: $(SRC_PATH)/Format.cpp $(INC_PATH)/Format.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/gamesave.o: $(SRC_PATH)/GameSave.cpp $(INC_PATH)/GameSave.hpp
		$(CXX) -c $< -o $@

$(BIN_PATH)/export.o: $(SRC_PATH)/Export.cpp $(INC_PATH)/Export.hpp
		$(CXX) -c $< -o $@

$(BIN_PATH)/import.o: $(SRC_PATH)/Import.cpp $(INC_PATH)/Import.hpp
		$(CXX) -c $< -o $@

$(BIN_PATH)/loadfiles.o: $(SRC_PATH)/LoadFiles.cpp $(INC_PATH)/LoadFiles.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/menu.o: $(SRC_PATH)/Menu.cpp $(INC_PATH)/Menu.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/appmenu.o: $(SRC_PATH)/AppMenu.cpp $(INC_PATH)/AppMenu.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/savedgamesmenu.o: $(SRC_PATH)/SavedGamesMenu.cpp $(INC_PATH)/SavedGamesMenu.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/command.o: $(SRC_PATH)/Command.cpp $(INC_PATH)/Command.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/newgamecommand.o: $(SRC_PATH)/NewGameCommand.cpp $(INC_PATH)/NewGameCommand.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/loadgamecommand.o: $(SRC_PATH)/LoadGameCommand.cpp $(INC_PATH)/LoadGameCommand.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/nocommand.o: $(SRC_PATH)/NoCommand.cpp $(INC_PATH)/NoCommand.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/quitcommand.o: $(SRC_PATH)/QuitCommand.cpp $(INC_PATH)/QuitCommand.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/appcommand.o: $(SRC_PATH)/AppCommand.cpp $(INC_PATH)/AppCommand.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/application.o: $(SRC_PATH)/Application.cpp $(INC_PATH)/Application.hpp
	$(CXX) -c $< -o $@

$(BIN_PATH)/menuoption.o: $(SRC_PATH)/MenuOption.cpp $(INC_PATH)/MenuOption.hpp $(INC_PATH)/CommandCodes.hpp
	$(CXX) -c $< -o $@

clean:
	rm -rf $(BIN_PATH)/*.o

mrproper: clean
	rm -rf $(BIN_PATH)/$(APP_BIN)
