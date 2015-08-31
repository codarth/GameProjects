#pragma once

#include "TextureCache.h"
#include <string>

namespace Cogine {

	class ResourceManager {
	public:
		static GLTexture getTexture(std::string texturePath);

	private:
		static TextureCache m_textureCache;
	};

}