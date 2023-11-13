#include "global_build_default.h"
#include "create_project.h"


std::string getAnswer(std::string question){
    std::string name;
    do{
     std::cout << " " << question;
    std::cin >> name;    
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
    std::vector<std::string> categories_raw = Build_default.categories;
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
            //createFileConfig(dirPathName + "/build.yml", getDataYaml(build_yml) );
            createFileConfig(dirPathName + "/build.yml", Build_default.yml() );            
            // -------------------------------------------------------------
            auto screens = Build_default.screens;
            std::vector<std::string> screens_key;
            for( const auto&[key,value] : screens){                
                screens_key.push_back(key);
            }
            
            for(const auto &category : categories_raw){

                YAML::Emitter out;
                out << YAML::BeginMap;
                
                /*
                auto properties =   PropertiesCss.at( category ).as<std::map<std::string,std::map<std::string,std::string>>>();
                for( auto const&[ cssproperty , option ] : properties ){                                        
                    out << YAML::Key << cssproperty ;
                    out << YAML::Value;                    
                    out << YAML::BeginMap;
                    out << YAML::Key << "screens" << YAML::Value << YAML::BeginSeq;
                    for( auto key : screens_key){
                        out << key;    
                    }
                    out << YAML::EndSeq ;
                    out << YAML::Key << "include" << YAML::Value;
                    out << YAML::BeginSeq;
                     for( auto const&[nameClass, valueClass ] : option ){
                        out << nameClass;
                     }                      
                    out << YAML::EndSeq;
                    out << YAML::EndMap;                    
                }*/

                out << YAML::EndMap;
                
                    
                std::string fileCategoryYaml = dirPathNameConfig+"/"+category+".yml";
                if( !fs::exists(fileCategoryYaml) ){
                    createFileConfig( fileCategoryYaml , out.c_str() );
                    std::cout << termcolor::green << "    Created : " << termcolor::reset <<  category +" -> "+category+".yaml" << "\n";
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