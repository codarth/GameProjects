#include "Window.h"
#include "CogineErrors.h"

namespace Cogine {

	Window::Window() {}


	Window::~Window() {}

	int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags) {

		Uint32 flags = SDL_WINDOW_OPENGL;

		m_screenWidth = screenWidth;
		m_screenHeight = screenHeight;

		if (currentFlags & INVISABLE) {
			flags |= SDL_WINDOW_HIDDEN;
		}
		if (currentFlags & FULLSCREEN) {
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		}
		if (currentFlags & BORDERLESS) {
			flags |= SDL_WINDOW_BORDERLESS;
		}


		m_sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
		if (m_sdlWindow == nullptr) {
			fatalError("SDL window could not be created!");
		}

		SDL_GLContext glContext = SDL_GL_CreateContext(m_sdlWindow);
		if (glContext == nullptr) {
			fatalError("SDL_GL context could no be created!");
		}

		GLenum error = glewInit();
		if (error != GLEW_OK) {
			fatalError("Could not initialize glew!");
		}

		//check the OpenGl Version
		printf("*** OpenGL version: %s ***\n", glGetString(GL_VERSION));

		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

		SDL_GL_SetSwapInterval(0);

		//Enable alpha blend
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		return 0;
	}

	void Window::swapBuffer() {
		SDL_GL_SwapWindow(m_sdlWindow);

	}
}