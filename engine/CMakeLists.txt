cmake_minimum_required(VERSION 3.25)

project(vkTest)

file(GLOB_RECURSE vkTest_sources CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE vkTest_headers CONFIGURE_DEPENDS include/*.h)

add_library(${PROJECT_NAME} ${vkTest_sources} ${vkTest_headers})
add_library(vkTest::engine ALIAS ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PUBLIC vkTest::libraries)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
