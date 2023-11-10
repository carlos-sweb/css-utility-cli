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
#include "config/normalize.min.h"
#include "config/build.h"
#include "config/states.h"
#include "config/screens.h"
#include "config/categories.h"
// -----------------------------------------------------------------------------------------------
#include "config/property/h/alignment.h"
#include "config/property/h/backgrounds.h"
#include "config/property/h/bgcolor.h"
#include "config/property/h/border.h"
#include "config/property/h/effects.h"
#include "config/property/h/flexbox.h"
#include "config/property/h/grid.h"
#include "config/property/h/interactivity.h"
#include "config/property/h/layout.h"
#include "config/property/h/sizing.h"
#include "config/property/h/spacing.h"
#include "config/property/h/tables.h"
#include "config/property/h/typography.h"
#include "config/property/h/transform.h"
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
    { "alignment" , YAML::Load(getDataYaml(alignment_yml)) },
    { "backgrounds" , YAML::Load(getDataYaml(backgrounds_yml)) },
    { "bgcolor" , YAML::Load(getDataYaml(bgcolor_yml))}, 
    { "border" , YAML::Load(getDataYaml(border_yml))}, 
    { "effects" , YAML::Load(getDataYaml(effects_yml))}, 
    { "flexbox" , YAML::Load(getDataYaml(flexbox_yml))}, 
    { "grid" , YAML::Load(getDataYaml(grid_yml))}, 
    { "interactivity" , YAML::Load(getDataYaml(interactivity_yml))},
    { "layout" , YAML::Load(getDataYaml(layout_yml))}, 
    { "sizing" , YAML::Load(getDataYaml(sizing_yml))}, 
    { "spacing" , YAML::Load(getDataYaml(spacing_yml))}, 
    { "tables" , YAML::Load(getDataYaml(tables_yml))}, 
    { "typography" , YAML::Load(getDataYaml(typography_yml))},
    { "transform" , YAML::Load(getDataYaml(transform_yml))}
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
    vector<string> categories_raw = YAML::Load( getDataYaml( categories_yml ) ).as<vector<string>>();
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
            createFileConfig(dirPathName + "/build.yml", getDataYaml(build_yml) );
            // -------------------------------------------------------------

            auto screens = YAML::Load(getDataYaml(screens_yml)).as<std::map<std::string,std::map<std::string,std::string>>>();
            std::vector<std::string> screens_key;
            for( auto const&[key,value] : screens){                
                screens_key.push_back(key);
            }
            


            for(string category : categories_raw){

                YAML::Emitter out;
                out << YAML::BeginMap;
                auto properties =   PropertiesCss.at( category ).as<map<std::string,std::map<string,string>>>();
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
                }
                out << YAML::EndMap;
                
                    
                std::string fileCategoryYaml = dirPathNameConfig+"/"+category+".yml";
                if( !fs::exists(fileCategoryYaml) ){
                    createFileConfig( fileCategoryYaml , out.c_str() );
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
// ----------------------------------------------------------------------------------
void buildProject( string dirbuild ){        
    string dirPath = fs::current_path().generic_string() + "/" + dirbuild;
    if( !fs::exists(dirPath) ){        
        errorMesage( "The folder does not exist : " + dirPath );
        exit(1);
    }
    string buildyaml = dirPath + "/build.yml";
    if(!fs::exists(buildyaml)){
        errorMesage( "The config file does not exist : " + buildyaml );
        exit(1);
    }

    auto start = std::chrono::system_clock::now();
    normalMesage("Starting...");
    YAML::Node node = YAML::LoadFile( buildyaml );
    auto states = node["states"].as<std::vector<std::string>>();
    auto screens = node["screens"].as<map<std::string,std::map<string,string>>>();
    auto normalize = node["normalize"].as<bool>();
    // CATEGORIES SECTION
    vector<string> categories_raw = YAML::Load( getDataYaml( categories_yml ) ).as<vector<string>>();
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
    string d_master =  dirPath + "/dist/master.min.css";    
    if( categories.size() > 0 ){
        std::ofstream fileMaster( d_master );
        if( normalize ){ fileMaster << getDataYaml(normalize_min_css); }
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
