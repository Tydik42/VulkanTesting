set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(Vulkan REQUIRED)
find_package(SDL2 REQUIRED)
find_package(glm REQUIRED)
find_package(fmt REQUIRED)
find_package(vma REQUIRED)

add_library(libraries INTERFACE)
add_library(vkTest::libraries ALIAS libraries)

target_link_libraries(libraries INTERFACE
        Vulkan::Vulkan
        Vulkan::Headers
        SDL2::SDL2
        SDL2::SDL2main
        glm::glm
        fmt::fmt
        vma
)

target_include_directories(libraries SYSTEM INTERFACE
        ${Vulkan_INCLUDE_DIRS}
        ${SDL2_INCLUDE_DIRS}
        ${glm_INCLUDE_DIRS}
        ${fmt_INCLUDE_DIRS}
        ${vma_INCLUDE_DIRS}
)