#include "global_build_default.h"


std::vector<std::string> global_build_default::getScreensKey() const{
    std::vector<std::string> str = {};
    for(const auto&[key,value] : screens){
        str.push_back(key);
    }    
    return str;
}
std::vector<std::string> global_build_default::getCategories() const{
    std::vector<std::string> str = {};
    for(const auto &item : _cat){
        str.push_back(item->name_category);
    }    
    return str;
}

bool global_build_default::stateExists(std::string name) const {
    return std::find(states.begin(), states.end(), name) != states.end();
}

bool global_build_default::categoryExists(std::string name) const {
    std::vector<std::string> categories = getCategories();
    return std::find(categories.begin(), categories.end(), name) != categories.end();
}

std::string global_build_default::yml() const {
    YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << "normalize" << YAML::Value << normalize;
    out << YAML::Key << "categories" << YAML::Value << YAML::Flow << getCategories();
    out << YAML::Key << "screens" << YAML::Value << YAML::Flow << screens;
    out << YAML::Key << "states" << YAML::Value << YAML::Flow << states;
    out << YAML::EndMap;
    return out.c_str();
}
std::ostream& operator<<(std::ostream& os, const std::map<std::string, std::map<std::string, std::string>>& listado){
    for( const auto&[key,value] : listado ){
        os << " -" << key << "\n";
        if(value.find("min") != value.end()){
          os << "   - min -> " << value.at("min") << "\n";
        }        
        if(value.find("max") != value.end()){
          os << "   - max -> " << value.at("max") << "\n";
        }
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& listado) {
    for( const auto &item : listado){
        os << " - " << item << "\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const global_build_default& config) {
    os << "* normalize: " << config.normalize << "\n";
    os << "* categories:\n" << config.getCategories();
    os << "* screens:\n" << config.screens;
    os << "* states:\n" << config.states;
    return os;
}
