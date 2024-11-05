#include "create_project.h"
// -----------------------------------------------------------------------------------------------
void createProject( std::string name ){
    helperOptions ho;
    global_build_default Build_default; 
    std::string dirPath = fs::current_path().generic_string();    
    // --------------------------------------------------------------------------------------------
    // VERIFICAMOS EL NOMBRE DE PROJECTO QUE NO SEA NADA
    if( name == "" ){
        ho.warningMesage("Must provide a name");
        name =  ho.getAnswer("name -> ");
    }
    // --------------------------------------------------------------------------------------------
    if( name == "" ){ ho.errorMesage("the project name cannot be empty");}else{
        std::string dirPathName = dirPath + "/" +name;
        std::string dirPathNameConfig = dirPathName + "/config";
        std::string dirPathNameDist = dirPathName + "/dist";
        if( fs::exists( dirPathName ) ){
            ho.warningMesage("folder already exists.");                                
            if( ho.answer(" You want to initialize a project") ){ /*initialize();*/}else{
                ho.normalMesage( "the next step is:" );
                ho.normalMesage( "   cd " + name + " && cssutilitycli --init");
            }
        }else{
            if( 
            ho.createDirectory( dirPathName ) && ho.createDirectory( dirPathNameConfig  ) 
            &&  ho.createDirectory( dirPathNameDist )  ){                
            // -------------------------------------------------------------   
            ho.successMesage("The directory was created");
            // -------------------------------------------------------------
            ho.createFileConfig(dirPathName + "/build.json", Build_default.json() );
            // -------------------------------------------------------------
            for(const auto &category : Build_default.getCategories() ){
                std::string fileCategoryJson = dirPathNameConfig+"/"+category+".json";
                if( !fs::exists(fileCategoryJson) ){
                    ho.createFileConfig( fileCategoryJson ,  Build_default.getConfigCategory(category) );        
                    std::cout << termcolor::green << " Created : " << termcolor::reset <<  category +" -> "+category+".json" << "\n";
                }
            }                                                     
            // -------------------------------------------------------------
            if( ho.answer(" You want to initialize a project") ){ /*initialize();*/ }else{
                ho.normalMesage( "the next step is:" );
                ho.normalMesage( "   cd " + name + " && cssutilitycli --init");
            }
            }
        }
    }
}