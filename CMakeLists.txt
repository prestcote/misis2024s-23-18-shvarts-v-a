cmake_minimum_required(VERSION 3.20)

project(shvarts-v-a-23-18)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin.dbg)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin.rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_CURRENT_SOURCE_DIR}bin.relwithdbg)


#option(BUILD_WITH_CODEFORCES "Build prj.codeforces targets" on)
#if (BUILD_WITH_CODEFORCES)
  #add_subdirectory(prj.codeforces)
#endif()

add_subdirectory(prj.lab)
add_subdirectory(prj.test)
add_subdirectory(prj.codeforces)
add_subdirectory(prj.app)