# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\examen_pentru_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\examen_pentru_autogen.dir\\ParseCache.txt"
  "examen_pentru_autogen"
  )
endif()
