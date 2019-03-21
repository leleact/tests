将目录加入 `CMAKE_MODULE_PATH` 需要使用 `list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/CMakeModules)`

`find_package` top `CMakeLists.txt` 可以获取到 `Findxxx.cmake`中的变量

`add_subdirectory` 上层的`CMakeList.txt`不能获取到子目录中的变量

`find_package_handle_standard_args` 会设置 `XXX_FOUNT`变量
