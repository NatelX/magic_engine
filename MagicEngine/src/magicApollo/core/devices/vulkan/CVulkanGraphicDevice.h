#ifndef CVULKANGRAPHICDEVICE_H
#define CVULKANGRAPHICDEVICE_H

#include "../CMagicApolloGraphicDevice.h"
#include <vulkan/vulkan.hpp>
#include <magicEngine/core/collections/CArray.h>

using namespace MagicEngine;

namespace MagicApollo {

	class MAGICENGINE_API CVulkanGraphicDevice : public CMagicApolloGraphicDevice {
	protected:
		vk::Instance m_vkInstance;

	public:
		CVulkanGraphicDevice();

	private:
		void initVulkanContext();
		CArray<const char*> getVulkanExtensions() const;
		CArray<const char*> getVulkanLayers() const;
	};

}

#endif