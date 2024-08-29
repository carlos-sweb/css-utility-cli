cmake_minimum_required(VERSION 3.5)

project(cssutilitycli LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(fmt REQUIRED)

add_executable(cssutilitycli 

src/main.cpp 

src/css_var/global_color.cpp
src/helperOptions.cpp

src/global_css_property.cpp
src/global_css_category.cpp

src/css_properties/alignment.cpp
src/css_categories/alignment.cpp

src/css_properties/backgrounds.cpp
src/css_categories/backgrounds.cpp

src/css_properties/bgcolor.cpp
src/css_categories/bgcolor.cpp

src/css_properties/border.cpp
src/css_categories/border.cpp

src/css_properties/effects.cpp
src/css_categories/effects.cpp

src/css_properties/flexbox.cpp
src/css_categories/flexbox.cpp

src/css_properties/grid.cpp
src/css_categories/grid.cpp

src/css_properties/interactivity.cpp
src/css_categories/interactivity.cpp

src/css_properties/layout.cpp
src/css_categories/layout.cpp

src/css_properties/sizing.cpp
src/css_categories/sizing.cpp

src/css_properties/spacing.cpp
src/css_categories/spacing.cpp

src/css_properties/tables.cpp
src/css_categories/tables.cpp

src/css_properties/transforms.cpp
src/css_categories/transforms.cpp

src/css_properties/typography.cpp
src/css_categories/typography.cpp


src/global_build_default.cpp 
src/create_project.cpp
src/build_project.cpp

)

target_link_libraries(cssutilitycli fmt::fmt)

target_include_directories(cssutilitycli PRIVATE includes)

add_custom_target(copy_www_folder ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/www
    ${PROJECT_BINARY_DIR}/www
    COMMENT "Copy www folder into binary directory")


include(GNUInstallDirs)
install(TARGETS cssutilitycli
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
