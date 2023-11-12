cmake_minimum_required(VERSION 3.5)

project(cssutilitycli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt)

add_executable(cssutilitycli main.cpp src/version.cpp src/helperOptions.cpp src/global_build_default.cpp)

target_link_libraries(cssutilitycli yaml-cpp fmt::fmt )

target_include_directories(cssutilitycli PRIVATE includes)

include(GNUInstallDirs)
install(TARGETS cssutilitycli
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)