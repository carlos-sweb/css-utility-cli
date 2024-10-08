#include "global_build_default.h"
std::string global_build_default::getConfigCategory(std::string name_category) const {    
    
    Document d;
    d.Parse(R"({})");

    for(const auto &item : _cat){
        if( name_category == item->name_category ){
            for(const auto &_item : item->getProperties()){
                for(const auto &[key,value] : _item){
                    // n means normal , I dont sure how i can called when
                    // the property is outside of screens list(xs-md-sm-lg)
                    //SECTION n ( normal )
                    // -------------------------------------------------------------
                    for( const auto &className : value ){
                        std::string PointerString = "/"+key+"/"+className+"/screens";                        
                        Pointer(PointerString.c_str()).Create(d);
                        Value * _value = Pointer(PointerString.c_str()).Get(d);
                        _value->SetArray();
                        SetValueByPointer(d , Pointer(std::string(PointerString+"/-").c_str()) , "n" );
                        for( const auto & screen : getScreensKey() ){
                            // SetValueByPointer(d , Pointer(std::string(PointerString+"/-").c_str()) , screen.c_str() );
                            /*
                            for(const auto &state : states){
                                SetValueByPointer(d , Pointer(std::string(PointerString+"/-").c_str()) , std::string(screen+":"+state).c_str() );
                            }
                            */
                        }
                    }
                    // -------------------------------------------------------------
                }
            }
        // verificar si podemos agregar un break; aqui    
        }
    }
    // --------------------------------------------------------------------------------


    StringBuffer buffer;
    PrettyWriter<StringBuffer> writer(buffer);
    d.Accept(writer);
    return buffer.GetString();
    // --------------------------------------------------------------------------------
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

void global_build_default::eachCategories(const Value &categoriesJson , std::function<void(global_css_category*)> func) const{        
    if( categoriesJson.IsArray() ){
        for( SizeType i = 0 ; i < categoriesJson.Size() ; i++ ){
            const std::string nameCategory = categoriesJson[i].GetString();
            if( categoryExists(nameCategory) ){
              global_css_category* categoryBuild = at( nameCategory );  
              func(categoryBuild);
            }
        }
    }
}

void global_build_default::eachStates(const Value &statesJson , std::function<void(const char*)> func) const{
    if( statesJson.IsArray() ){
       for(auto& v : statesJson.GetArray()){
            if( stateExists( std::string( v.GetString() ) ) ){
                func( v.GetString() );
            }            
        } 
    }
}

void global_build_default::eachScreens(const Value &screensJson,std::function<void(std::string,std::string,std::string)> func) const{
    if( screensJson.IsObject() ){        
        for( auto& screen : screensJson.GetObject()){
            std::string name  = std::string( screen.name.GetString());
            std::string min = std::string(screen.value["min"].GetString());
            std::string max = std::string(screen.value["max"].GetString());
            if( screen.value.HasMember("min") && screen.value.HasMember("max") ){                                        
                func(name,min,max);
            }
        }
    }
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
    d.Parse(R"({"normalize":true,"categories":[],"screens":{},"states":[],"output":{"file":"master.css","minify":true}})");
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

global_css_category* global_build_default::at(std::string name_category) const{
    int indice = -1;
    for( int i = 0 ; i < _cat.size() ; i++ ){
       if( _cat[i]->name_category == name_category ){
        indice = i;
        break;
       }
    }
    return _cat[ indice ];
}