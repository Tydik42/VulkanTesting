#!/bin/bash

cd ./thirdparty/vcpkg

./bootstrap-vcpkg.sh
./integrate install

./vcpkg install vulkan vulkan-headers vulkan-utility-libraries vulkan-memory-allocator vk-bootstrap fmt glm sdl2[vulkan]

cd ../../

echo "Installation completed. You can proceed to build the project."
