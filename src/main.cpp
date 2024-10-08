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
	    std::cout << "init work\n";
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
    return EXIT_SUCCESS;
    // -------------------------------------------------------------------------------------
}
