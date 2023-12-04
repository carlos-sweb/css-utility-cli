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
    void normalMesage(std::string message);
    void errorMesage(std::string message);
    void errorMesage(std::string message1,std::string message2);
    void errorMesage(std::string message1,std::string message2,std::string message3);
    void successMesage(std::string message);
    void successMesage(std::string message1,std::string message2);
    void successMesage(std::string message1,std::string message2,std::string message3);
    void warningMesage(std::string message);
    void warningMesage(std::string message1,std::string message2);
    void warningMesage(std::string message1,std::string message2,std::string message3);
    std::string getAnswer(std::string question);
    bool answer( std::string question);
    bool createDirectory( std::string directoryName );
    void createFileConfig(std::string filename , std::string content);
}helperOptions;

#endif // HELPEROPTIONS_H
