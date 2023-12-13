#ifndef GLOBAL_CSS_CATEGORY_H
#define GLOBAL_CSS_CATEGORY_H

#include "global_css_property.h"

typedef struct global_css_category{
    std::string name_category;
    std::vector<global_css_property*> properties;
    global_css_category(std::string n,std::vector<global_css_property*> p);
    std::vector<std::map<std::string,std::vector<std::string>>> getProperties() const;
    std::string css() const;
    std::string css(const char* state) const;
    std::string cssScreenWrapper(std::string prefix) const;
    std::string cssScreenWrapper(std::string prefix , const char* state) const;
}global_css_category;


#endif // GLOBAL_CSS_CATEGORY_H