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
void helperOptions::errorMesage( std::string message1,std::string message2 ){ std::cout << termcolor::red << " Error -> "<< termcolor::reset <<  message1  << message2  << "\n";}
void helperOptions::errorMesage( std::string message1,std::string message2,std::string message3 ){ std::cout << termcolor::red << " Error -> "<< termcolor::reset <<  message1  << message2  << message3  << "\n";}
void helperOptions::warningMesage( std::string message ){ std::cout << termcolor::yellow << " Warning -> "<< termcolor::reset <<  message  << "\n";}
void helperOptions::warningMesage( std::string message1,std::string message2 ){ std::cout << termcolor::yellow << " Warning -> "<< termcolor::reset <<  message1  << message2 <<"\n";}
void helperOptions::warningMesage( std::string message1,std::string message2,std::string message3 ){ std::cout << termcolor::yellow << " Warning -> "<< termcolor::reset <<  message1  << message2 << message3 <<"\n";}
void helperOptions::successMesage( std::string message ){std::cout << termcolor::green << " Success -> "<< termcolor::reset <<  message  << "\n";}
void helperOptions::successMesage( std::string message1,std::string message2){std::cout << termcolor::green << " Success -> "<< termcolor::reset <<  message1  << message2 << "\n";}
void helperOptions::successMesage( std::string message1,std::string message2,std::string message3){std::cout << termcolor::green << " Success -> "<< termcolor::reset <<  message1  << message2 << message3 << "\n";}

std::string helperOptions::getVersion(){ 
    return " version 1.0";
}
void helperOptions::showVersion(){    
    fmt::print("{}\n", getVersion() );
}

void helperOptions::help(){
    
    std::cout << "\n";
    std::cout << termcolor::bold << " Welcome to "<< termcolor::reset<< termcolor::green << "Css-Utility-Cli " << termcolor::reset << " \n";
    std::vector<std::string> outputs = {        
        getVersion(),        
        "",
        fmt::format("{:4}{:33}{}","","-v, --version","Show version"),
        fmt::format("{:4}{:33}{}","","-h, --help","Show help"),        
        fmt::format("{:4}{:33}{}","","-l, --list","Show list of:"),        
        fmt::format("{:4}{}","","List options"),        
        fmt::format("{:7}{:30}{}","","all","list all options to build"),
        fmt::format("{:7}{:30}{}","","categories","list categories options to build"),
        fmt::format("{:7}{:30}{}","","screens","list screens options to build"),
        fmt::format("{:7}{:30}{}","","states","list states options to build"),
        fmt::format("{:4}{:33}{}","","-c=PROJECT, --create=PROJECT","create css-utility-cli project"),        
        fmt::format("{:4}{:33}{}","","-i, --init ", "initialize css-utility-cli project"),        
        fmt::format("{:4}{:33}{}","","-b, --build","build project"),
        fmt::format("{:33}{}","","\n")
    };    
    fmt::print("{}", fmt::join(outputs, "\n"));        
}