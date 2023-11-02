cmake_minimum_required(VERSION 3.5)

project(cssutilitycli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cssutilitycli main.cpp)

target_link_libraries(cssutilitycli yaml-cpp )

include(GNUInstallDirs)
install(TARGETS cssutilitycli
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)