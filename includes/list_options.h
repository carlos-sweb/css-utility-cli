#ifndef LISTOPTIONS_H
#define LISTOPTIONS_H

#include <filesystem>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>  
#include <termcolor/termcolor.hpp>
#include <fmt/core.h>
#include "global_build_default.h"
#include "helperOptions.h"
namespace fs = std::filesystem;
void listOptions( std::string option );

#endif // LISTOPTIONS_H