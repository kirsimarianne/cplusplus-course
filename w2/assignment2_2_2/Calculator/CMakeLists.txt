cmake_minimum_required(VERSION 3.24.2)

project(Calculator)

# builds main
add_executable(${PROJECT_NAME} main.cpp)

# voi luoda ite, tulee automaattisesti kun addaa submodulen
add_subdirectory(src external/cxxopts)

#Finds include directories eli headerit etsitään täältä
target_include_directories(${PROJECT_NAME} PUBLIC includes external/cxxopts/include) 

# eli tiedostot mitä on src:n sisällä
target_link_libraries(${PROJECT_NAME} utils)


#git submodule add git@github.com:jarro2783/cxxopts.git external/cxxopts/