#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Player
{
public:
	Player(SDL_Renderer* sdlRenderer, int _windowW, int _windowH);

	void init();
	void render();
	void update();
	void clean();


	void moveR()
	{
		portion.x += someSpeedConstant;
		
		if (portion.x + portion.w >= windowW)
		{
			portion.x = windowW - portion.x;
		}
	}

	void MoveL()
	{
		portion.x -= someSpeedConstant;

		
	}

	void MoveUp()
	{
		portion.y -= someSpeedConstant;

		
	}

	void MoveDown()
	{
		portion.y += someSpeedConstant;
	}


private:
	
	int windowH = 750;
	int windowW = 750;
	int someSpeedConstant = 10;

	SDL_Rect portion;

	SDL_Renderer* renderer = nullptr;

	SDL_Texture* texture = nullptr;
};



