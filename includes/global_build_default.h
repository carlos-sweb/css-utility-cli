#ifndef GLOBAL_BUILD_DEFAULT_H
#define GLOBAL_BUILD_DEFAULT_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <yaml-cpp/yaml.h>
#include "css_categories/category_alignment.h"

struct global_build_default {
    bool normalize = true;
    std::vector<std::string> categories = {
        "alignment",
        "backgrounds",
        "bgcolor",
        "border",
        "effects",
        "flexbox",
        "grid",
        "interactivity",
        "layout",
        "sizing",
        "spacing",
        "tables",
        "typography",
        "transforms"
    }; ;
    std::map<std::string, std::map<std::string, std::string>> screens = { 
        {"xs", { {"min","0px"},{"max","639px"} } } , 
        {"sm", { {"min","640px"},{"max","767px"} } } ,
        {"md", { {"min","768px"},{"max","1023px"} } } ,
        {"lg", { {"min","1024px"},{"max","2000px"} } } 
        };;
    std::vector<std::string> states ={
        "link",
        "visited",
        "hover",
        "focus",
        "active",
        "checked",
        "disabled",
        "focus-visible",
        "required"
    };;

    global_build_default() = default; // Constructor

    bool stateExists(std::string name) const;
    bool categoryExists(std::string name) const;
    std::string yml() const;
    friend std::ostream& operator<<(std::ostream& os, const global_build_default& config);
    friend std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& listado);
    friend std::ostream& operator<<(std::ostream& os, const std::map<std::string, std::map<std::string, std::string>>& listado);
};
#endif // GLOBAL_BUILD_DEFAULT_H