#include "global_css_property.h"

global_css_property::global_css_property(std::string m, std::map<std::string,std::string> o ): main_property(m) , options(o) {
    
}

std::string global_css_property::css() const {
    std::string str = "";
    for( auto const&[className,css_value]: options ){
        str.append(fmt::format(".{0}{3}{1}:{2}{4}", className , main_property, css_value ,"{","}"));
    }        
    return str;
}
