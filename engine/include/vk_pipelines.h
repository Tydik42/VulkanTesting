#pragma once

#include "vk_initializers.h"

namespace vkutil {
bool load_shader_module(const char* filePath,
		VkDevice device,
		VkShaderModule* outShaderModule);

} // vkutil