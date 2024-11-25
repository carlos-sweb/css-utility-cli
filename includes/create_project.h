#ifndef CREATE_PROJECT_H
#define CREATE_PROJECT_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <stdint.h>
#include <termcolor/termcolor.hpp>
#include <fmt/core.h>
#include "global_build_default.h"
#include "helperOptions.h"
#include <filesystem>
void createProject( std::string name );
namespace fs = std::filesystem;
using std::vector;
using std::string;
using std::cout;

typedef struct create_project{
	const vector<string> paths = { 
		"dist" , 
		"dist/category", 
		"dist/screen" , 
		"config"
	};	
	bool createDirectory( string directoryName ){    		
		if( fs::exists( directoryName ) ){ return true;}
	    try{
	    	return fs::create_directory( directoryName );
	    }catch(const std::exception& e){        
	        cout << e.what() << "\n";        
	        return false;
	    }
	    return false;
	}
	
	create_project(string nameProject ){
	    
	    helperOptions ho;
		fs::path pathProject = fs::current_path();
		
		if( nameProject == "" || nameProject == " " || nameProject == "  " || nameProject == "   " ){
			ho.warningMessage("Must provide a name");
			nameProject =  ho.getAnswer("name -> ");
		}

		pathProject /=  nameProject  ;
				
		ho.normalMessage(" making the foler ...");
		if( !fs::exists( pathProject ) ){			
			createDirectory(pathProject);
		}else{
			ho.warningMessage( "folder already exists \"" ,pathProject ,  "\"");
		}
		
		global_build_default Build_default;
		ho.createFileConfig(pathProject.generic_string() + "/build.json", Build_default.json() );
		
	
		for( auto path : paths){
			fs::path tmp = pathProject;
			tmp /= path;

			if( !fs::exists(tmp)){
				if(createDirectory(tmp)){
					ho.successMessage("the folder was created \"", tmp , "\"");		
				}
			}else{
				ho.warningMessage( "folder already exists \"" ,tmp ,  "\"");
			}			
		}				

		// -------------------------------------------------------------
		fs::path pathConfig = pathProject;
		pathConfig /= "config";		
            for(const auto &category : Build_default.getCategories() ){
                std::string fileCategoryJson = pathConfig.generic_string() + "/" +category+".json";
                if( !fs::exists(fileCategoryJson) ){
                    ho.createFileConfig( fileCategoryJson ,  Build_default.getConfigCategory(category) );        
                    std::cout << termcolor::green << " Created : " << termcolor::reset <<  category +" -> "+category+".json" << "\n";
                }
            }
		// -------------------------------------------------------------
		ho.successMessage("folder tree has been created");
		if( ho.answer("  You want to initialize a project") ){
			// Aqui hay que inicializar 
		}else{
			ho.normalMessage(" the next step is:");
			ho.normalMessage("   cd "+ pathProject.generic_string() +" && cssutilitycli --init");
		}		
	};
	~create_project() = default;	
}create_project;



#endif // CREATE_PROJECT_H