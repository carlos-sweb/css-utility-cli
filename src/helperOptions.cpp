#include "helperOptions.h"
// -----------------------------------------------------------------------------------------------
bool helperOptions::createDirectory( std::string directoryName ){    
    try{
        if( fs::exists( directoryName ) ){
            return true;
        }else{
            if( fs::create_directory( directoryName ) ){
                return true;
            }else{
                return false;
            }
        }
    }catch(const std::exception& e){
        errorMesage( e.what() );        
        return false;
    }
    return false;
}
// -----------------------------------------------------------------------------------------------
void helperOptions::createFileConfig(std::string filename , std::string content){
    std::ofstream archivo(filename);
    if (archivo.is_open()){
        archivo << content;                
        archivo.close();
    }
}

std::string helperOptions::getAnswer(std::string question){
    std::string name;
    do{std::cout << " " << question;std::cin >> name;    
    }while( !std::cin.fail() && name == "" );    
    return name;
}

bool helperOptions::answer( std::string question ){
    char type;
    do{std::cout << question << " ? [y/n] ";std::cin >> type;
    }while( !std::cin.fail() && type!='y' && type!='n' && type!='Y' && type!='N' );
    return  ( "y" == std::string(1,type) ) || ( "Y" == std::string(1,type) );
}

void helperOptions::normalMesage(std::string message){ fmt::print("{}\n", message ); }

void helperOptions::errorMesage( std::string message ){ std::cout << termcolor::red << " Error -> "<< termcolor::reset <<  message  << "\n";}

void helperOptions::warningMesage( std::string message ){ std::cout << termcolor::yellow << " Warning -> "<< termcolor::reset <<  message  << "\n";}

void helperOptions::successMesage( std::string message ){std::cout << termcolor::green << " Success -> "<< termcolor::reset <<  message  << "\n";}


std::string helperOptions::getVersion(){ 
    return " version 1.0";
}
void helperOptions::showVersion(){    
    fmt::print("{}\n", getVersion() );
}

void helperOptions::help(){
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