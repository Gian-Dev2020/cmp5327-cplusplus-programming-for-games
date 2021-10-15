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
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void Player::update()
{

}

void Player::clean()
{

}
