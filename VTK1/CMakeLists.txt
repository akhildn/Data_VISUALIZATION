
cmake_minimum_required(VERSION 2.8)
 
PROJECT(Terrain)
 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
 
add_executable(Terrain MACOSX_BUNDLE Terrain.cxx )
 
target_link_libraries(Terrain ${VTK_LIBRARIES})
