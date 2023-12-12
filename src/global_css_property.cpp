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


std::string global_css_property::css( const char* state ) const{
    std::string str = "";
    for( auto const&[className,css_value]: options ){
        if( std::string(state)  == "first-child" || std::string(state)  == "last-child" ){
            size_t position = std::string(state).find("-");
            std::string shortState = std::string(state).substr(0, position);
            str.append(fmt::format(".{5}\\:{0} > :{6}{3}{1}:{2}{4}", className , main_property, css_value ,"{","}",shortState,state));
        }else if( std::string(state)  == "only-child" ){
            size_t position = std::string(state).find("-");
            std::string shortState = std::string(state).substr(0, position);
            str.append(fmt::format(".{5}\\:{0}:{6}{3}{1}:{2}{4}", className , main_property, css_value ,"{","}",shortState,state));
        }else if( std::string(state)  == "nth-child(odd)"  || std::string(state)  == "nth-child(even)" ){
            
            std::string shortState = std::string(state) == "nth-child(odd)" ? "odd" : "even";
            str.append(fmt::format(".{5}\\:{0} > :{6}{3}{1}:{2}{4}", className , main_property, css_value ,"{","}",shortState,state));
        }else{
            str.append(fmt::format(".{5}\\:{0}:{5}{3}{1}:{2}{4}", className , main_property, css_value ,"{","}",state));
        }
        
    }        
    return str;
}
