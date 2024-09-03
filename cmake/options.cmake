#======================================= Information ========================================#

cmake_host_system_information(RESULT vkTest_platform QUERY OS_NAME)
string(TOUPPER ${vkTest_platform} vkTest_upper_platform)
string(TOLOWER ${vkTest_platform} vkTest_lower_platform)

#========================================== Options =========================================#

option(vkTest_BUILD_DEMOS                 "Build the demos"                    ON)
option(vkTest_COMPILE_SHADERS             "Compile the shaders"                ON)

#======================================== Directories ========================================#

set(vkTest_assets_dir ${vkTest_root}/assets CACHE PATH "Path to the assets directory")
set(vkTest_engine_dir ${vkTest_root}/engine CACHE PATH "Path to the engine directory")
set(vkTest_thirdparty_dir ${vkTest_root}/thirdparty CACHE PATH "Path to the thirdparty directory")
set(vkTest_demos_dir  ${vkTest_root}/demos  CACHE PATH "Path to the demo directory")

#====================================== Configurations ======================================#

list(APPEND CMAKE_MODULE_PATH
        ${vkTest_assets_dir}/cmake
        ${vkTest_engine_dir}/cmake
        ${vkTest_demos_dir}/cmake
        ${vkTest_thirdparty_dir}/make
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GENERATE OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/engine/include/config.h
        CONTENT "#define ASSETS_DIR \"${vkTest_assets_dir}\"\n")

add_compile_definitions(
        vkTest_${vkTest_upper_platform}
        vkTest_$<UPPER_CASE:$<CONFIG>>
)
