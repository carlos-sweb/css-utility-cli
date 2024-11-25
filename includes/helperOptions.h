#ifndef HELPEROPTIONS_H
#define HELPEROPTIONS_H
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <vector>
#include <string>
#include <termcolor/termcolor.hpp>
#include <fmt/core.h>
#include <fmt/ranges.h>

namespace fs = std::filesystem;
typedef struct helperOptions{    
    void help();
    std::string getVersion();
    void showVersion();
    void normalMessage(std::string message);
    void errorMessage(std::string message);
    void errorMessage(std::string message1,std::string message2);
    void errorMessage(std::string message1,std::string message2,std::string message3);
    void successMessage(std::string message);
    void successMessage(std::string message1,std::string message2);
    void successMessage(std::string message1,std::string message2,std::string message3);
    void warningMessage(std::string message);
    void warningMessage(std::string message1,std::string message2);
    void warningMessage(std::string message1,std::string message2,std::string message3);
    std::string getAnswer(std::string question);
    bool answer( std::string question);
    bool createDirectory( std::string directoryName );
    void createFileConfig(std::string filename , std::string content);
}helperOptions;

#endif // HELPEROPTIONS_H
