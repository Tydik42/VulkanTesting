cmake_minimum_required(VERSION 3.24)

set(vkTest_root ${CMAKE_CURRENT_SOURCE_DIR}) # VulkanTesting

project(vkTest)

include(${vkTest_root}/cmake/options.cmake)

add_subdirectory(${vkTest_engine_dir})
add_subdirectory(${vkTest_thirdparty_dir})

if (vkTest_BUILD_DEMOS)
    add_subdirectory(${vkTest_demos_dir})
endif ()

if (vkTest_COMPILE_SHADERS)
    include(CompileShaders)
    compile_shaders(DIRECTORY ${vkTest_assets_dir}/shaders)
endif ()
