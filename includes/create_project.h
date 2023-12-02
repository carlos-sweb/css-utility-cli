#ifndef CREATE_PROJECT_H
#define CREATE_PROJECT_H


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <stdint.h>
#include <termcolor/termcolor.hpp>
#include <fmt/core.h>
#include "global_build_default.h"
#include "helperOptions.h"
#include <filesystem>
namespace fs = std::filesystem;
void createProject( std::string name );
#endif // CREATE_PROJECT_H