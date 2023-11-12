#ifndef HELPER_H
#define HELPER_H

struct global_css_property{
    std::string main_property;
    std::map<std::string,std::string> options;
    global_css_property( std::string mp , std::map<std::string,std::string> opt ){
        main_property = mp;
        options = opt;    
    }
    std::string css(){
        std::string str = "";
        for( auto const&[className,css_value]: options ){
            str.append(fmt::format(".{0}{3}{1}:{2}{4}", className , main_property, css_value ,"{","}"));
        }        
        return str;
    }
};

struct global_css_category{
    std::string name_category;
    std::vector<global_css_property> properties;
    global_css_category( std::string n , std::vector<global_css_property> p){
        name_category = n; properties = p;
    }
    std::string css(){
        std::string str = "";
        for( auto property : properties){
            str.append( property.css() );
        }
        return str;
    }
};

#endif //HELPER_H