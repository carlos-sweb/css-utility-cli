#ifndef GLOBAL_BUILD_DEFAULT_H
#define GLOBAL_BUILD_DEFAULT_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <fmt/core.h>
#include <fmt/format.h>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/pointer.h"
#include "rapidjson/error/en.h"
#include "rapidjson/istreamwrapper.h"

using namespace rapidjson;

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
    rapidjson::Value getScreensJson(rapidjson::Document::AllocatorType& allocator) const;
    rapidjson::Value getStatesjson(rapidjson::Document::AllocatorType& allocator) const;
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
    };
    global_build_default() = default; // Constructor
    bool stateExists(std::string name) const;
    bool categoryExists(std::string name) const;
    std::string json() const;    
    std::string getConfigCategory(std::string name_category) const;    
    global_css_category* at(std::string name_category) const;
};
#endif // GLOBAL_BUILD_DEFAULT_H