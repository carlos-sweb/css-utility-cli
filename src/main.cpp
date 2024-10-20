#include <stdio.h>                                                              
#include <stdlib.h>  
#include <filesystem>
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstring>
#include <chrono>
#include <ctime>
#include <thread>
#include <algorithm>
#include <functional>
#include <typeinfo>
#include "argh.h"
// -----------------------------------------------------------------------------------------------
// normalize_min_css
#include "helperOptions.h"
#include "create_project.h"
#include "build_project.h"

#define CROW_STATIC_DIRECTORY "/home/sweb/cppProjects/css-utility-cli/public/"
//#define CROW_STATIC_ENDPOINT "/alternative_endpoint/<path>"
//#define CROW_DISABLE_STATIC_DIR


#include "crow.h"


#include <random>


int numeroAleatorio(int min, int max) {
    static std::mt19937 generador(std::time(0));
    std::uniform_int_distribution<int> distribucion(min, max);
    return distribucion(generador);
}


// -----------------------------------------------------------------------------------------------
int main(int argc, char* argv[]){
    // -------------------------------------------------------------------------------------
    argh::parser cmdl(argv);    
    if( cmdl[{"-v","--version"}] || cmdl[{"-h","--help"}] ){
        helperOptions ho;        
        if(cmdl[{"-v","--version"}]){ ho.showVersion();}        
        if(cmdl[{"-h","--help"}]){ ho.help(); }
    }    
    if( cmdl[{"-i","--init"}] ){
        std::cout << "Try Init Working...\n";
    }
    // -------------------------------------------------------------------------------------
    // Aqui sabemos que esta declaro con un = , auque de todas 
    // formas proria venir vacio
    if( cmdl({"-c","--create"})){createProject( cmdl({ "-c", "--create" }).str());}
    // Verificamos presencia del atributo pero sabemos de ante mano que esta vacio
    if(cmdl[{"-c","--create"}]){createProject( "" );}
    // -------------------------------------------------------------------------------------
    // Aqui sabemos que la palabra  buil viene solo --build
    if(cmdl[{"-b","--build"}]){buildProject("");}
    // Aqui sabemos que viene --build="somethink" de todas manera podria venir vacia 
    if(cmdl({"-b","--build"})){buildProject(cmdl({ "-b", "--build" }).str());}    
    // -------------------------------------------------------------------------------------
    if(cmdl[{"-s","--server"}]){

        // int port = numeroAleatorio(8000,125000);

        crow::SimpleApp app;        
        crow::mustache::set_base("/home/sweb/cppProjects/css-utility-cli/public");
        crow::mustache::set_global_base("/home/sweb/cppProjects/css-utility-cli/public");

        CROW_ROUTE(app, "/")([](){
            std::string name = "Carlos";                                        
            auto page = crow::mustache::load("index.html"); // 
            crow::mustache::context ctx ({{"person", name}}); // 
            return page.render(ctx); //
        });
        
         CROW_ROUTE(app, "/bulma.css")
    ([](const crow::request&, crow::response& res) {
        //replace cat.jpg with your file path
        res.set_static_file_info("css/bulma.min.css");
        res.end();
    });

        CROW_ROUTE(app, "/json")
        ([]{

            crow::json::wvalue x({{"message", "Hello, World!"}});
            x["message2"] = "Hello, World.. Again!";
            return x;
        });
        CROW_ROUTE(app,"/hello/<string>")
        ([](std::string s){
            return crow::response(s);
        });
        // app.port(port).multithreaded().run();  
        app.port(18080).multithreaded().run();  

    }    


    return EXIT_SUCCESS;
    // -------------------------------------------------------------------------------------
}
