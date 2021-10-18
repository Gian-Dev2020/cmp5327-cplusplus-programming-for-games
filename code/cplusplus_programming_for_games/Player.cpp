#include "Player.h"
#include <SDL_image.h>

using namespace std;

Player::Player(SDL_Renderer* sdlRenderer)
{
	renderer = sdlRenderer;
}

void Player::init()
{
	SDL_Surface* image = IMG_Load("Assets/chibiCarlo.png");

	if (image == nullptr)
	{
		cout << "Could not load image!!" << endl;
		return;
	}

	texture = SDL_CreateTextureFromSurface(renderer, image);
}

void Player::render()
{
	SDL_Rect portion = SDL_Rect();
	portion.x = x;
	portion.y = y;

	float playerWidth = 0.2f * (float)windowW;

	portion.w = 120;
	portion.h = 120;
	SDL_RenderCopy(renderer, texture, NULL, &portion);
}


void Player::moveR()
{
	x += someSpeedConstant;
}

void Player::update()
{

}

void Player::clean()
{

}
