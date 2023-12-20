#include "css_var/global_color.h"

std::map<std::string,std::string> global_var_color::get() const {

    return colors;

}
std::map<std::string,std::string> global_var_color::get(std::string prefix) const{

    std::map<std::string,std::string> tmp;

    for(const auto&[key,value]:colors){

        tmp.insert(std::make_pair(prefix + "-" + key , value ));

    }

    return tmp;
}

std::string global_var_color::toRGBA(std::string hexColor) const{
     unsigned int hexValue;
    std::istringstream(hexColor.substr(1)) >> std::hex >> hexValue;

    int r = (hexValue >> 16) & 255;
    int g = (hexValue >> 8) & 255;
    int b = hexValue & 255;

    // Asegurarse de que los valores estén en el rango de 0 a 255
    r = std::min(255, std::max(0, r));
    g = std::min(255, std::max(0, g));
    b = std::min(255, std::max(0, b));
    
    // Construir la cadena de resultado compatible con CSS
    std::ostringstream result;
    result << "rgba(" << r << "," << g << "," << b << "," << ".25" << ")";
    return result.str();
}

std::map<std::string,std::string> global_var_color::getRGBA() const{
    std::map<std::string,std::string> tmp;
    for(const auto&[key,value]:colors){
        tmp.insert(std::make_pair( key , toRGBA(value) ));
    }
    return tmp;
}
std::map<std::string,std::string> global_var_color::getRGBA( std::string prefix) const{
    std::map<std::string,std::string> tmp;
    for(const auto&[key,value]:colors){
        tmp.insert(std::make_pair(prefix + "-" + key , toRGBA(value) ));
    }
    return tmp;
}
std::map<std::string,std::string> global_var_color::getRGBA( std::string prefix , std::string prefixvalue) const{
    std::map<std::string,std::string> tmp;
    for(const auto&[key,value]:colors){
        tmp.insert(std::make_pair(prefix + "-" + key , prefixvalue +" "+toRGBA(value) ));
    }
    return tmp;
}

global_var_color g_color;