add_executable(test_complex test_complex.cpp)
target_link_libraries(test_complex complex)

add_executable(test_rational test_rational.cpp)
target_link_libraries(test_rational rational)

add_executable(test_dynarr test_dynarr.cpp)
target_link_libraries(test_dynarr dynarr)

add_executable(test_complex_doctest test_complex_doctest.cpp)
target_link_libraries(test_complex_doctest complex)

add_executable(test_stackarr test_stackarr.cpp)
target_link_libraries(test_stackarr stackarr)
target_link_libraries(test_stackarr complex)

add_executable(test_stacklst test_stacklst.cpp)
target_link_libraries(test_stacklst stacklst)
target_link_libraries(test_stacklst complex)

add_executable(test_queuelst test_queuelst.cpp)
target_link_libraries(test_queuelst queuelst)
target_link_libraries(test_queuelst complex)

add_executable(test_queuearr test_queuearr.cpp)
target_link_libraries(test_queuearr queuearr)
target_link_libraries(test_queuearr complex)

add_executable(test_queuelstpr test_queuelstpr.cpp)
target_link_libraries(test_queuelstpr queuelstpr)

add_executable(test_bitset test_bitset.cpp)
target_link_libraries(test_bitset bitset)

add_executable(test_stacklstt test_stacklstt.cpp)
target_link_libraries(test_stacklstt stacklstt)
target_link_libraries(test_stacklstt complex)

add_executable(test_stackarrt test_stackarrt.cpp)
target_link_libraries(test_stackarrt stackarrt)
target_link_libraries(test_stackarrt complex)

add_executable(test_queuelstprt test_queuelstprt.cpp)
target_link_libraries(test_queuelstprt queuelstprt)
target_link_libraries(test_queuelstprt complex)

add_executable(test_queuelstt test_queuelstt.cpp)
target_link_libraries(test_queuelstt queuelstt)
target_link_libraries(test_queuelstt complex)

add_executable(test_queuearrt test_queuearrt.cpp)
target_link_libraries(test_queuearrt queuearr)
target_link_libraries(test_queuearrt complex)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_complex)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_rational)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_dynarr)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_complex_doctest)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_stackarr)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_stacklst)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_queuelst)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_queuearr)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_queuelstpr)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_bitset)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_stacklstt)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_stackarrt)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_queuelstprt)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_queuelstt)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_queuearrt)