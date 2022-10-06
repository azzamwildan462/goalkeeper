cmake_minimum_required(VERSION 3.0.2)
project(goalkeeper)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  motion
)

catkin_package(
 INCLUDE_DIRS include
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(${PROJECT_NAME}_lib src/${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME}_lib ${catkin_LIBRARIES} motion_lib)
