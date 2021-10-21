#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include "Player.h"
#include "FontRender.h"


const int screenW = 800;
const int screenH = 600;



class GameLoop
{
public:

	int init();

	void update();
	void render();
	bool keepAlive();
	void handleInput(SDL_Scancode& keyScanCode);

	void clean();

	SDL_Renderer* getRenderer() { return renderer; }

private:
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;

	std::unique_ptr<FontRender> fontRenderer;

	Player* player = nullptr;

};

