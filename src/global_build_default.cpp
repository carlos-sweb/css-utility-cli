#include "global_build_default.h"


std::string global_build_default::getConfigCategory(std::string name_category) const {

    if( categoryExists(name_category) ){
        
        global_css_category *choose_cat;
        Document d;
        d.SetObject();
                          
        for( const auto&item : _cat ){            
            if( name_category == item->name_category ){
                choose_cat = item;
                for( const auto &_item : item->getProperties() ){                    
                    for(const auto &[key,value] : _item ){
                        Value keyProperty; 
                        keyProperty.SetString(key.c_str(),static_cast<SizeType>(key.length()),d.GetAllocator());
                        Value valueProperty;valueProperty.SetObject();
                        for(const auto &className : value){
                            Value c_name; 
                            c_name.SetString(className.c_str(),static_cast<SizeType>(className.length()),d.GetAllocator());
                            Value c_value;c_value.SetObject();
                        }
                        d.AddMember(keyProperty,valueProperty,d.GetAllocator());
                    }                    
                }                    
            }            
        }
        


        StringBuffer buffer;
        PrettyWriter<StringBuffer> writer(buffer);
        d.Accept(writer);
        return buffer.GetString();         
    }else{
        return "";
    }

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
    
    // definimos el documento como un objecy {}    
    Document config_json;
    config_json.SetObject();

    // Agregando normalize al config file
    Value keyNormalize;
    keyNormalize.SetString("normalize",config_json.GetAllocator());
    Value valueNormalize;
    valueNormalize.SetBool(true);
    config_json.AddMember(keyNormalize,valueNormalize,config_json.GetAllocator());
    //Add options categories
    Value keyCategories; keyCategories.SetString("categories",config_json.GetAllocator());
    Value valueCategories;valueCategories.SetArray();
    for( const auto &opt: getCategories() ){
        Value optValue;
        optValue.SetString(opt.c_str(),static_cast<SizeType>(opt.length()),config_json.GetAllocator());
        valueCategories.PushBack(optValue,config_json.GetAllocator());
    }
    config_json.AddMember(keyCategories ,valueCategories,config_json.GetAllocator());
    // -------------------------------------------------------------------------------
    // Add  options screens
    Value keyScreens; keyScreens.SetString("screens");
    Value valueScreens; valueScreens.SetObject();
    for( const auto &[_key,_value] : screens  ){
        Value optKey;
        optKey.SetString(_key.c_str(),static_cast<SizeType>(_key.length()),config_json.GetAllocator());
        Value optValue;
        optValue.SetObject();
        for(const auto &[__key,__value] : _value){
            Value optSubKey;optSubKey.SetString(__key.c_str(),static_cast<SizeType>(__key.length()),config_json.GetAllocator());
            Value optSubValue;optSubValue.SetString(__value.c_str(),static_cast<SizeType>(__value.length()),config_json.GetAllocator());
            optValue.AddMember(optSubKey,optSubValue,config_json.GetAllocator());
        }                
        valueScreens.AddMember(optKey,optValue,config_json.GetAllocator());
    }
    config_json.AddMember(keyScreens,valueScreens,config_json.GetAllocator());
    // Agregando los estados posibles
    Value keyStates; keyStates.SetString("states",config_json.GetAllocator());
    Value valueStates = getStatesjson( config_json.GetAllocator());    
    config_json.AddMember(keyStates,valueStates,config_json.GetAllocator());

    // -------------------------------------------------------------------------------
    
    // 3. Stringify the DOM
    StringBuffer buffer;
    PrettyWriter<StringBuffer> writer(buffer);
    config_json.Accept(writer);
    
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
