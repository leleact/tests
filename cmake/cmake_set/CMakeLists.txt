cmake_minimum_required(VERSION 3.11)

set(F "a" "b" "c")
MESSAGE(STATUS ${F})

list(APPEND F "d")
MESSAGE(STATUS ${F})

set(F ${F} "e")
MESSAGE(STATUS ${F})
