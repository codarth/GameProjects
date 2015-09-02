#pragma once

#include "Window.h"
#include "Cogine.h"
#include "InputManager.h"

#include <memory>

namespace Cogine {

	class ScreenList;
	class IGameScreen;

	class IMainGame {
	public:
		IMainGame();
		virtual ~IMainGame();

		// Runs and Initializes the game
		void run();
		// Exits the game
		void exitGame();
		
		// Called in initialization
		virtual void onInit() = 0;
		// For Adding all screens
		virtual void addScreens() = 0; 
		//Called when exiting
		virtual void onExit() = 0;

		void onSDLEvent(SDL_Event& evnt);

		const float getFps() const { return m_fps; }

		InputManager inputManager;

	protected:
		virtual void update();
		virtual void draw();

		bool init();
		bool initSystems();

		std::unique_ptr<ScreenList> m_screenList = nullptr;
		IGameScreen* m_currentScreen = nullptr;
		bool m_isRunning = false;
		float m_fps = 0.0f;
		Window m_window;
		int m_screenWidth = 1024;
		int m_screenHeight = 768;
		std::string m_windowName = "The Game!!";
	};

}