#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <string>
#include <iostream>

using namespace std;

class FontRender
{
public: // Access specifier

	// Everything here is an attribute in the form of functions.
	FontRender(SDL_Renderer* sdlRendererF);

	void init();
	void render(string text);
	void clean();

private:
	SDL_Renderer* Renderer;
	TTF_Font* Font;

};

