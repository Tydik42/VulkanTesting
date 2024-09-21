# VulkanTesting

## How to build

### 1. Downloading the repository:

Start by cloning the repository with `git clone --recurse-submodules https://github.com/Tydik42/VulkanTesting.git`.

If the repository was cloned non-recursively previously, use `git submodule update --init` to clone the necessary submodules.

### 2. Dependencies:

1. Install [Vulkan SDK](https://vulkan.lunarg.com/sdk/home).
2. If you use linux, run the [vcpkg-install.sh](https://github.com/Tydik42/VulkanTesting/blob/main/scripts/vcpkg-install.sh) file. If the Vulkan SDK is installed properly, it will then download the Vulkan SDK libraries. (This may take a longer amount of time)

### 3. Configure

This project uses CMake to generate the build files. To configure the project, you can use
the following commands:

```bash
cmake -B build -S .
```

### 4. Build

After configuring the project, you can build it using the following command:

```bash
cmake --build build
```
