cmake_minimum_required(VERSION 2.8.3)
project(test_pkg)

find_package(catkin  REQUIRED COMPONENTS
  roscpp
  tf
)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS} )

add_executable(save_traj_as_tum src/trajectorysave.cpp )
target_link_libraries(save_traj_as_tum ${catkin_LIBRARIES})
