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
#include "argh.h"
// -----------------------------------------------------------------------------------------------
// normalize_min_css
#include "./../config/normalize.min.h"
#include "helperOptions.h"
#include "create_project.h"
#include "build_project.h"
// -----------------------------------------------------------------------------------------------
int main(int argc, char* argv[]){
    // -------------------------------------------------------------------------------------
    argh::parser cmdl(argv);
    // -------------------------------------------------------------------------------------
    if(cmdl[{"-v","--version"}]){showVersion();}
    // -------------------------------------------------------------------------------------
    if(cmdl[{"-h","--help"}]){helpOptions();}
    // -------------------------------------------------------------------------------------
    // Aqui sabemos que esta declaro con un = , auque de todas 
    // formas proria venir vacio
    if( cmdl({"-c","--create"})){createProject( cmdl({ "-c", "--create" }).str());}
    // Verificamos presencia del atributo pero sabemos de ante mano que esta vacio
    if(cmdl[{"-c","--create"}]){createProject( "" );}
    // -------------------------------------------------------------------------------------
    // Aqui sabemos que la palabra  buil viene solo --build
    if(cmdl[{"-b","--build"}]){buildProject("");}
    // Aqui sabemos que viene --build="somethink" de todas manera podria venir bacia 
    if(cmdl({"-b","--build"})){buildProject(cmdl({ "-b", "--build" }).str());}
    // -------------------------------------------------------------------------------------
    return EXIT_SUCCESS;
    // -------------------------------------------------------------------------------------
}
