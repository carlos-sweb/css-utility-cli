#ifndef GLOBAL_CSS_PROPERTY_H
#define GLOBAL_CSS_PROPERTY_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fmt/core.h>

typedef struct Global_css_property{
    std::string main_property;
    std::map<std::string,std::string> options;
    Global_css_property(std::string m ,std::map<std::string,std::string> o );    
    std::string getMainProperty();
    std::string css() const;
}global_css_property;

#endif // GLOBAL_CSS_PROPERTY_H