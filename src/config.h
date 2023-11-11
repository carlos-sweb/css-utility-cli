struct global_css_property{
    std::string main_property;
    std::map<std::string,std::string> options;
};

struct global_build_default {
    bool normalize= true;
    std::vector<std::string> categories {
        "alignment",
        "backgrounds",
        "bgcolor",
        "border",
        "effects",
        "flexbox",
        "grid",
        "interactivity",
        "layout",
        "sizing",
        "spacing",
        "tables",
        "typography",
        "transform"
    };
    std::map<std::string,std::map<std::string,std::string>> screens { 
        {"xs", { {"min","0px"},{"max","639px"} } } , 
        {"sm", { {"min","640px"},{"max","767px"} } } ,
        {"md", { {"min","768px"},{"max","1023px"} } } ,
        {"lg", { {"min","1024px"},{"max","2000px"} } } 
        };
    std::vector<std::string> states {
        "link",
        "visited",
        "hover",
        "focus",
        "active",
        "checked",
        "disabled",
        "focus-visible",
        "required"
    };
    friend std::ostream& operator<<(std::ostream& os,const std::vector<std::string>& listado );
    friend std::ostream& operator<<(std::ostream& os,const std::map<std::string,std::string>& mapa );    
    bool stateExists(std::string name){
        bool result = false;
        if( std::find( states.begin() , states.end() , name )!= states.end() ){
            result = true;
        }
        return result;
    }
    bool categoryExists(std::string name){
        bool result = false;
        if( std::find( categories.begin() , categories.end() , name )!= categories.end() ){
            result = true;
        }
        return result;
    }
    std::string yml(){
        YAML::Emitter out;
        out << YAML::BeginMap; 
        out << YAML::Key << "normalize" << YAML::Value << true;
        out << YAML::Key << "categories" << YAML::Value  << YAML::Flow << categories;
        out << YAML::Key << "screens" << YAML::Value << YAML::Flow << screens;
        out << YAML::Key << "states" << YAML::Value << YAML::Flow << states ;
        out << YAML::EndMap;
        std::string str;
        str.append(reinterpret_cast<const char*>(out.c_str()));
        return str;
    }
}Build_default;
std::ostream& operator<<(std::ostream& os,const std::vector<std::string>& listado ){
    for( std::string item : listado ){os <<  item << "\n";}
    return os;
}
std::ostream& operator<<(std::ostream& os,const std::map<std::string,std::string>& mapa ){
    for( auto const&[key,value] : mapa ){os << key << " => " << value << "\n";}
    return os;
}


