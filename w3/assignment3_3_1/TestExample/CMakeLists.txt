cmake_minimum_required(VERSION 3.15)
project(TestExample)

#add_library(utils STATIC utils.cpp)
#add_subdirectory(src)
#add_sudirectory(external)
target_include_directories(${PROJECT_NAME} PUBLIC includes)
#target_link_libraries(${PROJECT_NAME} utils raylib)
#Sudo apt-get install cmake | asentaa cmaken
#git submodules add <repository> <path> | lisää submoduulin
#tuon jälkeen on hyvä kommitoida muutokset
#mkdir build || luodaan uusi kansio kääntämiseen tarvitsemille tiedostoille
#cmake -S . -B build | luo build kansioon tarvittavat tiedostot
#make -C build | kääntää projektin