cmake_minimum_required(VERSION 3.15)

project(FinanceSystem)

add_subdirectory(src)

target_include_directories(${PROJECT_NAME} PUBLIC includes)
