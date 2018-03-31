cmake_minimum_required(VERSION 3.8.2)

if (POLICY CMP0048)
    cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

project( cpptest-distribution )

enable_testing()
add_subdirectory(tests)
