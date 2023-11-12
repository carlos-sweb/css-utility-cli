#include "helperOptions.h"

void helpOptions(){
    std::cout << "\n";
    std::cout << " Welcome to "<< termcolor::green << "Css-Utility-Cli " << termcolor::reset << " \n";
    std::vector<std::string> outputs = {
        getVersion(),
        "    -v, --version                    Show version",
        "    -h, --help                       Show help",
        "    -c=PROJECT, --create=PROJECT     create css-utility-cli project",
        "    -i, --init                       initialize css-utility-cli project",
        "    -b, --build                      build project\n"
    };    
    fmt::print("{}", fmt::join(outputs, "\n"));    
}