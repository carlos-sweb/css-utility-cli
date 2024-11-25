#include "build_project.h"
#include "normalize.h"

void buildProject(std::string path){   
    helperOptions ho;
    fs::path pathBuild = fs::current_path();
    pathBuild /= path;
    if( !fs::is_directory( pathBuild ) ){        
        ho.errorMessage("The directory \"",pathBuild,"\" does not exist");        
        return;
    }
    fs::path buildJsonPath = pathBuild /  "build.json" ;
    if( !fs::exists(buildJsonPath) ){    
        ho.normalMessage( buildJsonPath );
        ho.errorMessage( "Configuration file does not exist " );
        return;
    }
    std::ifstream file( buildJsonPath , std::ifstream::in);
    IStreamWrapper isw(file);
    // ANALIZAMOS EL BUILD.JSON
    Document d;
    if (d.ParseStream(isw).HasParseError()){
        ho.normalMessage( buildJsonPath );
        ho.errorMessage("Unable to parse file");    
    
    fprintf(stderr, "\nError(offset %u): %s\n", 
        (unsigned)d.GetErrorOffset(),
        GetParseError_En(d.GetParseError()));
        return;    
    }
    
    auto start = std::chrono::system_clock::now();
    ho.successMessage("Start Build..");

    std::string outputFile = d["output"]["file"].GetString();
    fs::path MaterMinCss = pathBuild / "dist" / outputFile ;     
 
    std::ofstream archivo( MaterMinCss , std::ios::out | std::ios::trunc);
    // NORMALIZE SECTION
    bool normalize = d.HasMember("normalize") ?  d["normalize"].IsBool() ? d["normalize"].GetBool()  : false  : false;
    if( d.HasMember("normalize") ){
        if( !d["normalize"].IsBool() ){
            ho.warningMessage("The normalize option must be of boolean type");            
        }
    }
    if( normalize ){
        if (archivo.is_open()){
            archivo << normalize_min_css;                                
        }            
    }
    global_build_default Build_default; 
    // CATEGORIES SECCTION
    // Hay que Arreglar aqui   
    //const Value &states = d.HasMember("states") ? d["states"] : "Vacio";
    //const Value &categories = d.HasMember("categories") ?  d["categories"] : "Array Vacio";
    //const Value &screens = d.HasMember("screens") ?  d["screens"] : "Array Vacio";

    const Value &states = d["states"];
    const Value &categories = d["categories"];
    const Value &screens = d["screens"];
    /* Bloque de Prueba ---------------------------------- */
    Build_default.eachCategories( categories , [&path,&archivo,&states,&Build_default](global_css_category *categoryBuild){
        // Aqui debemos crear los archivos por categorias
        // std::cout << categoryBuild->name_category  << "\n";        
    });
    /* Bloque de Prueba ---------------------------------- */

    // Compilación Principal del archivo master.css
    Build_default.eachScreens(screens,[&archivo,&states,&Build_default,&categories](std::string name , std::string min , std::string max){        
        archivo << std::string(fmt::format(" @media screen and (min-width:{0}) and (max-width:{1}){{",min,max));        
        Build_default.eachCategories( categories , [&archivo,&states,&Build_default,&name](global_css_category *categoryBuild){
            archivo << categoryBuild->cssScreenWrapper(name);
            Build_default.eachStates( states ,[&archivo,&categoryBuild,&name](const char* state){
                archivo << categoryBuild->cssScreenWrapper(name,state);
            });
        });
        archivo << "}";        
    });
    // Compilación Principal del archivo master.css
    
    Build_default.eachCategories( categories , [&archivo,&states,&Build_default](global_css_category *categoryBuild){
        archivo << categoryBuild->css();
        Build_default.eachStates( states ,[&archivo,&categoryBuild](const char* state){
            archivo << categoryBuild->css(state);
        });
    });
     
    // CLOSE FILE   
    if (archivo.is_open()){archivo.close();}
    // Some computation here
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);    
    ho.successMessage( "elapsed time: " , std::to_string(elapsed_seconds.count()) , "s" );

}