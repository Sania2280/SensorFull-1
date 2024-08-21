# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SensorFull_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SensorFull_autogen.dir\\ParseCache.txt"
  "SensorFull_autogen"
  )
endif()
