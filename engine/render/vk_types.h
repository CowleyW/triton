#pragma once

#include "io/logging.h"

#include "buffer.h"

#include <vk_mem_alloc.h>
#include <vulkan/vk_enum_string_helper.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

#include <cstdint>

#define VK_ASSERT(x)                                                           \
  do {                                                                         \
    VkResult err = x;                                                          \
    if (err) {                                                                 \
      io::error("{}", string_VkResult(err));                                   \
    }                                                                          \
  } while (false)

struct Dimensions {
  uint32_t width;
  uint32_t height;
};

struct CameraData {
  glm::mat4 viewproj;
};

struct SceneData {
  glm::vec4 fog_color;
  glm::vec4 fog_distances;
  glm::vec4 ambient_color;
  glm::vec4 sunlight_direction;
  glm::vec4 sunlight_color;
};

struct AllocatedImage {
  VkImage image;
  VmaAllocation allocation;
};

struct FrameData {
  VkSemaphore present_semaphore;
  VkSemaphore render_semaphore;
  VkFence render_fence;

  VkCommandPool command_pool;
  VkCommandBuffer main_command_buffer;

  AllocatedBuffer camera_buffer;
  AllocatedBuffer object_buffer;

  VkDescriptorSet global_descriptor;
  VkDescriptorSet object_descriptor;
};

struct ObjectData {
  glm::mat4 model;
};

struct UploadContext {
  VkFence upload_fence;
  VkCommandPool command_pool;
  VkCommandBuffer command_buffer;
};

enum class ShaderType { Vertex = 0, Fragment };
