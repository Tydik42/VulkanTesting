cmake_minimum_required(VERSION 3.25)

project(vkTest-demo-models)

set(_target vkTest-demo-models)
set(_sources main.cpp)

add_executable(${_target} ${_sources})
target_link_libraries(${_target} PUBLIC vkTest::engine)

unset(_target)
unset(_sources)
