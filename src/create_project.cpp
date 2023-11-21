
#include "create_project.h"

std::string getAnswer(std::string question){
    std::string name;
    do{std::cout << " " << question;std::cin >> name;    
    }while( !std::cin.fail() && name == "" );    
    return name;
}


bool answer( std::string question ){
    char type;
    do{std::cout << question << " ? [y/n] ";std::cin >> type;
    }while( !std::cin.fail() && type!='y' && type!='n' && type!='Y' && type!='N' );
    return  ( "y" == std::string(1,type) ) || ( "Y" == std::string(1,type) );
}


bool createDirectory( std::string directoryName ){
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
void createFileConfig(std::string filename , std::string content){
    std::ofstream archivo(filename);
    if (archivo.is_open()){
        archivo << content;                
        archivo.close();
    }
}
// -----------------------------------------------------------------------------------------------
void normalMesage(std::string message){ fmt::print("{}\n", message ); }
// -----------------------------------------------------------------------------------------------
void errorMesage( std::string message ){ std::cout << termcolor::red << " Error -> "<< termcolor::reset <<  message  << "\n";}
// -----------------------------------------------------------------------------------------------
void warningMesage( std::string message ){ std::cout << termcolor::yellow << " Warning -> "<< termcolor::reset <<  message  << "\n";}
// -----------------------------------------------------------------------------------------------
void successMesage( std::string message ){std::cout << termcolor::green << " Success -> "<< termcolor::reset <<  message  << "\n";}
// -----------------------------------------------------------------------------------------------
void createProject( std::string name ){
    
    global_build_default Build_default; 
    std::string dirPath = fs::current_path().generic_string();    
    // --------------------------------------------------------------------------------------------
    // VERIFICAMOS EL NOMBRE DE PROJECTO QUE NO SEA NADA
    if( name == "" ){
        warningMesage("Must provide a name");
        name =  getAnswer("name -> ");
    }
    // --------------------------------------------------------------------------------------------
    if( name == "" ){ errorMesage("the project name cannot be empty");}else{
        std::string dirPathName = dirPath + "/" +name;
        std::string dirPathNameConfig = dirPathName + "/config";
        std::string dirPathNameDist = dirPathName + "/dist";
        if( fs::exists( dirPathName ) ){
            warningMesage("folder already exists.");                                
            if( answer(" You want to initialize a project") ){ /*initialize();*/}else{
                normalMesage( "the next step is:" );
                normalMesage( "   cd " + name + " && cssutilitycli --init");
            }
        }else{
            if( 
            createDirectory( dirPathName ) && createDirectory( dirPathNameConfig  ) 
            &&  createDirectory( dirPathNameDist )  ){                
            // -------------------------------------------------------------   
            successMesage("The directory was created");
            // -------------------------------------------------------------            
            createFileConfig(dirPathName + "/build.json", Build_default.json() );            
            // -------------------------------------------------------------
            for(const auto &category : Build_default.getCategories() ){
                std::string fileCategoryJson = dirPathNameConfig+"/"+category+".json";
                if( !fs::exists(fileCategoryJson) ){
                    createFileConfig( fileCategoryJson ,  Build_default.getConfigCategory(category) );
                    std::cout << termcolor::green << "    Created : " << termcolor::reset <<  category +" -> "+category+".json" << "\n";
                }
            }                                                     
            // -------------------------------------------------------------
            if( answer(" You want to initialize a project") ){ /*initialize();*/ }else{
                normalMesage( "the next step is:" );
                normalMesage( "   cd " + name + " && cssutilitycli --init");
            }
            }
        }
    }
}