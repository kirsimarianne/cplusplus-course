cmake_minimum_required(VERSION 3.2)

project(HeapArray)

#add_subdirectory(src)

add_subdirectory(test)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

#add_executable(${PROJECT_NAME} heap_array_tests.cpp)

#target_include_directories(${PROJECT_NAME} PUBLIC includes)

#target_link_libraries(${PROJECT_NAME} PUBLIC heap_array)