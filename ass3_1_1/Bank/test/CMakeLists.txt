add_executable(test bank_tests.cpp)
target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/external)
target_link_libraries(test PUBLIC bank)