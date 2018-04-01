
cmake_minimum_required (VERSION 2.6)

project (script)


find_path(sub_cmake_directory
    CMakeLists.txt
    PATHS ${CMAKE_CURRENT_SOURCE_DIR}
    PATH_SUFFIXES sub1)

file(GLOB SUB_HAS_CMAKELISTS_TXT_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} */CMakeLists.txt)
foreach(ITEM ${SUB_HAS_CMAKELISTS_TXT_DIRS})
    string(REPLACE "CMakeLists.txt" "" SUB_DIR ${ITEM})
    message(STATUS "SUB_DIR: " ${SUB_DIR})
    add_subdirectory(${SUB_DIR})
endforeach()

message(STATUS "sub_cmake_dirs: " ${sub_cmake_dirs})
message(STATUS "sub_cmake_directory: " ${sub_cmake_directory})
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "CMAKE_CURRENT_BINARY_DIR: " ${CMAKE_CURRENT_BINARY_DIR})
