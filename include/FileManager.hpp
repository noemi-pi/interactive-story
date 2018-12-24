/**
    Interactive Story project
	by No�mie Pierre-Jean  
	IMAC school of multimedia engineering - Universit� Paris Est Marne La Vall�e
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
