#ifndef GLOBAL_CSS_PROPERTY_H
#define GLOBAL_CSS_PROPERTY_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fmt/core.h>

using std::vector;
using std::string;
using std::map;

typedef struct global_css_property{
    // Nombre de la propiedad principal. Por Ejemplo text-align
    string main_property;
    // Se define la clase y el valor - En este punto es algo raro     
    // { "text-left" , "left" } -  1 Argumento el nombre de la clase y el segundo el valor 
    // Osea .text-left{text-align:left}
    map<string,string> options;
    // Definimos el listado de valores que puede acceder esta propiedad
    vector<string> values;
    global_css_property(string m ,map<string,string> o );
    string css() const;
    string css(const char* state) const;
    string cssScreenWrapper(string prefix) const;
    string cssScreenWrapper(string prefix , const char* state) const;
    map<string,vector<string>> getProperties() const;
}global_css_property;

#endif // GLOBAL_CSS_PROPERTY_H