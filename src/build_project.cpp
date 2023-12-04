#include "build_project.h"
#include "normalize.h"

void buildProject(std::string path){   
    helperOptions ho;
    auto start = std::chrono::system_clock::now();
    ho.successMesage("Start Build..");
    fs::path pathBuild = fs::current_path();
    pathBuild /= path;
    if( !fs::is_directory( pathBuild ) ){
        ho.normalMesage( pathBuild );
        ho.errorMesage("The directory does not exist");
        return;
    }
    fs::path buildJsonPath = pathBuild /  "build.json" ;
    if( !fs::exists(buildJsonPath) ){    
        ho.normalMesage( buildJsonPath );
        ho.errorMesage( "Configuration file does not exist " );
        return;
    }
    std::ifstream file( buildJsonPath , std::ifstream::in);
    IStreamWrapper isw(file);
    // ANALIZAMOS EL BUILD.JSON
    Document d;
    if (d.ParseStream(isw).HasParseError()){
        ho.normalMesage( buildJsonPath );
        ho.errorMesage("Unable to parse file");    
    
    fprintf(stderr, "\nError(offset %u): %s\n", 
        (unsigned)d.GetErrorOffset(),
        GetParseError_En(d.GetParseError()));
        return;    
    }    
    std::string outputFile = d["output"]["file"].GetString();
    fs::path MaterMinCss = pathBuild / "dist" / outputFile ;     
 
    std::ofstream archivo( MaterMinCss , std::ios::out | std::ios::trunc);
    // NORMALIZE SECTION

    bool normalize = d.HasMember("normalize") ?  d["normalize"].IsBool() ? d["normalize"].GetBool()  : false  : false;

    if( d.HasMember("normalize") ){
        if( !d["normalize"].IsBool() ){
            ho.warningMesage("The normalize option must be of boolean type");            
        }
    }

    if( normalize ){
        if (archivo.is_open()){
            archivo << normalize_min_css;                                
        }            
    }

    global_build_default Build_default; 
    // CATEGORIES SECCTION
    const Value &categories = d["categories"];    

    if( categories.IsArray() && archivo.is_open() ){            
        for( SizeType i = 0 ; i < categories.Size() ; i++ ){
        const std::string nameCategory = categories[i].GetString();
            if( Build_default.categoryExists( nameCategory ) ){                
                global_css_category* categoryBuild = Build_default.at( nameCategory );
                archivo << categoryBuild->css();
            }else{
                //std::cout << "Noexiste -> " << nameCategory  << "\n";
                // Dont know this category
            }
            // this break i must remove only test
            
        }        
    }

    // CLOSE FILE   
    if (archivo.is_open()){archivo.close();}
    // Some computation here
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);    
    ho.successMesage( "elapsed time: " , std::to_string(elapsed_seconds.count()) , "s" );

}