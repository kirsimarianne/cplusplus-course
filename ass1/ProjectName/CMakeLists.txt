cmake_minimum_required(VERSION 3.24.2)

project(ProjectName)

# luo itse src file tai tällä automaattisesti
add_subdirectory(src)

# builds main
add_executable(${PROJECT_NAME} main.cpp)

#Finds include directories eli headerit etsitään täältä
target_include_directories(${PROJECT_NAME} PUBLIC includes)

# eli tiedostot mitä on src:n sisällä
target_link_libraries(ProjectName utils)

