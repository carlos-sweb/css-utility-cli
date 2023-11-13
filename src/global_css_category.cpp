#include "global_css_category.h"


Global_css_category::Global_css_category(std::string n,std::vector<global_css_property*> p):name_category(n),properties(p){

    std::cout << n << "\n";
    std::cout << name_category << "\n";
    for( const auto &item : p ){
        std::cout << "Hay una property " << item->main_property << "\n";
    }

}

std::string Global_css_category::css() const {
    std::string str = "";    
    std::cout << name_category << "\n";
    for( const auto &property : properties){
        std::cout << "Estamos dentro de css" <<  property->getMainProperty() <<"\n";
        str.append( property->css() );
    }
    return str;    
}