#include "CogineErrors.h"

#include <iostream>
#include <cstdlib>
#include <SDL/SDL.h>

namespace Cogine {

	void fatalError(std::string errorString) {
		std::cout << errorString << std::endl;
		std::cout << "Enter key to quit...";
		int tmp;
		std::cin >> tmp;
		SDL_Quit();
		exit(1);
	}
}