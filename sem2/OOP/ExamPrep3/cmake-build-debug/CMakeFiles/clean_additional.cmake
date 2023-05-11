# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\prima_restanta_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\prima_restanta_autogen.dir\\ParseCache.txt"
  "prima_restanta_autogen"
  )
endif()
