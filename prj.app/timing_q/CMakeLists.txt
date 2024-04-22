add_executable(timing_q timing_q.cpp)
target_link_libraries(timing_q queuearr)
target_link_libraries(timing_q queuelst)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT timing_q)