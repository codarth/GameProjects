#pragma once

#include "GLTexture.h"
#include <string>

namespace Cogine {

	class ImageLoader {
	public:
		static GLTexture loadPNG(std::string filePath);
	};

}