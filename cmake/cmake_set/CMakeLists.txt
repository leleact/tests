cmake_minimum_required(VERSION 3.11)

set(F "a" "b" "c")
MESSAGE(STATUS ${F})

list(APPEND F "d")
MESSAGE(STATUS ${F})

# 设置字符连接 将F 加上 e 赋值给F
set(F ${F} "e")
MESSAGE(STATUS ${F})
