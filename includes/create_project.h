#ifndef CREATE_PROJECT_H
#define CREATE_PROJECT_H

#include <filesystem>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <termcolor/termcolor.hpp>
#include <fmt/core.h>
#include "global_build_default.h"
namespace fs = std::filesystem;
std::string getAnswer(std::string question);
bool answer(std::string question);
bool createDirectory( std::string directoryName );
void normalMesage(std::string message);
void errorMesage( std::string message );
void warningMesage( std::string message );
void successMesage( std::string message );
void createProject( std::string name );
#endif // CREATE_PROJECT_H