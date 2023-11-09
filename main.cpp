#include <filesystem>
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>

#include <chrono>
#include <ctime>
#include <thread>
#include <algorithm>

#include <functional>

#include "termcolor/termcolor.hpp"
#include "argh.h"
#include "yaml-cpp/yaml.h"

// -----------------------------------------------------------------------------------------------
// normalize_min_css
#include "config/normalize.h"

#include "config/build.h"
#include "config/states.h"
#include "config/screens.h"
#include "config/categories.h"
// -----------------------------------------------------------------------------------------------
#include "config/property/alignment.h"
#include "config/property/backgrounds.h"
#include "config/property/bgcolor.h"
#include "config/property/border.h"
#include "config/property/effects.h"
#include "config/property/flexbox.h"
#include "config/property/grid.h"
#include "config/property/interactivity.h"
#include "config/property/layout.h"
#include "config/property/sizing.h"
#include "config/property/spacing.h"
#include "config/property/tables.h"
#include "config/property/typography.h"
#include "config/property/transform.h"
// -----------------------------------------------------------------------------------------------
#define VERSION "1.0"
#define QUESTION_INITIALIZE " You want to initialize a project"
// -----------------------------------------------------------------------------------------------
using namespace std;
// -----------------------------------------------------------------------------------------------
namespace fs = std::filesystem;
// -----------------------------------------------------------------------------------------------
void normalMesage(string message){ cout << " " << message << "\n"; }
// -----------------------------------------------------------------------------------------------
void errorMesage( string message ){ cout << termcolor::red << " Error -> "<< termcolor::reset <<  message  << "\n";}
// -----------------------------------------------------------------------------------------------
void warningMesage( string message ){ cout << termcolor::yellow << " Warning -> "<< termcolor::reset <<  message  << "\n";}
// -----------------------------------------------------------------------------------------------
void successMesage( string message ){cout << termcolor::green << " Success -> "<< termcolor::reset <<  message  << "\n";}
// -----------------------------------------------------------------------------------------------
void showVersion(){ cout << " version " << VERSION << "\n"; }
// -----------------------------------------------------------------------------------------------

string getDataYaml( unsigned char* data){
        std::string str;
        str.append(reinterpret_cast<const char*>(data));
        return str;
}

std::map< std::string , YAML::Node > PropertiesCss = { 
    { "alignment" , YAML::Load(getDataYaml(alignment_yaml)) },
    { "backgrounds" , YAML::Load(getDataYaml(backgrounds_yaml)) },
    { "bgcolor" , YAML::Load(getDataYaml(bgcolor_yaml))}, 
    { "border" , YAML::Load(getDataYaml(border_yaml))}, 
    { "effects" , YAML::Load(getDataYaml(effects_yaml))}, 
    { "flexbox" , YAML::Load(getDataYaml(flexbox_yaml))}, 
    { "grid" , YAML::Load(getDataYaml(grid_yaml))}, 
    { "interactivity" , YAML::Load(getDataYaml(interactivity_yaml))},
    { "layout" , YAML::Load(getDataYaml(layout_yaml))}, 
    { "sizing" , YAML::Load(getDataYaml(sizing_yaml))}, 
    { "spacing" , YAML::Load(getDataYaml(spacing_yaml))}, 
    { "tables" , YAML::Load(getDataYaml(tables_yaml))}, 
    { "typography" , YAML::Load(getDataYaml(typography_yaml))},
    { "transform" , YAML::Load(getDataYaml(transform_yaml))}
};

void helpOptions(){
    cout << "\n";
    cout << " Welcome to "<< termcolor::green << "Css-Utility-Cli " << termcolor::reset << " \n";
    showVersion();
    cout << "\n";
    cout << "    -v, --version                    Show version\n";
    cout << "    -h, --help                       Show help\n";
    cout << "    -c=PROJECT, --create=PROJECT     create css-utility-cli project\n";
    cout << "    -i, --init                       initialize css-utility-cli project\n";
    cout << "    -b, --build                      build project\n";
    cout << "\n";
}
// -----------------------------------------------------------------------------------------------

string getAnswer(string question){
    string name;
    do{
     cout << " " << question;
    cin >> name;    
    }while( !cin.fail() && name == "" );    
    return name;
}

bool answer( string question ){
    char type;
    do{cout << question << " ? [y/n] ";cin >> type;
    }while( !cin.fail() && type!='y' && type!='n' && type!='Y' && type!='N' );
    return  ( "y" == string(1,type) ) || ( "Y" == string(1,type) );
}
// -----------------------------------------------------------------------------------------------
void initialize(){
    cout << " Initialize........................\n";
}
// -----------------------------------------------------------------------------------------------
bool createDirectory( string directoryName ){
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
void createProject( string name ){
    string dirPath = fs::current_path().generic_string();
    vector<string> categories_raw = YAML::Load( getDataYaml( categories_yaml ) ).as<vector<string>>();
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
            if( answer(QUESTION_INITIALIZE) ){ initialize();}else{
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
            createFileConfig(dirPathName + "/build.yaml", getDataYaml(build_yaml) );                                                

            for(string category : categories_raw){
                std::string fileCategoryYaml = dirPathNameConfig+"/"+category+".yaml";
                if( !fs::exists(fileCategoryYaml) ){
                    createFileConfig( fileCategoryYaml , "Pipi\n" );
                    cout << termcolor::green << "    Created : " << termcolor::reset <<  category +" -> "+category+".yaml" << "\n";
                }
            }                                                     
            // -------------------------------------------------------------
            if( answer(QUESTION_INITIALIZE) ){ initialize(); }else{
                normalMesage( "the next step is:" );
                normalMesage( "   cd " + name + " && cssutilitycli --init");
            }
            }
        }
    }
}
// -----------------------------------------------------------------------------------------------------

vector<string> cleanCategories( vector<string> categories , vector<string> raw , std::function<void(string,bool)> done ){    
    
    vector<string> str;
    // ------------------------------------------------------------------------------
    for( string category : raw ){
        if(  !count( categories.begin() , categories.end() , category )  ){            
            done( category , false );
        }else{
            str.push_back( category );
            done( category , true );
        }
    }
    
    // ------------------------------------------------------------------------------    
    return str;    
}

void buildProject( string dirbuild ){        
    string dirPath = fs::current_path().generic_string() + "/" + dirbuild;
    if( !fs::exists(dirPath) ){        
        errorMesage( "The folder does not exist : " + dirPath );
        exit(1);
    }
    string buildyaml = dirPath + "/build.yaml";
    if(!fs::exists(buildyaml)){
        errorMesage( "The config file does not exist : " + buildyaml );
        exit(1);
    }

    auto start = std::chrono::system_clock::now();
    normalMesage("Starting...");

    YAML::Node node = YAML::LoadFile( buildyaml );

    auto states = node["states"].as<std::vector<std::string>>();
    auto screens = node["screens"].as<map<std::string,std::map<string,string>>>();
    // CATEGORIES SECTION
    vector<string> categories_raw = YAML::Load( getDataYaml( categories_yaml ) ).as<vector<string>>();
    // VERIFICAMOS SI LA CATEGORIA EXISTE EN LISTADO ORIGINAL Y PERMITIDO
    // SI ES ASI CREAMOS EL DIRECTOIO SI NO ESTA ACEPTADA SE ELIMINA EL DIRECTORIO
    vector<string> categories = cleanCategories( node["categories"].as<vector<string>>() , categories_raw , [dirPath](string name , bool approved ){
        /*
        string d_base = dirPath + "/dist/" + name;        
        if( fs::exists(d_base) && !approved ){ fs::remove_all(d_base); };
        if( !fs::exists(d_base) && approved  ){ createDirectory( d_base );};
        */
    });
    


    // --------------------------------------------------------------------------------------
    if( categories.size() == 0 ){warningMesage("No categories to build");}
    // --------------------------------------------------------------------------------------
    string d_master =  dirPath + "/dist/master.css";
    
    if( categories.size() > 0 ){        
                        
        std::ofstream fileMaster( d_master );
        fileMaster << getDataYaml(normalize_min_css);
        
        for(string category : categories ){            
            auto properties =   PropertiesCss.at( category ).as<map<std::string,std::map<string,string>>>();
            for( auto const&[ cssproperty , option ] : properties ){                                
                for( auto const&[nameClass, valueClass ] : option ){
                    fileMaster << "." + nameClass + "{";
                    fileMaster  << cssproperty +":"+valueClass +"";
                    fileMaster  << "}";
                    for( auto const &state : states ){
                        fileMaster << "."+ state + "\\:" + nameClass + ":"+ state +"{";
                        fileMaster  << cssproperty +":"+valueClass +"";
                        fileMaster  << "}";
                    }
                }
            }                        
        }


        for( auto const&[ screen_name , screen_property  ] : screens ){
            fileMaster << "@media only screen and (max-width:"+screen_property.at("max")+") and ( min-width:"+screen_property.at("min")+"){\n";
            // SECTION---
        for(string category : categories ){            
            auto properties =   PropertiesCss.at( category ).as<map<std::string,std::map<string,string>>>();
            for( auto const&[ cssproperty , option ] : properties ){                                
                for( auto const&[nameClass, valueClass ] : option ){
                    fileMaster  << "." + screen_name +"-" + nameClass + "{";
                    fileMaster  << cssproperty +":"+valueClass +"";
                    fileMaster  << "}";
                    for( auto const &state : states ){
                        fileMaster  << "."+ state + "\\:" + screen_name +"-" + nameClass + ":"+state+"{";
                        fileMaster  << cssproperty +":"+valueClass +"";
                        fileMaster  << "}";
                    }
                }
            }                        
        }    
            // SECTION---
            // END @media only screen and .....
            fileMaster << "}";
        }
        fileMaster.close();
    }
    // ================================================================================================    
    // ================================================================================================
    
    successMesage("Finished build");    
    normalMesage("output  -> " + d_master );
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    normalMesage("Elapsed time: " + to_string( elapsed_seconds.count() ) + "s" );
}
// -----------------------------------------------------------------------------------------------


int main(int argc, char* argv[]){    
    // -------------------------------------------------------------------------------------
    argh::parser cmdl(argv);
    // -------------------------------------------------------------------------------------
    if(cmdl[{"-v","--version"}]){showVersion();}
    // -------------------------------------------------------------------------------------
    if(cmdl[{"-h","--help"}]){helpOptions();}
    // -------------------------------------------------------------------------------------
    // Aqui sabemos que esta declaro con un = , auque de todas 
    // formas proria venir vacio
    if( cmdl({"-c","--create"})){createProject( cmdl({ "-c", "--create" }).str());}
    // Verificamos presencia del atributo pero sabemos de ante mano que esta vacio
    if(cmdl[{"-c","--create"}]){createProject( "" );}
    // -------------------------------------------------------------------------------------
    // Aqui sabemos que la palabra  buil viene solo --build
    if(cmdl[{"-b","--build"}]){buildProject("");}
    // Aqui sabemos que viene --build="somethink" de todas manera podria venir bacia 
    if(cmdl({"-b","--build"})){buildProject(cmdl({ "-b", "--build" }).str());}
    // -------------------------------------------------------------------------------------
    return EXIT_SUCCESS;
    // -------------------------------------------------------------------------------------
}
