#include "global_build_default.h"

std::string global_build_default::getConfigCategory(std::string name_category) const {
    Document d;
    d.Parse(R"({"general":[]})");

    for(const auto &item : _cat){
        if( name_category == item->name_category ){
            for(const auto &_item : item->getProperties()){
                for(const auto &[key,value] : _item){
                    // Key -> es el nombre de la propiedad
                    std::string a = "/"+key;
                    std::string aa = "/"+key+"/-";                                                       
                    Pointer(a.c_str()).Create(d);
                }
            }
        }
    }
    


    StringBuffer buffer;
    PrettyWriter<StringBuffer> writer(buffer);
    d.Accept(writer);
    return buffer.GetString();
}

rapidjson::Value global_build_default::getStatesjson(rapidjson::Document::AllocatorType& allocator) const{
    rapidjson::Value value;
    value.SetArray();
    for( const auto state : states ){
        rapidjson::Value name;
        name.SetString(state.c_str(),static_cast<SizeType>(state.length()),allocator);        
        value.PushBack(name,allocator);
    }
    return value;
}

rapidjson::Value global_build_default::getScreensJson(rapidjson::Document::AllocatorType& allocator) const{
    rapidjson::Value value;
    value.SetArray();
    for( const auto screen : getScreensKey() ){
        rapidjson::Value name;
        name.SetString(screen.c_str(),static_cast<SizeType>(screen.length()),allocator);        
        value.PushBack(name,allocator);
    }
    return value;
}

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

std::string global_build_default::json() const {
    Document d;
    d.Parse(R"({"normalize":true,"categories":[],"screens":{},"states":[]})");
    for(const auto &name : getCategories() ){
        SetValueByPointer(d,"/categories/-",name.c_str());
    }
    for(const auto &state : states ){
        SetValueByPointer(d,"/states/-",state.c_str());
    }
    for(const auto &[key,value] : screens){
        std::string pathMin = "/screens/"+key+"/min";
        std::string pathMax = "/screens/"+key+"/max";        
        Pointer(pathMin.c_str()).Create(d);
        Pointer(pathMin.c_str()).Set(d,value.at("min").c_str());
        Pointer(pathMax.c_str()).Create(d);
        Pointer(pathMax.c_str()).Set(d,value.at("max").c_str());
    }    
    StringBuffer buffer;
    PrettyWriter<StringBuffer> writer(buffer);
    d.Accept(writer);      
    return buffer.GetString();       
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
