project(test)
cmake_minimum_required(VERSION 2.8)

# find Python3
find_package(Python3 COMPONENTS Interpreter Development NumPy)
if (${Python3_FOUND})
  include_directories(${Python3_INCLUDE_DIRS})
  message(STATUS "Python include dirs: ${Python3_INCLUDE_DIRS}")
else()
  message(WARNING "Python3 not found."
  "\nPlease install it to use any function of `matplotlibcpp.h`.")
endif()

# find NumPy
if (${Python3_NumPy_FOUND})
    include_directories(${Python3_NumPy_INCLUDE_DIRS})
else()
  message(WARNING "Python3 NumPy not found, proceeding with -DWITHOUT_NUMPY."
  " Some functions of `matplotlibcpp.h` might not work as expected.")
  add_definitions(-DWITHOUT_NUMPY)
endif()
