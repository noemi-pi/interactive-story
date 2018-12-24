/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#include <iostream>
#include <string>
#include <vector>
#include "../include/LoadFiles.hpp"
#include "../include/FileManager.hpp"
#include "../include/File.hpp"
#include <stdexcept>
#include <fstream>

/*LoadFiles class :
provide static methods to load files from a path, or from by using information contained in other files*/

/*
Load a vector of Files (each containing information representing a Node) from a single File (listing the paths of each node file)
parameters: File graph_file, the source File
return: std::vector<File>
*/
std::vector<File> LoadFiles::loadGraphNodesFiles(File graph_file){
  std::vector<File> node_files;
  for(int i = 0; i < graph_file.getData().size(); i++){
    File node_file = loadFile(graph_file.getData()[i]); //each element in graph_file contains the path to a node file. node_file is loaded using this path
    node_files.push_back(node_file);
  }
  return node_files;
}

/*
Load a File from a string
parameters: std::string path, the path used to load the file
return: File
*/
File LoadFiles::loadFile(std::string path){
  File file;
  try{
    file = FileManager().load(path);
  }
  catch(const std::exception &e){
    std::cerr << "error : " << e.what() <<std::endl;
    exit(EXIT_FAILURE);
  }
  return file;
}
