# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\gittest_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\gittest_autogen.dir\\ParseCache.txt"
  "gittest_autogen"
  )
endif()
