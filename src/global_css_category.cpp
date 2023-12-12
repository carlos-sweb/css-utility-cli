#include "global_css_category.h"

global_css_category::global_css_category(std::string n,std::vector<global_css_property*> p):name_category(n),properties(p){

}

std::vector<std::map<std::string,std::vector<std::string>>> global_css_category::getProperties() const{  
    std::vector<std::map<std::string,std::vector<std::string>>> _str;    
    for( const auto &property : properties ){
        _str.push_back( property->getProperties() );
    }    
    return _str;
}

std::string global_css_category::css() const {
    std::string str = "";
    for( const auto &property : properties){        
        str.append( property->css() );
    }
    return str;    
}
std::string global_css_category::css(const char* state) const{
    std::string str = "";
    for( const auto &property : properties){        
        str.append( property->css(state) );
    }
    return str;
};
