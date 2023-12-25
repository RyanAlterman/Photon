#pragma once

#include <string>
#include <vulkan/vulkan.h>

namespace Photon
{
	enum class ImageFormat
	{
		None = 0,
		RGBA,
		RGBA32F
	};

	class Image
	{
	public:
		// TODO: Add documentation comments
		Image(const std::string& path);
		Image(uint32_t width, uint32_t height, ImageFormat format, const void* data = nullptr);
		~Image();

		void SetData(const void* data);

		VkDescriptorSet GetDescriptorSet() const { return m_DescriptorSet; }

		void Resize(uint32_t width, uint32_t height);

		uint32_t GetWidth() const { return m_Width; }
		uint32_t GetHeight() const { return m_Height; }

	protected:
	private:
		void AllocateMemory(uint64_t size);
		void Release();

		uint32_t m_Width;
		uint32_t m_Height;

		VkImage m_Image = nullptr;
		VkImageView m_ImageView = nullptr;
		VkDeviceMemory m_Memory = nullptr;
		VkSampler m_Sampler = nullptr;

		ImageFormat m_Format = ImageFormat::None;

		VkBuffer m_StagingBuffer = nullptr;
		VkDeviceMemory m_StagingMemory = nullptr;

		size_t m_AlignedSize = 0;

		VkDescriptorSet m_DescriptorSet = nullptr;

		std::string m_FilePath;
	};
}
