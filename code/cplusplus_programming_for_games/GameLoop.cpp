#include "GameLoop.h"


using namespace std;

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;

int main()
{
	GameLoop gameloop = GameLoop();
	if (gameloop.init() < 0) return 1;

	while (gameloop.keepAlive())
	{
		gameloop.update();
		gameloop.render();
	}

	gameloop.clean();
	return 0;
}

int GameLoop::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Could not initialise SDL2" << endl;
		cout << SDL_GetError() << endl;
		return -1;
	}

	
	window = SDL_CreateWindow(
		"Window Finally",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		screenW, screenH,
		SDL_WINDOW_SHOWN
	);

	if (window == NULL)
	{
		cout << "Could not initialise window." << endl;
		cout << SDL_GetError() << endl;
		return -1;
	}

	screenSurface = SDL_GetWindowSurface(window);

	return 0;
}

bool GameLoop::keepAlive()
{
	SDL_Event userInput;

	while (SDL_PollEvent(&userInput))
	{
		if (userInput.type == SDL_QUIT)
		{
			return false;
		}

		if (userInput.type == SDL_KEYDOWN)
		{
			switch (userInput.key.keysym.scancode)
			{
			case SDL_SCANCODE_F:
				break;
			default:
				break;
			}
		}
	}

	return true;
}

void GameLoop::update()
{

}

void GameLoop::render()
{

}

void GameLoop::clean()
{
	SDL_DestroyWindow(window);
	SDL_Quit();

}