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
	// The x and y sets the sprite's location on the screen
	portion.x = x; 
	portion.y = y;

	float playerWidth = 0.2f * (float)windowW;

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
