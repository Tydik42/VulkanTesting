cmake_minimum_required(VERSION 3.24)

project(vkTest-demo-models)

set(_target vkTest-demo-models)

file(GLOB_RECURSE _sources CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h**
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c**
)
add_executable(${_target} ${_sources})
target_link_libraries(${_target} PUBLIC vkTest::engine)

unset(_target)
unset(_sources)
