#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>


const int screenW = 800;
const int screenH = 600;



class GameLoop
{
public:
	
	int init();

	void update();
	void render();
	bool keepAlive();
	void clean();

private:
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;

	Player* player = nullptr;

};

