#pragma once

#include <unordered_map>
#include <glm/glm.hpp>

namespace Cogine {

	class InputManager {
	public:
		InputManager();
		~InputManager();

		void update();

		void pressKey(unsigned int keyID);
		void releaseKey(unsigned int keyID);

		/// Returns true if the key is held down
		bool isKeyDown(unsigned int keyID);

		/// Returns true if the key was just presses
		bool isKeyPressed(unsigned int keyID);


		void setMouseCoords(float x, float y);

		glm::vec2 getMouseCoords() const { return m_mouseCoords; }
	private:

		bool wasKeyDown(unsigned int keyID);

		std::unordered_map<unsigned int, bool> m_keyMap;
		std::unordered_map<unsigned int, bool> m_previousKeyMap;
		glm::vec2 m_mouseCoords;
	};
}