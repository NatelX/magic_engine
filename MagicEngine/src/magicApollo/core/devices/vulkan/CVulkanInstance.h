#ifndef CVULKANINSTANCE_H
#define CVULKANINSTANCE_H

#include <magicEngine/core/Core.h>
#include "CVulkan.h"

using namespace MagicEngine;

namespace MagicApollo {

	enum CRendererDebugger;

	class MAGICENGINE_API CVulkanInstance {
	protected:
		vk::Instance m_vkInstance;
		vk::DispatchLoaderDynamic m_dynamicDispatchLoader;

	public:
		CVulkanInstance(CRendererDebugger rendererDebugger);

		void destroy() const;

		vk::Instance getInstance() const;

	private:
		CArray<const char*> getVulkanExtensions(
			CRendererDebugger rendererDebugger) const;
		CArray<const char*> getVulkanLayers(
			CRendererDebugger rendererDebugger) const;
	};

}

#endif