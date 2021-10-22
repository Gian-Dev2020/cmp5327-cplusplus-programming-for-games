#include "TiledMap.h"
#include <SDL_image.h>


TiledMap::TiledMap(SDL_Renderer* TMRenderer, string TMfilename)
{
	MapRenderer = TMRenderer;
	filename = TMfilename;

}

int TiledMap::init()
{
	SDL_Surface* Mapimage = IMG_Load(filename.c_str());
	MapTexture = SDL_CreateTextureFromSurface(MapRenderer, Mapimage);
	SDL_FreeSurface(Mapimage);
	return 0;
}

void TiledMap::render()
{
	for (int i = 0; i < mapH; i++) 
	{
		for (int j = 0; j < mapW; j++)
		{
			// the code below will crop the images using a rectangle
			SDL_Rect sourceRect;
			sourceRect.x = (map[i][j] % 6) * sourceTilePx;
			sourceRect.y = (map[i][j] / 6) * sourceTilePx;
			sourceRect.h = sourceTilePx;
			sourceRect.w = sourceTilePx;

			SDL_Rect renderRect;
			renderRect.x = j * TileW;
			renderRect.y = j * TileH;
			renderRect.h = TileH;
			renderRect.w = TileW;

			SDL_RenderCopy(MapRenderer, MapTexture, &sourceRect, &renderRect);
		}
	}

}

void TiledMap::clean()
{

}
