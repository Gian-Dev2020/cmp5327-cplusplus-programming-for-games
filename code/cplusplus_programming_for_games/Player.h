#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Player
{
public:
	Player(SDL_Renderer* sdlRenderer);

	void init();
	void render();
	void update();
	void clean();


	void moveR()
	{
		x += someSpeedConstant;
	}

private:
	int x = 0;
	int y = 0;
	int windowH = 0;
	int windowW = 0;
	int someSpeedConstant = 15;

	SDL_Renderer* renderer = nullptr;

	SDL_Texture* texture = nullptr;
};



