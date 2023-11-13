#ifndef GLOBAL_CSS_CATEGORY_H
#define GLOBAL_CSS_CATEGORY_H


#include "global_css_property.h"

typedef struct Global_css_category{
    std::string name_category;
    std::vector<global_css_property*> properties;
    Global_css_category(std::string n,std::vector<global_css_property*> p);
    std::string css() const;    
}global_css_category;


#endif // GLOBAL_CSS_CATEGORY_H