#include "build_project.h"
#include "normalize.h"

void buildProject(std::string path){

    fs::path pathBuild = fs::current_path();    
    pathBuild /= path;
    
    if( !fs::is_directory( pathBuild ) ){
        std::cout << " Error no existe el directorio ? "  << '\n';
        // errorMesage("jajaja");
        return;
    }

    fs::path buildJsonPath = pathBuild /  "build.json" ; 
    
    if( !fs::exists( buildJsonPath ) ){
        std::cout << " Error no existe el build.json ? "  << '\n';
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


    

    std::ofstream archivo("/home/sweb/Escritorio/basura/hola/dist/master.min.css" , std::ios::out | std::ios::trunc);
    // NORMALIZE SECTION
    const Value &normalize = d["normalize"];    
    if( normalize.IsBool() ){        
        if( normalize.GetBool()  ){        
            if (archivo.is_open()){
                archivo << normalize_min_css;                                
            }            
        }
    }else{
        std::cout << "Normalize option must be boolean :(";
    }

    global_build_default Build_default; 
    // CATEGORIES SECCTION
    const Value &categories = d["categories"];
    if( categories.IsArray() ){            
        for( SizeType i = 0 ; i < categories.Size() ; i++ ){
        const std::string nameCategory = categories[i].GetString();
            if( Build_default.categoryExists( nameCategory ) ){
                std::cout << "Existe -> " <<  nameCategory << "\n";
            }else{
                std::cout << "Noexiste -> " << nameCategory  << "\n";
            }
        }
    }

    // CLOSE FILE   
    if (archivo.is_open()){archivo.close();}





}