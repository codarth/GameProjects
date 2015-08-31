#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>

namespace Cogine {

	TextureCache::TextureCache() {}


	TextureCache::~TextureCache() {}

	GLTexture TextureCache::getTexture(std::string texturePath) {
		//lookup the texture and see if its in the map
		//std::map<std::string, GLTexture>::iterator mit= _textureMap.find(texturePath);
		auto mit = m_textureMap.find(texturePath);

		//check if its not in the map
		if (mit == m_textureMap.end()) {
			//Load the texture
			GLTexture newTexture = ImageLoader::loadPNG(texturePath);

			//insert it into the map
			//std::cout << "Loaded Texture!\n";
			m_textureMap.insert(make_pair(texturePath, newTexture));

			return newTexture;
		}

		//std::cout << "Used cached texture!\n";
		return mit->second;
	}
}