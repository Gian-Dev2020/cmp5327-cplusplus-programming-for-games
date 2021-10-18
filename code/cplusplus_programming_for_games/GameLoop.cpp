#include "GameLoop.h"


using namespace std;

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

	// checks if the SDL2 is working properly
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Could not initialise SDL2" << endl;
		cout << SDL_GetError() << endl;
		return -1;
	}

	// creates a game window
	window = SDL_CreateWindow(
		"Window Finally",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		screenW, screenH,
		SDL_WINDOW_SHOWN
	);

	// checks if the window has been made
	if (window == NULL)
	{
		cout << "Could not initialise window." << endl;
		cout << SDL_GetError() << endl;
		return -1;
	}

	// The block of code below creates a render to use in the window then checks if the renderer is working
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		cout << "Could not initialise renderer." << endl;
		cout << SDL_GetError() << endl;
		return -1;
	}

	player = new Player(renderer);
	player->init();

	screenSurface = SDL_GetWindowSurface(window); // grabs the window's size

	return 0;

	// return 0 means it's working, any other number means an error has occured.
}


void GameLoop::handleInput(SDL_Scancode& keyScanCode)
{
	switch (keyScanCode)
	{
	case SDL_SCANCODE_D:
		player->moveR();
	}
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

void GameLoop::render()
{
	SDL_RenderClear(renderer);
	player->render();
	SDL_RenderPresent(renderer);
}

void GameLoop::update()
{

}


void GameLoop::clean()
{
	delete player;
	SDL_DestroyWindow(window);
	SDL_Quit();

}