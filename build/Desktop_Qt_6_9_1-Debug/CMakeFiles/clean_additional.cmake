# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/MainWindow_prototype_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MainWindow_prototype_autogen.dir/ParseCache.txt"
  "MainWindow_prototype_autogen"
  )
endif()
