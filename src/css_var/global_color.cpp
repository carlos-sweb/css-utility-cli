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

std::string toRGBA(std::string hex) const{
    return "";
}

std::map<std::string,std::string> getRGBA() const{

   std::map<std::string,std::string> tmp;

   return tmp; 

}

global_var_color g_color;