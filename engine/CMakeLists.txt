cmake_minimum_required(VERSION 3.25)

project(vkTest)

set(vkTest_sources
   src/vk_descriptors.cpp
   src/vk_engine.cpp
   src/vk_images.cpp
   src/vk_initializers.cpp
   src/vk_pipelines.cpp
)

add_library(${PROJECT_NAME} STATIC ${vkTest_sources})
target_include_directories(${PROJECT_NAME} PUBLIC "include")
add_library(vkTest::engine ALIAS ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PUBLIC vkTest::libraries)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
