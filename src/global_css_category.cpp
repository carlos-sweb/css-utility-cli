#include "global_css_category.h"

global_css_category::global_css_category(std::string n,std::vector<global_css_property*> p):name_category(n),properties(p){

}

std::string global_css_category::css() const {
    std::string str = "";
    for( const auto &property : properties){        
        str.append( property->css() );
    }
    return str;    
}