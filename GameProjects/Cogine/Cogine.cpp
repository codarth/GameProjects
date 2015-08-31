#include <SDL/SDL.h>
#include <GL/glew.h>

#include "Cogine.h"

namespace Cogine {

	int init() {
		//initialize SDL
		SDL_Init(SDL_INIT_EVERYTHING);

		//double buffer to create two windows, one for draw the other to clear. stop screen flickering.
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		return 0;
	}
}