// -----------------------------------------------------------------------------------------------
#define QUESTION_INITIALIZE " You want to initialize a project"
// -----------------------------------------------------------------------------------------------
using namespace std;
// -----------------------------------------------------------------------------------------------
namespace fs = std::filesystem;
// -----------------------------------------------------------------------------------------------
void normalMesage(std::string message){ fmt::printf("%s\n", message ); }
// -----------------------------------------------------------------------------------------------
void errorMesage( std::string message ){ std::cout << termcolor::red << " Error -> "<< termcolor::reset <<  message  << "\n";}
// -----------------------------------------------------------------------------------------------
void warningMesage( std::string message ){ std::cout << termcolor::yellow << " Warning -> "<< termcolor::reset <<  message  << "\n";}
// -----------------------------------------------------------------------------------------------
void successMesage( std::string message ){std::cout << termcolor::green << " Success -> "<< termcolor::reset <<  message  << "\n";}
// -----------------------------------------------------------------------------------------------
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

// -----------------------------------------------------------------------------------------------------
vector<string> cleanCategories( vector<string> categories , vector<string> raw , std::function<void(string,bool)> done ){
    vector<string> str;
    // ------------------------------------------------------------------------------
    for( const auto &category : raw ){
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
    global_build_default Build_default;
            
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
    vector<string> categories_raw = Build_default.categories;
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
        for(const auto &category : categories ){            
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