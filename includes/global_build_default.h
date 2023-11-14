#ifndef GLOBAL_BUILD_DEFAULT_H
#define GLOBAL_BUILD_DEFAULT_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <yaml-cpp/yaml.h>
#include "css_categories/alignment.h"
#include "css_categories/backgrounds.h"
#include "css_categories/bgcolor.h"
#include "css_categories/border.h"
#include "css_categories/effects.h"
#include "css_categories/flexbox.h"
#include "css_categories/grid.h"
#include "css_categories/interactivity.h"
#include "css_categories/layout.h"
#include "css_categories/sizing.h"
#include "css_categories/spacing.h"
#include "css_categories/tables.h"
#include "css_categories/transforms.h"
#include "css_categories/typography.h"

struct global_build_default {
    bool normalize = true;
    std::vector<global_css_category*> _cat = {
        alignment,
        backgrounds,
        bgcolor,
        border,
        effects,
        flexbox,
        grid,
        interactivity,
        layout,
        sizing,
        spacing,
        tables,
        transforms,
        typography
    };
    std::vector<std::string> getCategories() const;
    std::vector<std::string> getScreensKey() const;
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