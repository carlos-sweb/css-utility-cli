#include "global_css_property.h"

Global_css_property::Global_css_property(std::string m, std::map<std::string,std::string> o ): main_property(m) , options(o) {
    std::cout << "pROPERTY ---> " << main_property << "\n";
}

std::string Global_css_property::getMainProperty(){
    return main_property;
}

std::string Global_css_property::css() const {
    std::string str = "";
    for( auto const&[className,css_value]: options ){
        str.append(fmt::format(".{0}{3}{1}:{2}{4}", className , main_property, css_value ,"{","}"));
    }        
    return str;
}
