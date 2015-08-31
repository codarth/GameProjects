#include "InputManager.h"

namespace Cogine {

	InputManager::InputManager() : m_mouseCoords(0.0f) {}


	InputManager::~InputManager() {}

	void InputManager::update() {

		//loop through _keyMap using a for each loop, and copy it over to _previousKeyMap
		for (auto& it : m_keyMap) {
			m_previousKeyMap[it.first] = it.second; 
		}
	}

	void InputManager::pressKey(unsigned int keyID) {
		m_keyMap[keyID] = true;
	}
	
	void InputManager::releaseKey(unsigned int keyID) {
		m_keyMap[keyID] = false;
	}

	bool InputManager::isKeyDown(unsigned int keyID) {
		auto it = m_keyMap.find(keyID);
		if (it != m_keyMap.end()) {
			return it->second;
		} else {
			return false;
		}
	}

	bool InputManager::isKeyPressed(unsigned int keyID) {
		// Check if it is pressed this frame, and wasn't pressed last frame
		if (isKeyDown(keyID)==true && wasKeyDown(keyID)==false) {
			return true;
		}
		return false;
	}

	void InputManager::setMouseCoords(float x, float y) {
		m_mouseCoords.x = x;
		m_mouseCoords.y = y;
	}

	bool InputManager::wasKeyDown(unsigned int keyID) {
		auto it = m_previousKeyMap.find(keyID);
		if (it != m_previousKeyMap.end()) {
			return it->second;
		} else {
			return false;
		}
	}

}