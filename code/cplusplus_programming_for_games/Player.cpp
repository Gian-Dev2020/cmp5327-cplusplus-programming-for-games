#include "Player.h"
#include <SDL_image.h>

using namespace std;

Player::Player(SDL_Renderer* sdlRenderer, int _windowW, int _windowH)
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
	

	float playerWidth = 0.1f * (float)windowW;

	// The w and h sets the player's size
	portion.w = (int)playerWidth;
	portion.h = (int)playerWidth;
	SDL_RenderCopy(renderer, texture, NULL, &portion);
}

//
//void Player::moveR()
//{
//	x += someSpeedConstant;
//}

void Player::update()
{

}

void Player::clean()
{

}
