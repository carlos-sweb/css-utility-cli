#include "global_css_property.h"

global_css_property::global_css_property(std::string m, std::map<std::string,std::string> o ): main_property(m) , options(o) {
    
}

std::map<std::string,std::vector<std::string>> global_css_property::getProperties() const{
    std::map<std::string,std::vector<std::string>> str;
    std::vector<std::string> names;
    for(const auto &[K,V] : options){
        names.push_back(K);
    }
    str.insert(std::make_pair(main_property,names));
    return str;
};

std::string global_css_property::css() const {
    std::string str = "";
    for( auto const&[className,css_value]: options ){
        str.append(fmt::format(".{0}{3}{1}:{2}{4}", className , main_property, css_value ,"{","}"));
    }        
    return str;
}
