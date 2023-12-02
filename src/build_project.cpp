#include "build_project.h"
#include "normalize.h"

void buildProject(std::string path){
    helperOptions ho;
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
    if (d.ParseStream(isw).HasParseError()) {    
    std::cout << "hay un error al analizar el archivo json " << "\n";
    fprintf(stderr, "\nError(offset %u): %s\n", 
        (unsigned)d.GetErrorOffset(),
        GetParseError_En(d.GetParseError()));
        return;    
    }
    
    std::string outputFile = d["output"]["file"].GetString();

    fs::path MaterMinCss = pathBuild / "dist" / outputFile ; 
    
    if( !fs::exists( buildJsonPath ) ){
        std::cout << " Error no existe el build.json ? "  << '\n';
        return;
    }

    std::ofstream archivo( MaterMinCss , std::ios::out | std::ios::trunc);
    // NORMALIZE SECTION
    //const Value &normalize = d["normalize"];

    bool normalize = d.HasMember("normalize") ?  d["normalize"].IsBool() ? d["normalize"].GetBool()  : false  : false;

    if( d.HasMember("normalize") ){
        if( !d["normalize"].IsBool() ){
            std::cout << "Error la opcion normalize debe ser verdadero o falso" << "\n";
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





}