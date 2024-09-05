include("${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(Vulkan REQUIRED)
find_package(VulkanMemoryAllocator REQUIRED)
find_package(vk-bootstrap CONFIG REQUIRED)
find_package(VulkanUtilityLibraries CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
add_library(imgui
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
)

add_library(libraries INTERFACE)
add_library(vkTest::libraries ALIAS libraries)

target_link_libraries(libraries INTERFACE
        Vulkan::Vulkan
        Vulkan::Headers
        SDL2::SDL2
        SDL2::SDL2main
        glm::glm
        fmt::fmt
        GPUOpen::VulkanMemoryAllocator
        vk-bootstrap::vk-bootstrap
        Vulkan::SafeStruct Vulkan::LayerSettings Vulkan::UtilityHeaders Vulkan::CompilerConfiguration
        imgui
)

target_include_directories(libraries SYSTEM INTERFACE
        ${Vulkan_INCLUDE_DIRS}
        ${SDL2_INCLUDE_DIRS}
        ${glm_INCLUDE_DIRS}
        ${fmt_INCLUDE_DIRS}
        ${vma_INCLUDE_DIRS}
        ${IMGUI_DIR}
)
