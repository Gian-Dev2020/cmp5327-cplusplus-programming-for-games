#pragma once
#include <SDL.h>
#include <string>
#include <iostream>

using namespace std;

class TiledMap
{
public:
	TiledMap(SDL_Renderer* TMRenderer, string TMfilename);

	int init();
	void clean();
	void render();

private:

	const int sourceTilePx = 70;
	const int TileW = 180;
	const int TileH = 160;

	string filename;
	SDL_Renderer* MapRenderer;
	SDL_Texture* MapTexture;

};

const int mapW = 4;
const int mapH = 4;
const int map[mapH][mapW] =
{
	{1,1,1,1},
	{12,12,12,12},
	{10,10,10,10},
	{26,26,26,26}
};

