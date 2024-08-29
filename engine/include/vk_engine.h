#pragma once

#include "vk_types.h"
#include "vk_initializers.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
#include <SDL_video.h>
#include <VkBootstrap.h>

#include <chrono>
#include <thread>

struct FrameData {

	VkCommandPool _commandPool;
	VkCommandBuffer _mainCommandBuffer;
};

constexpr unsigned int FRAME_OVERLAP = 2;

class VulkanEngine
{
public:
	FrameData _frames[FRAME_OVERLAP];
	bool _isInitialized { false };
	int _frameNumber {0};
	bool stop_rendering { false };
	VkExtent2D _windowExtent{ 1700 , 900 };

	struct SDL_Window* _window{ nullptr };

	static VulkanEngine& Get();

	//initializes everything in the engine
	void init();

	//shuts down the engine
	void cleanup();

	//draw loop
	void draw();

	//run main loop
	void run();

	FrameData& get_current_frame() { return _frames[_frameNumber % FRAME_OVERLAP]; }

	VkInstance _instance;// Vulkan library handle
	VkDebugUtilsMessengerEXT _debug_messenger;// Vulkan debug output handle
	VkPhysicalDevice _chosenGPU;// GPU chosen as the default device
	VkDevice _device; // Vulkan device for commands
	VkSurfaceKHR _surface;// Vulkan window surface
	VkSwapchainKHR _swapchain;
	VkFormat _swapchainImageFormat;

	std::vector<VkImage> _swapchainImages;
	std::vector<VkImageView> _swapchainImageViews;
	VkExtent2D _swapchainExtent;

	VkQueue _graphicsQueue;
	uint32_t _graphicsQueueFamily;

private:

	void init_vulkan();
	void init_swapchain();
	void init_commands();
	void init_sync_structures();
	void create_swapchain(uint32_t width, uint32_t height);
	void destroy_swapchain();
};
