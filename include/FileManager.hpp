/**
    Interactive Story project
	by Noémie Pierre-Jean  
	IMAC school of multimedia engineering - Université Paris Est Marne La Vallée
*/
#pragma once
#include "File.hpp"
#include <fstream>
#include <string>
class FileManager{

public:
  FileManager();
  ~FileManager();
  File load(std::string path);
  void write(File file);
  void removeFile(File file);

};
